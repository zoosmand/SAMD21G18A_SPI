__Interrupts

;=========================== SysTick ==========================;
SysTick_HANDLER PROC
    PUSH {R1-R2, R7, LR}

    LDR tmpa, =WDT
    LDR tmpd, =WDT_CLEAR_CLEAR
    STR tmpd, [tmpa, #WDT_CLEAR_offset]

_SysTick_HANDLER_wdt_wait_sync
    LDRB tmpd, [tmpa, #WDT_STATUS_offset]
    LSRS tmpd, #WDT_STATUS_SYNCBUSY_Pos + 1
    BCS _SysTick_HANDLER_wdt_wait_sync

    LDR tmpa, =SYST_CSR
    LDR tmpd, [tmpa]
    LDR tmp, =SYST_CSR_COUNTFLAG
    TST tmpd, tmp
    BAL _SysTick_HANDLER_exit

_SysTick_HANDLER_exit
    POP {R1-R2, R7, PC}
    ENDP
;==============================================================;




;========================= TC3 Handler ========================;
TC3_HANDLER PROC
    PUSH {R1-R2, R7, LR}

    FLAG "set", _EREG_, (1<<_MEIF_)

    LDR tmpa, =TC3
    LDR tmpd, =TC_INTENFLAG_MC0
    STRB tmpd, [tmpa, #TC_INTFLAG_offset]
    POP {R1-R2, R7, PC}
    ENDP
;==============================================================;




;========================= TC4 Handler ========================;
TC4_HANDLER PROC
    PUSH {R1-R2, R7, LR}

    FLAG "set", _EREG_, (1<<_TF_)

    LDR tmpa, =TC4
    LDR tmpd, =TC_INTENFLAG_MC0
    STRB tmpd, [tmpa, #TC_INTFLAG_offset]
    POP {R1-R2, R7, PC}
    ENDP
;==============================================================;




;========================== SERCOM1 ===========================;
SERCOM1_HANDLER PROC
    PUSH {R1-R2, LR}
    
_SERCOM1_HANDLER_rxc_handler    
    LDR tmpa, =SERCOM1
    LDR tmpd, [tmpa, #SPI_INTFLAG_offset]
    LSRS tmpd, #SPI_INTFLAG_RXC_Pos + 1
    BCC _SERCOM1_HANDLER_error_handler

    LDR trPacket, [tmpa, #SPI_DATA_offset]

_SERCOM1_HANDLER_error_handler    
    LDR tmpa, =SERCOM1
    LDR tmpd, [tmpa, #SPI_INTFLAG_offset]
    LSRS tmpd, #SPI_INTFLAG_ERROR_Pos + 1
    BCC _SERCOM0_HANDLER_exit

    FLAG "set", _SPIREG_, (1<<_ERRF_)

; Clear Flags
_SERCOM0_HANDLER_exit
    LDR tmpa, =SERCOM1
    LDR tmpd, =SPI_INTFLAG_ERROR
    STR tmpd, [tmpa, #SPI_INTFLAG_offset]
    POP {R1-R2, PC}
    ENDP
;==============================================================;

    END
