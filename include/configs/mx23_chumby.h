/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2013 Marek Vasut <marex@denx.de>
 */
#ifndef __CONFIGS_MX23_CHUMBY_H__
#define __CONFIGS_MX23_CHUMBY_H__

/* System configurations */
//masquerade as olimex mx233
//#define CONFIG_MACH_TYPE	4105
//Sigmatel STMP378x from http://arm.linux.org.uk/devloper/machines
#define CONFIG_MACH_TYPE	1733

#define CONFIG_CMDLINE_TAG
//#define CONFIG_SERIAL_TAG

/* U-Boot Commands */

/* Memory configuration */
#define PHYS_SDRAM_1			0x40000000	/* Base address */
//basic chumby
//#define PHYS_SDRAM_1_SIZE		0x08000000	/* Max 128 MB RAM */
#define PHYS_SDRAM_1_SIZE		0x04000000	/* 64 MB RAM */
#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1

/* USB */
#ifdef CONFIG_CMD_USB
#define CONFIG_EHCI_MXS_PORT0
#define CONFIG_USB_MAX_CONTROLLER_COUNT 1
#endif

/* Framebuffer support */
#ifdef CONFIG_VIDEO
#define CONFIG_VIDEO_LOGO
#define CONFIG_SPLASH_SCREEN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_VIDEO_BMP_GZIP
#define CONFIG_SYS_VIDEO_LOGO_MAX_SIZE  (512 << 10)
#endif

/* Booting Linux */
#define CONFIG_CMD_BOOTZ 
#define CONFIG_BOOTFILE		"zImage"
#define CONFIG_LOADADDR		0x42000000
#define CONFIG_SYS_LOAD_ADDR	CONFIG_LOADADDR

/* Extra Environment */
#define CONFIG_EXTRA_ENV_SETTINGS \
	"script=boot.scr\0"	\
	"zimage=/boot/zImage\0" \
	"console=ttyAMA0\0" \
	"fdt_file=/boot/imx23-chumby.dtb\0" \
	"fdt_addr=0x41000000\0" \
	"boot_fdt=try\0" \
	"mmcdev=0\0" \
	"mmcpart=3\0" \
	"mmcroot=/dev/mmcblk0p3 rw rootwait\0" \
	"mmcargs=setenv bootargs console=${console},${baudrate} " \
		"rootfstype=ext4 ssp1=mmc ram=64M net.ifnames=0 " \
		"root=${mmcroot} debug\0" \
	"loadbootscript="  \
		"ext4load mmc ${mmcdev}:${mmcpart} ${loadaddr} ${script};\0" \
	"bootscript=echo Running bootscript from mmc ...; "	\
		"source\0" \
	"loadzimage=ext4load mmc ${mmcdev}:${mmcpart} ${loadaddr} ${zimage}\0" \
	"loadfdt=ext4load mmc ${mmcdev}:${mmcpart} ${fdt_addr} ${fdt_file}\0" \
	"mmcboot=echo Booting from mmc ...; " \
		"run mmcargs; " \
		"if test ${boot_fdt} = yes || test ${boot_fdt} = try; then " \
			"if run loadfdt; then " \
				"bootz ${loadaddr} - ${fdt_addr}; " \
			"else " \
				"if test ${boot_fdt} = try; then " \
					"bootm; " \
				"else " \
					"echo WARN: Cannot load the DT; " \
				"fi; " \
			"fi; " \
		"else " \
			"bootm; " \
		"fi;\0" \
	

#define CONFIG_BOOTCOMMAND \
	"mmc dev ${mmcdev}; if mmc rescan; then " \
		"if run loadbootscript; then " \
			"run bootscript; " \
		"else " \
			"if run loadzimage; then " \
				"run mmcboot; " \
			"fi; " \
		"fi; " \
	"fi"

/* The rest of the configuration is shared */
#include <configs/mxs.h>

#endif /* __CONFIGS_MX23_CHUMBY_H__ */
