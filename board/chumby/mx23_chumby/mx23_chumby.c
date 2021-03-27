// SPDX-License-Identifier: GPL-2.0+
/*
 * Chumby bootloader hack
 * Olimex MX23 Olinuxino board
 *
 * Copyright (C) 2013 Marek Vasut <marex@denx.de>
 */
//from spl_boot.c
//#include <config.h>

#define MUX_CONFIG_EMI  (MXS_PAD_3V3 | MXS_PAD_12MA | MXS_PAD_PULLUP)
#define MUX_CONFIG_SSP  (MXS_PAD_8MA | MXS_PAD_PULLUP)
//end spl_boot.c

#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/iomux-mx23.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>

DECLARE_GLOBAL_DATA_PTR;

const iomux_cfg_t iomux_setup[] = {
        /* DUART */
        MX23_PAD_PWM0__DUART_RX,
        MX23_PAD_PWM1__DUART_TX,

        /* EMI */
        MX23_PAD_EMI_D00__EMI_D00 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D01__EMI_D01 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D02__EMI_D02 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D03__EMI_D03 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D04__EMI_D04 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D05__EMI_D05 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D06__EMI_D06 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D07__EMI_D07 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D08__EMI_D08 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D09__EMI_D09 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D10__EMI_D10 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D11__EMI_D11 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D12__EMI_D12 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D13__EMI_D13 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D14__EMI_D14 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_D15__EMI_D15 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_DQM0__EMI_DQM0 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_DQM1__EMI_DQM1 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_DQS0__EMI_DQS0 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_DQS1__EMI_DQS1 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_CLK__EMI_CLK | MUX_CONFIG_EMI,
        MX23_PAD_EMI_CLKN__EMI_CLKN | MUX_CONFIG_EMI,

        MX23_PAD_EMI_A00__EMI_A00 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A01__EMI_A01 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A02__EMI_A02 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A03__EMI_A03 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A04__EMI_A04 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A05__EMI_A05 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A06__EMI_A06 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A07__EMI_A07 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A08__EMI_A08 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A09__EMI_A09 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A10__EMI_A10 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A11__EMI_A11 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_A12__EMI_A12 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_BA0__EMI_BA0 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_BA1__EMI_BA1 | MUX_CONFIG_EMI,
        MX23_PAD_EMI_CASN__EMI_CASN | MUX_CONFIG_EMI,
        MX23_PAD_EMI_CE0N__EMI_CE0N | MUX_CONFIG_EMI,
        MX23_PAD_EMI_CE1N__EMI_CE1N | MUX_CONFIG_EMI,
        MX23_PAD_EMI_CKE__EMI_CKE | MUX_CONFIG_EMI,
        MX23_PAD_EMI_RASN__EMI_RASN | MUX_CONFIG_EMI,
        MX23_PAD_EMI_WEN__EMI_WEN | MUX_CONFIG_EMI,
        
	/* MMC 0 */
        MX23_PAD_SSP1_CMD__SSP1_CMD | MUX_CONFIG_SSP,
        MX23_PAD_SSP1_DATA0__SSP1_DATA0 | MUX_CONFIG_SSP,
        MX23_PAD_SSP1_DATA1__SSP1_DATA1 | MUX_CONFIG_SSP,
        MX23_PAD_SSP1_DATA2__SSP1_DATA2 | MUX_CONFIG_SSP,
        MX23_PAD_SSP1_DATA3__SSP1_DATA3 | MUX_CONFIG_SSP,
        MX23_PAD_SSP1_SCK__SSP1_SCK | MUX_CONFIG_SSP,
};



/*
 * Functions
 */
int board_early_init_f(void)
{
	//already initted from stock bootloader
	/* IO0 clock at 480MHz */
//	mxs_set_ioclk(MXC_IOCLK0, 480000);

	/* SSP0 clock at 96MHz */
//	mxs_set_sspclk(MXC_SSPCLK0, 96000, 0);

	return 0;
}

int dram_init(void)
{
	return mxs_dram_init();

/*
	arch/arm/cpu/arm926ejs/mxs/mxs.c 
	manually hacked - might could just snip this bit in here
	data->mem_dram_size = 0x04000000;
        gd->ram_size = data->mem_dram_size;
*/

}

int board_init(void)
{
	/* Adress of boot parameters */
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;
	//Executed after get_ram_size
	
	printf("IOMuxing: ");
	//enable UART and MMC pins
	mxs_iomux_setup_multiple_pads(iomux_setup, ARRAY_SIZE(iomux_setup));

        mxs_set_ioclk(MXC_IOCLK0, 480000);
        mxs_set_sspclk(MXC_SSPCLK0, 96000, 0);

	printf("Done.\n");	

	//disable hardware watchdog
	printf("Muzzling Watchdog: \n");
	printf("Watchdog: %08lX\n", (ulong)readl(0x8005C050));
	printf("RTC: %08lX\n", (ulong)readl(0x8005C000));
	writel(0x00000010, 0x8005C008);		
	//writel(0x8005C058, 0x00000000); doesn't work
	//writel(0x8005C004, 0x00000000); //doesn't work turn off watchdog thru hw_rtc_ctrl
	//writel(0x8005C008, 0x00000010); //clear watchdog bit with hw_rtc_ctrl_clr
	//writel(0x8005C00C, 0x00000010); //toggle watchdog bit with hw_rtc_ctrl_clr
	//writel(0x8005C054, 0x000FFFFF); //set watchdog timer 
	
	udelay(5000);
	printf("Watchdog: %08lX\n", (ulong)readl(0x8005C050)); //read watchdog timer
	printf("RTC: %08lX\n", (ulong)readl(0x8005C000));
	
/* - chumby source shell.c
    // Run the watchdogtimer, set to reboot the device in 20 seconds.
    "regutil -w HW_RTC_WATCHDOG 0x00004e20\n" 20000 - 20 seconds
    "regutil -w HW_RTC_CTRL_SET 0x00000010\n" - 1 ONEMSEC_IRQ_EN RW 0x0 1= Enable one millisecond interrupt. Use SCT writes to 

*/

//	arch/arm/cpu/arm926ejs/mxs/mxs.c:	writel(RTC_CTRL_WATCHDOGEN, &rtc_regs->hw_rtc_ctrl_set);
//HW_RTC_CTRL 0x8005C000
//HW_RTC_CTRL_SET 0x8005C004
//HW_RTC_CTRL_CLR 0x8005C008
//HW_RTC_CTRL_TOG 0x8005C00C

//HW_RTC_WATCHDOG 0x8005C050
//HW_RTC_WATCHDOG_CLR 0x8005C058
//HW_RTC_WATCHDOG_SET 0x8005C054
//HW_RTC_WATCHDOG_TOG 0x8005C05C

//MX23_PAD_PWM0__DUART_RX
//mxs_common_spl_init(arg, resptr, iomux_setup, ARRAY_SIZE(iomux_setup));
//mxs_iomux_setup_multiple_pads
//int mxs_iomux_setup_pad(iomux_cfg_t pad)
/*
arch/arm/include/asm/arch-mxs/iomux-mx23.h:#define MX23_PAD_PWM0__DUART_RX			MXS_IOMUX_PAD_NAKED(1, 26, PAD_MUXSEL_2)
arch/arm/include/asm/arch-mxs/iomux-mx23.h:#define MX23_PAD_PWM1__DUART_TX			MXS_IOMUX_PAD_NAKED(1, 27, PAD_MUXSEL_2)
*/

	return 0;
}


#ifdef CONFIG_CMD_USB
int board_ehci_hcd_init(int port)
{
        /* Enable LAN9512 (Maxi) or GL850G (Mini) USB HUB power. */
        gpio_direction_output(MX23_PAD_GPMI_ALE__GPIO_0_17, 1);
        udelay(100);
        return 0;
}

int board_ehci_hcd_exit(int port)
{
        /* Enable LAN9512 (Maxi) or GL850G (Mini) USB HUB power. */
        gpio_direction_output(MX23_PAD_GPMI_ALE__GPIO_0_17, 0);
        return 0;
}
#endif

#ifdef  CONFIG_CMD_MMC
static int mx23_olx_mmc_cd(int id)
{
        return 1;       /* Card always present */
}

int board_mmc_init(bd_t *bis)
{
        return mxsmmc_initialize(bis, 0, NULL, mx23_olx_mmc_cd);
}
#endif
