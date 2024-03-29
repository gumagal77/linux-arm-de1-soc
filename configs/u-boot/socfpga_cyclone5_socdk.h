/*
 * Copyright (C) 2014 Marek Vasut <marex@denx.de>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */
#ifndef __CONFIG_SOCFPGA_CYCLONE5_H__
#define __CONFIG_SOCFPGA_CYCLONE5_H__

#include <asm/arch/base_addr_ac5.h>

/* U-Boot Commands */
#define CONFIG_SYS_NO_FLASH
#define CONFIG_DOS_PARTITION
#define CONFIG_FAT_WRITE
#define CONFIG_HW_WATCHDOG

/* Memory configurations */
#define PHYS_SDRAM_1_SIZE		0x40000000	/* 1GiB on SoCDK */

/* Booting Linux */
#define CONFIG_BOOTDELAY	3
#define CONFIG_BOOTFILE		"zImage"
#define CONFIG_BOOTARGS		"console=ttyS0," __stringify(CONFIG_BAUDRATE)
#ifdef CONFIG_SOCFPGA_VIRTUAL_TARGET
#define CONFIG_BOOTCOMMAND	"run callscript"
#else
#define CONFIG_BOOTCOMMAND	"run callscript"
#endif
#define CONFIG_LOADADDR		0x01000000
#define CONFIG_SYS_LOAD_ADDR	CONFIG_LOADADDR

/* Ethernet on SoC (EMAC) */
#if defined(CONFIG_CMD_NET)
#define CONFIG_PHY_MICREL
#define CONFIG_PHY_MICREL_KSZ9021
#endif

#define CONFIG_ENV_IS_IN_MMC

/* Extra Environment */
/*#define CONFIG_EXTRA_ENV_SETTINGS \
	"verify=n\0" \
	"loadaddr=" __stringify(CONFIG_SYS_LOAD_ADDR) "\0" \
	"ramboot=setenv bootargs " CONFIG_BOOTARGS ";" \
		"bootm ${loadaddr} - ${fdt_addr}\0" \
	"bootimage=zImage\0" \
	"fdt_addr=100\0" \
	"fdtimage=socfpga.dtb\0" \
	"bootm ${loadaddr} - ${fdt_addr}\0" \
	"mmcroot=/dev/mmcblk0p2\0" \
	"mmcboot=setenv bootargs " CONFIG_BOOTARGS \
		" root=${mmcroot} rw rootwait;" \
		"bootz ${loadaddr} - ${fdt_addr}\0" \
	"mmcload=mmc rescan;" \
		"load mmc 0:1 ${loadaddr} ${bootimage};" \
		"load mmc 0:1 ${fdt_addr} ${fdtimage}\0" \
	"qspiload=sf probe && mtdparts default && run ubiload\0" \
	"qspiboot=setenv bootargs " CONFIG_BOOTARGS \
		" ubi.mtd=1,64 root=ubi0:rootfs rw rootfstype=ubifs;"\
		"bootz ${loadaddr} - ${fdt_addr}\0" \
	"ubiload=ubi part UBI && ubifsmount ubi0 && " \
		"ubifsload ${loadaddr} /boot/${bootimage} && " \
		"ubifsload ${fdt_addr} /boot/${fdtimage}\0"
*/

#define CONFIG_EXTRA_ENV_SETTINGS \
	"scriptfile=u-boot.scr" "\0" \
	"fpgadata=0x2000000" "\0" \
	"callscript=fatload mmc 0:1 $fpgadata $scriptfile;" \
	"source $fpgadata" "\0"


/* The rest of the configuration is shared */
#include <configs/socfpga_common.h>

#endif	/* __CONFIG_SOCFPGA_CYCLONE5_H__ */
