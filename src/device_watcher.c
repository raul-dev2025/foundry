#include <linux/config.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/init.h>
#include "device_watcher.h"


// struct pci_device_id pci_watcher_ids;
struct pci_device_id pci_watcher_ids[] = {
	{ PCI_DEVICE(VENDOR_ID, DEVICE_ID) },
	{0, }
};

MODULE_DEVICE_TABLE(pci, pci_watcher_ids);

static struct pci_driver pci_watcher_driver = {
	.name = "pci_watcher",
	.id_table = pci_watcher_ids,
	.probe = pci_watcher_probe,
	.remove = pci_watcher_remove,
};

static int __init device_watcher_init(void){
	return pci_register_driver(&pci_watcher_driver)
}

struct pci_dev *dev;
dev = pci_get_device(PCI_VENDOR_*, PCI_DEVICE_*, NULL);
if (dev){
	...
	pci_dev_put(dev);
}
		 
/*
	Before any access of a device resource, it should be enabled 
	in the probe function.
*/
int pci_enable_device(struct pci_dev *dev);

/*
	This function is used to address configuration variables using the
	pci_user_read_* functions; it fetches the value from *dev structure
	and pass it to the where argument on every function variant.
	TODO:
		[x]- Vendor_ID
		[x]- Device_ID
		[]- Command_reg_ID
		[]- Status_reg
		[x]- Revision	
		[]- Header_type
		[]- Implement a way to retrive the add. conf. vars using
				the PCI_ANY_ID place holder.
		
*/
static unsigned char dw_get_vendor(struct pci_dev *dev){
	u16 vendor;
	
	pci_user_read_config_word(dev, PCI_VENDOR_ID, &vendor);
	return vendor;
}

static unsigned char dw_get_device(struct pci_dev *dev){
	u16 device;
	
	pci_user_read_config_word(dev, PCI_DEVICE_ID, &device);
	return device;
}

static unsigned char dw_get_revision(struct pci_dev *dev){
	u8 revision;
	
	pci_user_read_config_byte(dev, PCI_REVISION_ID, &revision);
	return revision;
}















static void __exit device_watcher_exit(void){
	pci_unregister_driver(&pci_watcher_driver);
}

