// SPDX-License-Identifier: GPL-2.0+
/*
 * Chumby Chumby One falconwing board
 * based on
 * Olimex MX23 Olinuxino board
 *
 * Copyright (C) 2013 Marek Vasut <marex@denx.de>
 */

#include <linux/delay.h>
#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/iomux-mx23.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>

DECLARE_GLOBAL_DATA_PTR;

/*
 * Functions
 */
int board_early_init_f(void)
{
	/* IO0 clock at 480MHz */
	mxs_set_ioclk(MXC_IOCLK0, 480000);

	/* SSP0 clock at 96MHz */
	mxs_set_sspclk(MXC_SSPCLK0, 96000, 0);

	return 0;
}

int dram_init(void)
{
	return mxs_dram_init();
}

int board_init(void)
{
	/* Adress of boot parameters */
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;

	return 0;
}


#ifdef CONFIG_CMD_USB
int board_ehci_hcd_init(int port)
{
        /* Enable USB HUB power. */
        gpio_direction_output(MX23_PAD_AUART1_CTS__GPIO_0_26, 1);
	/* Disable USB HUB reset. */
        gpio_direction_output(MX23_PAD_AUART1_TX__GPIO_0_29, 1);
        udelay(100);
        return 0;
}

int board_ehci_hcd_exit(int port)
{
        /* Disable USB HUB power. */
        gpio_direction_output(MX23_PAD_AUART1_CTS__GPIO_0_26, 0);
	/* Enable USB HUB reset. */
        gpio_direction_output(MX23_PAD_AUART1_TX__GPIO_0_29, 0);
        return 0;
}
#endif

#ifdef  CONFIG_CMD_MMC
static int mx23_olx_mmc_cd(int id)
{
        return 1;       /* Card always present */
}

int board_mmc_init(struct bd_info *bis)
{
        return mxsmmc_initialize(bis, 0, NULL, mx23_olx_mmc_cd);
}
#endif
