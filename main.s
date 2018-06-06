Stack_Size EQU 0x00000400

  AREA STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem SPACE Stack_Size
__initial_sp


Heap_Size EQU 0x00000200

  AREA HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem SPACE Heap_Size
__heap_limit



  PRESERVE8
  THUMB

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  AREA RESET, DATA, READONLY
  ALIGN

  GET samd21g18a.inc
  GET vectors.inc
  GET macroses.inc


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  AREA |.text|, CODE, READONLY
  ALIGN

  GBLA  GCNT
GCNT SETA   0


tmpa     RN R1
tmpd     RN R2
trPacket RN R6 
tmp      RN R7


; Events Register Flags
_MEIF_   EQU 0 ; Main Event Interval Flag
_RDF_    EQU 1 ; Run Display Flag
_DF_     EQU 2 ; Delay Flag
_NSF_    EQU 3 ; No Sleep Flag
_GSIF_   EQU 4 ; Global Software Interrupt is on Flag
_TF_     EQU 5 ; Ticker MAX7219 Flag
_DEV0_   EQU 12 ; Device 0 is ready to use
_DEV1_   EQU 13 ; Device 1 is ready to use
_DEV2_   EQU 14 ; Device 2 is ready to use
_DEV3_   EQU 15 ; Device 3 is ready to use
_DEV4_   EQU 16 ; Device 4 is ready to use
_DEV5_   EQU 17 ; Device 5 is ready to use
_DEV6_   EQU 18 ; Device 6 is ready to use
_DEV7_   EQU 19 ; Device 7 is ready to use
_DEV8_   EQU 20 ; Device 8 is ready to use
_DEV9_   EQU 21 ; Device 9 is ready to use


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  ENTRY
  AREA |.text|, CODE, READONLY

  GET init.inc
  GET spi.inc


;======================== MAIN Loop ===========================;
MAIN PROC

  FLAG_CHK "clear", _EREG_, _MEIF_, _MAIN_check_delay
  FLAG "clear", _EREG_, (1<<_MEIF_)
  BL LED_BLINK

_MAIN_check_delay
  FLAG_CHK "clear", _EREG_, _DF_, _MAIN_run_ticker
  FLAG "set", _EREG_, (1<<_NSF_)

  LDR tmpa, =TC5
  LDRB tmpd, [tmpa, #TC_STATUS_offset]
  LSRS tmpd, #TC_STATUS_STOP_Pos + 1
  BCC _MAIN_check_sleep

  FLAG "clear", _EREG_, (1<<_NSF_)

  LDR tmpa, =_DELAY_wait_exit
  MOV PC, tmpa

_MAIN_run_ticker
  FLAG_CHK "clear", _EREG_, _TF_, _MAIN_check_sleep
  FLAG "clear", _EREG_, (1<<_TF_)
  BL TICKER

_MAIN_check_sleep
  FLAG_CHK "set", _EREG_, _NSF_, MAIN

_MAIN_sleep
  WFI
  B.N MAIN
_MAIN_exit
  B.N MAIN
  ENDP
;==============================================================;




;/****************************************************************/
TICKER PROC
	PUSH {LR}
	
	FLAG_CHK "set", _EREG_, _GSIF_, _TICKER_exit ; check global software interrupt, if it on, then exit
	FLAG "set", _EREG_, (1<<_GSIF_)
	
	BL MAX7219_RUN

	FLAG "clear", _EREG_, (1<<_GSIF_)
	
_TICKER_exit
	POP {PC}
	ENDP
;/****************************************************************/



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  AREA |.text|, CODE, READONLY
  ALIGN
  GET utils.inc
  GET interrupts.inc
  GET max7219.inc
  GET bmp280.inc

  GET var.inc

  END
