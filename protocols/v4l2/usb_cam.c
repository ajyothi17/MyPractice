#include <linux/module.h>
#include <linux/usb.h>
#include <media/v4l2-device.h>

struct usb_camera
{
	struct usb_device *udev;
	struct usb_interface *intf;
	struct v4l2_device vdev;
};

static int usb_cam_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
	struct usb_device *udev = interface_to_usbdev(intf);
	struct usb_camera *dev;

	/* Allocate memory for the device and initialize it. */
    dev = kzalloc(sizeof(*dev), GFP_KERNEL);
    if (dev == NULL)
        return -ENOMEM;

	dev->udev = usb_get_dev(udev);
    dev->intf = usb_get_intf(intf);
	
	if (v4l2_device_register(&intf->dev, &dev->vdev) < 0)
	{
		return -ENODEV;
	}

	printk(KERN_INFO "Inside probe\n");
	return 0;
}

static void usb_cam_disconnect(struct usb_interface *intf)
{
    struct usb_camera *dev = usb_get_intfdata(intf);

    /* Set the USB interface data to NULL. This can be done outside the
     * lock, as there's no other reader.
     */
    usb_set_intfdata(intf, NULL);

	if (dev->vdev.dev)
        v4l2_device_unregister(&dev->vdev);
}

static const struct v4l2_file_operations fops = {
    .owner = THIS_MODULE,
//    .open = usb_open,
//    .read = usb_read,
//	.write = usb_write,
//    .release = usb_release,
};

static const struct usb_device_id usb_ids[] = {
	{ .match_flags      = USB_DEVICE_ID_MATCH_DEVICE
                | USB_DEVICE_ID_MATCH_INT_INFO,
      .idVendor     = 0x041e,
      .idProduct        = 0x406c,
      .bInterfaceClass  = USB_CLASS_VENDOR_SPEC,
      .bInterfaceSubClass   = 1,
      .bInterfaceProtocol   = 0 },

    { }
};

struct usb_driver usb_cam_driver = {
	.name = "usb_camera",
	.probe = usb_cam_probe,
	.disconnect = usb_cam_disconnect,
	.id_table = usb_ids,
};

static int __init usb_cam_init(void)
{
    int status;

    status = usb_register(&usb_cam_driver);

    if(status < 0){
        printk(KERN_INFO "driver not added\n");
        return status;
    }

    printk(KERN_INFO "driver added\n");
    
    return 0;
}

static void __exit usb_cam_exit(void)
{
    printk(KERN_INFO "exiting device\n");
    usb_deregister(&usb_cam_driver);

    return ;
}

module_init(usb_cam_init);
module_exit(usb_cam_exit);
MODULE_LICENSE("GPL");
MODULE_INFO(intree, "Y");
MODULE_AUTHOR("Jyothi A.");
