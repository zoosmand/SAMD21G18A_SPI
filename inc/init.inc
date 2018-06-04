Reset_HANDLER PROC
  NOP
  NOP
  NOP
  NOP
  NOP

  ; Clear registers
  REG "clear", _EREG_, 0xffffffff



;======================= Init SYSCTRL =========================;
  LDR tmpa, =SYSCTRL
; Internal 8M oscillator, remove divider
  LDR tmpd, [tmpa, #SYSCTRL_OSC8M_offset]
  LDR tmp, =\
    SYSCTRL_OSC8M_PRESC_1 \
  | SYSCTRL_OSC8M_PRESC_MASK
  ANDS tmpd, tmp
  STR tmpd, [tmpa, #SYSCTRL_OSC8M_offset]
_INIT_SYSCTRL_wait_OSC8M
  LDR tmpd, [tmpa, #SYSCTRL_PCLKSR_offset]
  LSRS tmpd, #SYSCTRL_PCLKSR_OSC8MRDY_Pos + 1
  BCC _INIT_SYSCTRL_wait_OSC8M


; External 32K Crystal oscillator
;--------------------------------------------------------------;
x32kStartup	EQU 0x05 << SYSCTRL_XOSC32K_STARTUP_Pos
  LDR tmpd, [tmpa, #SYSCTRL_XOSC32K_offset]
  ;--;
  LDR tmp, =SYSCTRL_XOSC32K_ONDEMAND
  BICS tmpd, tmp
  LDR tmp, =\
    SYSCTRL_XOSC32K_ENABLE \
  | SYSCTRL_XOSC32K_XTALEN \
  | SYSCTRL_XOSC32K_EN32K \
  | SYSCTRL_XOSC32K_RUNSTDBY \
  | x32kStartup
  ORRS tmpd, tmp
  STR tmpd, [tmpa, #SYSCTRL_XOSC32K_offset]
  ;--;
_INIT_SYSCTRL_wait_XOSC32K
  LDR tmpd, [tmpa, #SYSCTRL_PCLKSR_offset]
  LSRS tmpd, #SYSCTRL_PCLKSR_XOSC32KRDY_Pos + 1
  BCC _INIT_SYSCTRL_wait_XOSC32K


; Internal 32K Crystal oscillator
;--------------------------------------------------------------;
i32kStartup	EQU 0x05 << SYSCTRL_OSC32K_STARTUP_Pos
  LDR tmpd, [tmpa, #SYSCTRL_OSC32K_offset]
  ;--;
  LDR tmp, =SYSCTRL_OSC32K_ONDEMAND
  BICS tmpd, tmp
  LDR tmp, =\
    SYSCTRL_OSC32K_ENABLE \
  | SYSCTRL_OSC32K_EN32K \
  | SYSCTRL_OSC32K_EN1K \
  | SYSCTRL_OSC32K_RUNSTDBY \
  | i32kStartup
  ORRS tmpd, tmp
  STR tmpd, [tmpa, #SYSCTRL_OSC32K_offset]
  ;--;
_INIT_SYSCTRL_wait_OSC32K
  LDR tmpd, [tmpa, #SYSCTRL_PCLKSR_offset]
  LSRS tmpd, #SYSCTRL_PCLKSR_OSC32KRDY_Pos + 1
  BCC _INIT_SYSCTRL_wait_OSC32K
;==============================================================;




;======================== Init GCLK ===========================;
; GEN1 feed by External 32K Crystal oscillator
genId1	EQU 0x01
gen1Div	EQU 0x00
  LDR tmpa, =GCLK
  LDR tmpd, =\
    genId1 << GCLK_GENDIV_ID_Pos \
  | gen1Div << GCLK_GENDIV_DIV_Pos
  STR tmpd, [tmpa, #GCLK_GENDIV_offset]

_INIT_GCLK_wait_sync_GEN1_DIV
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_sync_GEN1_DIV

  LDR tmpd, =\
    genId1 << GCLK_GENCTRL_ID_Pos \
  | GCLK_GENCTRL_SRC_XOSC32K \
  | GCLK_GENCTRL_GENEN
  STR tmpd, [tmpa, #GCLK_GENCTRL_offset]

_INIT_GCLK_wait_sync_GEN1
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_sync_GEN1


;!!!!!!!!! RUN DFLL 48MHz !!!!!!!!!!!
; First create GEN0 feed by DFLL48M
;--------------------------------------------------------------;
genId0 	EQU 0x00
gen0Div	EQU 0x00 ; no divide. full speed on ~ 48MHz 
  LDR tmpa, =GCLK
  LDR tmpd, =\
    genId0 << GCLK_GENDIV_ID_Pos \
  | gen0Div << GCLK_GENDIV_DIV_Pos
  STR tmpd, [tmpa, #GCLK_GENDIV_offset]

_INIT_GCLK_wait_sync_GEN0_DIV
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_sync_GEN0_DIV

  LDR tmpd, =\
    genId0 << GCLK_GENCTRL_ID_Pos\
  | GCLK_GENCTRL_SRC_DFLL48M \
  | GCLK_GENCTRL_GENEN
  STR tmpd, [tmpa, #GCLK_GENCTRL_offset]

_INIT_GCLK_wait_sync_GEN0
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_sync_GEN0



; Second setup flash to 48MHz latency 
;--------------------------------------------------------------;
  LDR tmpa, =NVMCTRL
  LDR tmpd, =NVMCTRL_CTRLB_RWS_HALF
  STR tmpd, [tmpa, #NVMCTRL_CTRLB_offset]


; Third run DFLL ~48Mhz = 32.768 * 1464.8 (0x05b8 or 0x05b9 as DFLLMUL mutiplify by reference frequency of GEN1)
;--------------------------------------------------------------;
  LDR tmpa, =SYSCTRL
  LDR tmpd, [tmpa, #SYSCTRL_DFLLCTRL_offset]
  LDR tmp, =SYSCTRL_DFLLCTRL_ENABLE
  ORRS tmpd, tmp
  ;	STR tmpd, [tmpa, #SYSCTRL_DFLLCTRL_offset]
  LDR tmp, =SYSCTRL_DFLLCTRL_ONDEMAND
  BICS tmpd, tmp
  STR tmpd, [tmpa, #SYSCTRL_DFLLCTRL_offset]

_INIT_SYSCTRL_wait_DFLL
  LDR tmpd, [tmpa, #SYSCTRL_PCLKSR_offset]
  LSRS tmpd, #SYSCTRL_PCLKSR_DFLLRDY_Pos + 1
  BCC _INIT_SYSCTRL_wait_DFLL

dfllFine		EQU 0x0200 << SYSCTRL_DFLLVAL_FINE_Pos
dfllCoarse	EQU 0x1d << SYSCTRL_DFLLVAL_COARSE_Pos
  LDR tmpd, =\
    dfllFine \
  | dfllCoarse
  STR tmpd, [tmpa, #SYSCTRL_DFLLVAL_offset]

dfllMul			EQU 0x05b9 << SYSCTRL_DFLLMUL_MUL_Pos
dfllFstep		EQU 0x02 << SYSCTRL_DFLLMUL_FSTEP_Pos
dfllCstep		EQU 0x01 << SYSCTRL_DFLLMUL_CSTEP_Pos
  LDR tmpd, =\
    dfllMul \
  | dfllFstep \
  | dfllCstep
  STR tmpd, [tmpa, #SYSCTRL_DFLLMUL_offset]

  LDR tmpd, [tmpa, #SYSCTRL_DFLLCTRL_offset]
  LDR tmp, =\
SYSCTRL_DFLLCTRL_MODE \
  | SYSCTRL_DFLLCTRL_BPLCKC \
  | SYSCTRL_DFLLCTRL_STABLE
  ORRS tmpd, tmp
  STR tmpd, [tmpa, #SYSCTRL_DFLLCTRL_offset]



; Forth run clock ID 0 feed by Generator1
;--------------------------------------------------------------;
  LDR tmpa, =GCLK
  LDR tmpd, =\
    GCLK_CLKCTRL_ID_DFLL48 \
  | GCLK_CLKCTRL_GEN_GCLK1	\
  | GCLK_CLKCTRL_CLKEN
  STRH tmpd, [tmpa, #GCLK_CLKCTRL_offset] 

_INIT_GCLK_wait_GEN0
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_GEN0



;--------------------------------------------------------------;
;--------------------------------------------------------------;
;--------------------------------------------------------------;



; GEN2 feed by internal 32KHz Ultra Low Power Oscillator enable by default	
;--------------------------------------------------------------;
genId2 	EQU 0x02
gen2Div	EQU 0x08 ; max possible divider for OSCULP32K, to make WDT period longer 
  LDR tmpa, =GCLK
  LDR tmpd, =\
    genId2 << GCLK_GENDIV_ID_Pos \
  | gen2Div << GCLK_GENDIV_DIV_Pos
  STR tmpd, [tmpa, #GCLK_GENDIV_offset]

_INIT_GCLK_wait_sync_GEN2_DIV
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_sync_GEN2_DIV



; GEN3 feed by internal 32K Oscillator
;--------------------------------------------------------------;
genId3 	EQU 0x03 << GCLK_GENDIV_ID_Pos
gen3Div	EQU 0x08 << GCLK_GENDIV_DIV_Pos
  LDR tmpa, =GCLK
  LDR tmpd, =\
    genId3 \
  | gen3Div
  STR tmpd, [tmpa, #GCLK_GENDIV_offset]

_INIT_GCLK_wait_sync_GEN3_DIV
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_sync_GEN3_DIV

  LDR tmpd, =\
    genId3 \
  | GCLK_GENCTRL_SRC_OSC32K
  STRH tmpd, [tmpa, #GCLK_GENCTRL_offset] 

_INIT_GCLK_wait_GEN3
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_GEN3

  LDR tmpd, =genId3
  STRB tmpd, [tmpa, #GCLK_GENCTRL_offset]
  LDR tmpd, [tmpa, #GCLK_GENCTRL_offset]

  LDR tmp, =\
    GCLK_GENCTRL_GENEN	\
  | GCLK_GENCTRL_OE \
  | GCLK_GENCTRL_DIVSEL

  ORRS tmpd, tmp
  STR tmpd, [tmpa, #GCLK_GENCTRL_offset] 

_INIT_GCLK_wait_GEN3_run
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_GEN3_run


; GEN4 feed by internal 8M Oscillator 
;--------------------------------------------------------------;
genId4 	EQU 0x04 << GCLK_GENDIV_ID_Pos
gen4Div	EQU 0x00 << GCLK_GENDIV_DIV_Pos
  LDR tmpa, =GCLK
  LDR tmpd, =\
    genId4 \
  | gen4Div
  STR tmpd, [tmpa, #GCLK_GENDIV_offset]

_INIT_GCLK_wait_sync_GEN4_DIV
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_sync_GEN4_DIV

  LDR tmpd, =\
    genId4 \
  | GCLK_GENCTRL_SRC_OSC8M
  STRH tmpd, [tmpa, #GCLK_GENCTRL_offset] 

_INIT_GCLK_wait_GEN4
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_GEN4

  LDR tmpd, =genId4
  STRB tmpd, [tmpa, #GCLK_GENCTRL_offset]
  LDR tmpd, [tmpa, #GCLK_GENCTRL_offset]

  LDR tmp, =GCLK_GENCTRL_GENEN
  ORRS tmpd, tmp
  STR tmpd, [tmpa, #GCLK_GENCTRL_offset] 

_INIT_GCLK_wait_GEN4_run
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_wait_GEN4_run
;==============================================================;



; Enabling peripherals
;========================= Init PM ============================;
  LDR tmpa, =PM	
  LDRB tmpd, [tmpa, #PM_SLEEP_offsef]
  LDR tmp, =PM_SLEEP_IDLE_APB
  ORRS tmpd, tmp
  STRB tmpd, [tmpa, #PM_SLEEP_offsef]

  LDR tmpd, [tmpa, #PM_APBCMASK_offsef]
  LDR tmp, =\
    PM_APBCMASK_TC3 \
  | PM_APBCMASK_TC4 \
  | PM_APBCMASK_TC5 \
  | PM_APBCMASK_SERCOM1
  ORRS tmpd, tmp
  STR tmpd, [tmpa, #PM_APBCMASK_offsef]
;==============================================================;



; Enabling peripheral clocks
;==============================================================;
; Timer 2-3 feed by GEN2 (OCLULP32K)
	LDR tmpa, =GCLK
	LDR tmpd, =\
		GCLK_CLKCTRL_CLKEN \
	| GCLK_CLKCTRL_GEN_GCLK2 \
	| GCLK_CLKCTRL_ID_TCC2_TC3
	STRH tmpd, [tmpa, #GCLK_CLKCTRL_offset]

_INIT_GCLK_Timer2_3_wait_sync
	LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
	LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
	BCS _INIT_GCLK_Timer2_3_wait_sync


;--------------------------------------------------------------;
; Timer 4-5 feed by GEN4 (OSC8M)
  LDR tmpd, =\
    GCLK_CLKCTRL_CLKEN \
  | GCLK_CLKCTRL_GEN_GCLK4 \
  | GCLK_CLKCTRL_ID_TC4_TC5
  STRH tmpd, [tmpa, #GCLK_CLKCTRL_offset]

_INIT_GCLK_Timer4_5_wait_sync
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_Timer4_5_wait_sync


;--------------------------------------------------------------;
; Watchdog feed by GEN2 (OCLULP32K)
  LDR tmpd, =\
    GCLK_CLKCTRL_CLKEN \
  | GCLK_CLKCTRL_GEN_GCLK2 \
  | GCLK_CLKCTRL_ID_WDT
  STRH tmpd, [tmpa, #GCLK_CLKCTRL_offset]

_INIT_GCLK_WDT_wait_sync
  LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
  LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
  BCS _INIT_GCLK_WDT_wait_sync


;--------------------------------------------------------------;
; SERCOM1 SPI feed by GEN0 (DFLL48M)
	LDR tmpd, =\
		GCLK_CLKCTRL_CLKEN \
	| GCLK_CLKCTRL_GEN_GCLK0 \
	| GCLK_CLKCTRL_ID_SERCOM1_CORE
	STRH tmpd, [tmpa, #GCLK_CLKCTRL_offset]

_INIT_GCLK_SERCOM1_wait_sync
	LDRB tmpd, [tmpa, #GCLK_STATUS_offset]
	LSRS tmpd, #GCLK_STATUS_SYNCBUSY_Pos + 1
	BCS _INIT_GCLK_SERCOM1_wait_sync

;==============================================================;




;========================= Init PORT ==========================;
ledPin EQU BIT_POS_4
  LDR tmpa, =PORT0
  LDR tmpd, =ledPin
  STR tmpd, [tmpa, #PORT_DIRSET_offset]
  LDR tmpd, =\
    ledPin \
  | PORT_WRCONFIG_HWSEL \
  | PORT_WRCONFIG_WRPINCFG \
  | PORT_WRCONFIG_DRVSTR
  STR tmpd, [tmpa, #PORT_WRCONFIG_offset]
;==============================================================;




; max period ~15s with 16K period WDT and 0x1e (30) divider fot OSCUPL32K
;======================== Init Watchdog =======================;
  LDR tmpa, =WDT
  LDR tmpd, =\
    WDT_CONFIG_PER_16K \
  | WDT_CONFIG_WINDOW_16K
  STRB tmpd, [tmpa, #WDT_CONFIG_offset]

  LDRB tmpd, [tmpa, #WDT_CTRL_offset]
  LDR tmp, =WDT_CTRL_ENABLE
  ORRS tmpd, tmp
  STRB tmpd, [tmpa, #WDT_CTRL_offset]

_WDT_INIT_wait_sync
  LDRB tmpd, [tmpa, #WDT_STATUS_offset]
  LSRS tmpd, #WDT_STATUS_SYNCBUSY_Pos + 1
  BCS _WDT_INIT_wait_sync
;==============================================================;




;======================== Init SYSTICK ========================;
sysTickVal EQU 0xffffff
  LDR tmpa, =SYST_CSR
  LDR tmpd, =sysTickVal
  STR tmpd, [tmpa, #SYST_RVR_offset]

  LDR tmpd, [tmpa]
  LDR tmp, =\
    SYST_CSR_ENABLE \
  | SYST_CSR_TICKINT \
  | SYST_CSR_CLOCKSOURCE
  ORRS tmpd, tmp
  STR tmpd, [tmpa]
;==============================================================;




;========================== Init NVIC =========================;
TC3_irq  EQU BIT_POS_18
TC3_pri  EQU (0xc0 & NVIC_PRI_Mask) << NVIC_PRI2_Pos
TC4_irq  EQU BIT_POS_19
TC4_pri  EQU (0xc0 & NVIC_PRI_Mask) << NVIC_PRI3_Pos
TC5_irq  EQU BIT_POS_20
TC5_pri  EQU (0x80 & NVIC_PRI_Mask) << NVIC_PRI0_Pos

  LDR tmpa, =NVICISER_SETENA
	LDR tmpd, =\
    TC3_irq \
	| TC4_irq \
	| TC5_irq
	STR tmpd, [tmpa]
	
	LDR tmpa, =NVICIPR

	LDR tmpd, =\
	  TC3_pri \
	+ TC4_pri
	STR tmpd, [tmpa, #NVICIPR4_offset]
	
	LDR tmpd, =TC5_pri
	STR tmpd, [tmpa, #NVICIPR5_offset]
;==============================================================;



;~8s
;========================== Init TC3 ==========================;
	LDR tmpa, =TC3
	LDR tmpd, [tmpa, #TC_CTRLA_offset]
	LDR tmp, =\
		TC_CTRLA_PRESCALER_DIV256 \
	| TC_CTRLA_MODE_COUNT8 \
	| TC_CTRLA_WAVEGEN_MFRQ \
	| TC_CTRLA_PRESCSYNC_PRESC
	ORRS tmpd, tmp
	STR tmpd, [tmpa, #TC_CTRLA_offset]

	LDR tmpd, =TC_INTENSET_MC0
	STRB tmpd, [tmpa, #TC_INTENSET_offset]

TC3_max_comp		EQU 0x80 ; ~4s 0x3f
	LDR tmpd, =TC3_max_comp
	STR tmpd, [tmpa, #TC_COUNT16_CC0_offset]

	LDRB tmpd, [tmpa, #TC_CTRLA_offset]
	LDR tmp, =TC_CTRLA_ENABLE
	ORRS tmpd, tmp
	STRB tmpd, [tmpa, #TC_CTRLA_offset]

_INIT_TC3_wait_sync
	LDRB tmpd, [tmpa, #TC_STATUS_offset]
	LSRS tmpd, #TC_STATUS_SYNCBUSY_Pos + 1
	BCS _INIT_TC3_wait_sync
;==============================================================;




;==============================================================;
  BL DELAY_TC5_INIT
  BL MAX7219_INIT



; Set Main Event Flag 
;==============================================================;
  FLAG "set", _EREG_, (1<<_MEIF_)


  ENDP
  END
