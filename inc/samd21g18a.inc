SRAM_BASE                               EQU 0x20000000
PERIPH_BASE                             EQU 0x40000000
	
FLASH_SIZE                              EQU 0x40000
FLASH_PAGE_SIZE                         EQU 64
FLASH_NB_OF_PAGES                       EQU 4096
FLASH_USER_PAGE_SIZE                    EQU 64
HMCRAMC0_SIZE                           EQU 0x8000
FLASH_ADDR                              EQU 0x00000000
FLASH_USER_PAGE_ADDR                    EQU 0x00800000
HMCRAMC0_ADDR                           EQU 0x20000000

DSU_DID_RESETVALUE                      EQU 0x10010005
EIC_EXTINT_NUM                          EQU 16
PORT_GROUPS                             EQU 2

BIT_POS_0                               EQU 0x00000001
BIT_POS_1                               EQU 0x00000002
BIT_POS_2                               EQU 0x00000004
BIT_POS_3                               EQU 0x00000008
BIT_POS_4                               EQU 0x00000010
BIT_POS_5                               EQU 0x00000020
BIT_POS_6                               EQU 0x00000040
BIT_POS_7                               EQU 0x00000080
BIT_POS_8                               EQU 0x00000100
BIT_POS_9                               EQU 0x00000200
BIT_POS_10                              EQU 0x00000400
BIT_POS_11                              EQU 0x00000800
BIT_POS_12                              EQU 0x00001000
BIT_POS_13                              EQU 0x00002000
BIT_POS_14                              EQU 0x00004000
BIT_POS_15                              EQU 0x00008000
BIT_POS_16                              EQU 0x00010000
BIT_POS_17                              EQU 0x00020000
BIT_POS_18                              EQU 0x00040000
BIT_POS_19                              EQU 0x00080000
BIT_POS_20                              EQU 0x00100000
BIT_POS_21                              EQU 0x00200000
BIT_POS_22                              EQU 0x00400000
BIT_POS_23                              EQU 0x00800000
BIT_POS_24                              EQU 0x01000000
BIT_POS_25                              EQU 0x02000000
BIT_POS_26                              EQU 0x04000000
BIT_POS_27                              EQU 0x08000000
BIT_POS_28                              EQU 0x10000000
BIT_POS_29                              EQU 0x20000000
BIT_POS_30                              EQU 0x40000000
BIT_POS_31                              EQU 0x80000000





; Flags
FLAG_N                                  EQU 0x80000000
FLAG_Z                                  EQU 0x40000000
FLAG_C                                  EQU 0x20000000
FLAG_V                                  EQU 0x10000000


	



AC                                      EQU 0x42004400
ADC                                     EQU 0x42004000
DAC                                     EQU 0x42004800
DMAC                                    EQU 0x41004800
DSU                                     EQU 0x41002000
EIC                                     EQU 0x40001800
EVSYS                                   EQU 0x42000400
GCLK                                    EQU 0x40000C00
SBMATRIX                                EQU 0x41007000
I2S                                     EQU 0x42005000
MTB                                     EQU 0x41006000
NVMCTRL                                 EQU 0x41004000
NVMCTRL_CAL                             EQU 0x00800000
NVMCTRL_LOCKBIT                         EQU 0x00802000
NVMCTRL_OTP1                            EQU 0x00806000
NVMCTRL_OTP2                            EQU 0x00806008
NVMCTRL_OTP4                            EQU 0x00806020
NVMCTRL_TEMP_LOG                        EQU 0x00806030
NVMCTRL_USER                            EQU 0x00804000
PAC0                                    EQU 0x40000000
PAC1                                    EQU 0x41000000
PAC2                                    EQU 0x42000000
PM                                      EQU 0x40000400
PORT                                    EQU 0x41004400
PORT_IOBUS                              EQU 0x60000000
RTC                                     EQU 0x40001400
SERCOM                                  EQU 0x42000800
SERCOM0                                 EQU 0x42000800
SERCOM1                                 EQU 0x42000C00
SERCOM2                                 EQU 0x42001000
SERCOM3                                 EQU 0x42001400
SERCOM4                                 EQU 0x42001800
SERCOM5                                 EQU 0x42001C00
SYSCTRL                                 EQU 0x40000800
TC3                                     EQU 0x42002C00
TC4                                     EQU 0x42003000
TC5                                     EQU 0x42003400
TCC0                                    EQU 0x42002000
TCC1                                    EQU 0x42002400
TCC2                                    EQU 0x42002800
USB                                     EQU 0x41005000
WDT                                     EQU 0x40001000



JACKSON_5                               EQU 0x00




SYST_CSR                                EQU 0xe000e010

SYST_RVR_offset                         EQU 0x04
SYST_CVR_offset                         EQU 0x08
SYST_CALIB_offset                       EQU 0x0c

SYST_RVR                                EQU SYST_CSR + SYST_RVR_offset
SYST_CVR                                EQU SYST_CSR + SYST_CVR_offset
SYST_CALIB                              EQU SYST_CSR + SYST_CALIB_offset

SYST_CSR_ENABLE                         EQU BIT_POS_0
SYST_CSR_TICKINT                        EQU BIT_POS_1
SYST_CSR_CLOCKSOURCE                    EQU BIT_POS_2
SYST_CSR_COUNTFLAG                      EQU BIT_POS_16

SYST_RVR_RELOAD                         EQU SYST_RVR

SYST_CVR_CURRENT                        EQU SYST_CVR

SYST_CALIB_TENMS                        EQU SYST_CALIB
SYST_CALIB_SKEW                         EQU 0x40000000
SYST_CALIB_NOREF                        EQU 0x10000000








NVICISER                                EQU 0xe000e100
NVICISER_SETENA                         EQU NVICISER
NVICICER                                EQU 0xe000e180
NVICICER_CLRENA                         EQU NVICICER
NVICISPR                                EQU 0xe000e200
NVICISPR_SETPEND                        EQU NVICISPR
NVICICPR                                EQU 0xe000e280
NVICICPR_CLRPEND                        EQU NVICICPR

NVICIPR                                 EQU 0xe000e400
NVICIPR0_offset                         EQU 0x00
NVICIPR1_offset                         EQU 0x04
NVICIPR2_offset                         EQU 0x08
NVICIPR3_offset                         EQU 0x0c
NVICIPR4_offset                         EQU 0x10
NVICIPR5_offset                         EQU 0x14
NVICIPR6_offset                         EQU 0x18
NVICIPR7_offset                         EQU 0x1c

NVICIPR0                                EQU NVICIPR + NVICIPR0_offset
NVICIPR1                                EQU NVICIPR + NVICIPR1_offset
NVICIPR2                                EQU NVICIPR + NVICIPR2_offset
NVICIPR3                                EQU NVICIPR + NVICIPR3_offset
NVICIPR4                                EQU NVICIPR + NVICIPR4_offset
NVICIPR5                                EQU NVICIPR + NVICIPR5_offset
NVICIPR6                                EQU NVICIPR + NVICIPR6_offset
NVICIPR7                                EQU NVICIPR + NVICIPR7_offset

NVIC_PRI0_Pos                           EQU 0
NVIC_PRI1_Pos                           EQU 8
NVIC_PRI2_Pos                           EQU 16
NVIC_PRI3_Pos                           EQU 24
NVIC_PRI_Mask                           EQU 0xc0









PORT_offset                             EQU 0x80
PORT0                                   EQU PORT
PORT1                                   EQU PORT0 + PORT_offset

PORT_DIR_offset                         EQU 0x00
PORT_DIRCLR_offset                      EQU 0x04
PORT_DIRSET_offset                      EQU 0x08
PORT_DIRTGL_offset                      EQU 0x0c
PORT_OUT_offset                         EQU 0x10
PORT_OUTCLR_offset                      EQU 0x14
PORT_OUTSET_offset                      EQU 0x18
PORT_OUTTGL_offset                      EQU 0x1c
PORT_IN_offset                          EQU 0x20
PORT_CTRL_offset                        EQU 0x24
PORT_WRCONFIG_offset                    EQU 0x28
PORT_PMUX_offset                        EQU 0x30
PORT_PINCFG_offset                      EQU 0x40

PORT0_DIR                               EQU PORT0 + PORT_DIR_offset
PORT0_DIRCLR                            EQU PORT0 + PORT_DIRCLR_offset
PORT0_DIRSET                            EQU PORT0 + PORT_DIRSET_offset
PORT0_DIRTGL                            EQU PORT0 + PORT_DIRTGL_offset
PORT0_OUT                               EQU PORT0 + PORT_OUT_offset
PORT0_OUTCLR                            EQU PORT0 + PORT_OUTCLR_offset
PORT0_OUTSET                            EQU PORT0 + PORT_OUTSET_offset
PORT0_OUTTGL                            EQU PORT0 + PORT_OUTTGL_offset
PORT0_IN                                EQU PORT0 + PORT_IN_offset
PORT0_CTRL                              EQU PORT0 + PORT_CTRL_offset
PORT0_WRCONFIG                          EQU PORT0 + PORT_WRCONFIG_offset
PORT0_PMUX                              EQU PORT0 + PORT_PMUX_offset
PORT0_PINCFG                            EQU PORT0 + PORT_PINCFG_offset

PORT1_DIR                               EQU PORT1 + PORT_DIR_offset
PORT1_DIRCLR                            EQU PORT1 + PORT_DIRCLR_offset
PORT1_DIRSET                            EQU PORT1 + PORT_DIRSET_offset
PORT1_DIRTGL                            EQU PORT1 + PORT_DIRTGL_offset
PORT1_OUT                               EQU PORT1 + PORT_OUT_offset
PORT1_OUTCLR                            EQU PORT1 + PORT_OUTCLR_offset
PORT1_OUTSET                            EQU PORT1 + PORT_OUTSET_offset
PORT1_OUTTGL                            EQU PORT1 + PORT_OUTTGL_offset
PORT1_IN                                EQU PORT1 + PORT_IN_offset
PORT1_CTRL                              EQU PORT1 + PORT_CTRL_offset
PORT1_WRCONFIG                          EQU PORT1 + PORT_WRCONFIG_offset
PORT1_PMUX                              EQU PORT1 + PORT_PMUX_offset
PORT1_PINCFG                            EQU PORT1 + PORT_PINCFG_offset


PORT_PMUX_PMUXE_A                       EQU 0x00
PORT_PMUX_PMUXE_B                       EQU 0x01
PORT_PMUX_PMUXE_C                       EQU 0x02
PORT_PMUX_PMUXE_D                       EQU 0x03
PORT_PMUX_PMUXE_E                       EQU 0x04
PORT_PMUX_PMUXE_F                       EQU 0x05
PORT_PMUX_PMUXE_G                       EQU 0x06
PORT_PMUX_PMUXE_H                       EQU 0x07
PORT_PMUX_PMUXE_I                       EQU 0x08

PORT_PMUX_PMUXO_A                       EQU 0x00
PORT_PMUX_PMUXO_B                       EQU 0x10
PORT_PMUX_PMUXO_C                       EQU 0x20
PORT_PMUX_PMUXO_D                       EQU 0x30
PORT_PMUX_PMUXO_E                       EQU 0x40
PORT_PMUX_PMUXO_F                       EQU 0x50
PORT_PMUX_PMUXO_G                       EQU 0x60
PORT_PMUX_PMUXO_H                       EQU 0x70
PORT_PMUX_PMUXO_I                       EQU 0x80

PORT_PMUX_PMUX_A                        EQU 0x0
PORT_PMUX_PMUX_B                        EQU 0x1
PORT_PMUX_PMUX_C                        EQU 0x2
PORT_PMUX_PMUX_D                        EQU 0x3
PORT_PMUX_PMUX_E                        EQU 0x4
PORT_PMUX_PMUX_F                        EQU 0x5
PORT_PMUX_PMUX_G                        EQU 0x6
PORT_PMUX_PMUX_H                        EQU 0x7
PORT_PMUX_PMUX_I                        EQU 0x8

PORT_PINCFG_PMUXEN                      EQU 0x01
PORT_PINCFG_INEN                        EQU 0x02
PORT_PINCFG_PULLEN                      EQU 0x04
PORT_PINCFG_DRVSTR                      EQU 0x40

PORT_WRCONFIG_PINMASK                   EQU 0x0000
PORT_WRCONFIG_PMUXEN                    EQU 0x00010000
PORT_WRCONFIG_INEN                      EQU 0x00020000
PORT_WRCONFIG_PULLEN                    EQU 0x00040000
PORT_WRCONFIG_DRVSTR                    EQU 0x00400000
;PORT_WRCONFIG_PMUX                      EQU 0x0000
PORT_WRCONFIG_PMUX_Pos                  EQU 24
PORT_WRCONFIG_WRPMUX                    EQU 0x10000000
PORT_WRCONFIG_WRPINCFG                  EQU 0x40000000
PORT_WRCONFIG_HWSEL                     EQU 0x80000000









GCLK_CTRL_offset                        EQU 0x00
GCLK_STATUS_offset                      EQU 0x01
GCLK_CLKCTRL_offset                     EQU 0x02
GCLK_GENCTRL_offset                     EQU 0x04
GCLK_GENDIV_offset                      EQU 0x08

GCLK_CTRL                               EQU GCLK + GCLK_CTRL_offset
GCLK_STATUS                             EQU GCLK + GCLK_STATUS_offset
GCLK_CLKCTRL                            EQU GCLK + GCLK_CLKCTRL_offset
GCLK_GENCTRL                            EQU GCLK + GCLK_GENCTRL_offset
GCLK_GENDIV                             EQU GCLK + GCLK_GENDIV_offset
	
GCLK_CTRL_SWRST                         EQU BIT_POS_0
	
GCLK_STATUS_SYNCBUSY                    EQU BIT_POS_7
GCLK_STATUS_SYNCBUSY_Pos                EQU 7

GCLK_CLKCTRL_ID_DFLL48                  EQU 0x00
GCLK_CLKCTRL_ID_FDPLL                   EQU 0x01
GCLK_CLKCTRL_ID_FDPLL32K                EQU 0x02
GCLK_CLKCTRL_ID_WDT                     EQU 0x03
GCLK_CLKCTRL_ID_RTC                     EQU 0x04
GCLK_CLKCTRL_ID_EIC                     EQU 0x05
GCLK_CLKCTRL_ID_USB                     EQU 0x06
GCLK_CLKCTRL_ID_EVSYS_0                 EQU 0x07
GCLK_CLKCTRL_ID_EVSYS_1                 EQU 0x08
GCLK_CLKCTRL_ID_EVSYS_2                 EQU 0x09
GCLK_CLKCTRL_ID_EVSYS_3                 EQU 0x0a
GCLK_CLKCTRL_ID_EVSYS_4                 EQU 0x0b
GCLK_CLKCTRL_ID_EVSYS_5                 EQU 0x0c
GCLK_CLKCTRL_ID_EVSYS_6                 EQU 0x0d
GCLK_CLKCTRL_ID_EVSYS_7                 EQU 0x0e
GCLK_CLKCTRL_ID_EVSYS_8                 EQU 0x0f
GCLK_CLKCTRL_ID_EVSYS_9                 EQU 0x10
GCLK_CLKCTRL_ID_EVSYS_10                EQU 0x11
GCLK_CLKCTRL_ID_EVSYS_11                EQU 0x12
GCLK_CLKCTRL_ID_SERCOMX_SLOW            EQU 0x13
GCLK_CLKCTRL_ID_SERCOM0_CORE            EQU 0x14
GCLK_CLKCTRL_ID_SERCOM1_CORE            EQU 0x15
GCLK_CLKCTRL_ID_SERCOM2_CORE            EQU 0x16
GCLK_CLKCTRL_ID_SERCOM3_CORE            EQU 0x17
GCLK_CLKCTRL_ID_SERCOM4_CORE            EQU 0x18
GCLK_CLKCTRL_ID_SERCOM5_CORE            EQU 0x19
GCLK_CLKCTRL_ID_TCC0_TCC1               EQU 0x1a
GCLK_CLKCTRL_ID_TCC2_TC3                EQU 0x1b
GCLK_CLKCTRL_ID_TC4_TC5                 EQU 0x1c
GCLK_CLKCTRL_ID_TC6_TC7                 EQU 0x1d
GCLK_CLKCTRL_ID_ADC                     EQU 0x1e
GCLK_CLKCTRL_ID_AC_DIG                  EQU 0x1f
GCLK_CLKCTRL_ID_AC_ANA                  EQU 0x20
GCLK_CLKCTRL_ID_DAC                     EQU 0x21
GCLK_CLKCTRL_ID_PTC                     EQU 0x22
GCLK_CLKCTRL_ID_I2S_0                   EQU 0x23
GCLK_CLKCTRL_ID_I2S_1                   EQU 0x24

GCLK_CLKCTRL_GEN_GCLK0                  EQU 0x0000
GCLK_CLKCTRL_GEN_GCLK1                  EQU 0x0100
GCLK_CLKCTRL_GEN_GCLK2                  EQU 0x0200
GCLK_CLKCTRL_GEN_GCLK3                  EQU 0x0300
GCLK_CLKCTRL_GEN_GCLK4                  EQU 0x0400
GCLK_CLKCTRL_GEN_GCLK5                  EQU 0x0500
GCLK_CLKCTRL_GEN_GCLK6                  EQU 0x0600
GCLK_CLKCTRL_GEN_GCLK7                  EQU 0x0700

GCLK_CLKCTRL_CLKEN                      EQU BIT_POS_14
GCLK_CLKCTRL_WRTLOCK                    EQU BIT_POS_15
	
GCLK_GENCTRL_ID                         EQU 0x00
GCLK_GENCTRL_ID_Pos                     EQU 0
GCLK_GENCTRL_SRC_XOSC                   EQU 0x0000
GCLK_GENCTRL_SRC_GCLKIN                 EQU 0x0100
GCLK_GENCTRL_SRC_GCLKGEN1               EQU 0x0200
GCLK_GENCTRL_SRC_OSCULP32K              EQU 0x0300
GCLK_GENCTRL_SRC_OSC32K                 EQU 0x0400
GCLK_GENCTRL_SRC_XOSC32K                EQU 0x0500
GCLK_GENCTRL_SRC_OSC8M                  EQU 0x0600
GCLK_GENCTRL_SRC_DFLL48M                EQU 0x0700
GCLK_GENCTRL_SRC_FDPLL                  EQU 0x0800
GCLK_GENCTRL_GENEN                      EQU BIT_POS_16
GCLK_GENCTRL_IDC                        EQU BIT_POS_17
GCLK_GENCTRL_OOV                        EQU BIT_POS_18
GCLK_GENCTRL_OE                         EQU BIT_POS_19
GCLK_GENCTRL_DIVSEL                     EQU BIT_POS_20
GCLK_GENCTRL_RUNSTDBY                   EQU BIT_POS_21

GCLK_GENDIV_ID                          EQU	0x0
GCLK_GENDIV_ID_Pos                      EQU 0
GCLK_GENDIV_DIV                         EQU 0x00
GCLK_GENDIV_DIV_Pos                     EQU	8
	









PM_CTRL_offset                          EQU 0x00
PM_SLEEP_offsef                         EQU 0x01
PM_CPUSEL_offsef                        EQU 0x08
PM_APBASEL_offsef                       EQU 0x09
PM_APBBSEL_offsef                       EQU 0x0a
PM_APBCSEL_offsef                       EQU 0x0b
PM_AHBMASK_offset                       EQU 0x14
PM_APBAMASK_offsef                      EQU 0x18
PM_APBBMASK_offsef                      EQU 0x1c
PM_APBCMASK_offsef                      EQU 0x20
PM_INTENCLR_offsef                      EQU 0x34
PM_INTENSET_offsef                      EQU 0x35
PM_INTFLAG_offsef                       EQU 0x36
PM_RCAUSE_offsef                        EQU 0x38
	
PM_CTRL                                 EQU PM + PM_CTRL_offset
PM_SLEEP                                EQU PM + PM_SLEEP_offsef
PM_CPUSEL                               EQU PM + PM_CPUSEL_offsef
PM_APBASEL                              EQU PM + PM_APBASEL_offsef
PM_APBBSEL                              EQU PM + PM_APBBSEL_offsef
PM_APBCSEL                              EQU PM + PM_APBCSEL_offsef
PM_AHBMASK                              EQU PM + PM_AHBMASK_offset
PM_APBAMASK                             EQU PM + PM_APBAMASK_offsef
PM_APBBMASK                             EQU PM + PM_APBBMASK_offsef
PM_APBCMASK                             EQU PM + PM_APBCMASK_offsef
PM_INTENCLR                             EQU PM + PM_INTENCLR_offsef
PM_INTENSET                             EQU PM + PM_INTENSET_offsef
PM_INTFLAG                              EQU PM + PM_INTFLAG_offsef
PM_RCAUSE                               EQU PM + PM_RCAUSE_offsef


PM_SLEEP_IDLE_CPU                       EQU BIT_POS_0
PM_SLEEP_IDLE_AHB                       EQU BIT_POS_1
PM_SLEEP_IDLE_APB                       EQU BIT_POS_2

PM_CPUSEL_CPUDIV_DIV1                   EQU BIT_POS_0
PM_CPUSEL_CPUDIV_DIV2                   EQU BIT_POS_1
PM_CPUSEL_CPUDIV_DIV4                   EQU BIT_POS_2
PM_CPUSEL_CPUDIV_DIV8                   EQU BIT_POS_3
PM_CPUSEL_CPUDIV_DIV16                  EQU BIT_POS_4
PM_CPUSEL_CPUDIV_DIV32                  EQU BIT_POS_5
PM_CPUSEL_CPUDIV_DIV64                  EQU BIT_POS_6
PM_CPUSEL_CPUDIV_DIV128                 EQU BIT_POS_7

PM_APBASEL_APBADIV_DIV1                 EQU BIT_POS_0
PM_APBASEL_APBADIV_DIV2                 EQU BIT_POS_1
PM_APBASEL_APBADIV_DIV4                 EQU BIT_POS_2
PM_APBASEL_APBADIV_DIV8                 EQU BIT_POS_3
PM_APBASEL_APBADIV_DIV16                EQU BIT_POS_4
PM_APBASEL_APBADIV_DIV32                EQU BIT_POS_5
PM_APBASEL_APBADIV_DIV64                EQU BIT_POS_6
PM_APBASEL_APBADIV_DIV128               EQU BIT_POS_7

PM_APBBSEL_APBADIV_DIV1                 EQU BIT_POS_0
PM_APBBSEL_APBADIV_DIV2                 EQU BIT_POS_1
PM_APBBSEL_APBADIV_DIV4                 EQU BIT_POS_2
PM_APBBSEL_APBADIV_DIV8                 EQU BIT_POS_3
PM_APBBSEL_APBADIV_DIV16                EQU BIT_POS_4
PM_APBBSEL_APBADIV_DIV32                EQU BIT_POS_5
PM_APBBSEL_APBADIV_DIV64                EQU BIT_POS_6
PM_APBBSEL_APBADIV_DIV128               EQU BIT_POS_7

PM_APBCSEL_APBADIV_DIV1                 EQU BIT_POS_0
PM_APBCSEL_APBADIV_DIV2                 EQU BIT_POS_1
PM_APBCSEL_APBADIV_DIV4                 EQU BIT_POS_2
PM_APBCSEL_APBADIV_DIV8                 EQU BIT_POS_3
PM_APBCSEL_APBADIV_DIV16                EQU BIT_POS_4
PM_APBCSEL_APBADIV_DIV32                EQU BIT_POS_5
PM_APBCSEL_APBADIV_DIV64                EQU BIT_POS_6
PM_APBCSEL_APBADIV_DIV128               EQU BIT_POS_7

PM_AHBMASK_HPB0                         EQU BIT_POS_0
PM_AHBMASK_HPB1                         EQU BIT_POS_1
PM_AHBMASK_HPB2                         EQU BIT_POS_2
PM_AHBMASK_DSU                          EQU BIT_POS_3
PM_AHBMASK_NVMCTRL                      EQU BIT_POS_4
PM_AHBMASK_DMAC                         EQU BIT_POS_5
PM_AHBMASK_USB                          EQU BIT_POS_6
	
PM_APBAMASK_PAC0                        EQU BIT_POS_0
PM_APBAMASK_PM                          EQU BIT_POS_1
PM_APBAMASK_SYSCTRL                     EQU BIT_POS_2
PM_APBAMASK_GCLK                        EQU BIT_POS_3
PM_APBAMASK_WDT                         EQU BIT_POS_4
PM_APBAMASK_RTC                         EQU BIT_POS_5
PM_APBAMASK_EIC                         EQU BIT_POS_6

PM_APBBMASK_PAC1                        EQU BIT_POS_0
PM_APBBMASK_DSU                         EQU BIT_POS_1
PM_APBBMASK_NVMCTRL                     EQU BIT_POS_2
PM_APBBMASK_PORT                        EQU BIT_POS_3
PM_APBBMASK_DMAC                        EQU BIT_POS_4
PM_APBBMASK_USB                         EQU BIT_POS_5
PM_APBBMASK_HMATRIX                     EQU BIT_POS_6

PM_APBCMASK_PAC2                        EQU BIT_POS_0
PM_APBCMASK_EVSYS                       EQU BIT_POS_1
PM_APBCMASK_SERCOM0                     EQU BIT_POS_2
PM_APBCMASK_SERCOM1                     EQU BIT_POS_3
PM_APBCMASK_SERCOM2                     EQU BIT_POS_4
PM_APBCMASK_SERCOM3                     EQU BIT_POS_5
PM_APBCMASK_SERCOM4                     EQU BIT_POS_6
PM_APBCMASK_SERCOM5                     EQU BIT_POS_7
PM_APBCMASK_TCC0                        EQU BIT_POS_8
PM_APBCMASK_TCC1                        EQU BIT_POS_9
PM_APBCMASK_TCC2                        EQU BIT_POS_10
PM_APBCMASK_TC3                         EQU BIT_POS_11
PM_APBCMASK_TC4                         EQU BIT_POS_12
PM_APBCMASK_TC5                         EQU BIT_POS_13
PM_APBCMASK_ADC                         EQU BIT_POS_16
PM_APBCMASK_AC                          EQU BIT_POS_17
PM_APBCMASK_DAC                         EQU BIT_POS_18
PM_APBCMASK_PTC                         EQU BIT_POS_19
PM_APBCMASK_I2S                         EQU BIT_POS_20

PM_INTENCLR_CKRDY                       EQU BIT_POS_0

PM_INTENSET_CKRDY                       EQU BIT_POS_0

PM_INTENFLAG_CKRDY                      EQU BIT_POS_0

PM_RCAUSE_POR                           EQU BIT_POS_0
PM_RCAUSE_BOD12                         EQU BIT_POS_1
PM_RCAUSE_BOD33                         EQU BIT_POS_2
PM_RCAUSE_EXT                           EQU BIT_POS_4
PM_RCAUSE_WDT                           EQU BIT_POS_5
PM_RCAUSE_SYST                          EQU BIT_POS_6










TC_CTRLA_offset                         EQU 0x00
TC_READREQ_offset                       EQU 0x02
TC_CTRLBCLR_offset                      EQU 0x04
TC_CTRLBSET_offset                      EQU 0x05
TC_CTRLC_offset                         EQU 0x06
TC_DBGCTRL_offset                       EQU 0x08
TC_EVCTRL_offset                        EQU 0x0a
TC_INTENCLR_offset                      EQU 0x0c
TC_INTENSET_offset                      EQU 0x0d
TC_INTFLAG_offset                       EQU 0x0e
TC_STATUS_offset                        EQU 0x0f
TC_COUNT16_COUNT_offset                 EQU 0x10
TC_COUNT16_CC0_offset                   EQU 0x18
TC_COUNT16_CC1_offset                   EQU 0x1a
TC_COUNT32_COUNT_offset                 EQU 0x10
TC_COUNT32_CC0_offset                   EQU 0x18
TC_COUNT32_CC1_offset                   EQU 0x1c
TC_COUNT8_COUNT_offset                  EQU 0x10
TC_COUNT8_PER_offset                    EQU 0x14
TC_COUNT8_CC0_offset                    EQU 0x18
TC_COUNT8_CC1_offset                    EQU 0x19

TC3_CTRLA                               EQU TC3 + TC_CTRLA_offset
TC3_READREQ                             EQU TC3 + TC_READREQ_offset
TC3_CTRLBCLR                            EQU TC3 + TC_CTRLBCLR_offset
TC3_CTRLBSET                            EQU TC3 + TC_CTRLBSET_offset
TC3_CTRLC                               EQU TC3 + TC_CTRLC_offset
TC3_DBGCTRL                             EQU TC3 + TC_DBGCTRL_offset
TC3_EVCTRL                              EQU TC3 + TC_EVCTRL_offset
TC3_INTENCLR                            EQU TC3 + TC_INTENCLR_offset
TC3_INTENSET                            EQU TC3 + TC_INTENSET_offset
TC3_INTFLAG                             EQU TC3 + TC_INTFLAG_offset
TC3_STATUS                              EQU TC3 + TC_STATUS_offset
TC3_COUNT16_COUNT                       EQU TC3 + TC_COUNT16_COUNT_offset
TC3_COUNT16_CC0                         EQU TC3 + TC_COUNT16_CC0_offset
TC3_COUNT16_CC1                         EQU TC3 + TC_COUNT16_CC1_offset
TC3_COUNT32_COUNT                       EQU TC3 + TC_COUNT32_COUNT_offset
TC3_COUNT32_CC0                         EQU TC3 + TC_COUNT32_CC0_offset
TC3_COUNT32_CC1                         EQU TC3 + TC_COUNT32_CC1_offset
TC3_COUNT8_COUNT                        EQU TC3 + TC_COUNT8_COUNT_offset
TC3_COUNT8_PER                          EQU TC3 + TC_COUNT8_PER_offset
TC3_COUNT8_CC0                          EQU TC3 + TC_COUNT8_CC0_offset
TC3_COUNT8_CC1                          EQU TC3 + TC_COUNT8_CC1_offset

TC4_CTRLA                               EQU TC4 + TC_CTRLA_offset
TC4_READREQ                             EQU TC4 + TC_READREQ_offset
TC4_CTRLBCLR                            EQU TC4 + TC_CTRLBCLR_offset
TC4_CTRLBSET                            EQU TC4 + TC_CTRLBSET_offset
TC4_CTRLC                               EQU TC4 + TC_CTRLC_offset
TC4_DBGCTRL                             EQU TC4 + TC_DBGCTRL_offset
TC4_EVCTRL                              EQU TC4 + TC_EVCTRL_offset
TC4_INTENCLR                            EQU TC4 + TC_INTENCLR_offset
TC4_INTENSET                            EQU TC4 + TC_INTENSET_offset
TC4_INTFLAG                             EQU TC4 + TC_INTFLAG_offset
TC4_STATUS                              EQU TC4 + TC_STATUS_offset
TC4_COUNT16_COUNT                       EQU TC4 + TC_COUNT16_COUNT_offset
TC4_COUNT16_CC0                         EQU TC4 + TC_COUNT16_CC0_offset
TC4_COUNT16_CC1                         EQU TC4 + TC_COUNT16_CC1_offset
TC4_COUNT32_COUNT                       EQU TC4 + TC_COUNT32_COUNT_offset
TC4_COUNT32_CC0                         EQU TC4 + TC_COUNT32_CC0_offset
TC4_COUNT32_CC1                         EQU TC4 + TC_COUNT32_CC1_offset
TC4_COUNT8_COUNT                        EQU TC4 + TC_COUNT8_COUNT_offset
TC4_COUNT8_PER                          EQU TC4 + TC_COUNT8_PER_offset
TC4_COUNT8_CC0                          EQU TC4 + TC_COUNT8_CC0_offset
TC4_COUNT8_CC1                          EQU TC4 + TC_COUNT8_CC1_offset

TC5_CTRLA                               EQU TC5 + TC_CTRLA_offset
TC5_READREQ                             EQU TC5 + TC_READREQ_offset
TC5_CTRLBCLR                            EQU TC5 + TC_CTRLBCLR_offset
TC5_CTRLBSET                            EQU TC5 + TC_CTRLBSET_offset
TC5_CTRLC                               EQU TC5 + TC_CTRLC_offset
TC5_DBGCTRL                             EQU TC5 + TC_DBGCTRL_offset
TC5_EVCTRL                              EQU TC5 + TC_EVCTRL_offset
TC5_INTENCLR                            EQU TC5 + TC_INTENCLR_offset
TC5_INTENSET                            EQU TC5 + TC_INTENSET_offset
TC5_INTFLAG                             EQU TC5 + TC_INTFLAG_offset
TC5_STATUS                              EQU TC5 + TC_STATUS_offset
TC5_COUNT16_COUNT                       EQU TC5 + TC_COUNT16_COUNT_offset
TC5_COUNT16_CC0                         EQU TC5 + TC_COUNT16_CC0_offset
TC5_COUNT16_CC1                         EQU TC5 + TC_COUNT16_CC1_offset
TC5_COUNT32_COUNT                       EQU TC5 + TC_COUNT32_COUNT_offset
TC5_COUNT32_CC0                         EQU TC5 + TC_COUNT32_CC0_offset
TC5_COUNT32_CC1                         EQU TC5 + TC_COUNT32_CC1_offset
TC5_COUNT8_COUNT                        EQU TC5 + TC_COUNT8_COUNT_offset
TC5_COUNT8_PER                          EQU TC5 + TC_COUNT8_PER_offset
TC5_COUNT8_CC0                          EQU TC5 + TC_COUNT8_CC0_offset
TC5_COUNT8_CC1                          EQU TC5 + TC_COUNT8_CC1_offset

TC_CTRLA_SWRST                          EQU BIT_POS_0
TC_CTRLA_ENABLE                         EQU BIT_POS_1
TC_CTRLA_MODE_COUNT16                   EQU 0x00
TC_CTRLA_MODE_COUNT8                    EQU 0x04
TC_CTRLA_MODE_COUNT32                   EQU 0x08
TC_CTRLA_WAVEGEN_NFRQ                   EQU 0x00
TC_CTRLA_WAVEGEN_MFRQ                   EQU 0x20
TC_CTRLA_WAVEGEN_NPWM                   EQU 0x40
TC_CTRLA_WAVEGEN_MPWM                   EQU 0x60
TC_CTRLA_PRESCALER_DIV1                 EQU 0x0000
TC_CTRLA_PRESCALER_DIV2                 EQU 0x0100
TC_CTRLA_PRESCALER_DIV4                 EQU 0x0200
TC_CTRLA_PRESCALER_DIV8                 EQU 0x0300
TC_CTRLA_PRESCALER_DIV16                EQU 0x0400
TC_CTRLA_PRESCALER_DIV64                EQU 0x0500
TC_CTRLA_PRESCALER_DIV256               EQU 0x0600
TC_CTRLA_PRESCALER_DIV1024              EQU 0x0700
TC_CTRLA_RUNSTDBY                       EQU BIT_POS_11
TC_CTRLA_PRESCSYNC_GCLK                 EQU 0x0000
TC_CTRLA_PRESCSYNC_PRESC                EQU 0x1000
TC_CTRLA_PRESCSYNC_RESYNC               EQU 0x2000

TC_READREQ_ADDR                         EQU 0x0
TC_READREQ_RCONT                        EQU BIT_POS_14
TC_READREQ_RREQ                         EQU BIT_POS_15

TC_CTRLBCLR_DIR                         EQU BIT_POS_0
TC_CTRLBCLR_ONESHOT                     EQU BIT_POS_2
TC_CTRLBCLR_CMD_NONE                    EQU 0x00
TC_CTRLBCLR_CMD_RETRIGGER               EQU 0x40
TC_CTRLBCLR_CMD_STOP                    EQU 0x80

TC_CTRLBSET_DIR                         EQU BIT_POS_0
TC_CTRLBSET_ONESHOT                     EQU BIT_POS_2
TC_CTRLBSET_CMD_NONE                    EQU 0x00
TC_CTRLBSET_CMD_RETRIGGER               EQU 0x40
TC_CTRLBSET_CMD_STOP                    EQU 0x80

TC_CTRLC_INVEN0                         EQU BIT_POS_0
TC_CTRLC_INVEN1                         EQU BIT_POS_1
TC_CTRLC_CPTEN0                         EQU BIT_POS_4
TC_CTRLC_CPTEN1                         EQU BIT_POS_5

TC_DBGCTRL_DBGRUN                       EQU BIT_POS_0

TC_EVCTRL_EVACT_OFF                     EQU 0x0
TC_EVCTRL_EVACT_RETRIGGER               EQU 0x1
TC_EVCTRL_EVACT_COUNT                   EQU 0x2
TC_EVCTRL_EVACT_START                   EQU 0x3
TC_EVCTRL_EVACT_PPW                     EQU 0x5
TC_EVCTRL_EVACT_PWP                     EQU 0x6
TC_EVCTRL_TCINV                         EQU BIT_POS_4
TC_EVCTRL_TCEI                          EQU BIT_POS_5
TC_EVCTRL_OVFEO                         EQU BIT_POS_8
TC_EVCTRL_MCEO0                         EQU BIT_POS_12
TC_EVCTRL_MCEO1                         EQU BIT_POS_13

TC_INTENCLR_OVF                         EQU BIT_POS_0
TC_INTENCLR_ERR                         EQU BIT_POS_1
TC_INTENCLR_SYNCRDY                     EQU BIT_POS_3
TC_INTENCLR_MC0                         EQU BIT_POS_4
TC_INTENCLR_MC1                         EQU BIT_POS_5

TC_INTENSET_OVF                         EQU BIT_POS_0
TC_INTENSET_ERR                         EQU BIT_POS_1
TC_INTENSET_SYNCRDY                     EQU BIT_POS_3
TC_INTENSET_MC0                         EQU BIT_POS_4
TC_INTENSET_MC1                         EQU BIT_POS_5

TC_INTENFLAG_OVF                        EQU BIT_POS_0
TC_INTENFLAG_ERR                        EQU BIT_POS_1
TC_INTENFLAG_SYNCRDY                    EQU BIT_POS_3
TC_INTENFLAG_MC0                        EQU BIT_POS_4
TC_INTENFLAG_MC1                        EQU BIT_POS_5

TC_STATUS_STOP                          EQU BIT_POS_3
TC_STATUS_STOP_Pos                      EQU 3
TC_STATUS_SLAVE                         EQU BIT_POS_4
TC_STATUS_SYNCBUSY                      EQU BIT_POS_7
TC_STATUS_SYNCBUSY_Pos                  EQU 7

TC_COUNT16_COUNT                        EQU 0x0000
TC_COUNT16_CC0_CC                       EQU 0x0000
TC_COUNT16_CC1_CC                       EQU 0x0000

TC_COUNT32_COUNT                        EQU 0x00000000
TC_COUNT32_CC0_CC                       EQU 0x00000000
TC_COUNT32_CC1_CC                       EQU 0x00000000

TC_COUNT8_COUNT                         EQU 0x00
TC_COUNT8_PER                           EQU 0x00
TC_COUNT8_CC0_CC                        EQU 0x00
TC_COUNT8_CC1_CC                        EQU 0x00






SYSCTRL_INTENCLR_offset                 EQU 0x00
SYSCTRL_INTENSET_offset                 EQU 0x04
SYSCTRL_INTFLAG_offset                  EQU 0x08
SYSCTRL_PCLKSR_offset                   EQU 0x0c
SYSCTRL_XOSC_offset                     EQU 0x10
SYSCTRL_XOSC32K_offset                  EQU 0x14
SYSCTRL_OSC32K_offset                   EQU 0x18
SYSCTRL_OSCULP32K_offset                EQU 0x1c
SYSCTRL_OSC8M_offset                    EQU 0x20
SYSCTRL_DFLLCTRL_offset                 EQU 0x24
SYSCTRL_DFLLVAL_offset                  EQU 0x28
SYSCTRL_DFLLMUL_offset                  EQU 0x2c
SYSCTRL_DFLLSYNC_offset                 EQU 0x30
SYSCTRL_BOD33_offset                    EQU 0x34
SYSCTRL_VREG_offset                     EQU 0x3c
SYSCTRL_VREF_offset                     EQU 0x40
SYSCTRL_DPLLCTRLA_offset                EQU 0x44
SYSCTRL_DPLLRATIO_offset                EQU 0x48
SYSCTRL_DPLLCTRLB_offset                EQU 0x4c
SYSCTRL_DPLLSTATUS_offset               EQU 0x50
	
SYSCTRL_INTENCLR                        EQU SYSCTRL + SYSCTRL_INTENCLR_offset
SYSCTRL_INTENSET                        EQU SYSCTRL + SYSCTRL_INTENSET_offset
SYSCTRL_INTFLAG                         EQU SYSCTRL + SYSCTRL_INTFLAG_offset
SYSCTRL_PCLKSR                          EQU SYSCTRL + SYSCTRL_PCLKSR_offset
SYSCTRL_XOSC                            EQU SYSCTRL + SYSCTRL_XOSC_offset
SYSCTRL_XOSC32K                         EQU SYSCTRL + SYSCTRL_XOSC32K_offset
SYSCTRL_OSC32K                          EQU SYSCTRL + SYSCTRL_OSC32K_offset
SYSCTRL_OSCULP32K                       EQU SYSCTRL + SYSCTRL_OSCULP32K_offset
SYSCTRL_OSC8M                           EQU SYSCTRL + SYSCTRL_OSC8M_offset
SYSCTRL_DFLLCTRL                        EQU SYSCTRL + SYSCTRL_DFLLCTRL_offset
SYSCTRL_DFLLVAL                         EQU SYSCTRL + SYSCTRL_DFLLVAL_offset
SYSCTRL_DFLLMUL                         EQU SYSCTRL + SYSCTRL_DFLLMUL_offset
SYSCTRL_DFLLSYNC                        EQU SYSCTRL + SYSCTRL_DFLLSYNC_offset
SYSCTRL_BOD33                           EQU SYSCTRL + SYSCTRL_BOD33_offset
SYSCTRL_VREG                            EQU SYSCTRL + SYSCTRL_VREG_offset
SYSCTRL_VREF                            EQU SYSCTRL + SYSCTRL_VREF_offset
SYSCTRL_DPLLCTRLA                       EQU SYSCTRL + SYSCTRL_DPLLCTRLA_offset
SYSCTRL_DPLLRATIO                       EQU SYSCTRL + SYSCTRL_DPLLRATIO_offset
SYSCTRL_DPLLCTRLB                       EQU SYSCTRL + SYSCTRL_DPLLCTRLB_offset
SYSCTRL_DPLLSTATUS                      EQU SYSCTRL + SYSCTRL_DPLLSTATUS_offset

SYSCTRL_INTENCLR_XOSCRDY                EQU BIT_POS_0
SYSCTRL_INTENCLR_XOSC32KRDY             EQU BIT_POS_1
SYSCTRL_INTENCLR_OSC32KRDY              EQU BIT_POS_2
SYSCTRL_INTENCLR_OSC8MRDY               EQU BIT_POS_3
SYSCTRL_INTENCLR_DFLLRDY                EQU BIT_POS_4
SYSCTRL_INTENCLR_DFLLOOB                EQU BIT_POS_5
SYSCTRL_INTENCLR_DFLLLCKF               EQU BIT_POS_6
SYSCTRL_INTENCLR_DFLLLCKC               EQU BIT_POS_7
SYSCTRL_INTENCLR_DFLLRCS                EQU BIT_POS_8
SYSCTRL_INTENCLR_BOD33RDY               EQU BIT_POS_9
SYSCTRL_INTENCLR_BOD33DET               EQU BIT_POS_10
SYSCTRL_INTENCLR_BOD33SRDY              EQU BIT_POS_11
SYSCTRL_INTENCLR_DPLLLCKR               EQU BIT_POS_15
SYSCTRL_INTENCLR_DPLLLCKF               EQU BIT_POS_16
SYSCTRL_INTENCLR_DPLLLTO                EQU BIT_POS_17

SYSCTRL_INTENSET_XOSCRDY                EQU BIT_POS_0
SYSCTRL_INTENSET_XOSC32KRDY             EQU BIT_POS_1
SYSCTRL_INTENSET_OSC32KRDY              EQU BIT_POS_2
SYSCTRL_INTENSET_OSC8MRDY               EQU BIT_POS_3
SYSCTRL_INTENSET_DFLLRDY                EQU BIT_POS_4
SYSCTRL_INTENSET_DFLLOOB                EQU BIT_POS_5
SYSCTRL_INTENSET_DFLLLCKF               EQU BIT_POS_6
SYSCTRL_INTENSET_DFLLLCKC               EQU BIT_POS_7
SYSCTRL_INTENSET_DFLLRCS                EQU BIT_POS_8
SYSCTRL_INTENSET_BOD33RDY               EQU BIT_POS_9
SYSCTRL_INTENSET_BOD33DET               EQU BIT_POS_10
SYSCTRL_INTENSET_BOD33SRDY              EQU BIT_POS_11
SYSCTRL_INTENSET_DPLLLCKR               EQU BIT_POS_15
SYSCTRL_INTENSET_DPLLLCKF               EQU BIT_POS_16
SYSCTRL_INTENSET_DPLLLTO                EQU BIT_POS_17

SYSCTRL_INTENFLAG_XOSCRDY               EQU BIT_POS_0
SYSCTRL_INTENFLAG_XOSC32KRDY            EQU BIT_POS_1
SYSCTRL_INTENFLAG_OSC32KRDY             EQU BIT_POS_2
SYSCTRL_INTENFLAG_OSC8MRDY              EQU BIT_POS_3
SYSCTRL_INTENFLAG_DFLLRDY               EQU BIT_POS_4
SYSCTRL_INTENFLAG_DFLLOOB               EQU BIT_POS_5
SYSCTRL_INTENFLAG_DFLLLCKF              EQU BIT_POS_6
SYSCTRL_INTENFLAG_DFLLLCKC              EQU BIT_POS_7
SYSCTRL_INTENFLAG_DFLLRCS               EQU BIT_POS_8
SYSCTRL_INTENFLAG_BOD33RDY              EQU BIT_POS_9
SYSCTRL_INTENFLAG_BOD33DET              EQU BIT_POS_10
SYSCTRL_INTENFLAG_BOD33SRDY             EQU BIT_POS_11
SYSCTRL_INTENFLAG_DPLLLCKR              EQU BIT_POS_15
SYSCTRL_INTENFLAG_DPLLLCKF              EQU BIT_POS_16
SYSCTRL_INTENFLAG_DPLLLTO               EQU BIT_POS_17

SYSCTRL_PCLKSR_XOSCRDY                  EQU BIT_POS_0
SYSCTRL_PCLKSR_XOSC32KRDY               EQU BIT_POS_1
SYSCTRL_PCLKSR_OSC32KRDY                EQU BIT_POS_2
SYSCTRL_PCLKSR_OSC8MRDY                 EQU BIT_POS_3
SYSCTRL_PCLKSR_DFLLRDY                  EQU BIT_POS_4
SYSCTRL_PCLKSR_DFLLOOB                  EQU BIT_POS_5
SYSCTRL_PCLKSR_DFLLLCKF                 EQU BIT_POS_6
SYSCTRL_PCLKSR_DFLLLCKC                 EQU BIT_POS_7
SYSCTRL_PCLKSR_DFLLRCS                  EQU BIT_POS_8
SYSCTRL_PCLKSR_BOD33RDY                 EQU BIT_POS_9
SYSCTRL_PCLKSR_BOD33DET                 EQU BIT_POS_10
SYSCTRL_PCLKSR_BOD33SRDY                EQU BIT_POS_11
SYSCTRL_PCLKSR_DPLLLCKR                 EQU BIT_POS_15
SYSCTRL_PCLKSR_DPLLLCKF                 EQU BIT_POS_16
SYSCTRL_PCLKSR_DPLLLTO                  EQU BIT_POS_17

SYSCTRL_PCLKSR_XOSCRDY_Pos              EQU 0
SYSCTRL_PCLKSR_XOSC32KRDY_Pos           EQU 1
SYSCTRL_PCLKSR_OSC32KRDY_Pos            EQU 2
SYSCTRL_PCLKSR_OSC8MRDY_Pos             EQU 3
SYSCTRL_PCLKSR_DFLLRDY_Pos              EQU 4
SYSCTRL_PCLKSR_DFLLOOB_Pos              EQU 5
SYSCTRL_PCLKSR_DFLLLCKF_Pos             EQU 6
SYSCTRL_PCLKSR_DFLLLCKC_Pos             EQU 7
SYSCTRL_PCLKSR_DFLLRCS_Pos              EQU 8
SYSCTRL_PCLKSR_BOD33RDY_Pos             EQU 9
SYSCTRL_PCLKSR_BOD33DET_Pos             EQU 10
SYSCTRL_PCLKSR_BOD33SRDY_Pos            EQU 11
SYSCTRL_PCLKSR_DPLLLCKR_Pos             EQU 15
SYSCTRL_PCLKSR_DPLLLCKF_Pos             EQU 16
SYSCTRL_PCLKSR_DPLLLTO_Pos              EQU 17

SYSCTRL_XOSC_ENABLE                     EQU BIT_POS_1
SYSCTRL_XOSC_XTALEN                     EQU BIT_POS_2
SYSCTRL_XOSC_RUNSTDBY                   EQU BIT_POS_6
SYSCTRL_XOSC_ONDEMAND                   EQU BIT_POS_7
SYSCTRL_XOSC_GAIN_2M                    EQU 0x0000 ; 2MHz
SYSCTRL_XOSC_GAIN_4M                    EQU 0x0100 ; 4MHz
SYSCTRL_XOSC_GAIN_8M                    EQU 0x0200 ; 8MHz
SYSCTRL_XOSC_GAIN_16M                   EQU 0x0300 ; 16MHz
SYSCTRL_XOSC_GAIN_30M                   EQU 0x0400 ; 30MHz
SYSCTRL_XOSC_GAIN_5                     EQU 0x0500
SYSCTRL_XOSC_GAIN_6                     EQU 0x0600
SYSCTRL_XOSC_GAIN_7                     EQU 0x0700
SYSCTRL_XOSC_AMPGC                      EQU BIT_POS_11
SYSCTRL_XOSC_STARTUP                    EQU 0x0
SYSCTRL_XOSC_STARTUP_Pos                EQU 12

SYSCTRL_XOSC32K_ENABLE                  EQU BIT_POS_1
SYSCTRL_XOSC32K_XTALEN                  EQU BIT_POS_2
SYSCTRL_XOSC32K_EN32K                   EQU BIT_POS_3
SYSCTRL_XOSC32K_EN1K                    EQU BIT_POS_4
SYSCTRL_XOSC32K_AAMPEN                  EQU BIT_POS_5
SYSCTRL_XOSC32K_RUNSTDBY                EQU BIT_POS_6
SYSCTRL_XOSC32K_ONDEMAND                EQU BIT_POS_7
SYSCTRL_XOSC32K_STARTUP                 EQU 0x0
SYSCTRL_XOSC32K_STARTUP_Pos             EQU 8
SYSCTRL_XOSC32K_WRTLOCK                 EQU BIT_POS_12

SYSCTRL_OSC32K_ENABLE                   EQU BIT_POS_1
SYSCTRL_OSC32K_EN32K                    EQU BIT_POS_2
SYSCTRL_OSC32K_EN1K                     EQU BIT_POS_3
SYSCTRL_OSC32K_RUNSTDBY                 EQU BIT_POS_6
SYSCTRL_OSC32K_ONDEMAND                 EQU BIT_POS_7
SYSCTRL_OSC32K_STARTUP                  EQU 0x0
SYSCTRL_OSC32K_STARTUP_Pos              EQU 8
SYSCTRL_OSC32K_WRTLOCK                  EQU BIT_POS_12
SYSCTRL_OSC32K_CALIB                    EQU 0x00
SYSCTRL_OSC32K_CALIB_Pos                EQU 16

SYSCTRL_OSCULP32K_CALIB                 EQU 0x0
SYSCTRL_OSCULP32K_CALIB_Pos             EQU 0
SYSCTRL_OSCULP32K_WRTLOCK               EQU BIT_POS_7

SYSCTRL_OSC8M_ENABLE                    EQU BIT_POS_1
SYSCTRL_OSC8M_RUNSTDBY                  EQU BIT_POS_6
SYSCTRL_OSC8M_ONDEMAND                  EQU BIT_POS_7
SYSCTRL_OSC8M_PRESC_1                   EQU 0x0000 ; 1
SYSCTRL_OSC8M_PRESC_2                   EQU 0x0100 ; 2
SYSCTRL_OSC8M_PRESC_4                   EQU 0x0200 ; 4
SYSCTRL_OSC8M_PRESC_8                   EQU 0x0300 ; 8
SYSCTRL_OSC8M_PRESC_MASK                EQU 0xffff00ff
SYSCTRL_OSC8M_CALIB                     EQU 0x0000
SYSCTRL_OSC8M_CALIB_Pos                 EQU 16
SYSCTRL_OSC8M_FRANGE_4_6                EQU 0x00000000 ; 4 - 6 MHz
SYSCTRL_OSC8M_FRANGE_6_8                EQU 0x40000000 ; 6 - 8 MHz
SYSCTRL_OSC8M_FRANGE_8_11               EQU 0x80000000 ; 8 - 11 MHz
SYSCTRL_OSC8M_FRANGE_11_16              EQU 0xc0000000 ; 11 - 16 MHz

SYSCTRL_DFLLCTRL_ENABLE                 EQU BIT_POS_1
SYSCTRL_DFLLCTRL_MODE                   EQU BIT_POS_2
SYSCTRL_DFLLCTRL_STABLE                 EQU BIT_POS_3
SYSCTRL_DFLLCTRL_LLAW                   EQU BIT_POS_4
SYSCTRL_DFLLCTRL_USBCRM                 EQU BIT_POS_5
SYSCTRL_DFLLCTRL_RUNSTDBY               EQU BIT_POS_6
SYSCTRL_DFLLCTRL_ONDEMAND               EQU BIT_POS_7
SYSCTRL_DFLLCTRL_CCDIS                  EQU BIT_POS_8
SYSCTRL_DFLLCTRL_QLDIS                  EQU BIT_POS_9
SYSCTRL_DFLLCTRL_BPLCKC                 EQU BIT_POS_10
SYSCTRL_DFLLCTRL_WAITLOCK               EQU BIT_POS_11

SYSCTRL_DFLLVAL_FINE                    EQU 0x000000
SYSCTRL_DFLLVAL_FINE_Pos                EQU 0
SYSCTRL_DFLLVAL_COARSE                  EQU 0x000
SYSCTRL_DFLLVAL_COARSE_Pos              EQU 10
SYSCTRL_DFLLVAL_DIFF                    EQU 0x000000
SYSCTRL_DFLLVAL_DIFF_Pos                EQU 16

SYSCTRL_DFLLMUL_MUL                     EQU 0x0000
SYSCTRL_DFLLMUL_MUL_Pos                 EQU 0
SYSCTRL_DFLLMUL_FSTEP                   EQU 0x000
SYSCTRL_DFLLMUL_FSTEP_Pos               EQU 16
SYSCTRL_DFLLMUL_CSTEP                   EQU 0x00
SYSCTRL_DFLLMUL_CSTEP_Pos               EQU 26

SYSCTRL_DFLLSYNC_READREQ                EQU	BIT_POS_7

SYSCTRL_BOD33_ENABLE                    EQU BIT_POS_1
SYSCTRL_BOD33_HYST                      EQU BIT_POS_2
SYSCTRL_BOD33_ACTION_NONE               EQU 0x00
SYSCTRL_BOD33_ACTION_RESET              EQU 0x08
SYSCTRL_BOD33_ACTION_INTERRUPT          EQU 0x10
SYSCTRL_BOD33_ACTION_3                  EQU 0x18
SYSCTRL_BOD33_RUNSTDBY                  EQU BIT_POS_6
SYSCTRL_BOD33_MODE                      EQU BIT_POS_8
SYSCTRL_BOD33_CEN                       EQU BIT_POS_9
SYSCTRL_BOD33_PSEL_2                    EQU 0x0000 ; 2
SYSCTRL_BOD33_PSEL_4                    EQU 0x1000 ; 4
SYSCTRL_BOD33_PSEL_8                    EQU 0x2000 ; 8
SYSCTRL_BOD33_PSEL_16                   EQU 0x3000 ; 16
SYSCTRL_BOD33_PSEL_32                   EQU 0x4000 ; 32
SYSCTRL_BOD33_PSEL_64                   EQU 0x5000 ; 64
SYSCTRL_BOD33_PSEL_128                  EQU 0x6000 ; 128
SYSCTRL_BOD33_PSEL_256                  EQU 0x7000 ; 256
SYSCTRL_BOD33_PSEL_512                  EQU 0x8000 ; 512
SYSCTRL_BOD33_PSEL_1024                 EQU 0x9000 ; 1024
SYSCTRL_BOD33_PSEL_2048                 EQU 0xa000 ; 2048
SYSCTRL_BOD33_PSEL_4096                 EQU 0xb000 ; 4096
SYSCTRL_BOD33_PSEL_8192                 EQU 0xc000 ; 8192
SYSCTRL_BOD33_PSEL_16384                EQU 0xd000 ; 16384
SYSCTRL_BOD33_PSEL_32768                EQU 0xe000 ; 32768
SYSCTRL_BOD33_PSEL_65536                EQU 0xf000 ; 65536
SYSCTRL_BOD33_LEVEL                     EQU 0x000
SYSCTRL_BOD33_LEVEL_Pos                 EQU 16

SYSCTRL_VREG_RUNSTDBY                   EQU BIT_POS_6
SYSCTRL_VREG_FORCELDO                   EQU BIT_POS_13

SYSCTRL_VREF_TSEN                       EQU BIT_POS_1
SYSCTRL_VREF_BGOUTEN                    EQU BIT_POS_2
SYSCTRL_VREF_CALIB                      EQU 0x000
SYSCTRL_VREF_CALIB_Pos                  EQU 16

SYSCTRL_DPLLCTRLA_ENABLE                EQU	BIT_POS_1
SYSCTRL_DPLLCTRLA_RUNSTDBY              EQU BIT_POS_6
SYSCTRL_DPLLCTRLA_ONDEMAND              EQU	BIT_POS_7

SYSCTRL_DPLLRATIO_LDR                   EQU 0x00
SYSCTRL_DPLLRATIO_LDR_Pos               EQU 0
SYSCTRL_DPLLRATIO_LDRFRAC               EQU 0x0
SYSCTRL_DPLLRATIO_LDRFRAC_Pos           EQU 16

SYSCTRL_DPLLCTRLB_FILTER_DEFAULT        EQU 0x0
SYSCTRL_DPLLCTRLB_FILTER_LBFILT         EQU 0x1
SYSCTRL_DPLLCTRLB_FILTER_HBFILT         EQU 0x2
SYSCTRL_DPLLCTRLB_FILTER_HDFILT         EQU 0x3
SYSCTRL_DPLLCTRLB_LPEN                  EQU BIT_POS_2
SYSCTRL_DPLLCTRLB_WUF                   EQU BIT_POS_3
SYSCTRL_DPLLCTRLB_REFCLK_REF0           EQU 0x00
SYSCTRL_DPLLCTRLB_REFCLK_REF1           EQU 0x10
SYSCTRL_DPLLCTRLB_REFCLK_GCLK           EQU 0x20
SYSCTRL_DPLLCTRLB_REFCLK_3              EQU 0x30
SYSCTRL_DPLLCTRLB_DEFAULT               EQU	0x0000
SYSCTRL_DPLLCTRLB_1                     EQU	0x0100
SYSCTRL_DPLLCTRLB_2                     EQU	0x0200
SYSCTRL_DPLLCTRLB_3                     EQU	0x0300
SYSCTRL_DPLLCTRLB_8MS                   EQU	0x0400
SYSCTRL_DPLLCTRLB_9MS                   EQU	0x0500
SYSCTRL_DPLLCTRLB_10MS                  EQU	0x0600
SYSCTRL_DPLLCTRLB_11MS                  EQU	0x0700
SYSCTRL_DPLLCTRLB_LBYPASS               EQU BIT_POS_12
SYSCTRL_DPLLCTRLB_DIV                   EQU 0x000
SYSCTRL_DPLLCTRLB_DIV_Pos               EQU 16

SYSCTRL_DPLLSTATUS_LOCK                 EQU BIT_POS_0
SYSCTRL_DPLLSTATUS_CLKRDY               EQU BIT_POS_1
SYSCTRL_DPLLSTATUS_ENABLE               EQU BIT_POS_2
SYSCTRL_DPLLSTATUS_DIV                  EQU BIT_POS_3





WDT_CTRL_offset                         EQU 0x00
WDT_CONFIG_offset                       EQU 0x01
WDT_EWCTRL_offset                       EQU 0x02
WDT_INTENCLR_offset                     EQU 0x04
WDT_INTENSET_offset                     EQU 0x05
WDT_INTFLAG_offset                      EQU 0x06
WDT_STATUS_offset                       EQU 0x07
WDT_CLEAR_offset                        EQU 0x08

WDT_CTRL                                EQU WDT + WDT_CTRL_offset
WDT_CONFIG                              EQU WDT + WDT_CONFIG_offset
WDT_EWCTRL                              EQU WDT + WDT_EWCTRL_offset
WDT_INTENCLR                            EQU WDT + WDT_INTENCLR_offset
WDT_INTENSET                            EQU WDT + WDT_INTENSET_offset
WDT_INTFLAG                             EQU WDT + WDT_INTFLAG_offset
WDT_STATUS                              EQU WDT + WDT_STATUS_offset
WDT_CLEAR                               EQU WDT + WDT_CLEAR_offset

WDT_CTRL_ENABLE                         EQU BIT_POS_1
WDT_CTRL_WEN                            EQU BIT_POS_2
WDT_CTRL_ALWAYSON                       EQU BIT_POS_7

WDT_CONFIG_PER_8                        EQU 0x00
WDT_CONFIG_PER_16                       EQU 0x01
WDT_CONFIG_PER_32                       EQU 0x02
WDT_CONFIG_PER_64                       EQU 0x03
WDT_CONFIG_PER_128                      EQU 0x04
WDT_CONFIG_PER_256                      EQU 0x05
WDT_CONFIG_PER_512                      EQU 0x06
WDT_CONFIG_PER_1K                       EQU 0x07
WDT_CONFIG_PER_2K                       EQU 0x08
WDT_CONFIG_PER_4K                       EQU 0x09
WDT_CONFIG_PER_8K                       EQU 0x0a
WDT_CONFIG_PER_16K                      EQU 0x0b

WDT_CONFIG_WINDOW_8                     EQU 0x00
WDT_CONFIG_WINDOW_16                    EQU 0x10
WDT_CONFIG_WINDOW_32                    EQU 0x20
WDT_CONFIG_WINDOW_64                    EQU 0x30
WDT_CONFIG_WINDOW_128                   EQU 0x40
WDT_CONFIG_WINDOW_256                   EQU 0x50
WDT_CONFIG_WINDOW_512                   EQU 0x60
WDT_CONFIG_WINDOW_1K                    EQU 0x70
WDT_CONFIG_WINDOW_2K                    EQU 0x80
WDT_CONFIG_WINDOW_4K                    EQU 0x90
WDT_CONFIG_WINDOW_8K                    EQU 0xa0
WDT_CONFIG_WINDOW_16K                   EQU 0xb0

WDT_EWCTRL_EWOFFSET_8                   EQU 0x00
WDT_EWCTRL_EWOFFSET_16                  EQU 0x01
WDT_EWCTRL_EWOFFSET_32                  EQU 0x02
WDT_EWCTRL_EWOFFSET_64                  EQU 0x03
WDT_EWCTRL_EWOFFSET_128                 EQU 0x04
WDT_EWCTRL_EWOFFSET_256                 EQU 0x05
WDT_EWCTRL_EWOFFSET_512                 EQU 0x06
WDT_EWCTRL_EWOFFSET_1K                  EQU 0x07
WDT_EWCTRL_EWOFFSET_2K                  EQU 0x08
WDT_EWCTRL_EWOFFSET_4K                  EQU 0x09
WDT_EWCTRL_EWOFFSET_8K                  EQU 0x0a
WDT_EWCTRL_EWOFFSET_16K                 EQU 0x0b

WDT_INTENCLR_EW                         EQU BIT_POS_0

WDT_INTENSET_EW                         EQU BIT_POS_0

WDT_INTENFLAG_EW                        EQU BIT_POS_0

WDT_STATUS_SYNCBUSY                     EQU BIT_POS_7
WDT_STATUS_SYNCBUSY_Pos                 EQU 7

WDT_CLEAR_CLEAR                         EQU 0xa5
WDT_CLEAR_CLEAR_Pos                     EQU 0









NVMCTRL_CTRLA_offset                    EQU 0x00
NVMCTRL_CTRLB_offset                    EQU 0x04
NVMCTRL_PARAM_offset                    EQU 0x08
NVMCTRL_INTENCLR_offset                 EQU 0x0c
NVMCTRL_INTENSET_offset                 EQU 0x10
NVMCTRL_INTFLAG_offset                  EQU 0x14
NVMCTRL_STATUS_offset                   EQU 0x18
NVMCTRL_ADDR_offset                     EQU 0x1c
NVMCTRL_LOCK_offset                     EQU 0x20

NVMCTRL_CTRLA                           EQU NVMCTRL + NVMCTRL_CTRLA_offset
NVMCTRL_CTRLB                           EQU NVMCTRL + NVMCTRL_CTRLB_offset
NVMCTRL_PARAM                           EQU NVMCTRL + NVMCTRL_PARAM_offset
NVMCTRL_INTENCLR                        EQU NVMCTRL + NVMCTRL_INTENCLR_offset
NVMCTRL_INTENSET                        EQU NVMCTRL + NVMCTRL_INTENSET_offset
NVMCTRL_INTFLAG                         EQU NVMCTRL + NVMCTRL_INTFLAG_offset
NVMCTRL_STATUS                          EQU NVMCTRL + NVMCTRL_STATUS_offset
NVMCTRL_ADDR                            EQU NVMCTRL + NVMCTRL_ADDR_offset
NVMCTRL_LOCK                            EQU NVMCTRL + NVMCTRL_LOCK_offset


NVMCTRL_CTRLA_CMD                       EQU 0x00
NVMCTRL_CTRLA_CMD_Pos                   EQU 0
NVMCTRL_CTRLA_CMD_ER                    EQU 0x02
NVMCTRL_CTRLA_CMD_WP                    EQU 0x04
NVMCTRL_CTRLA_CMD_EAR                   EQU 0x05
NVMCTRL_CTRLA_CMD_WAP                   EQU 0x06
NVMCTRL_CTRLA_CMD_SF                    EQU 0x0a
NVMCTRL_CTRLA_CMD_WL                    EQU 0x0f
NVMCTRL_CTRLA_CMD_LR                    EQU 0x40
NVMCTRL_CTRLA_CMD_UR                    EQU 0x41
NVMCTRL_CTRLA_CMD_SPRM                  EQU 0x42
NVMCTRL_CTRLA_CMD_CPRM                  EQU 0x43
NVMCTRL_CTRLA_CMD_PBC                   EQU 0x44
NVMCTRL_CTRLA_CMD_SSB                   EQU 0x45
NVMCTRL_CTRLA_CMD_INVALL                EQU 0x46

NVMCTRL_CTRLA_CMDEX                     EQU 0x00
NVMCTRL_CTRLA_CMDEXPos                  EQU 8

NVMCTRL_CTRLB_RWS_SINGLE                EQU 0x0
NVMCTRL_CTRLB_RWS_HALF                  EQU 0x2
NVMCTRL_CTRLB_RWS_DUAL                  EQU 0x4
NVMCTRL_CTRLB_MANW                      EQU BIT_POS_7
NVMCTRL_CTRLB_SLEEPPRM_WAKEONACCESS     EQU 0x0000
NVMCTRL_CTRLB_SLEEPPRM_WAKEUPINSTANT    EQU 0x0100
NVMCTRL_CTRLB_SLEEPPRM_DISABLED         EQU 0x0300
NVMCTRL_CTRLB_READMODE_NO_MISS_PENALTY  EQU 0x000000
NVMCTRL_CTRLB_READMODE_LOW_POWER        EQU 0x010000
NVMCTRL_CTRLB_READMODE_DETERMINISTIC    EQU 0x020000
NVMCTRL_CTRLB_CACHEDIS                  EQU BIT_POS_18

NVMCTRL_PARAM_PSZ                       EQU 0x0000
NVMCTRL_PARAM_PSZ_Pos                   EQU 0
NVMCTRL_PARAM_PSZ_8                     EQU 0x000000
NVMCTRL_PARAM_PSZ_16                    EQU 0x010000
NVMCTRL_PARAM_PSZ_32                    EQU 0x020000
NVMCTRL_PARAM_PSZ_64                    EQU 0x030000
NVMCTRL_PARAM_PSZ_128                   EQU 0x040000
NVMCTRL_PARAM_PSZ_256                   EQU 0x050000
NVMCTRL_PARAM_PSZ_512                   EQU 0x060000
NVMCTRL_PARAM_PSZ_1024                  EQU 0x070000

NVMCTRL_INTENCLR_READY                  EQU BIT_POS_0
NVMCTRL_INTENCLR_ERROR                  EQU BIT_POS_1

NVMCTRL_INTENSET_READY                  EQU BIT_POS_0
NVMCTRL_INTENSET_ERROR                  EQU BIT_POS_1

NVMCTRL_INTENFLAG_READY                 EQU BIT_POS_0
NVMCTRL_INTENFLAG_ERROR                 EQU BIT_POS_1

NVMCTRL_STATUS_PRM                      EQU BIT_POS_0
NVMCTRL_STATUS_LOAD                     EQU BIT_POS_1
NVMCTRL_STATUS_PROGE                    EQU BIT_POS_2
NVMCTRL_STATUS_LOCKE                    EQU BIT_POS_3
NVMCTRL_STATUS_NVME                     EQU BIT_POS_4
NVMCTRL_STATUS_SB                       EQU BIT_POS_8

NVMCTRL_ADDR_ADDR                       EQU 0x00000000
NVMCTRL_ADDR_ADDR_Pos                   EQU 0

NVMCTRL_LOCK_LOCK                       EQU 0x0000
NVMCTRL_LOCK_LOCK_Pos                   EQU 0









EIC_CTRL_offset                         EQU 0x00
EIC_STATUS_offset                       EQU 0x01
EIC_NMICTRL_offset                      EQU 0x02
EIC_NMIFLAG_offset                      EQU 0x03
EIC_EVCTRL_offset                       EQU 0x04
EIC_INTENCLR_offset                     EQU 0x08
EIC_INTENSET_offset                     EQU 0x0c
EIC_INTFLAG_offset                      EQU 0x10
EIC_WAKEUP_offset                       EQU 0x14
EIC_CONFIG0_offset                      EQU 0x18
EIC_CONFIG1_offset                      EQU 0x1c

EIC_CTRL_SWRST                          EQU BIT_POS_0
EIC_CTRL_ENABLE                         EQU BIT_POS_1

EIC_STATUS_SYNCBUSY                     EQU BIT_POS_7
EIC_STATUS_SYNCBUSY_Pos                 EQU 7

EIC_NMICTRL_NMISENSE_NONE               EQU 0x0
EIC_NMICTRL_NMISENSE_RISE               EQU 0x1
EIC_NMICTRL_NMISENSE_FALL               EQU 0x2
EIC_NMICTRL_NMISENSE_BOTH               EQU 0x3
EIC_NMICTRL_NMISENSE_HIGH               EQU 0x4
EIC_NMICTRL_NMISENSE_LOW                EQU 0x5
EIC_NMICTRL_NMIFILTEN                   EQU BIT_POS_3

EIC_NMIFLAG_NMI                         EQU BIT_POS_0

EIC_EVCTRL_EXTINTEO0                    EQU BIT_POS_0
EIC_EVCTRL_EXTINTEO1                    EQU BIT_POS_1
EIC_EVCTRL_EXTINTEO2                    EQU BIT_POS_2
EIC_EVCTRL_EXTINTEO3                    EQU BIT_POS_3
EIC_EVCTRL_EXTINTEO4                    EQU BIT_POS_4
EIC_EVCTRL_EXTINTEO5                    EQU BIT_POS_5
EIC_EVCTRL_EXTINTEO6                    EQU BIT_POS_6
EIC_EVCTRL_EXTINTEO7                    EQU BIT_POS_7
EIC_EVCTRL_EXTINTEO8                    EQU BIT_POS_8
EIC_EVCTRL_EXTINTEO9                    EQU BIT_POS_9
EIC_EVCTRL_EXTINTEO10                   EQU BIT_POS_10
EIC_EVCTRL_EXTINTEO11                   EQU BIT_POS_11
EIC_EVCTRL_EXTINTEO12                   EQU BIT_POS_12
EIC_EVCTRL_EXTINTEO13                   EQU BIT_POS_13
EIC_EVCTRL_EXTINTEO14                   EQU BIT_POS_14
EIC_EVCTRL_EXTINTEO15                   EQU BIT_POS_15

EIC_INTENCLR_EXTINT0                    EQU BIT_POS_0
EIC_INTENCLR_EXTINT1                    EQU BIT_POS_1
EIC_INTENCLR_EXTINT2                    EQU BIT_POS_2
EIC_INTENCLR_EXTINT3                    EQU BIT_POS_3
EIC_INTENCLR_EXTINT4                    EQU BIT_POS_4
EIC_INTENCLR_EXTINT5                    EQU BIT_POS_5
EIC_INTENCLR_EXTINT6                    EQU BIT_POS_6
EIC_INTENCLR_EXTINT7                    EQU BIT_POS_7
EIC_INTENCLR_EXTINT8                    EQU BIT_POS_8
EIC_INTENCLR_EXTINT9                    EQU BIT_POS_9
EIC_INTENCLR_EXTINT10                   EQU BIT_POS_10
EIC_INTENCLR_EXTINT11                   EQU BIT_POS_11
EIC_INTENCLR_EXTINT12                   EQU BIT_POS_12
EIC_INTENCLR_EXTINT13                   EQU BIT_POS_13
EIC_INTENCLR_EXTINT14                   EQU BIT_POS_14
EIC_INTENCLR_EXTINT15                   EQU BIT_POS_15

EIC_INTENSET_EXTINT0                    EQU BIT_POS_0
EIC_INTENSET_EXTINT1                    EQU BIT_POS_1
EIC_INTENSET_EXTINT2                    EQU BIT_POS_2
EIC_INTENSET_EXTINT3                    EQU BIT_POS_3
EIC_INTENSET_EXTINT4                    EQU BIT_POS_4
EIC_INTENSET_EXTINT5                    EQU BIT_POS_5
EIC_INTENSET_EXTINT6                    EQU BIT_POS_6
EIC_INTENSET_EXTINT7                    EQU BIT_POS_7
EIC_INTENSET_EXTINT8                    EQU BIT_POS_8
EIC_INTENSET_EXTINT9                    EQU BIT_POS_9
EIC_INTENSET_EXTINT10                   EQU BIT_POS_10
EIC_INTENSET_EXTINT11                   EQU BIT_POS_11
EIC_INTENSET_EXTINT12                   EQU BIT_POS_12
EIC_INTENSET_EXTINT13                   EQU BIT_POS_13
EIC_INTENSET_EXTINT14                   EQU BIT_POS_14
EIC_INTENSET_EXTINT15                   EQU BIT_POS_15

EIC_INTFLAG_EXTINT0                     EQU BIT_POS_0
EIC_INTFLAG_EXTINT1                     EQU BIT_POS_1
EIC_INTFLAG_EXTINT2                     EQU BIT_POS_2
EIC_INTFLAG_EXTINT3                     EQU BIT_POS_3
EIC_INTFLAG_EXTINT4                     EQU BIT_POS_4
EIC_INTFLAG_EXTINT5                     EQU BIT_POS_5
EIC_INTFLAG_EXTINT6                     EQU BIT_POS_6
EIC_INTFLAG_EXTINT7                     EQU BIT_POS_7
EIC_INTFLAG_EXTINT8                     EQU BIT_POS_8
EIC_INTFLAG_EXTINT9                     EQU BIT_POS_9
EIC_INTFLAG_EXTINT10                    EQU BIT_POS_10
EIC_INTFLAG_EXTINT11                    EQU BIT_POS_11
EIC_INTFLAG_EXTINT12                    EQU BIT_POS_12
EIC_INTFLAG_EXTINT13                    EQU BIT_POS_13
EIC_INTFLAG_EXTINT14                    EQU BIT_POS_14
EIC_INTFLAG_EXTINT15                    EQU BIT_POS_15

EIC_WAKEUP_WAKEUPEN0                    EQU BIT_POS_0
EIC_WAKEUP_WAKEUPEN1                    EQU BIT_POS_1
EIC_WAKEUP_WAKEUPEN2                    EQU BIT_POS_2
EIC_WAKEUP_WAKEUPEN3                    EQU BIT_POS_3
EIC_WAKEUP_WAKEUPEN4                    EQU BIT_POS_4
EIC_WAKEUP_WAKEUPEN5                    EQU BIT_POS_5
EIC_WAKEUP_WAKEUPEN6                    EQU BIT_POS_6
EIC_WAKEUP_WAKEUPEN7                    EQU BIT_POS_7
EIC_WAKEUP_WAKEUPEN8                    EQU BIT_POS_8
EIC_WAKEUP_WAKEUPEN9                    EQU BIT_POS_9
EIC_WAKEUP_WAKEUPEN10                   EQU BIT_POS_10
EIC_WAKEUP_WAKEUPEN11                   EQU BIT_POS_11
EIC_WAKEUP_WAKEUPEN12                   EQU BIT_POS_12
EIC_WAKEUP_WAKEUPEN13                   EQU BIT_POS_13
EIC_WAKEUP_WAKEUPEN14                   EQU BIT_POS_14
EIC_WAKEUP_WAKEUPEN15                   EQU BIT_POS_15

EIC_CONFIG_SENSE0_NONE                  EQU 0x0
EIC_CONFIG_SENSE0_RISE                  EQU 0x1
EIC_CONFIG_SENSE0_FALL                  EQU 0x2
EIC_CONFIG_SENSE0_BOTH                  EQU 0x3
EIC_CONFIG_SENSE0_HIGH                  EQU 0x4
EIC_CONFIG_SENSE0_LOW                   EQU 0x5
EIC_CONFIG_FILTEN0                      EQU BIT_POS_3
EIC_CONFIG_SENSE1_NONE                  EQU 0x00
EIC_CONFIG_SENSE1_RISE                  EQU 0x10
EIC_CONFIG_SENSE1_FALL                  EQU 0x20
EIC_CONFIG_SENSE1_BOTH                  EQU 0x30
EIC_CONFIG_SENSE1_HIGH                  EQU 0x40
EIC_CONFIG_SENSE1_LOW                   EQU 0x50
EIC_CONFIG_FILTEN1                      EQU BIT_POS_7
EIC_CONFIG_SENSE2_NONE                  EQU 0x00
EIC_CONFIG_SENSE2_RISE                  EQU 0x100
EIC_CONFIG_SENSE2_FALL                  EQU 0x200
EIC_CONFIG_SENSE2_BOTH                  EQU 0x300
EIC_CONFIG_SENSE2_HIGH                  EQU 0x400
EIC_CONFIG_SENSE2_LOW                   EQU 0x500
EIC_CONFIG_FILTEN2                      EQU BIT_POS_11
EIC_CONFIG_SENSE3_NONE                  EQU 0x0000
EIC_CONFIG_SENSE3_RISE                  EQU 0x1000
EIC_CONFIG_SENSE3_FALL                  EQU 0x2000
EIC_CONFIG_SENSE3_BOTH                  EQU 0x3000
EIC_CONFIG_SENSE3_HIGH                  EQU 0x4000
EIC_CONFIG_SENSE3_LOW                   EQU 0x5000
EIC_CONFIG_FILTEN3                      EQU BIT_POS_15
EIC_CONFIG_SENSE4_NONE                  EQU 0x00000
EIC_CONFIG_SENSE4_RISE                  EQU 0x10000
EIC_CONFIG_SENSE4_FALL                  EQU 0x20000
EIC_CONFIG_SENSE4_BOTH                  EQU 0x30000
EIC_CONFIG_SENSE4_HIGH                  EQU 0x40000
EIC_CONFIG_SENSE4_LOW                   EQU 0x50000
EIC_CONFIG_FILTEN4                      EQU BIT_POS_19
EIC_CONFIG_SENSE5_NONE                  EQU 0x000000
EIC_CONFIG_SENSE5_RISE                  EQU 0x100000
EIC_CONFIG_SENSE5_FALL                  EQU 0x200000
EIC_CONFIG_SENSE5_BOTH                  EQU 0x300000
EIC_CONFIG_SENSE5_HIGH                  EQU 0x400000
EIC_CONFIG_SENSE5_LOW                   EQU 0x500000
EIC_CONFIG_FILTEN5                      EQU BIT_POS_23
EIC_CONFIG_SENSE6_NONE                  EQU 0x0000000
EIC_CONFIG_SENSE6_RISE                  EQU 0x1000000
EIC_CONFIG_SENSE6_FALL                  EQU 0x2000000
EIC_CONFIG_SENSE6_BOTH                  EQU 0x3000000
EIC_CONFIG_SENSE6_HIGH                  EQU 0x4000000
EIC_CONFIG_SENSE6_LOW                   EQU 0x5000000
EIC_CONFIG_FILTEN6                      EQU BIT_POS_27
EIC_CONFIG_SENSE7_NONE                  EQU 0x00000000
EIC_CONFIG_SENSE7_RISE                  EQU 0x10000000
EIC_CONFIG_SENSE7_FALL                  EQU 0x20000000
EIC_CONFIG_SENSE7_BOTH                  EQU 0x30000000
EIC_CONFIG_SENSE7_HIGH                  EQU 0x40000000
EIC_CONFIG_SENSE7_LOW                   EQU 0x50000000
EIC_CONFIG_FILTEN7                      EQU BIT_POS_31








; I2CM
I2CM_CTRLA_offset                       EQU 0x00
I2CM_CTRLB_offset                       EQU 0x04
I2CM_BAUD_offset                        EQU 0x0c
I2CM_INTENCLR_offset                    EQU 0x14
I2CM_INTENSET_offset                    EQU 0x16
I2CM_INTFLAG_offset                     EQU 0x18
I2CM_STATUS_offset                      EQU 0x1a
I2CM_SYNCBUSY_offset                    EQU 0x1c
I2CM_ADDR_offset                        EQU 0x24
I2CM_DATA_offset                        EQU 0x28
I2CM_DBGCTRL_offset                     EQU 0x30

I2CM0_CTRLA                             EQU SERCOM0 + I2CM_CTRLA_offset
I2CM0_CTRLB                             EQU SERCOM0 + I2CM_CTRLB_offset
I2CM0_BAUD                              EQU SERCOM0 + I2CM_BAUD_offset
I2CM0_INTENCLR                          EQU SERCOM0 + I2CM_INTENCLR_offset
I2CM0_INTENSET                          EQU SERCOM0 + I2CM_INTENSET_offset
I2CM0_INTFLAG                           EQU SERCOM0 + I2CM_INTFLAG_offset
I2CM0_STATUS                            EQU SERCOM0 + I2CM_STATUS_offset
I2CM0_SYNCBUSY                          EQU SERCOM0 + I2CM_SYNCBUSY_offset
I2CM0_ADDR                              EQU SERCOM0 + I2CM_ADDR_offset
I2CM0_DATA                              EQU SERCOM0 + I2CM_DATA_offset
I2CM0_DBGCTRL                           EQU SERCOM0 + I2CM_DBGCTRL_offset

I2CM1_CTRLA                             EQU SERCOM1 + I2CM_CTRLA_offset
I2CM1_CTRLB                             EQU SERCOM1 + I2CM_CTRLB_offset
I2CM1_BAUD                              EQU SERCOM1 + I2CM_BAUD_offset
I2CM1_INTENCLR                          EQU SERCOM1 + I2CM_INTENCLR_offset
I2CM1_INTENSET                          EQU SERCOM1 + I2CM_INTENSET_offset
I2CM1_INTFLAG                           EQU SERCOM1 + I2CM_INTFLAG_offset
I2CM1_STATUS                            EQU SERCOM1 + I2CM_STATUS_offset
I2CM1_SYNCBUSY                          EQU SERCOM1 + I2CM_SYNCBUSY_offset
I2CM1_ADDR                              EQU SERCOM1 + I2CM_ADDR_offset
I2CM1_DATA                              EQU SERCOM1 + I2CM_DATA_offset
I2CM1_DBGCTRL                           EQU SERCOM1 + I2CM_DBGCTRL_offset

I2CM2_CTRLA                             EQU SERCOM2 + I2CM_CTRLA_offset
I2CM2_CTRLB                             EQU SERCOM2 + I2CM_CTRLB_offset
I2CM2_BAUD                              EQU SERCOM2 + I2CM_BAUD_offset
I2CM2_INTENCLR                          EQU SERCOM2 + I2CM_INTENCLR_offset
I2CM2_INTENSET                          EQU SERCOM2 + I2CM_INTENSET_offset
I2CM2_INTFLAG                           EQU SERCOM2 + I2CM_INTFLAG_offset
I2CM2_STATUS                            EQU SERCOM2 + I2CM_STATUS_offset
I2CM2_SYNCBUSY                          EQU SERCOM2 + I2CM_SYNCBUSY_offset
I2CM2_ADDR                              EQU SERCOM2 + I2CM_ADDR_offset
I2CM2_DATA                              EQU SERCOM2 + I2CM_DATA_offset
I2CM2_DBGCTRL                           EQU SERCOM2 + I2CM_DBGCTRL_offset

I2CM3_CTRLA                             EQU SERCOM3 + I2CM_CTRLA_offset
I2CM3_CTRLB                             EQU SERCOM3 + I2CM_CTRLB_offset
I2CM3_BAUD                              EQU SERCOM3 + I2CM_BAUD_offset
I2CM3_INTENCLR                          EQU SERCOM3 + I2CM_INTENCLR_offset
I2CM3_INTENSET                          EQU SERCOM3 + I2CM_INTENSET_offset
I2CM3_INTFLAG                           EQU SERCOM3 + I2CM_INTFLAG_offset
I2CM3_STATUS                            EQU SERCOM3 + I2CM_STATUS_offset
I2CM3_SYNCBUSY                          EQU SERCOM3 + I2CM_SYNCBUSY_offset
I2CM3_ADDR                              EQU SERCOM3 + I2CM_ADDR_offset
I2CM3_DATA                              EQU SERCOM3 + I2CM_DATA_offset
I2CM3_DBGCTRL                           EQU SERCOM3 + I2CM_DBGCTRL_offset

I2CM4_CTRLA                             EQU SERCOM4 + I2CM_CTRLA_offset
I2CM4_CTRLB                             EQU SERCOM4 + I2CM_CTRLB_offset
I2CM4_BAUD                              EQU SERCOM4 + I2CM_BAUD_offset
I2CM4_INTENCLR                          EQU SERCOM4 + I2CM_INTENCLR_offset
I2CM4_INTENSET                          EQU SERCOM4 + I2CM_INTENSET_offset
I2CM4_INTFLAG                           EQU SERCOM4 + I2CM_INTFLAG_offset
I2CM4_STATUS                            EQU SERCOM4 + I2CM_STATUS_offset
I2CM4_SYNCBUSY                          EQU SERCOM4 + I2CM_SYNCBUSY_offset
I2CM4_ADDR                              EQU SERCOM4 + I2CM_ADDR_offset
I2CM4_DATA                              EQU SERCOM4 + I2CM_DATA_offset
I2CM4_DBGCTRL                           EQU SERCOM4 + I2CM_DBGCTRL_offset

I2CM5_CTRLA                             EQU SERCOM5 + I2CM_CTRLA_offset
I2CM5_CTRLB                             EQU SERCOM5 + I2CM_CTRLB_offset
I2CM5_BAUD                              EQU SERCOM5 + I2CM_BAUD_offset
I2CM5_INTENCLR                          EQU SERCOM5 + I2CM_INTENCLR_offset
I2CM5_INTENSET                          EQU SERCOM5 + I2CM_INTENSET_offset
I2CM5_INTFLAG                           EQU SERCOM5 + I2CM_INTFLAG_offset
I2CM5_STATUS                            EQU SERCOM5 + I2CM_STATUS_offset
I2CM5_SYNCBUSY                          EQU SERCOM5 + I2CM_SYNCBUSY_offset
I2CM5_ADDR                              EQU SERCOM5 + I2CM_ADDR_offset
I2CM5_DATA                              EQU SERCOM5 + I2CM_DATA_offset
I2CM5_DBGCTRL                           EQU SERCOM5 + I2CM_DBGCTRL_offset


I2CM_CTRLA_SWRST                        EQU BIT_POS_0
I2CM_CTRLA_ENABLE                       EQU BIT_POS_1
I2CM_CTRLA_MODE_USART_EXT_CLK           EQU 0x00
I2CM_CTRLA_MODE_USART_INT_CLK           EQU 0x04
I2CM_CTRLA_MODE_SPI_SLAVE               EQU 0x08
I2CM_CTRLA_MODE_SPI_MASTER              EQU 0x0c
I2CM_CTRLA_MODE_I2C_SLAVE               EQU 0x10
I2CM_CTRLA_MODE_I2C_MASTER              EQU 0x14
I2CM_CTRLA_RUNSTDBY                     EQU BIT_POS_7
I2CM_CTRLA_PINOUT                       EQU BIT_POS_16
I2CM_CTRLA_SDAHOLD                      EQU 0x0
I2CM_CTRLA_SDAHOLD_Pos                  EQU 20
I2CM_CTRLA_MEXTTOEN                     EQU BIT_POS_22
I2CM_CTRLA_SEXTTOEN                     EQU BIT_POS_23
I2CM_CTRLA_SPEED                        EQU 0x0
I2CM_CTRLA_SPEED_Pos                    EQU 24
I2CM_CTRLA_SCLSM                        EQU BIT_POS_27
I2CM_CTRLA_INACTOUT                     EQU 0x0
I2CM_CTRLA_INACTOUT_Pos                 EQU 28
I2CM_CTRLA_LOWTOUTEN                    EQU BIT_POS_30

I2CM_CTRLB_SMEN                         EQU BIT_POS_8
I2CM_CTRLB_QCEN                         EQU BIT_POS_9
I2CM_CTRLB_CMD                          EQU 0x0
I2CM_CTRLB_CMD_Pos                      EQU 16
I2CM_CTRLB_ACKACT                       EQU BIT_POS_18

I2CM_BAUD_BAUD                          EQU 0x00
I2CM_BAUD_BAUD_Pos                      EQU 0
I2CM_BAUD_BAUDLOW                       EQU 0x00
I2CM_BAUD_BAUDLOW_Pos                   EQU 8
I2CM_BAUD_HSBAUD                        EQU 0x00
I2CM_BAUD_HSBAUD_Pos                    EQU 16
I2CM_BAUD_HSBAUDLOW                     EQU 0x00
I2CM_BAUD_HSBAUDLOW_Pos                 EQU 24

I2CM_INTENCLR_MB                        EQU BIT_POS_0
I2CM_INTENCLR_SB                        EQU BIT_POS_1
I2CM_INTENCLR_ERROR                     EQU BIT_POS_7

I2CM_INTENSET_MB                        EQU BIT_POS_0
I2CM_INTENSET_SB                        EQU BIT_POS_1
I2CM_INTENSET_ERROR                     EQU BIT_POS_7

I2CM_INTFLAG_MB                         EQU BIT_POS_0
I2CM_INTFLAG_MB_Pos                     EQU 0
I2CM_INTFLAG_SB                         EQU BIT_POS_1
I2CM_INTFLAG_SB_Pos                     EQU 1
I2CM_INTFLAG_ERROR                      EQU BIT_POS_7
I2CM_INTFLAG_ERROR_Pos                  EQU 7

I2CM_STATUS_BUSERR                      EQU BIT_POS_0
I2CM_STATUS_BUSERR_Pos                  EQU 0
I2CM_STATUS_ARBLOST                     EQU BIT_POS_1
I2CM_STATUS_ARBLOST_Pos                 EQU 1
I2CM_STATUS_RXNACK                      EQU BIT_POS_2
I2CM_STATUS_RXNACK_Pos                  EQU 2
I2CM_STATUS_BUSSTATE                    EQU 0x0
I2CM_STATUS_BUSSTATE_Pos                EQU 4
I2CM_STATUS_LOWTOUT                     EQU BIT_POS_6
I2CM_STATUS_CLKHOLD                     EQU BIT_POS_7
I2CM_STATUS_CLKHOLD_Pos                 EQU 7
I2CM_STATUS_MEXTTOUT                    EQU BIT_POS_8
I2CM_STATUS_SEXTTOUT                    EQU BIT_POS_9
I2CM_STATUS_LENERR                      EQU BIT_POS_10

I2CM_SYNCBUSY_SWRST                     EQU BIT_POS_0
I2CM_SYNCBUSY_ENABLE                    EQU BIT_POS_1
I2CM_SYNCBUSY_ENABLE_Pos                EQU 1
I2CM_SYNCBUSY_SYSOP                     EQU BIT_POS_2
I2CM_SYNCBUSY_SYSOP_Pos                 EQU 2

I2CM_ADDR_ADDR                          EQU 0x00
I2CM_ADDR_ADDR_Pos                      EQU 0
I2CM_ADDR_LENEN                         EQU BIT_POS_13
I2CM_ADDR_HS                            EQU BIT_POS_14
I2CM_ADDR_TENBITEN                      EQU BIT_POS_15
I2CM_ADDR_LEN                           EQU 0x00
I2CM_ADDR_LEN_Pos                       EQU 16

I2CM_DATA_DATA                          EQU 0x00
I2CM_DATA_DATA_Pos                      EQU 0

I2CM_DBGCTRL_DBGSTOP                    EQU BIT_POS_0






; I2CS
I2CS_CTRLA_offset                       EQU 0x00
I2CS_CTRLB_offset                       EQU 0x04
I2CS_INTENCLR_offset                    EQU 0x14
I2CS_INTENSET_offset                    EQU 0x16
I2CS_INTFLAG_offset                     EQU 0x18
I2CS_STATUS_offset                      EQU 0x1a
I2CS_SYNCBUSY_offset                    EQU 0x1c
I2CS_ADDR_offset                        EQU 0x24
I2CS_DATA_offset                        EQU 0x28

I2CS0_CTRLA                             EQU SERCOM0 + I2CS_CTRLA_offset
I2CS0_CTRLB                             EQU SERCOM0 + I2CS_CTRLB_offset
I2CS0_INTENCLR                          EQU SERCOM0 + I2CS_INTENCLR_offset
I2CS0_INTENSET                          EQU SERCOM0 + I2CS_INTENSET_offset
I2CS0_INTFLAG                           EQU SERCOM0 + I2CS_INTFLAG_offset
I2CS0_STATUS                            EQU SERCOM0 + I2CS_STATUS_offset
I2CS0_SYNCBUSY                          EQU SERCOM0 + I2CS_SYNCBUSY_offset
I2CS0_ADDR                              EQU SERCOM0 + I2CS_ADDR_offset
I2CS0_DATA                              EQU SERCOM0 + I2CS_DATA_offset

I2CS1_CTRLA                             EQU SERCOM1 + I2CS_CTRLA_offset
I2CS1_CTRLB                             EQU SERCOM1 + I2CS_CTRLB_offset
I2CS1_INTENCLR                          EQU SERCOM1 + I2CS_INTENCLR_offset
I2CS1_INTENSET                          EQU SERCOM1 + I2CS_INTENSET_offset
I2CS1_INTFLAG                           EQU SERCOM1 + I2CS_INTFLAG_offset
I2CS1_STATUS                            EQU SERCOM1 + I2CS_STATUS_offset
I2CS1_SYNCBUSY                          EQU SERCOM1 + I2CS_SYNCBUSY_offset
I2CS1_ADDR                              EQU SERCOM1 + I2CS_ADDR_offset
I2CS1_DATA                              EQU SERCOM1 + I2CS_DATA_offset

I2CS2_CTRLA                             EQU SERCOM2 + I2CS_CTRLA_offset
I2CS2_CTRLB                             EQU SERCOM2 + I2CS_CTRLB_offset
I2CS2_INTENCLR                          EQU SERCOM2 + I2CS_INTENCLR_offset
I2CS2_INTENSET                          EQU SERCOM2 + I2CS_INTENSET_offset
I2CS2_INTFLAG                           EQU SERCOM2 + I2CS_INTFLAG_offset
I2CS2_STATUS                            EQU SERCOM2 + I2CS_STATUS_offset
I2CS2_SYNCBUSY                          EQU SERCOM2 + I2CS_SYNCBUSY_offset
I2CS2_ADDR                              EQU SERCOM2 + I2CS_ADDR_offset
I2CS2_DATA                              EQU SERCOM2 + I2CS_DATA_offset

I2CS3_CTRLA                             EQU SERCOM3 + I2CS_CTRLA_offset
I2CS3_CTRLB                             EQU SERCOM3 + I2CS_CTRLB_offset
I2CS3_INTENCLR                          EQU SERCOM3 + I2CS_INTENCLR_offset
I2CS3_INTENSET                          EQU SERCOM3 + I2CS_INTENSET_offset
I2CS3_INTFLAG                           EQU SERCOM3 + I2CS_INTFLAG_offset
I2CS3_STATUS                            EQU SERCOM3 + I2CS_STATUS_offset
I2CS3_SYNCBUSY                          EQU SERCOM3 + I2CS_SYNCBUSY_offset
I2CS3_ADDR                              EQU SERCOM3 + I2CS_ADDR_offset
I2CS3_DATA                              EQU SERCOM3 + I2CS_DATA_offset

I2CS4_CTRLA                             EQU SERCOM4 + I2CS_CTRLA_offset
I2CS4_CTRLB                             EQU SERCOM4 + I2CS_CTRLB_offset
I2CS4_INTENCLR                          EQU SERCOM4 + I2CS_INTENCLR_offset
I2CS4_INTENSET                          EQU SERCOM4 + I2CS_INTENSET_offset
I2CS4_INTFLAG                           EQU SERCOM4 + I2CS_INTFLAG_offset
I2CS4_STATUS                            EQU SERCOM4 + I2CS_STATUS_offset
I2CS4_SYNCBUSY                          EQU SERCOM4 + I2CS_SYNCBUSY_offset
I2CS4_ADDR                              EQU SERCOM4 + I2CS_ADDR_offset
I2CS4_DATA                              EQU SERCOM4 + I2CS_DATA_offset

I2CS5_CTRLA                             EQU SERCOM5 + I2CS_CTRLA_offset
I2CS5_CTRLB                             EQU SERCOM5 + I2CS_CTRLB_offset
I2CS5_INTENCLR                          EQU SERCOM5 + I2CS_INTENCLR_offset
I2CS5_INTENSET                          EQU SERCOM5 + I2CS_INTENSET_offset
I2CS5_INTFLAG                           EQU SERCOM5 + I2CS_INTFLAG_offset
I2CS5_STATUS                            EQU SERCOM5 + I2CS_STATUS_offset
I2CS5_SYNCBUSY                          EQU SERCOM5 + I2CS_SYNCBUSY_offset
I2CS5_ADDR                              EQU SERCOM5 + I2CS_ADDR_offset
I2CS5_DATA                              EQU SERCOM5 + I2CS_DATA_offset


I2CS_CTRLA_SWRST                        EQU BIT_POS_0
I2CS_CTRLA_ENABLE                       EQU BIT_POS_1
I2CS_CTRLA_MODE_USART_EXT_CLK           EQU 0x00
I2CS_CTRLA_MODE_USART_INT_CLK           EQU 0x04
I2CS_CTRLA_MODE_SPI_SLAVE               EQU 0x08
I2CS_CTRLA_MODE_SPI_MASTER              EQU 0x0c
I2CS_CTRLA_MODE_I2C_SLAVE               EQU 0x10
I2CS_CTRLA_MODE_I2C_MASTER              EQU 0x14
I2CS_CTRLA_RUNSTDBY                     EQU BIT_POS_7
I2CS_CTRLA_PINOUT                       EQU BIT_POS_16
I2CS_CTRLA_SDAHOLD                      EQU 0x0
I2CS_CTRLA_SDAHOLD_Pos                  EQU 20
I2CS_CTRLA_SEXTTOEN                     EQU BIT_POS_23
I2CS_CTRLA_SPEED                        EQU 0x0
I2CS_CTRLA_SPEED_Pos                    EQU 24
I2CS_CTRLA_SCLSM                        EQU BIT_POS_27
I2CS_CTRLA_LOWTOUTEN                    EQU BIT_POS_30

I2CS_CTRLB_SMEN                         EQU BIT_POS_8
I2CS_CTRLB_GCMD                         EQU BIT_POS_9
I2CS_CTRLB_AACKEN                       EQU BIT_POS_10
I2CS_CTRLB_AMODE                        EQU 0x0
I2CS_CTRLB_AMODE_Pos                    EQU 14
I2CS_CTRLB_CMD                          EQU 0x0
I2CS_CTRLB_CMD_Pos                      EQU 16
I2CS_CTRLB_ACKACT                       EQU BIT_POS_18

I2CS_INTENCLR_PREC                      EQU BIT_POS_0
I2CS_INTENCLR_AMATCH                    EQU BIT_POS_1
I2CS_INTENCLR_DRDY                      EQU BIT_POS_2
I2CS_INTENCLR_ERROR                     EQU BIT_POS_7

I2CS_INTENSET_PREC                      EQU BIT_POS_0
I2CS_INTENSET_AMATCH                    EQU BIT_POS_1
I2CS_INTENSET_DRDY                      EQU BIT_POS_2
I2CS_INTENSET_ERROR                     EQU BIT_POS_7

I2CS_INTFLAG_PREC                       EQU BIT_POS_0
I2CS_INTFLAG_AMATCH                     EQU BIT_POS_1
I2CS_INTFLAG_DRDY                       EQU BIT_POS_2
I2CS_INTFLAG_ERROR                      EQU BIT_POS_7

I2CS_STATUS_BUSERR                      EQU BIT_POS_0
I2CS_STATUS_COLL                        EQU BIT_POS_1
I2CS_STATUS_RXNACK                      EQU BIT_POS_2
I2CS_STATUS_DIR                         EQU BIT_POS_3
I2CS_STATUS_SR                          EQU BIT_POS_4
I2CS_STATUS_LOWTOUT                     EQU BIT_POS_6
I2CS_STATUS_CLKHOLD                     EQU BIT_POS_7
I2CS_STATUS_SEXTTOUT                    EQU BIT_POS_9
I2CS_STATUS_HS                          EQU BIT_POS_10

I2CS_ADDR_GENCEN                        EQU BIT_POS_0
I2CS_ADDR_ADDR                          EQU 0x00
I2CS_ADDR_ADDR_Pos                      EQU 1
I2CS_ADDR_TENBITEN                      EQU BIT_POS_15
I2CS_ADDR_ADDRMASK                      EQU 0x00
I2CS_ADDR_ADDRMASK_Pos                  EQU 17

I2CS_DATA_DATA                          EQU 0x00
I2CS_DATA_DATA_Pos                      EQU 0





; SPI
SPI_CTRLA_offset                        EQU 0x00
SPI_CTRLB_offset                        EQU 0x04
SPI_BAUD_offset                         EQU 0x0c
SPI_INTENCLR_offset                     EQU 0x14
SPI_INTENSET_offset                     EQU 0x16
SPI_INTFLAG_offset                      EQU 0x18
SPI_STATUS_offset                       EQU 0x1a
SPI_SYNCBUSY_offset                     EQU 0x1c
SPI_ADDR_offset                         EQU 0x24
SPI_DATA_offset                         EQU 0x28
SPI_DBGCTRL_offset                      EQU 0x30

SPI0_CTRLA                              EQU SERCOM0 + SPI_CTRLA_offset
SPI0_CTRLB                              EQU SERCOM0 + SPI_CTRLB_offset
SPI0_BAUD                               EQU SERCOM0 + SPI_BAUD_offset
SPI0_INTENCLR                           EQU SERCOM0 + SPI_INTENCLR_offset
SPI0_INTENSET                           EQU SERCOM0 + SPI_INTENSET_offset
SPI0_INTFLAG                            EQU SERCOM0 + SPI_INTFLAG_offset
SPI0_STATUS                             EQU SERCOM0 + SPI_STATUS_offset
SPI0_SYNCBUSY                           EQU SERCOM0 + SPI_SYNCBUSY_offset
SPI0_ADDR                               EQU SERCOM0 + SPI_ADDR_offset
SPI0_DATA                               EQU SERCOM0 + SPI_DATA_offset
SPI0_DBGCTRL                            EQU SERCOM0 + SPI_DBGCTRL_offset

SPI1_CTRLA                              EQU SERCOM1 + SPI_CTRLA_offset
SPI1_CTRLB                              EQU SERCOM1 + SPI_CTRLB_offset
SPI1_BAUD                               EQU SERCOM1 + SPI_BAUD_offset
SPI1_INTENCLR                           EQU SERCOM1 + SPI_INTENCLR_offset
SPI1_INTENSET                           EQU SERCOM1 + SPI_INTENSET_offset
SPI1_INTFLAG                            EQU SERCOM1 + SPI_INTFLAG_offset
SPI1_STATUS                             EQU SERCOM1 + SPI_STATUS_offset
SPI1_SYNCBUSY                           EQU SERCOM1 + SPI_SYNCBUSY_offset
SPI1_ADDR                               EQU SERCOM1 + SPI_ADDR_offset
SPI1_DATA                               EQU SERCOM1 + SPI_DATA_offset
SPI1_DBGCTRL                            EQU SERCOM1 + SPI_DBGCTRL_offset

SPI2_CTRLA                              EQU SERCOM2 + SPI_CTRLA_offset
SPI2_CTRLB                              EQU SERCOM2 + SPI_CTRLB_offset
SPI2_BAUD                               EQU SERCOM2 + SPI_BAUD_offset
SPI2_INTENCLR                           EQU SERCOM2 + SPI_INTENCLR_offset
SPI2_INTENSET                           EQU SERCOM2 + SPI_INTENSET_offset
SPI2_INTFLAG                            EQU SERCOM2 + SPI_INTFLAG_offset
SPI2_STATUS                             EQU SERCOM2 + SPI_STATUS_offset
SPI2_SYNCBUSY                           EQU SERCOM2 + SPI_SYNCBUSY_offset
SPI2_ADDR                               EQU SERCOM2 + SPI_ADDR_offset
SPI2_DATA                               EQU SERCOM2 + SPI_DATA_offset
SPI2_DBGCTRL                            EQU SERCOM2 + SPI_DBGCTRL_offset

SPI3_CTRLA                              EQU SERCOM3 + SPI_CTRLA_offset
SPI3_CTRLB                              EQU SERCOM3 + SPI_CTRLB_offset
SPI3_BAUD                               EQU SERCOM3 + SPI_BAUD_offset
SPI3_INTENCLR                           EQU SERCOM3 + SPI_INTENCLR_offset
SPI3_INTENSET                           EQU SERCOM3 + SPI_INTENSET_offset
SPI3_INTFLAG                            EQU SERCOM3 + SPI_INTFLAG_offset
SPI3_STATUS                             EQU SERCOM3 + SPI_STATUS_offset
SPI3_SYNCBUSY                           EQU SERCOM3 + SPI_SYNCBUSY_offset
SPI3_ADDR                               EQU SERCOM3 + SPI_ADDR_offset
SPI3_DATA                               EQU SERCOM3 + SPI_DATA_offset
SPI3_DBGCTRL                            EQU SERCOM3 + SPI_DBGCTRL_offset

SPI4_CTRLA                              EQU SERCOM4 + SPI_CTRLA_offset
SPI4_CTRLB                              EQU SERCOM4 + SPI_CTRLB_offset
SPI4_BAUD                               EQU SERCOM4 + SPI_BAUD_offset
SPI4_INTENCLR                           EQU SERCOM4 + SPI_INTENCLR_offset
SPI4_INTENSET                           EQU SERCOM4 + SPI_INTENSET_offset
SPI4_INTFLAG                            EQU SERCOM4 + SPI_INTFLAG_offset
SPI4_STATUS                             EQU SERCOM4 + SPI_STATUS_offset
SPI4_SYNCBUSY                           EQU SERCOM4 + SPI_SYNCBUSY_offset
SPI4_ADDR                               EQU SERCOM4 + SPI_ADDR_offset
SPI4_DATA                               EQU SERCOM4 + SPI_DATA_offset
SPI4_DBGCTRL                            EQU SERCOM4 + SPI_DBGCTRL_offset

SPI5_CTRLA                              EQU SERCOM5 + SPI_CTRLA_offset
SPI5_CTRLB                              EQU SERCOM5 + SPI_CTRLB_offset
SPI5_BAUD                               EQU SERCOM5 + SPI_BAUD_offset
SPI5_INTENCLR                           EQU SERCOM5 + SPI_INTENCLR_offset
SPI5_INTENSET                           EQU SERCOM5 + SPI_INTENSET_offset
SPI5_INTFLAG                            EQU SERCOM5 + SPI_INTFLAG_offset
SPI5_STATUS                             EQU SERCOM5 + SPI_STATUS_offset
SPI5_SYNCBUSY                           EQU SERCOM5 + SPI_SYNCBUSY_offset
SPI5_ADDR                               EQU SERCOM5 + SPI_ADDR_offset
SPI5_DATA                               EQU SERCOM5 + SPI_DATA_offset
SPI5_DBGCTRL                            EQU SERCOM5 + SPI_DBGCTRL_offset


SPI_CTRLA_SWRST                         EQU BIT_POS_0
SPI_CTRLA_ENABLE                        EQU BIT_POS_1
SPI_CTRLA_MODE_USART_EXT_CLK            EQU 0x00
SPI_CTRLA_MODE_USART_INT_CLK            EQU 0x04
SPI_CTRLA_MODE_SPI_SLAVE                EQU 0x08
SPI_CTRLA_MODE_SPI_MASTER               EQU 0x0c
SPI_CTRLA_MODE_I2C_SLAVE                EQU 0x10
SPI_CTRLA_MODE_I2C_MASTER               EQU 0x14
SPI_CTRLA_RUNSTDBY                      EQU BIT_POS_7
SPI_CTRLA_IBON                          EQU BIT_POS_8
SPI_CTRLA_DOPO                          EQU 0x0
SPI_CTRLA_DOPO_Pos                      EQU 16
SPI_CTRLA_DIPO                          EQU 0x0
SPI_CTRLA_DIPO_Pos                      EQU 20
SPI_CTRLA_FORM                          EQU 0x0
SPI_CTRLA_FORM_Pos                      EQU 24
SPI_CTRLA_CPHA                          EQU BIT_POS_28
SPI_CTRLA_CPOL                          EQU BIT_POS_29
SPI_CTRLA_DORD                          EQU BIT_POS_30

SPI_CTRLB_CHSIZE                        EQU 0x0
SPI_CTRLB_CHSIZE_Pos                    EQU 0
SPI_CTRLB_PLOADEN                       EQU BIT_POS_6
SPI_CTRLB_SSDE                          EQU BIT_POS_9
SPI_CTRLB_MSSEN                         EQU BIT_POS_13
SPI_CTRLB_AMODE                         EQU 0x0
SPI_CTRLB_AMODE_Pos                     EQU 14
SPI_CTRLB_RXEN                          EQU BIT_POS_17

SPI_BAUD_BAUD                           EQU 0x00
SPI_BAUD_BAUD_Pos                       EQU 0

SPI_INTENCLR_DRE                        EQU BIT_POS_0
SPI_INTENCLR_TXC                        EQU BIT_POS_1
SPI_INTENCLR_RXC                        EQU BIT_POS_2
SPI_INTENCLR_SSL                        EQU BIT_POS_3
SPI_INTENCLR_ERROR                      EQU BIT_POS_7

SPI_INTENSET_DRE                        EQU BIT_POS_0
SPI_INTENSET_TXC                        EQU BIT_POS_1
SPI_INTENSET_RXC                        EQU BIT_POS_2
SPI_INTENSET_SSL                        EQU BIT_POS_3
SPI_INTENSET_ERROR                      EQU BIT_POS_7

SPI_INTFLAG_DRE                         EQU BIT_POS_0
SPI_INTFLAG_DRE_Pos                     EQU 0
SPI_INTFLAG_TXC                         EQU BIT_POS_1
SPI_INTFLAG_TXC_Pos                     EQU 1
SPI_INTFLAG_RXC                         EQU BIT_POS_2
SPI_INTFLAG_RXC_Pos                     EQU 2
SPI_INTFLAG_SSL                         EQU BIT_POS_3
SPI_INTFLAG_SSL_Pos                     EQU 3
SPI_INTFLAG_ERROR                       EQU BIT_POS_7
SPI_INTFLAG_ERROR_Pos                   EQU 7

SPI_STATUS_BUFOVF                       EQU BIT_POS_2
SPI_STATUS_BUFOVF_Pos                   EQU 2

SPI_SYNCBUSY_SWRST                      EQU BIT_POS_0
SPI_SYNCBUSY_SWRST_Pos                  EQU 0
SPI_SYNCBUSY_ENABLE                     EQU BIT_POS_1
SPI_SYNCBUSY_ENABLE_Pos                 EQU 1
SPI_SYNCBUSY_CTRLB                      EQU BIT_POS_2
SPI_SYNCBUSY_CTRLB_Pos                  EQU 2

SPI_ADDR_ADDR                           EQU 0x00
SPI_ADDR_ADDR_Pos                       EQU 0
SPI_ADDR_ADDRMASK                       EQU 0x00
SPI_ADDR_ADDRMASK_Pos                   EQU 16

SPI_DATA_DATA                           EQU 0x00
SPI_DATA_DATA_Pos                       EQU 0

SPI_DBGCTRL_DBGSTOP                     EQU BIT_POS_0









; USART
USART_CTRLA_offset                      EQU 0x00
USART_CTRLB_offset                      EQU 0x04
USART_BAUD_offset                       EQU 0x0c
USART_BAUD_FRAC_MODE_offset             EQU 0x0c
USART_BAUD_FRACFP_MODE_offset           EQU 0x0c
USART_BAUD_USARTFP_MODE_offset          EQU 0x0c
USART_RXPL_offset                       EQU 0x0e
USART_INTENCLR_offset                   EQU 0x14
USART_INTENSET_offset                   EQU 0x16
USART_INTFLAG_offset                    EQU 0x18
USART_STATUS_offset                     EQU 0x1a
USART_SYNCBUSY_offset                   EQU 0x1c
USART_DATA_offset                       EQU 0x28
USART_DBGCTRL_offset                    EQU 0x30

USART0_CTRLA                            EQU SERCOM0 + USART_CTRLA_offset
USART0_CTRLB                            EQU SERCOM0 + USART_CTRLB_offset
USART0_BAUD                             EQU SERCOM0 + USART_BAUD_offset
USART0_BAUD_FRAC_MODE                   EQU SERCOM0 + USART_BAUD_FRAC_MODE_offset
USART0_BAUD_FRACFP_MODE                 EQU SERCOM0 + USART_BAUD_FRACFP_MODE_offset
USART0_BAUD_USARTFP_MODE                EQU SERCOM0 + USART_BAUD_USARTFP_MODE_offset
USART0_RXPL                             EQU SERCOM0 + USART_RXPL_offset
USART0_INTENCLR                         EQU SERCOM0 + USART_INTENCLR_offset
USART0_INTENSET                         EQU SERCOM0 + USART_INTENSET_offset
USART0_INTFLAG                          EQU SERCOM0 + USART_INTFLAG_offset
USART0_STATUS                           EQU SERCOM0 + USART_STATUS_offset
USART0_SYNCBUSY                         EQU SERCOM0 + USART_SYNCBUSY_offset
USART0_DATA                             EQU SERCOM0 + USART_DATA_offset
USART0_DBGCTRL                          EQU SERCOM0 + USART_DBGCTRL_offset

USART1_CTRLA                            EQU SERCOM1 + USART_CTRLA_offset
USART1_CTRLB                            EQU SERCOM1 + USART_CTRLB_offset
USART1_BAUD                             EQU SERCOM1 + USART_BAUD_offset
USART1_BAUD_FRAC_MODE                   EQU SERCOM1 + USART_BAUD_FRAC_MODE_offset
USART1_BAUD_FRACFP_MODE                 EQU SERCOM1 + USART_BAUD_FRACFP_MODE_offset
USART1_BAUD_USARTFP_MODE                EQU SERCOM1 + USART_BAUD_USARTFP_MODE_offset
USART1_RXPL                             EQU SERCOM1 + USART_RXPL_offset
USART1_INTENCLR                         EQU SERCOM1 + USART_INTENCLR_offset
USART1_INTENSET                         EQU SERCOM1 + USART_INTENSET_offset
USART1_INTFLAG                          EQU SERCOM1 + USART_INTFLAG_offset
USART1_STATUS                           EQU SERCOM1 + USART_STATUS_offset
USART1_SYNCBUSY                         EQU SERCOM1 + USART_SYNCBUSY_offset
USART1_DATA                             EQU SERCOM1 + USART_DATA_offset
USART1_DBGCTRL                          EQU SERCOM1 + USART_DBGCTRL_offset

USART2_CTRLA                            EQU SERCOM2 + USART_CTRLA_offset
USART2_CTRLB                            EQU SERCOM2 + USART_CTRLB_offset
USART2_BAUD                             EQU SERCOM2 + USART_BAUD_offset
USART2_BAUD_FRAC_MODE                   EQU SERCOM2 + USART_BAUD_FRAC_MODE_offset
USART2_BAUD_FRACFP_MODE                 EQU SERCOM2 + USART_BAUD_FRACFP_MODE_offset
USART2_BAUD_USARTFP_MODE                EQU SERCOM2 + USART_BAUD_USARTFP_MODE_offset
USART2_RXPL                             EQU SERCOM2 + USART_RXPL_offset
USART2_INTENCLR                         EQU SERCOM2 + USART_INTENCLR_offset
USART2_INTENSET                         EQU SERCOM2 + USART_INTENSET_offset
USART2_INTFLAG                          EQU SERCOM2 + USART_INTFLAG_offset
USART2_STATUS                           EQU SERCOM2 + USART_STATUS_offset
USART2_SYNCBUSY                         EQU SERCOM2 + USART_SYNCBUSY_offset
USART2_DATA                             EQU SERCOM2 + USART_DATA_offset
USART2_DBGCTRL                          EQU SERCOM2 + USART_DBGCTRL_offset

USART3_CTRLA                            EQU SERCOM3 + USART_CTRLA_offset
USART3_CTRLB                            EQU SERCOM3 + USART_CTRLB_offset
USART3_BAUD                             EQU SERCOM3 + USART_BAUD_offset
USART3_BAUD_FRAC_MODE                   EQU SERCOM3 + USART_BAUD_FRAC_MODE_offset
USART3_BAUD_FRACFP_MODE                 EQU SERCOM3 + USART_BAUD_FRACFP_MODE_offset
USART3_BAUD_USARTFP_MODE                EQU SERCOM3 + USART_BAUD_USARTFP_MODE_offset
USART3_RXPL                             EQU SERCOM3 + USART_RXPL_offset
USART3_INTENCLR                         EQU SERCOM3 + USART_INTENCLR_offset
USART3_INTENSET                         EQU SERCOM3 + USART_INTENSET_offset
USART3_INTFLAG                          EQU SERCOM3 + USART_INTFLAG_offset
USART3_STATUS                           EQU SERCOM3 + USART_STATUS_offset
USART3_SYNCBUSY                         EQU SERCOM3 + USART_SYNCBUSY_offset
USART3_DATA                             EQU SERCOM3 + USART_DATA_offset
USART3_DBGCTRL                          EQU SERCOM3 + USART_DBGCTRL_offset

USART4_CTRLA                            EQU SERCOM4 + USART_CTRLA_offset
USART4_CTRLB                            EQU SERCOM4 + USART_CTRLB_offset
USART4_BAUD                             EQU SERCOM4 + USART_BAUD_offset
USART4_BAUD_FRAC_MODE                   EQU SERCOM4 + USART_BAUD_FRAC_MODE_offset
USART4_BAUD_FRACFP_MODE                 EQU SERCOM4 + USART_BAUD_FRACFP_MODE_offset
USART4_BAUD_USARTFP_MODE                EQU SERCOM4 + USART_BAUD_USARTFP_MODE_offset
USART4_RXPL                             EQU SERCOM4 + USART_RXPL_offset
USART4_INTENCLR                         EQU SERCOM4 + USART_INTENCLR_offset
USART4_INTENSET                         EQU SERCOM4 + USART_INTENSET_offset
USART4_INTFLAG                          EQU SERCOM4 + USART_INTFLAG_offset
USART4_STATUS                           EQU SERCOM4 + USART_STATUS_offset
USART4_SYNCBUSY                         EQU SERCOM4 + USART_SYNCBUSY_offset
USART4_DATA                             EQU SERCOM4 + USART_DATA_offset
USART4_DBGCTRL                          EQU SERCOM4 + USART_DBGCTRL_offset

USART5_CTRLA                            EQU SERCOM5 + USART_CTRLA_offset
USART5_CTRLB                            EQU SERCOM5 + USART_CTRLB_offset
USART5_BAUD                             EQU SERCOM5 + USART_BAUD_offset
USART5_BAUD_FRAC_MODE                   EQU SERCOM5 + USART_BAUD_FRAC_MODE_offset
USART5_BAUD_FRACFP_MODE                 EQU SERCOM5 + USART_BAUD_FRACFP_MODE_offset
USART5_BAUD_USARTFP_MODE                EQU SERCOM5 + USART_BAUD_USARTFP_MODE_offset
USART5_RXPL                             EQU SERCOM5 + USART_RXPL_offset
USART5_INTENCLR                         EQU SERCOM5 + USART_INTENCLR_offset
USART5_INTENSET                         EQU SERCOM5 + USART_INTENSET_offset
USART5_INTFLAG                          EQU SERCOM5 + USART_INTFLAG_offset
USART5_STATUS                           EQU SERCOM5 + USART_STATUS_offset
USART5_SYNCBUSY                         EQU SERCOM5 + USART_SYNCBUSY_offset
USART5_DATA                             EQU SERCOM5 + USART_DATA_offset
USART5_DBGCTRL                          EQU SERCOM5 + USART_DBGCTRL_offset

USART_CTRLA_SWRST                       EQU BIT_POS_0
USART_CTRLA_ENABLE                      EQU BIT_POS_1
USART_CTRLA_MODE_USART_EXT_CLK          EQU 0x00
USART_CTRLA_MODE_USART_INT_CLK          EQU 0x04
USART_CTRLA_MODE_SPI_SLAVE              EQU 0x08
USART_CTRLA_MODE_SPI_MASTER             EQU 0x0c
USART_CTRLA_MODE_I2C_SLAVE              EQU 0x10
USART_CTRLA_MODE_I2C_MASTER             EQU 0x14
USART_CTRLA_RUNSTDBY                    EQU BIT_POS_7
USART_CTRLA_IBON                        EQU BIT_POS_8
USART_CTRLA_SAMPR                       EQU 0x0
USART_CTRLA_SAMPR_Pos                   EQU 13
USART_CTRLA_TXPO                        EQU 0x0
USART_CTRLA_TXPO_Pos                    EQU 16
USART_CTRLA_RXPO                        EQU 0x0
USART_CTRLA_RXPO_Pos                    EQU 20
USART_CTRLA_SAMPA                       EQU 0x0
USART_CTRLA_SAMPA_Pos                   EQU 22
USART_CTRLA_FORM                        EQU 0x0
USART_CTRLA_FORM_Pos                    EQU 24
USART_CTRLA_CMODE                       EQU BIT_POS_28
USART_CTRLA_CPOL                        EQU BIT_POS_29
USART_CTRLA_DORD                        EQU BIT_POS_30

USART_BAUD_BAUD                         EQU 0x00
USART_BAUD_BAUD_Pos                     EQU 0

USART_BAUD_FRAC_MODE_BAUD               EQU 0x00
USART_BAUD_FRAC_MODE_BAUD_Pos           EQU 0
USART_BAUD_FRAC_MODE_FP                 EQU 0x0
USART_BAUD_FRAC_MODE_FP_Pos             EQU 13

USART_BAUD_FRACFP_MODE_BAUD             EQU 0x00
USART_BAUD_FRACFP_MODE_BAUD_Pos         EQU 0
USART_BAUD_FRACFP_MODE_FP               EQU 0x0
USART_BAUD_FRACFP_MODE_FP_Pos           EQU 13

USART_BAUD_USARTFP_MODE_BAUD            EQU 0x00
USART_BAUD_USARTFP_MODE_BAUD_Pos        EQU 0

USART_RXPL_RXPL                         EQU 0x00
USART_RXPL_RXPL_Pos                     EQU 0

USART_INTENCLR_DRE                      EQU BIT_POS_0
USART_INTENCLR_TXC                      EQU BIT_POS_1
USART_INTENCLR_RXC                      EQU BIT_POS_2
USART_INTENCLR_RXS                      EQU BIT_POS_3
USART_INTENCLR_CTSIC                    EQU BIT_POS_4
USART_INTENCLR_RXBRK                    EQU BIT_POS_5
USART_INTENCLR_ERROR                    EQU BIT_POS_7

USART_INTENSET_DRE                      EQU BIT_POS_0
USART_INTENSET_TXC                      EQU BIT_POS_1
USART_INTENSET_RXC                      EQU BIT_POS_2
USART_INTENSET_RXS                      EQU BIT_POS_3
USART_INTENSET_CTSIC                    EQU BIT_POS_4
USART_INTENSET_RXBRK                    EQU BIT_POS_5
USART_INTENSET_ERROR                    EQU BIT_POS_7

USART_INTFLAG_DRE                       EQU BIT_POS_0
USART_INTFLAG_TXC                       EQU BIT_POS_1
USART_INTFLAG_RXC                       EQU BIT_POS_2
USART_INTFLAG_RXS                       EQU BIT_POS_3
USART_INTFLAG_CTSIC                     EQU BIT_POS_4
USART_INTFLAG_RXBRK                     EQU BIT_POS_5
USART_INTFLAG_ERROR                     EQU BIT_POS_7

USART_STATUS_PERR                       EQU BIT_POS_0
USART_STATUS_FERR                       EQU BIT_POS_1
USART_STATUS_BUFOVF                     EQU BIT_POS_2
USART_STATUS_CTS                        EQU BIT_POS_3
USART_STATUS_ISF                        EQU BIT_POS_4
USART_STATUS_COLL                       EQU BIT_POS_5

USART_SYNCBUSY_SWRST                    EQU BIT_POS_0
USART_SYNCBUSY_ENABLE                   EQU BIT_POS_1
USART_SYNCBUSY_CTRLB                    EQU BIT_POS_2

USART_DATA_DATA                         EQU 0x00
USART_DATA_DATA_Pos                     EQU 0

USART_DBGCTRL_DBGSTOP                   EQU BIT_POS_0


  END
