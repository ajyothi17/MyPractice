#include <linux/init.h> 
#include <linux/module.h>
#include <linux/types.h> //dev_t type
#include <linux/fs.h> //chrdev allocation
#include <linux/slab.h> //kmalloc and kfree
#include <linux/cdev.h> //struct cdev
#include <linux/errno.h> //error codes
#include <linux/mutex.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Jyothi");
MODULE_DESCRIPTION("scull driver");

#define SCULL_COUNT 4
#define SCULL_NAME "scull"
#define SCULL(min_index) "scull" 
#define SCULL_MINOR_START 0
#define SCULL_QUANTUM_SIZE 4000
#define SCULL_NUM_QUANTUM 1000
#define ZERO 0
#define ONE 1

//memory structure, works like a linked list, data is a table of quantum pointers
struct scull_qset{
	void **data;
	struct scull_qset *next;
};

//Device structure
struct scull_dev{
	struct scull_qset *data; //pointer to first quantum set
	int quantum; //the current quantum size
	int qset; //the current array size
	unsigned long size; //amount of data store here
	unsigned int access_key; 
	struct semaphore sem; //mutual exclusion semaphore
	struct cdev cdev; //char device structure
};

//class and driver structures
struct class *mychar_class;
struct device *mychar_device;

struct file_operations scull_fops = {
	.owner = THIS_MODULE
//	.open = scull_open,
	//.read = scull_read,
	//.write = scull_write,
//	.release = scull_release
};

struct scull_dev *scull_devices; //contains the scull devices
dev_t my_dev; //contains major and first minor

int scull_trim(struct scull_dev *dev);
int scull_open(struct inode *inode, struct file *my_file);
int scull_release(struct inode *inode, struct file *my_file);

static int scull_init(void)
{
	int status;
	int index;
	char *scull[4] = {"scull0", "scull1", "scull2", "scull3"};

	printk(KERN_INFO"Initializing scull device...\n");

	//allocating device number
	status = alloc_chrdev_region(&my_dev,SCULL_MINOR_START, SCULL_COUNT, SCULL_NAME);
	if(status < ZERO){
		printk(KERN_INFO"Device number allocation failed\n");
		status = -ENODEV;
		return status;
	}
	printk(KERN_INFO"major number allocated: %d\n", MAJOR(my_dev));

	//allocating memory for SCULL_COUNT scull devices
	scull_devices = kmalloc(SCULL_COUNT * sizeof(struct scull_dev), GFP_KERNEL);
	if(scull_devices == NULL){
		status = -ENOMEM;
		return status;
	}

	memset(scull_devices, ZERO, SCULL_COUNT * sizeof(struct scull_dev));

	//create mychar_class and entry in sysfs
	mychar_class = class_create(THIS_MODULE, SCULL_NAME);
    if(IS_ERR(mychar_class)){
    	printk(KERN_ERR "class_create failed\n");
		kfree(scull_devices);
		unregister_chrdev_region(my_dev, SCULL_COUNT);
    }

	//Initialize the devices
	for(index = ZERO; index < SCULL_COUNT; index++){
		scull_devices[index].quantum = SCULL_QUANTUM_SIZE;
		scull_devices[index].qset = SCULL_NUM_QUANTUM;
//		mutex_init(&scull_devices[index].sem);
		
		//register the cdev, scull_fops contains all the defined callbacks
		cdev_init(&scull_devices[index].cdev, &scull_fops);
		scull_devices[index].cdev.owner = THIS_MODULE;
		scull_devices[index].cdev.ops = &scull_fops;

		status = cdev_add(&scull_devices[index].cdev, MKDEV(MAJOR(my_dev), MINOR(my_dev) + index), ONE);
		if(status){
			printk(KERN_INFO"Error in %d adding scull %d\n", status, index);
		
		}else{
			printk(KERN_INFO"scull %d added\n", index);
		}
			
		//create mychar_device in sysfs and add entry in /dev

  		mychar_device = device_create(mychar_class, NULL, MKDEV(MAJOR(my_dev), MINOR(my_dev) + index), NULL, scull[index]);

    	if(IS_ERR(mychar_device)){
	    	printk(KERN_ERR "device_create failed for scull %d\n", index);
    	
		}else{
	    	printk(KERN_ERR "device_create success for scull %d\n", index);

		}
	}	

	return ZERO;
}

static void scull_exit(void)
{
	int index;

	if(scull_devices){
		for(index = ZERO; index < SCULL_COUNT; index++){
			scull_trim(&scull_devices[index]);
			cdev_del(&scull_devices[index].cdev);
			printk(KERN_INFO"scull %d removed\n", index);
		}

		kfree(scull_devices);
	}

	unregister_chrdev_region(my_dev, SCULL_COUNT);
	
	printk(KERN_INFO"scull exit\n");
}

//scull_qset linked list cleanup
int scull_trim(struct scull_dev *dev)
{
	struct scull_qset *next;
	struct scull_qset *cur;
	int qset = scull_devices -> qset;
	int index;

	//visit all nodes in the linked list, cleaning the current one
	for(cur = dev -> data; cur; cur = next){
		if(cur -> data){
		
			//in the current nodes, free all pointers
			for(index = ZERO; index < qset; index++){
				kfree(cur -> data);
				cur -> data = NULL;
			}
		}

		next = cur -> next;
		kfree(cur);
	}

	dev -> size = ZERO;
	dev -> quantum = SCULL_QUANTUM_SIZE;
	dev -> qset = SCULL_NUM_QUANTUM;
	dev -> data = NULL;

	return ZERO;
}

module_init(scull_init);
module_exit(scull_exit);
