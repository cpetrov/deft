UDEV_RULES := /lib/udev/rules.d/90-hid-rebind.rules
HID_REBIND := /sbin/hid-rebind
DEPMOD_CONF := /etc/depmod.d/hid-deft.conf
KERNEL_VERSION := $(shell uname -r)

obj-m += hid-deft.o

modules modules_install clean:
	make -C /lib/modules/$(KERNEL_VERSION)/build SUBDIRS=$(shell pwd) $@

install:
	make modules_install
	make post_install

post_install:
	install -D -m 0644 hid-deft.conf $(DEPMOD_CONF)
	depmod -a
	install hid-rebind $(HID_REBIND)
	install -m 0644 90-hid-rebind.rules $(UDEV_RULES)
	udevadm control --reload

uninstall:
	rm -vf /lib/modules/$(KERNEL_VERSION)/extra/hid-deft.ko.gz \
		/lib/modules/$(KERNEL_VERSION)/extra/hid-deft.ko
	make post_uninstall

post_uninstall:
	rm -vf $(UDEV_RULES) $(HID_REBIND) $(DEPMOD_CONF)
	udevadm control --reload
	depmod -a
