.PHONY: hello io-test bus-test pci-dw clean

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

hello:	
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/hello modules

io-test:
	$(MAKE) -C IO_tests

bus-test:
	$(MAKE) -C BUS_tests

pci-dw:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/pci_dw modules





clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	make -C IO_tests clean
	$(MAKE) -C BUS_tests clean
	