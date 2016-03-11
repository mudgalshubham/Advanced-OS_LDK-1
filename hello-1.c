#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/moduleparam.h>
#include<linux/init.h>
#include<linux/stat.h>

MODULE_AUTHOR("Shubham Mudgal");
MODULE_LICENSE("GPL");

static char *mystring = "something";

module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "Its a string");

static int __init hello_module_init(void)
{
	printk(KERN_INFO "Hello world: I am %s speaking from the kernel.\n", mystring);
	return 0;
}

static void __exit hello_module_exit(void)
{
	printk(KERN_INFO "Goodbye from %s. I am exiting the kernel.\n", mystring);
}

module_init(hello_module_init);
module_exit(hello_module_exit);

