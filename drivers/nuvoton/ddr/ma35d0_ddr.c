/*
 * Copyright (C) 2023 Nuvoton Technology Corp. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <stdint.h>
#include <string.h>

#include <lib/mmio.h>
#include <libfdt.h>

#include <plat/common/platform.h>
#include <platform_def.h>

#include <ma35d0_ddr.h>

#include <custom_ddr.h>

struct nvt_ddr_init_param ma35d0_wb_ddr3_256mb = {
		0x00000001,   // 0
		0x00000001,   // 1
		0x01040001,   // 2
		0x0000d010,   // 3
		0x00000000,   // 4
		0x00000000,   // 5
		0x00400010,   // 6
		0x000a0003,   // 7
		0x00210000,   // 8
		0x003c003c,   // 9
		0x00000000,   // 10
		0x0010002b,   // 11
		0x00000000,   // 12
		0x40020083,   // 13
		0x00350002,   // 14
		0x1b400006,   // 15
		0x00480000,   // 16
		0x00090000,   // 17
		0x00000000,   // 18
		0x0000032f,   // 19
		0x090d040a,   // 20
		0x0003020e,   // 21
		0x00000408,   // 22
		0x00003007,   // 23
		0x04020205,   // 24
		0x03030202,   // 25
		0x00000a02,   // 26
		0x80000032,   // 27
		0x00800020,   // 28
		0x00000100,   // 29
		0x04020101,   // 30
		0x00060101,   // 31
		0x0700b030,   // 32
		0x00400005,   // 33
		0x00170066,   // 34
		0x80000000,   // 35
		0x00000011,   // 36
		0x00000000,   // 37
		0x00000015,   // 38
		0x00080808,   // 39
		0x00000000,   // 40
		0x00000000,   // 41
		0x00001f1f,   // 42
		0x070f0707,   // 43
		0x0f0f0707,   // 44
		0x07070707,   // 45
		0x07070707,   // 46
		0x00000007,   // 47
		0x06000608,   // 48
		0x00000101,   // 49
		0x00f51f00,   // 50
		0x00000000,   // 51
		0x0f000001,   // 52
		0x0f00007f,   // 53
		0x0f00007f,   // 54
		0x00000000,   // 55
		0x00000000,   // 56
		0x00000000,   // 57
		0x00000001,   // 58
		0x00000000,   // 59
		0x00110011,   // 60
		0x00000001,   // 61
		0x00000000,   // 62
		0x00000000,   // 63
		0x00000000,   // 64
		0x00000000,   // 65
		0x00000000,   // 66
		0x00000001,   // 67
		0x00000000,   // 68
		0x0001500f,   // 69
		0x0001500f,   // 70
		0x0001500f,   // 71
		0x0001500f,   // 72
		0x0001500f,   // 73
		0x0001500f,   // 74
		0x0001500f,   // 75
		0x0000500f,   // 76
		0x0000500f,   // 77
		0x0000500f,   // 78
		0x0000500f,   // 79
		0x0000500f,   // 80
		0x0000500f,   // 81
		0x0000500f,   // 82
		0x00000008,   // 83
		0x00000000,   // 84

		 // DDR PHY
		0xf004649f,   // 85
		0x0300c461,   // 86
		0x00f0027f,   // 87
		0x0c806403,   // 88
		0x27100385,   // 89
		0x00083def,   // 90
		0x05b4111d,   // 91
		0x0801a072,   // 92
		0x00001b40,   // 93
		0x00000006,   // 94
		0x00000048,   // 95
		0x00000000,   // 96
		0x71568855,   // 97
		0x2282b32a,   // 98
		0x30023e00,   // 99
		0x0000105d,   // 100
		0x0000040b,   // 101
		0x91003587,   // 102
		0x0001c000,   // 103
		0x0000ff81,   // 104

		0x0000000b,   // 105
		0x00000000,   // 106
		0x00000001,   // 107
};

struct DDR_Setting nvt_ddr_init_setting[] = {
	DDR_CTL_REG(DBG1_1),     // 0
	DDR_CTL_REG(PWRCTL_1),   // 1
	DDR_CTL_REG(MSTR),       // 2
	DDR_CTL_REG(MRCTRL0),    // 3
	DDR_CTL_REG(MRCTRL1),    // 4
	DDR_CTL_REG(PWRCTL_2),   // 5
	DDR_CTL_REG(PWRTMG),     // 6
	DDR_CTL_REG(HWLPCTL),    // 7
	DDR_CTL_REG(RFSHCTL0),   // 8
	DDR_CTL_REG(RFSHCTL1),   // 9
	DDR_CTL_REG(RFSHCTL3),   // 10
	DDR_CTL_REG(RFSHTMG),    // 11
	DDR_CTL_REG(CRCPARCTL0), // 12
	DDR_CTL_REG(INIT0),      // 13
	DDR_CTL_REG(INIT1),      // 14
	DDR_CTL_REG(INIT3),      // 15
	DDR_CTL_REG(INIT4),      // 16
	DDR_CTL_REG(INIT5),      // 17
	DDR_CTL_REG(DIMMCTL),    // 18
	DDR_CTL_REG(RANKCTL),    // 19
	DDR_CTL_REG(DRAMTMG0),   // 20
	DDR_CTL_REG(DRAMTMG1),   // 21
	DDR_CTL_REG(DRAMTMG2),   // 22
	DDR_CTL_REG(DRAMTMG3),   // 23
	DDR_CTL_REG(DRAMTMG4),   // 24
	DDR_CTL_REG(DRAMTMG5),   // 25
	DDR_CTL_REG(DRAMTMG8),   // 26
	DDR_CTL_REG(DRAMTMG15),  // 27
	DDR_CTL_REG(ZQCTL0),     // 28
	DDR_CTL_REG(ZQCTL1),     // 29
	DDR_CTL_REG(DFITMG0),    // 30
	DDR_CTL_REG(DFITMG1),    // 31
	DDR_CTL_REG(DFILPCFG0),  // 32
	DDR_CTL_REG(DFIUPD0),    // 33
	DDR_CTL_REG(DFIUPD1),    // 34
	DDR_CTL_REG(DFIUPD2),    // 35
	DDR_CTL_REG(DFIMISC),    // 36
	DDR_CTL_REG(DFIPHYMSTR), // 37
	DDR_CTL_REG(ADDRMAP0),   // 38
	DDR_CTL_REG(ADDRMAP1),   // 39
	DDR_CTL_REG(ADDRMAP2),   // 40
	DDR_CTL_REG(ADDRMAP3),   // 41
	DDR_CTL_REG(ADDRMAP4),   // 42
	DDR_CTL_REG(ADDRMAP5),   // 43
	DDR_CTL_REG(ADDRMAP6),   // 44
	DDR_CTL_REG(ADDRMAP9),   // 45
	DDR_CTL_REG(ADDRMAP10),  // 46
	DDR_CTL_REG(ADDRMAP11),  // 47
	DDR_CTL_REG(ODTCFG),     // 48
	DDR_CTL_REG(ODTMAP),     // 49
	DDR_CTL_REG(SCHED),      // 50
	DDR_CTL_REG(SCHED1),     // 51
	DDR_CTL_REG(PERFHPR1),   // 52
	DDR_CTL_REG(PERFLPR1),   // 53
	DDR_CTL_REG(PERFWR1),    // 54
	DDR_CTL_REG(DBG0),       // 55
	DDR_CTL_REG(DBG1_2),     // 56
	DDR_CTL_REG(DBGCMD),     // 57
	DDR_CTL_REG(SWCTL_1),    // 58
	DDR_CTL_REG(SWCTLSTATIC),// 59
	DDR_CTL_REG(POISONCFG),  // 60
	DDR_CTL_REG(PCTRL_0),    // 61
	DDR_CTL_REG(PCTRL_1),    // 62
	DDR_CTL_REG(PCTRL_2),    // 63
	DDR_CTL_REG(PCTRL_3),    // 64
	DDR_CTL_REG(PCTRL_4),    // 65
	DDR_CTL_REG(PCTRL_5),    // 66
	DDR_CTL_REG(PCTRL_6),    // 67
	DDR_CTL_REG(PCCFG),      // 68
	DDR_CTL_REG(PCFGR_0),    // 69
	DDR_CTL_REG(PCFGR_1),    // 70
	DDR_CTL_REG(PCFGR_2),    // 71
	DDR_CTL_REG(PCFGR_3),    // 72
	DDR_CTL_REG(PCFGR_4),    // 73
	DDR_CTL_REG(PCFGR_5),    // 74
	DDR_CTL_REG(PCFGR_6),    // 75
	DDR_CTL_REG(PCFGW_0),    // 76
	DDR_CTL_REG(PCFGW_1),    // 77
	DDR_CTL_REG(PCFGW_2),    // 78
	DDR_CTL_REG(PCFGW_3),    // 79
	DDR_CTL_REG(PCFGW_4),    // 80
	DDR_CTL_REG(PCFGW_5),    // 81
	DDR_CTL_REG(PCFGW_6),    // 82
	DDR_CTL_REG(SARBASE0),   // 83
	DDR_CTL_REG(SARSIZE0),   // 84

	// DDR PHY
	DDR_PHY_REG(DSGCR),      // 85
	DDR_PHY_REG(PGCR1),      // 86
	DDR_PHY_REG(PGCR2),      // 87
	DDR_PHY_REG(PTR0),       // 88
	DDR_PHY_REG(PTR1),       // 89
	DDR_PHY_REG(PTR2),       // 90
	DDR_PHY_REG(PTR3),       // 91
	DDR_PHY_REG(PTR4),       // 92
	DDR_PHY_REG(MR0),        // 93
	DDR_PHY_REG(MR1),        // 94
	DDR_PHY_REG(MR2),        // 95
	DDR_PHY_REG(MR3),        // 96
	DDR_PHY_REG(DTPR0),      // 97
	DDR_PHY_REG(DTPR1),      // 98
	DDR_PHY_REG(DTPR2),      // 99
	DDR_PHY_REG(ZQ0CR1),     // 100
	DDR_PHY_REG(DCR),        // 101
	DDR_PHY_REG(DTCR),       // 102
	DDR_PHY_REG(PLLCR),      // 103
	DDR_PHY_REG(PIR),        // 104

	DDR_CTL_REG(SWCTL_2),    // 105
	DDR_CTL_REG(PWRCTL_3),   // 106
	DDR_CTL_REG(SWCTL_3),    // 107

};


void ma35d0_ddr_setting(struct nvt_ddr_init_param ddrparam, int size)
{
	uint32_t i;
	uint64_t ddr_reg_address;
	uint32_t value;
	uint32_t u32TimeOut1 = 0, u32TimeOut2 = 0, u32TimeOut3 = 0;

	for(i = 0; i < size; i++)
	{
		ddr_reg_address = (uint32_t)nvt_ddr_init_setting[i].base + (uint32_t)nvt_ddr_init_setting[i].offset;
		value =  *((uint32_t *)(((uintptr_t)&ddrparam) + nvt_ddr_init_setting[i].init_flow_offset));

		*(volatile uint32_t *)(ddr_reg_address) = value;

		if (i == 84) // 0xf08 //DDRCTRL
		{
			//de-assert reset signals of DDR memory controller
			mmio_write_32(SYS_BA+0x20,(mmio_read_32(SYS_BA+0x20) & 0x8fffffff));
			while( (mmio_read_32(SYS_BA+0x20) & 0x20000000) != 0x00000000);
		}

		if (i == 100) // 0x184 //DDRPHY
		{
			//polling PGSR0 (addr=4) to 0x0000000f
			while((mmio_read_32(DDRPHY_BASE + 0x010) & 0x0000000f) != 0x0000000f)
			{
				u32TimeOut1++;
			}
		}

		if (i == 104) // 0x04  // DDRPHY
		{

			//polling PGSR0 (addr=4) to 0xb0000f5f
			while((mmio_read_32(DDRPHY_BASE + 0x010) & 0xffffff5f) != 0xb0000f5f)
			{
				u32TimeOut2++;
			}

			//polling MCTL2 STAT to 0x00000001
			while((mmio_read_32(UMCTL2_BASE + 0x004) & 0x00000003) != 0x00000001)
			{
				u32TimeOut3++;
			}
		}

	}

#if 1   /* 2023.04.21, Adjust DDR AXI port priority to give DCUltra the higest priority */
	mmio_write_32(UMCTL2_BA+0x328, 0x1);
	INFO("\n  >>>>> AXI Port Priority Finish: 0x%x, 0x%x, 0x%x, 0x%x \n", mmio_read_32(UMCTL2_BA + 0x564),mmio_read_32(UMCTL2_BA + 0x4b4), mmio_read_32(UMCTL2_BA + 0x614), mmio_read_32(UMCTL2_BA + 0x404));

	mmio_write_32(UMCTL2_BA+0x564, mmio_read_32(UMCTL2_BA + 0x564) | (0x1 << 5));
	mmio_write_32(UMCTL2_BA+0x568, mmio_read_32(UMCTL2_BA + 0x568) | (0x1 << 5));
	mmio_write_32(UMCTL2_BA+0x4b4, mmio_read_32(UMCTL2_BA + 0x4b4) | (0x8 << 5));
	mmio_write_32(UMCTL2_BA+0x4b8, mmio_read_32(UMCTL2_BA + 0x4b8) | (0x8 << 5));
	mmio_write_32(UMCTL2_BA+0x614, mmio_read_32(UMCTL2_BA + 0x614) | (0x10 << 5));
	mmio_write_32(UMCTL2_BA+0x618, mmio_read_32(UMCTL2_BA + 0x618) | (0x10 << 5));
	mmio_write_32(UMCTL2_BA+0x404, mmio_read_32(UMCTL2_BA + 0x404) | (0x1f << 5));
	mmio_write_32(UMCTL2_BA+0x408, mmio_read_32(UMCTL2_BA + 0x408) | (0x1f << 5));
	mmio_write_32(UMCTL2_BA+0x328, 0x0);
	while((mmio_read_32(UMCTL2_BA + 0x324) & 0x1) != 0x00000001);
	INFO("\n  >>>>> AXI Port Priority Finish: 0x%x, 0x%x, 0x%x, 0x%x \n", mmio_read_32(UMCTL2_BA + 0x564),mmio_read_32(UMCTL2_BA + 0x4b4), mmio_read_32(UMCTL2_BA + 0x614), mmio_read_32(UMCTL2_BA + 0x404));
#endif

	while((mmio_read_32(UMCTL2_BASE + 0x324) & 0x00000001) != 0x00000001);

	INFO("\n DDR init Finish: 0x%x, 0x%x, 0x%x \n", u32TimeOut1, u32TimeOut2, u32TimeOut3);

	//while(1);
}

static void *fdt = (void *)MA35D0_DTB_BASE;

void ma35d0_ddr_init(void)
{
	uint32_t  clk_sel0;

	clk_sel0 = mmio_read_32(CLK_BA + 0x18);

	/* set SYS_CLK0, DCUltra, and GFX clock from SYS_PLL, instead of EPLL */
	mmio_write_32(CLK_BA + 0x18, 0xd000015);

	//Set TAHBCKEN,CM4CKEN,CA35CKEN,DDR6CKEN,GFXCKEN,VC8KCKEN,DCUCKEN,GMAC0CKEN,GMAC1CKEN,CAP0CKEN,CAP1CKEN
	mmio_write_32(CLK_BA + 0x04, (mmio_read_32(CLK_BA + 0x04) | 0x7F000037));
	mmio_write_32(CLK_BA + 0x0C, (mmio_read_32(CLK_BA + 0x0C) | 0x40000000));

	/* DDR control register clock gating disable */
	mmio_write_32(SYS_BA + 0x70, (mmio_read_32(SYS_BA + 0x70) | 0x00800000));
	/* de-assert presetn of MCTL2 */
	mmio_write_32(SYS_BA + 0x20, (mmio_read_32(SYS_BA + 0x20) & 0xafffffff));
	while((mmio_read_32(SYS_BA + 0x20) & 0x50000000) != 0x00000000);
	//set MCTLCRST to 1
	mmio_write_32(SYS_BA + 0x20, (mmio_read_32(SYS_BA + 0x20) | 0x20000000));

	/* read DTB */
	/* get device tree information */
	if (fdt_check_header(fdt) < 0) {
		WARN("device tree header check error.\n");
	}

	if (fdt_node_offset_by_compatible(fdt, -1, "wb-ddr3-256mb") >= 0) {
		ma35d0_ddr_setting(ma35d0_wb_ddr3_256mb, sizeof(ma35d0_wb_ddr3_256mb)/sizeof(uint32_t));
	} else if (fdt_node_offset_by_compatible(fdt, -1, "custom-ddr") >= 0) {
		ma35d0_ddr_setting(custom_ddr, sizeof(custom_ddr)/sizeof(uint32_t));
	} else {
		WARN("The compatible property ddr type not found\n");
	}

	mmio_write_32(UMCTL2_BA+0x490, 0x1);
	mmio_write_32(UMCTL2_BA+0x8b0, 0x1);
	mmio_write_32(UMCTL2_BA+0x960, 0x1);

	mmio_write_32(UMCTL2_BA+0x540, 0x1);
	mmio_write_32(UMCTL2_BA+0x5f0, 0x1);
	mmio_write_32(UMCTL2_BA+0x6a0, 0x1);
	mmio_write_32(UMCTL2_BA+0x750, 0x1);
	mmio_write_32(UMCTL2_BA+0x800, 0x1);

	mmio_write_32(SYS_BA + 0x70,(mmio_read_32(SYS_BA + 0x70) & ~0x00800000));	/* DDR control register clock gating enable */
	mmio_write_32(CLK_BA + 0x04, 0x35);

	/* restore CLK_SEL0 */
	mmio_write_32(CLK_BA + 0x18, clk_sel0);
}

