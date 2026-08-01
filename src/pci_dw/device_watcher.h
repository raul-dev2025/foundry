

/*
	Old-style PCI probing:
	This function was excluded from 2.6 kernels in order to prevent
	crashing, if they happened to modify the device list. Used to walk
	the device list.
*/
struct pci_dev *pci_get_device(unsigned int vendor, unsigned int device,
															 struct pci_dev *from);

/*
	It allows to specifie ss_vendor and ss_device when looling for the
	device.
		@ss_vendor - sussystem vendor.
		@ss_device - sussystem device.
*/
struct pci_dev *pci_get_subsys(unsigned int vendor, unsigned int device,
		unsigned int ss_vendor, unsigned int ss_device, struct pci_dev *from);

/*
	It searches the list of PCI devices in the system on the specified
	pci_bus structure for the specified device and function number.
*/
struct pci_dev *pci_get_slot(struct pci_bus *bus, unsigned int devfn);

/*
	Standard Linux interface to access the configuration space.
	- 8-Bit
	- 16-Bit
	- 32-Bit 
*/
int pci_user_read_config_byte(struct pci_dev *dev, int where, u8 *val);
int pci_user_read_config_word(struct pci_dev *dev, int where, u16 *val);
int pci_user_read_config_dword(struct pci_dev *dev, int where, u32 *val);






