/* rtsp server  programmer for capturing tha data and send it to the udp server*/

// v4l2src ! tee name=t t. ! x264enc ! mp4mux ! filesink location=/home/rish/Desktop/okay.264 t. ! videoconvert ! autovideosink
#include "../headers/headers.h"
static GMainLoop *loop;
static GstElement *pipeline,*pencode,*udpsink,*parse, *src,*encoder, *filter;
static GstBus *bus;
GstCaps *video_caps;


static gboolean message_cb (GstBus * bus, GstMessage * message, gpointer user_data)
{
  switch (GST_MESSAGE_TYPE (message)) {
    case GST_MESSAGE_ERROR:{
      GError *err = NULL;
      gchar *name, *debug = NULL;

      name = gst_object_get_path_string (message->src);
      gst_message_parse_error (message, &err, &debug);

      g_printerr ("ERROR: from element %s: %s\n", name, err->message);
      if (debug != NULL)
        g_printerr ("Additional debug info:\n%s\n", debug);

      g_error_free (err);
      g_free (debug);
      g_free (name);

      g_main_loop_quit (loop);
      break;
    }
    case GST_MESSAGE_WARNING:{
		GError *err = NULL;
		gchar *name, *debug = NULL;

		name = gst_object_get_path_string (message->src);
		gst_message_parse_warning (message, &err, &debug);

		g_printerr ("ERROR: from element %s: %s\n", name, err->message);
		if (debug != NULL)
		g_printerr ("Additional debug info:\n%s\n", debug);

		g_error_free (err);
		g_free (debug);
		g_free (name);
		break;
    }
    case GST_MESSAGE_EOS:{
		g_print ("Got EOS\n");
		g_main_loop_quit (loop);
		gst_element_set_state (pipeline, GST_STATE_NULL);
		g_main_loop_unref (loop);
		gst_object_unref (pipeline);
		exit(0);
		break;
	}
    default:
		break;
  }

  return TRUE;
}

void sigintHandler(int unused) {
	g_print("You ctrl-c-ed!");
	gst_element_send_event(pipeline, gst_event_new_eos()); 

}

int main(int argc, char *argv[])
{
	signal(SIGINT, sigintHandler);
	gst_init (&argc, &argv);

	pipeline = gst_pipeline_new(NULL);
	src = gst_element_factory_make("v4l2src", NULL);
	filter   = gst_element_factory_make ("capsfilter",      "filter");


	encoder = gst_element_factory_make("x264enc", NULL);
	parse = gst_element_factory_make("h264parse", NULL);
	pencode = gst_element_factory_make("rtph264pay", NULL);
	udpsink = gst_element_factory_make("udpsink", NULL);

	 video_caps = gst_caps_new_simple ("video/x-raw","format", G_TYPE_STRING, "NV12","width", G_TYPE_INT, 640,"height", G_TYPE_INT, 480,NULL);
	
	if (!pipeline || !src || !filter || !encoder || !parse || !pencode || !udpsink ||  !video_caps) {
		g_error("Failed to create elements");
		return -1;
	}
	 g_object_set (G_OBJECT (filter), "caps", video_caps, NULL);
        gst_caps_unref (video_caps);
        g_object_set (G_OBJECT (src), "num-buffers",3000, NULL);
	g_object_set (udpsink, "host", "172.16.9.225", "port", 5000,"sync","false",  NULL);

	g_object_set(encoder, "tune", 4, NULL); /* important, the encoder usually takes 1-3 seconds to process this. Queue buffer is generally upto 1 second. Hence, set tune=zerolatency (0x4) */

	gst_bin_add_many(GST_BIN(pipeline), src,  encoder,parse, pencode,udpsink, NULL);
/*
	if (!gst_element_link_many(src, NULL) 
		|| !gst_element_link_many(tee, queue_record, encoder, muxer, filesink, NULL)
			|| !gst_element_link_many(tee, queue_display, videoconvert, videosink, NULL)) {
		g_error("Failed to link elements");
		return -2;
	}*/

	if (!gst_element_link_many(src,encoder,parse,pencode,udpsink, NULL)) 
	  {
		g_error("Failed to link elements");
		return -2;
}
	loop = g_main_loop_new(NULL, FALSE);

	bus = gst_pipeline_get_bus(GST_PIPELINE (pipeline));
	gst_bus_add_signal_watch(bus);
	g_signal_connect(G_OBJECT(bus), "message", G_CALLBACK(message_cb), NULL);
	gst_object_unref(GST_OBJECT(bus));

	gst_element_set_state(pipeline, GST_STATE_PLAYING);

	g_print("Starting loop");
	g_main_loop_run(loop);

	return 0;
}
