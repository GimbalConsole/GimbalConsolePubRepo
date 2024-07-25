#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xc0d43364, "tty_port_open" },
	{ 0x90f1996f, "usb_deregister" },
	{ 0x8e17b3ae, "idr_destroy" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0x69acdf38, "memcpy" },
	{ 0x286e4f60, "usb_autopm_get_interface_async" },
	{ 0x978ee40f, "usb_anchor_urb" },
	{ 0x99021677, "usb_autopm_get_interface" },
	{ 0x25050594, "usb_control_msg" },
	{ 0x1a103589, "kmalloc_caches" },
	{ 0xb236c6eb, "kmalloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0xe9e192a, "usb_ifnum_to_if" },
	{ 0x4dfa8d4b, "mutex_lock" },
	{ 0xb8f11603, "idr_alloc" },
	{ 0x3213f038, "mutex_unlock" },
	{ 0xd9a5ea54, "__init_waitqueue_head" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x9b1ae450, "tty_port_init" },
	{ 0xb79c47fe, "usb_alloc_coherent" },
	{ 0x7939ca3d, "usb_alloc_urb" },
	{ 0x7665a95b, "idr_remove" },
	{ 0xa1ea6db, "usb_free_coherent" },
	{ 0x1e0c6f22, "_dev_info" },
	{ 0xefa37542, "usb_driver_claim_interface" },
	{ 0x3577e0db, "usb_get_intf" },
	{ 0x474e8ecf, "tty_port_register_device" },
	{ 0xb33ded93, "usb_free_urb" },
	{ 0x20978fb9, "idr_find" },
	{ 0xe524704e, "tty_standard_install" },
	{ 0x296695f, "refcount_warn_saturate" },
	{ 0x2d3385d3, "system_wq" },
	{ 0xc5b6f236, "queue_work_on" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0xc6cbbc89, "capable" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0xaad8c7d6, "default_wake_function" },
	{ 0xa0eeba40, "pcpu_hot" },
	{ 0x4afb2238, "add_wait_queue" },
	{ 0x1000e51, "schedule" },
	{ 0x37110088, "remove_wait_queue" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xcd9c13a3, "tty_termios_hw_change" },
	{ 0xbd394d8, "tty_termios_baud_rate" },
	{ 0x5c83bd09, "usb_put_intf" },
	{ 0xad64e54f, "tty_port_tty_get" },
	{ 0x7e5669ce, "tty_vhangup" },
	{ 0x343952d2, "tty_kref_put" },
	{ 0xf9839d94, "tty_unregister_device" },
	{ 0x273c91b1, "usb_driver_release_interface" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x975ba36c, "usb_submit_urb" },
	{ 0x88c59944, "_dev_err" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0xf9aef543, "usb_autopm_put_interface_async" },
	{ 0xaa3abd68, "usb_kill_urb" },
	{ 0x3c12dfe, "cancel_work_sync" },
	{ 0x8427cc7b, "_raw_spin_lock_irq" },
	{ 0x4b750f53, "_raw_spin_unlock_irq" },
	{ 0x4cf6cfe7, "tty_port_put" },
	{ 0xc215a2da, "__tty_alloc_driver" },
	{ 0x67b27ec1, "tty_std_termios" },
	{ 0xcb89f5db, "tty_register_driver" },
	{ 0x5b8de061, "usb_register_driver" },
	{ 0x122c3a7e, "_printk" },
	{ 0x32429417, "tty_unregister_driver" },
	{ 0xc0d96310, "tty_driver_kref_put" },
	{ 0x6ebe366f, "ktime_get_mono_fast_ns" },
	{ 0xe2964344, "__wake_up" },
	{ 0x14041045, "__dynamic_dev_dbg" },
	{ 0x2ed4dd54, "tty_port_tty_hangup" },
	{ 0x6c947c39, "tty_insert_flip_string_fixed_flag" },
	{ 0x4caedb49, "tty_flip_buffer_push" },
	{ 0x6b8a6a64, "usb_autopm_get_interface_no_resume" },
	{ 0xc24a5724, "usb_autopm_put_interface" },
	{ 0xc67bc93c, "usb_get_from_anchor" },
	{ 0xf23e7dcc, "tty_port_tty_wakeup" },
	{ 0x146b102, "tty_port_hangup" },
	{ 0xd9d1dd20, "tty_port_close" },
	{ 0x43581fb4, "module_layout" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("usb:v1A86p7523d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86p7522d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86p5523d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v1A86pE523d*dc*dsc*dp*ic*isc*ip*in*");
MODULE_ALIAS("usb:v4348p5523d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "E033D604EAE908AC72926F2");
