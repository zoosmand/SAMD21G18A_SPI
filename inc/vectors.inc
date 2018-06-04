__Vectors 
  DCD	__initial_sp                ; Top of Stack 0x0000
  DCD	Reset_HANDLER               ; Reset Handler 0x0004
  DCD	NMI_HANDLER                 ; NMI Handler 0x0008
  DCD	HardFault_HANDLER           ; Hard Fault Handler 0x000c
  DCD	0                           ; Reserved 0x0010
  DCD	0                           ; Reserved 0x0014
  DCD	0                           ; Reserved 0x0018
  DCD	0                           ; Reserved 0x001c
  DCD	0                           ; Reserved 0x0020
  DCD	0                           ; Reserved 0x0024
  DCD	0                           ; Reserved 0x0028
  DCD	SVC_HANDLER                 ; SVCall Handler 0x002c
  DCD	0                           ; Reserved 0x0030
  DCD	0                           ; Reserved 0x0034
  DCD	PendSV_HANDLER              ; PendSV Handler 0x0038
  DCD	SysTick_HANDLER             ; SysTick Handler 0x003c

  ;/* Peripheral handlers */
  DCD PM_HANDLER                  ;/*  0 Power Manager */
  DCD SYSCTRL_HANDLER             ;/*  1 System Control */
  DCD WDT_HANDLER                 ;/*  2 Watchdog Timer */
  DCD RTC_HANDLER                 ;/*  3 Real-Time Counter */
  DCD EIC_HANDLER                 ;/*  4 External Interrupt Controller */
  DCD NVMCTRL_HANDLER             ;/*  5 Non-Volatile Memory Controller */
  DCD DMAC_HANDLER                ;/*  6 Direct Memory Access Controller */
  DCD USB_HANDLER                 ;/*  7 Universal Serial Bus */
  DCD EVSYS_HANDLER               ;/*  8 Event System Interface */
  DCD SERCOM0_HANDLER             ;/*  9 Serial Communication Interface 0 */
  DCD SERCOM1_HANDLER             ;/* 10 Serial Communication Interface 1 */
  DCD SERCOM2_HANDLER             ;/* 11 Serial Communication Interface 2 */
  DCD SERCOM3_HANDLER             ;/* 12 Serial Communication Interface 3 */
  DCD SERCOM4_HANDLER             ;/* 13 Serial Communication Interface 4 */
  DCD SERCOM5_HANDLER             ;/* 14 Serial Communication Interface 5 */
  DCD TCC0_HANDLER                ;/* 15 Timer Counter Control 0 */
  DCD TCC1_HANDLER                ;/* 16 Timer Counter Control 1 */
  DCD TCC2_HANDLER                ;/* 17 Timer Counter Control 2 */
  DCD TC3_HANDLER                 ;/* 18 Basic Timer Counter 3 */
  DCD TC4_HANDLER                 ;/* 19 Basic Timer Counter 4 */
  DCD TC5_HANDLER                 ;/* 20 Basic Timer Counter 5 */
  DCD 0
  DCD 0
  DCD ADC_HANDLER                 ;/* 23 Analog Digital Converter */
  DCD AC_HANDLER                  ;/* 24 Analog Comparators */
  DCD DAC_HANDLER                 ;/* 25 Digital Analog Converter */
  DCD PTC_HANDLER                 ;/* 26 Peripheral Touch Controller */
  DCD I2S_HANDLER                 ;/* 27 Inter-IC Sound Interface */
  DCD 0


  AREA |.text|, CODE, READONLY

  ;/****************************************************************/
  ;/*************** Unused Interrupt Vector Handlers ***************/
  ;/****************************************************************/								
NMI_HANDLER
HardFault_HANDLER
SVC_HANDLER
PendSV_HANDLER
;SysTick_HANDLER
PM_HANDLER
SYSCTRL_HANDLER
WDT_HANDLER
RTC_HANDLER
EIC_HANDLER
NVMCTRL_HANDLER
DMAC_HANDLER
USB_HANDLER
EVSYS_HANDLER
SERCOM0_HANDLER
SERCOM1_HANDLER
SERCOM2_HANDLER
SERCOM3_HANDLER
SERCOM4_HANDLER
SERCOM5_HANDLER
TCC0_HANDLER
TCC1_HANDLER
TCC2_HANDLER
;TC3_HANDLER
;TC4_HANDLER
TC5_HANDLER
ADC_HANDLER
AC_HANDLER
DAC_HANDLER
PTC_HANDLER
I2S_HANDLER
  B Reset_HANDLER

  END
