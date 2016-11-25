/*
 *  HID driver for Elecom DEFT (trackball).
 *  Extend the number of buttons to 8, and
 *  remove a non-standard item in the HID
 *  descriptor.
 *  (This module is based on "hid-elecom".)
 *
 *  Copyright (c) 2016 Yuxuan Shui <yshuiv7@gmail.com>
 */

/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#include <linux/device.h>
#include <linux/hid.h>
#include <linux/module.h>

#include "hid-ids.h"

static __u8 *deft_report_fixup(struct hid_device *hdev, __u8 *rdesc,
		unsigned int *rsize)
{
	if (*rsize >= 34 && rdesc[20] == 0x29 && rdesc[21] == 0x05) {
		hid_info(hdev, "Fixing up Elecom DEFT report descriptor %x\n", rdesc[13]);
		rdesc[21] = 0x08;
		rdesc[13] = 0x08;

		memmove(rdesc+28, rdesc+34, *rsize-34);
		*rsize -= 6;
	}
	return rdesc;
}

static const struct hid_device_id deft_devices[] = {
	{ HID_USB_DEVICE(USB_VENDOR_ID_ELECOM, USB_DEVICE_ID_ELECOM_DEFT)},
	{ HID_USB_DEVICE(USB_VENDOR_ID_ELECOM, USB_DEVICE_ID_ELECOM_DEFTW)},
	{ }
};
MODULE_DEVICE_TABLE(hid, deft_devices);

static struct hid_driver deft_driver = {
	.name = "deft",
	.id_table = deft_devices,
	.report_fixup = deft_report_fixup,
};
module_hid_driver(deft_driver);

MODULE_LICENSE("GPL");
