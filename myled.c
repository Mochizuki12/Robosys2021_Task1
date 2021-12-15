#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/io.h>
#include <linux/delay.h>

#define a 73
#define b 17
#define x 20161
#define M 10000

#define a2 191
#define b2 31
#define x2 28657
#define M2 10000

MODULE_AUTHOR("Ryuichi Ueda and Yuya Mochizuki");
MODULE_DESCRIPTION("driver for 7segmentLED control");
MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.5");

static dev_t dev;
static struct cdev cdv;
static struct class *cls = NULL;
static volatile u32 *gpio_base = NULL;
char c;

static ssize_t led_write(struct file* filp, const char* buf, size_t count, loff_t* pos)
{
	
	int n, j, rand, first=0;
	if(copy_from_user(&c, buf, sizeof(char)))
		return -EFAULT;

//	printk(KERN_INFO "receive %c\n", c);


	if(c == 's'){
	for(j=0;j<100;j++){
	if(first == 0){
                rand = (a * x + b)%M;
		first = 1;

	}else if(first == 1){
		rand = (a * rand + b)%M;

	}
	
	n = rand % 9;
	
	if(n == 1){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 4;
		gpio_base[7] = 1 << 18;
		msleep(50);
		
	}else if(n == 2){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 2;
		gpio_base[7] = 1 << 4;
		gpio_base[7] = 1 << 14;
		gpio_base[7] = 1 << 15;
		gpio_base[7] = 1 << 17;
		msleep(50);

	}else if(n == 3){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 2;
		gpio_base[7] = 1 << 4;
		gpio_base[7] = 1 << 14;
		gpio_base[7] = 1 << 17;
		gpio_base[7] = 1 << 18;
		msleep(50);

	}else if(n == 4){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 3;
		gpio_base[7] = 1 << 4;
		gpio_base[7] = 1 << 14;
		gpio_base[7] = 1 << 18;
		msleep(50);

	}else if(n == 5){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 2;
		gpio_base[7] = 1 << 3;
		gpio_base[7] = 1 << 14;
		gpio_base[7] = 1 << 18;
		gpio_base[7] = 1 << 17;
		msleep(50);
		
	}else if(n == 6){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 2;
		gpio_base[7] = 1 << 3;
		gpio_base[7] = 1 << 14;
		gpio_base[7] = 1 << 15;
		gpio_base[7] = 1 << 17;
		gpio_base[7] = 1 << 18;
		msleep(50);

	}else if(n == 7){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 2;
		gpio_base[7] = 1 << 4;
		gpio_base[7] = 1 << 18;
		msleep(50);

	}else if(n == 8){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 2;
		gpio_base[7] = 1 << 3;
		gpio_base[7] = 1 << 4;
		gpio_base[7] = 1 << 14;
		gpio_base[7] = 1 << 15;
		gpio_base[7] = 1 << 17;
		gpio_base[7] = 1 << 18;
		msleep(50);

	}else if(n == 9){
		gpio_base[10] = 1 << 2;
		gpio_base[10] = 1 << 3;
		gpio_base[10] = 1 << 4;
		gpio_base[10] = 1 << 14;
		gpio_base[10] = 1 << 15;
		gpio_base[10] = 1 << 17;
		gpio_base[10] = 1 << 18;
		gpio_base[7] = 1 << 2;
		gpio_base[7] = 1 << 3;
		gpio_base[7] = 1 << 4;
		gpio_base[7] = 1 << 14;
		gpio_base[7] = 1 << 17;
		gpio_base[7] = 1 << 18;
		msleep(50);
	}
	}
        }

	return 1;
}

static struct file_operations led_fops = {
	.owner = THIS_MODULE,
	.write = led_write,
};

static int __init init_mod(void)
{
	int i;
	int gpio_num[8] = {14,15,18,17,2,3,4};
	int retval;
	retval = alloc_chrdev_region(&dev, 0, 1, "myled");
	if(retval < 0){
		printk(KERN_ERR "alloc_chrdev_region failed.\n");
		return retval;
	}

	printk(KERN_INFO "%s is loaded. major:%d\n", __FILE__, MAJOR(dev));

	cdev_init(&cdv, &led_fops);
	retval = cdev_add(&cdv, dev, 1);
	if(retval < 0){
		printk(KERN_ERR "cdev_add failed. major:%d, minor:%d\n", MAJOR(dev),MINOR(dev));
		return retval;
	}

	cls = class_create(THIS_MODULE, "myled");
	if(IS_ERR(cls)){
		printk(KERN_ERR " class_create failed.");
		return PTR_ERR(cls);
	}

	device_create(cls, NULL, dev, NULL, "myled%d",MINOR(dev));

	gpio_base = ioremap_nocache(0xfe200000, 0xA0);


	for(i=0;i<7;i++)
	{
		const u32 led = gpio_num[i];
	        const u32 index = led/10;
	        const u32 shift = (led%10)*3;
	        const u32 mask = ~(0x7<<shift);
	        gpio_base[index] = (gpio_base[index] & mask ) | (0x1 << shift);
	}

	return 0;
}

static void __exit cleanup_mod(void)
{
	cdev_del(&cdv);
	device_destroy(cls, dev);
	class_destroy(cls);
	unregister_chrdev_region(dev, 1);
	printk(KERN_INFO "%s is unloaded. major:%d\n", __FILE__, MAJOR(dev));
}

module_init(init_mod);
module_exit(cleanup_mod);

