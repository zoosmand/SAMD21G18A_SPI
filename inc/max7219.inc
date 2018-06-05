__MAX7219

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	AREA |.rodata|, DATA, READONLY
	ALIGN

tickerInit	DCW 0x0f00, 0x0900, 0x0a00, 0x0b07, 0x0c01, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0600, 0x0700, 0x0800, 0x0
;tickerInit	DCW 0x0f00, 0x0900
;	, 0x0a00, 0x0b07, 0x0c01, 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0600, 0x0700, 0x0800, 0x0
	
tickerPtrn	DCB \
	0x01, 0x02, 0x03, 0x04, \
  0x01, 0x02, 0x03, 0x04, \
  0x01, 0x02, 0x03, 0x04, \
  0x01, 0x02, 0x03, 0x04, \
  0x01, 0x02, 0x03, 0x04, \
  0x01, 0x02, 0x03, 0x04, \
  0x01, 0x02, 0x03, 0x04, \
  0x01, 0x02, 0x03, 0x04
	
	;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c,\
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c

	;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, \
  ;0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08



tickerDefaults	DCB 0x01, 0x99, 0x01, 0x00
	; number of blocks of 4xMAX7219
	; CC TC4 value
	; direction, 1 - left, 0 - right
	; reserved

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	AREA |.bss|, DATA, READWRITE
	ALIGN

;_SPIREG_		EQU	SRAM_BASE + 8
tickerData		SPACE 92 ; depends on number of blocks (segments), 3 (blocks) * 4 (segments) - 4 (taken word in RAM) (3*4 -4)
tickerParams	DCB 0, 0, 0, 0


;; _SPIREG_ SPI Register Flags
;_FWF_		EQU	0 ; First Word Flag
;_CCF_		EQU	1 ; Carry flag Captured Flag
	
		
	
	
	
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	AREA |.text|, CODE, READONLY
	ALIGN






MAX7219_TC4_INIT PROC
	LDR tmpa, =TC4

	LDR tmpd, [tmpa, #TC_CTRLA_offset]
	LDR tmp, =\
		TC_CTRLA_PRESCALER_DIV1024 \
	| TC_CTRLA_MODE_COUNT8 \
	| TC_CTRLA_WAVEGEN_MFRQ \
	| TC_CTRLA_PRESCSYNC_PRESC
	ORRS tmpd, tmp
	STR tmpd, [tmpa, #TC_CTRLA_offset]

	LDR tmpd, =TC_INTENSET_MC0
	STRB tmpd, [tmpa, #TC_INTENSET_offset]

	BX LR
	ENDP








	MACRO
$label MOVVA $src, $dst
	PUSH {R4, R5}
	LDR src, =$src
	LDR dst, =$dst
	BL MOVVA_
	POP {R4, R5}
	MEND
	

MOVVA_ PROC
	PUSH {R0, R3, LR}
src		RN R4
dst		RN R5
	MOVS R0, #0
_MOVVA_count_cycle
	MOV R3, R0
	LSLS R3, #2
	LDR tmpd, [src, R3]
	STR tmpd, [dst, R3]
	ADDS R0, #1
	CMP R0, tmp
	BNE _MOVVA_count_cycle
	POP {R0, R3, PC}	
	ENDP










MAX7219_INIT PROC
	PUSH {R4-R5, LR}
ini		RN R4
prm		RN R5

	FLAG "set", _EREG_, (1<<_DEV3_) ; mark the device as ready

	;move parameters into RAM
	MOVS tmp, #1
	MOVVA tickerDefaults, tickerParams
  
  BL MAX7219_TC4_INIT
	BL SPI_SERCOM1_INIT

	LDR prm, =tickerParams
	LDR ini, =tickerInit
	
	
	; load Display Pattern into RAM, now 'tmp' holds count of words in RAM to use for N blocks of 4xMAX7219
	LDRB tmp, [prm]
	LSLS tmp, #3 ; n-count * 8 (<<3) rows (bytes) 
	MOVVA tickerPtrn, tickerData
	
	
	DELAY 255

	MOVS R0, #14
_MAX7219_INIT_tx_param
		BL SPI_START

		MOVS R3, #0xff
_MAX7219_INIT_tx_param_segment	
		LDRB trPacket, [ini, #1]
		BL SPI_TX_PACKET
		LDRB trPacket, [ini]
		BL SPI_TX_PACKET
		
		SUBS R3, #1
		BNE _MAX7219_INIT_tx_param_segment
			
		BL SPI_STOP
		
		ADDS ini, #2 ;increase initialization parameters address
		
	SUBS R0, #1
	BNE _MAX7219_INIT_tx_param

	
	; load TC4 compare number and start the timer, now it's the speed of sliding
	LDRB tmpd, [prm, #1]
	LDR tmpa, =TC4
	STR tmpd, [tmpa, #TC_COUNT8_CC0_offset]

	LDRB tmpd, [tmpa, #TC_CTRLA_offset]
	LDR tmp, =TC_CTRLA_ENABLE
	ORRS tmpd, tmp
	STRB tmpd, [tmpa, #TC_CTRLA_offset]

_MAX7219_INIT_TC4_wait_sync
	LDRB tmpd, [tmpa, #TC_STATUS_offset]
	LSRS tmpd, #TC_STATUS_SYNCBUSY_Pos + 1
	BCS _MAX7219_INIT_TC4_wait_sync

	B _MAX7219_INIT_exit
	
_MAX7219_INIT_stop_error
	FLAG "clear", _EREG_, (3<<_DEV0_)

_MAX7219_INIT_exit
	POP {R4-R5, PC}
	ENDP










MAX7219_RUN PROC
	PUSH {R3-R5, LR}
ptrn		RN R4
prm			RN R5
prmItem	RN R3
	
	FLAG_CHK "clear", _EREG_, _DEV3_, _MAX7219_RUN_exit
	
	SPI_SERCOM_SELECT SERCOM1
	
	LDR ptrn, =tickerData
	LDR prm, =tickerParams

	MOVS R0, #8
_MAX7219_RUN_select_row
		; load number of blocks of 4xMAX7219
		BL SPI_START
		LDRB prmItem, [prm]
		LSLS prmItem, #2 ; and multipy it by 4 (each block contains 4 MAX7219)

_MAX7219_RUN_tx_row
			MOV trPacket, R0
			BL SPI_TX_PACKET
			LDRB trPacket, [ptrn]
			BL SPI_TX_PACKET
			ADDS ptrn, ptrn, #1		
			SUBS R3, #1 ; prmItem
			BNE _MAX7219_RUN_tx_row

		BL SPI_STOP
		SUBS R0, #1
		BNE _MAX7219_RUN_select_row

	; load direction 1 - left, 0 - right
	MOVS R0, #1
	LDRB prmItem, [prm, #2]
	TST prmItem, R0
	BEQ _MAX7219_RUN_ror
	BL MAX7219_ROL
	B.N _MAX7219_RUN_exit

_MAX7219_RUN_ror	
	BL MAX7219_ROR

_MAX7219_RUN_exit
	POP {R3-R5, PC}
	ENDP










MAX7219_ROL PROC
	PUSH {R0-R6, LR}
data					RN R4
prm						RN R5
carry					RN R6
ROLCarryMask	EQU 0x00000001
	
	LDR prm, =tickerParams
	LDRB tmp, [prm]
	
	;	MOV32 data, tickerData + 60. 64 bytes for 8 MAX7219 or 2 blocks of 4 MAX7219
	LDR data, =tickerData
	LSLS tmp, #5
	ADDS data, tmp
	SUBS data, #4
	
	MOVS R0, #8
_MAX7219_ROL_select_row

	APSRC FLAG_C ; clear C flag	
	MOVS carry, #0 ; clear carry emulation

	LDRB R3, [prm] ; load number of blocks of 4xMAX7219
_MAX7219_ROL_row

	LDR tmpd, [data]
	REV tmpd, tmpd
	LSLS tmpd, #1
	ORRS tmpd, carry
	REV tmpd, tmpd
	STR tmpd, [data]

	MRS carry, APSR
	LSRS carry, #29
	LDR tmp, =ROLCarryMask
	ANDS carry, tmp

	SUBS data, #4

	SUBS R3, #1
	BNE _MAX7219_ROL_row
		
	LDR prm, =tickerParams
	LDRB tmp, [prm]
	LSLS tmp, #2
	ADDS data, tmp
	LDR tmpd, [data]
	REV tmpd, tmpd	
	ORRS tmpd, carry
	REV tmpd, tmpd
	STR tmpd, [data]
	SUBS data, tmp

	SUBS R0, #1
	BNE _MAX7219_ROL_select_row
	
	POP {R0-R6, PC}
	ENDP
		








MAX7219_ROR PROC
	PUSH {R0-R6, LR}
data					RN R4
prm						RN R5
carry					RN R6
RORcarryMask	EQU 0x80000000
	
	LDR prm, =tickerParams
	LDRB tmp, [prm]
	
	LDR data, =tickerData
	
	MOVS R0, #8
_MAX7219_ROR_select_row

	APSRC FLAG_C ; clear C flag
	MOVS carry, #0 ; clear carry emulation

	LDRB R3, [prm] ; load number of blocks of 4xMAX7219
_MAX7219_ROR_row

	LDR tmpd, [data]
	REV tmpd, tmpd
	LSRS tmpd, #1
	ORRS tmpd, carry
	REV tmpd, tmpd
	STR tmpd, [data]

	MRS carry, APSR
	LSLS carry, #2
	LDR tmp, =RORcarryMask
	ANDS carry, tmp

	ADDS data, #4

	SUBS R3, #1
	BNE _MAX7219_ROR_row
		
	LDR prm, =tickerParams
	LDRB tmp, [prm]
	LSLS tmp, #2
	SUBS data, tmp
	LDR tmpd, [data]
	REV tmpd, tmpd	
	ORRS tmpd, carry
	REV tmpd, tmpd
	STR tmpd, [data]
	ADDS data, tmp

	SUBS R0, #1
	BNE _MAX7219_ROR_select_row
	
	POP {R0-R6, PC}
	ENDP


	END
		