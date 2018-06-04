__Utils

;======================= Just LED Blink =======================;
LED_BLINK PROC
  PUSH {LR}
  LDR tmpa, =PORT0_OUTTGL
  LDR tmpd, =BIT_POS_4
  STR tmpd, [tmpa]
  POP {PC}
  ENDP
;==============================================================;




;======================== Delay on TC5 =========================;
DELAY_TC5_INIT PROC
	LDR tmpa, =TC5
	LDR tmpd, [tmpa, #TC_CTRLA_offset]
	LDR tmp, =\
	  TC_CTRLA_PRESCALER_DIV8 \
	+ TC_CTRLA_MODE_COUNT16 \
	+ TC_CTRLA_WAVEGEN_MFRQ \
	+ TC_CTRLA_PRESCSYNC_PRESC
	ORRS tmpd, tmp
	STR tmpd, [tmpa, #TC_CTRLA_offset]

	LDR tmpd, =TC_CTRLBSET_ONESHOT
	STRB tmpd, [tmpa, #TC_CTRLBSET_offset]

_DELAY_TC5_INIT_wait_ctrlb_sync
	LDRB tmpd, [tmpa, #TC_STATUS_offset]
	LSRS tmpd, #TC_STATUS_SYNCBUSY_Pos + 1
	BCS _DELAY_TC5_INIT_wait_ctrlb_sync	

	LDRB tmpd, [tmpa, #TC_CTRLA_offset]
	LDR tmp, =TC_CTRLA_ENABLE
	ORRS tmpd, tmp
	STRB tmpd, [tmpa, #TC_CTRLA_offset]

_DELAY_TC5_INIT_wait_sync
	LDRB tmpd, [tmpa, #TC_STATUS_offset]
	LSRS tmpd, #TC_STATUS_SYNCBUSY_Pos + 1
	BCS _DELAY_TC5_INIT_wait_sync

	BX LR
	ENDP


;--------------------------------------------------------------;
	MACRO
$label DELAY $delay
	LDR tmpd, =$delay
	BL DELAY_
	MEND


;--------------------------------------------------------------;
DELAY_ PROC
	LDR tmpa, =TC5
	STRH tmpd, [tmpa, #TC_COUNT16_CC0_offset]

_DELAY_wait_cc_sync
	LDRB tmpd, [tmpa, #TC_STATUS_offset]
	LSRS tmpd, #TC_STATUS_SYNCBUSY_Pos + 1
	BCS _DELAY_wait_cc_sync

	LDR tmpd, =TC_CTRLBSET_CMD_RETRIGGER
	STRB tmpd, [tmpa, #TC_CTRLBSET_offset]

_DELAY_wait_trigger2_sync
	LDRB tmpd, [tmpa, #TC_STATUS_offset]
	LSRS tmpd, #TC_STATUS_SYNCBUSY_Pos + 1
	BCS _DELAY_wait_trigger2_sync

	FLAG "set", _EREG_, (1<<_DF_)

	LDR tmpa, =MAIN
	MOV PC, tmpa

_DELAY_wait_exit
	FLAG "clear", _EREG_, (1<<_DF_)

	BX LR
	ENDP
;==============================================================;




;==================== Device TestPinBlink =====================;
TEST_PIN_BLINK_INIT PROC
	PUSH {LR}
	FLAG "set", _EREG_, (1<<_DEV3_) ; mark the device as ready
	BL TEST_PIN_BLINK_INIT_PORT
	POP {PC}
	ENDP


;--------------------------------------------------------------;
TEST_PIN_BLINK_INIT_PORT PROC
	LDR tmpa, =PORT0
	; Timer Test Pin
	; PA15-pin5/D5
TestPin		EQU BIT_POS_15
	LDR tmpd, =TestPin
	STR tmpd, [tmpa, #PORT_DIRSET_offset]
	LDR tmpd, =\
		TestPin \
	| PORT_WRCONFIG_WRPINCFG \
	| PORT_WRCONFIG_DRVSTR
	STR tmpd, [tmpa, #PORT_WRCONFIG_offset]

	BX LR
	ENDP


;--------------------------------------------------------------;
TEST_PIN_BLINK PROC
	PUSH {R1-R2, LR}
	
	FLAG_CHK "clear", _EREG_, _DEV3_, _TEST_PIN_BLINK_exit
	
	LDR R0, =8
_TEST_PIN_BLINK_cycle
	LDR tmpa, =PORT0
	LDR tmpd, =TestPin
	STR tmpd, [tmpa, #PORT_OUTTGL_offset]
	DELAY 0x07a0
	SUBS R0, #1
	BNE _TEST_PIN_BLINK_cycle

_TEST_PIN_BLINK_exit	
	POP {R1-R2, PC}
	ENDP
;==============================================================;




;======================= RAM emptier ==========================;
ZEROED_DATA PROC
	PUSH {R3-R4, LR}
	MOVS R3, #0
_ZEROED_DATA_cycle
	LSLS R3, #2
	STR R0, [tmpa, R3]
	LSRS R3, #2
	ADDS R3, #1
	CMP R3, R4
	BNE _ZEROED_DATA_cycle
	POP {R3-R4, PC}
	ENDP
;==============================================================;




	END

