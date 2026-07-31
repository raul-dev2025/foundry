00:00.0 Host bridge
00:00.2 IOMMU
00:01.0 Host bridge
00:01.1 PCI bridge
00:01.3 PCI bridge
00:02.0 Host bridge
00:03.0 Host bridge
00:03.1 PCI bridge
00:04.0 Host bridge
00:07.0 Host bridge
00:07.1 PCI bridge
00:08.0 Host bridge
00:08.1 PCI bridge
00:14.0 SMBus
00:14.3 ISA bridge
00:18.0 Host bridge
00:18.1 Host bridge
00:18.2 Host bridge
00:18.3 Host bridge
00:18.4 Host bridge
00:18.5 Host bridge
00:18.6 Host bridge
00:18.7 Host bridge
01:00.0 Non-Volatile memory controller
02:00.0 USB controller
02:00.1 SATA controller
02:00.2 PCI bridge
03:00.0 PCI bridge
03:02.0 PCI bridge
03:03.0 PCI bridge
03:04.0 PCI bridge
04:00.0 USB controller
05:00.0 Ethernet controller
06:00.0 Ethernet controller
08:00.0 VGA compatible controller
08:00.1 Audio device
09:00.0 Non-Essential Instrumentation [1300]
09:00.2 Encryption controller
09:00.3 USB controller
0a:00.0 Non-Essential Instrumentation [1300]
0a:00.2 SATA controller

############################################

			==================
			=	----		------ =
			=	----		-    - =				-------------				------------
			=	RAM 		-    - = -------|Host Bridge|-------|PCI bridge|
			=	    		------ =				-------------				------------
			=	    		  CPU  =		(pci_bus0)|					(pci_bus1)|
			==================					----------					----------
																	|  CARD	 |					|  CARD	 |
																	----------					----------

####################################################
## (domain,		 bus, 			device, 		function)		 #
## (|->16bits,  |->8bits,		|->5bits,		 |->3bits) #
####################################################
domain 0000
		|
		|-->	00:00.0 --> Host bridge
						|--> 00:00.2  --- Input/output Memory Management Unit(IOMMU).
		|-->	00:01.0 --> Host bridge
						|--> 00:01.1 PCI Bridge
						|--> 00:01.3 PCI Bridge
		|-->	00:02.0 --> Host bridge
		|-->	00:03.0 --> Host bridge
						|--> 00:03.1 PCI Bridge
		|-->	00:04.0 --> Host bridge
		|-->	00:07.0 --> Host bridge
						|--> 00:07.1 PCI Bridge
		|-->	00:08.0 --> Host bridge
						|--> 00:08.1 PCI Bridge
		|-->	00:14.0 --> SMBus
						|--> 00:14.3 ISA bridge
		|-->	00:18.0 --> Host bridge
		|-->	00:18.1 --> Host bridge
		|-->	00:18.2 --> Host bridge
		|-->	00:18.3 --> Host bridge
		|-->	00:18.4 --> Host bridge
		|-->	00:18.5 --> Host bridge
		|-->	00:18.6 --> Host bridge
		|-->	00:18.7 --> Host bridge
		|-->	01:00.0 --> Non-volatile memory controller
		|-->	02:00.0 --> USB controller
						|--> 02:00.1 SATA controller
						|--> 02:00.2 PCI Bridge
		|-->	#################################(Host bridge ??)
						|--> 03:00.0 PCI Bridge
						|--> 03:02.0 PCI Bridge
						|--> 03:03.0 PCI Bridge
						|--> 03:04.0 PCI Bridge
		|-->	#################################(Host bridge ??)
		|-->	04:00.0 --> USB controller
		|-->	05:00.0 --> Ethernet controller
		|-->	06:00.0 --> Ethernet controller
		|-->	08:00.0 --> VGA compatible controller
						|--> 08:00.1 Audio device
		|-->	09:00.0 --> Non-Essential Instrumentation [1300]
						|--> 09:00.2 Encryption controller
						|--> 09:00.3 --> USB controller
		|-->	0a:00.0 --> Non-Essential Instrumentation [1300](0x000a->14)
						|--> 0a:00.2 --> SATA controller
#######################################################
##  Global registry -- PCI Special Interest Group.	 ##
#######################################################
 -Advanced Micro Devices, Inc (4130, 1022 Hex)
 -Intel Corporation (32902, 8086 Hex)






