__SPI

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    AREA |.bss|, DATA, READWRITE
    ALIGN

_SPIREG_   DCD 0


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    AREA |.text|, CODE, READONLY
    ALIGN
_FWF_         EQU	0 ; First Word Flag
_CCF_         EQU	1 ; Carry flag Captured Flag
_SPI0DEV_     EQU 12 ; Device on I2C0 bus in-use
_SPI1DEV_     EQU 13 ; Device on I2C1 bus in-use
_SPI2DEV_     EQU 14 ; Device on I2C2 bus in-use
_SPI3DEV_     EQU 15 ; Device on I2C3 bus in-use
_SPI4DEV_     EQU 16 ; Device on I2C4 bus in-use
_SPI5DEV_     EQU 17 ; Device on I2C5 bus in-use
_SPIDEV_      EQU 0x3f
_SPIDEV_Pos   EQU 12






;=========================================;
    MACRO
$label SPI_SERCOM_SELECT $sercom
    LDR tmpd, =$sercom
    LDR tmpa, =_SERCOM_
    STR tmpd, [tmpa]
    MEND


;=========================================;
    MACRO
$label SPI_SERCOM_INIT $sercom
    SPI_SERCOM_SELECT $sercom
    IF ("$sercom" = "SERCOM0")
        BL SPI_SERCOM0_INIT_PORT
    ELIF ("$sercom" = "SERCOM1")
        BL SPI_SERCOM1_INIT_PORT
    ELIF ("$sercom" = "SERCOM2")
        BL SPI_SERCOM2_INIT_PORT
    ELIF ("$sercom" = "SERCOM3")
        BL SPI_SERCOM3_INIT_PORT
    ELIF ("$sercom" = "SERCOM4")
        BL SPI_SERCOM4_INIT_PORT
    ELIF ("$sercom" = "SERCOM5")
        BL SPI_SERCOM5_INIT_PORT
    ELSE
        INFO 1, "Use SERCOMx, where x - number of SERCOM"
    ENDIF
    BL SPI_SERCOM_INIT_
    MEND


;=========================================;
SPI_SERCOM0_INIT_PORT PROC
    BX LR
    ENDP

;=========================================;
SPI_SERCOM1_INIT_PORT PROC
; SPI1, SERCOM1, MUX-C
; PA16-PAD0-pin11/D11-MOSI
; PA17-PAD1-pin13/D13-SCK
; PA18-PAD2-pin10/D10-SS
; PA19-PAD3-pin12/D12-MISO
MOSIPin     EQU BIT_POS_16
MISOPin     EQU BIT_POS_19
SCKPin      EQU BIT_POS_17
SSPin       EQU BIT_POS_18

    LDR tmpa, =PORT0
    LDR tmpd, =\
      MOSIPin \
    | SCKPin \
    | SSPin
    STR tmpd, [tmpa, #PORT_DIRSET_offset]

    LDR tmpd, =SSPin
    STR tmpd, [tmpa, #PORT_OUTSET_offset]

    LDR tmpd, =\
      MOSIPin >> 16 \
    | SCKPin >> 16 \
    | PORT_WRCONFIG_HWSEL \
    | PORT_WRCONFIG_WRPINCFG \
    | PORT_WRCONFIG_PMUXEN \
    | PORT_PMUX_PMUX_C << PORT_WRCONFIG_PMUX_Pos \
    | PORT_WRCONFIG_WRPMUX \
    | PORT_WRCONFIG_DRVSTR \
    | PORT_WRCONFIG_PULLEN
    STR tmpd, [tmpa, #PORT_WRCONFIG_offset]
    ;	| SSPin >> 16

    LDR tmpd, =\
      MISOPin >> 16 \
    | PORT_WRCONFIG_HWSEL \
    | PORT_WRCONFIG_WRPINCFG \
    | PORT_WRCONFIG_PMUXEN \
    | PORT_PMUX_PMUX_C << PORT_WRCONFIG_PMUX_Pos \
    | PORT_WRCONFIG_WRPMUX \
    | PORT_WRCONFIG_DRVSTR \
    | PORT_WRCONFIG_PULLEN \
    | PORT_WRCONFIG_INEN
    STR tmpd, [tmpa, #PORT_WRCONFIG_offset]

    BX LR
    ENDP

;=========================================;
SPI_SERCOM2_INIT_PORT PROC
    BX LR
    ENDP

;=========================================;
SPI_SERCOM3_INIT_PORT PROC
    BX LR
    ENDP

;=========================================;
SPI_SERCOM4_INIT_PORT PROC
    BX LR
    ENDP

;=========================================;
SPI_SERCOM5_INIT_PORT PROC
    BX LR
    ENDP





;=========================================;
SPI_SERCOM_INIT_ PROC
    PUSH {LR}
spi1_dipo		EQU 0x03
spi1_dopo		EQU 0x00
spi1_baud		EQU 0x17 ;(48MHz/(1MHz*2)-1), 1M Baud
    LDR tmpa, =_SERCOM_
    LDR tmpa, [tmpa]
    LDR tmpd, [tmpa, #SPI_CTRLA_offset]
    LDR tmp, =\
      SPI_CTRLA_MODE_SPI_MASTER \
    | spi1_dopo << SPI_CTRLA_DOPO_Pos \
    | spi1_dipo << SPI_CTRLA_DIPO_Pos
    ORRS tmpd, tmp
    STR tmpd, [tmpa, #SPI_CTRLA_offset]

    ;LDR tmpd, [tmpa, #SPI_CTRLB_offset]
    ;LDR tmp, =SPI_CTRLB_MSSEN
    ;ORRS tmpd, tmp
    ;STR tmpd, [tmpa, #SPI_CTRLB_offset]

    LDR tmpd, =spi1_baud
    STR tmpd, [tmpa, #SPI_BAUD_offset]

    LDR tmpd, [tmpa, #SPI_CTRLA_offset]
    LDR tmp, =SPI_CTRLA_ENABLE
    ORRS tmpd, tmp
    STR tmpd, [tmpa, #SPI_CTRLA_offset]

_INIT_SERCOM1_SPI_wait_sync
    LDRB tmpd, [tmpa, #SPI_SYNCBUSY_offset]
    LSRS tmpd, #SPI_SYNCBUSY_CTRLB_Pos + 1
    BCS _INIT_SERCOM1_SPI_wait_sync
    POP {PC}
    ENDP






;=========================================;
SPI_SERCOM1_INIT PROC
    PUSH {LR}
    SPI_SERCOM_INIT SERCOM1
    POP {PC}
    ENDP






;=========================================;
SPI_START PROC
    ;LDR tmpa, =_SERCOM_
    ;LDR tmpa, [tmpa]
    ;LDR tmpd, [tmpa, #SPI_CTRLA_offset]
    ;LDR tmp, =SPI_CTRLA_ENABLE
    ;ORRS tmpd, tmp
    ;STR tmpd, [tmpa, #SPI_CTRLA_offset]

    ;_SPI1_START_wait_sync
    ;LDRB tmpd, [tmpa, #SPI_SYNCBUSY_offset]
    ;LSRS tmpd, #SPI_SYNCBUSY_CTRLB_Pos + 1
    ;BCS _SPI1_START_wait_sync

    LDR tmpa, =PORT0

    LDR tmpd, =SSPin
    STR tmpd, [tmpa, #PORT_OUTCLR_offset]

    BX LR
    ENDP








;=========================================;
SPI_STOP PROC	
    LDR tmpa, =_SERCOM_
    LDR tmpa, [tmpa]
    ;LDR tmpd, [tmpa, #SPI_CTRLA_offset]
    ;LDR tmp, =SPI_CTRLA_ENABLE
    ;BICS tmpd, tmp
    ;STR tmpd, [tmpa, #SPI_CTRLA_offset]

    ;_SPI1_STOP_wait_sync
    ;LDRB tmpd, [tmpa, #SPI_SYNCBUSY_offset]
    ;LSRS tmpd, #SPI_SYNCBUSY_CTRLB_Pos + 1
    ;BCS _SPI1_STOP_wait_sync

    ;LDR tmpa, =SERCOM1

_SPI_STOP_wait_txc
    LDR tmpd, [tmpa, #SPI_INTFLAG_offset]
    LSRS tmpd, #SPI_INTFLAG_TXC_Pos + 1
    BCC _SPI_STOP_wait_txc

    LDR tmpa, =PORT0

    LDR tmpd, =SSPin
    STR tmpd, [tmpa, #PORT_OUTSET_offset]

    BX LR
    ENDP








;=========================================;
SPI_TX_PACKET PROC
    LDR tmpa, =_SERCOM_
    LDR tmpa, [tmpa]

_SPI_SEND_PACKET_wait_dre
    LDR tmpd, [tmpa, #SPI_INTFLAG_offset]
    LSRS tmpd, #SPI_INTFLAG_DRE_Pos + 1
    BCC _SPI_SEND_PACKET_wait_dre

    STRH trPacket, [tmpa, #SPI_DATA_offset]

    BX LR
    ENDP







;=========================================;
SPI_RX_PACKET PROC
    LDR tmpa, =_SERCOM_
    LDR tmpa, [tmpa]

    LDR trPacket, [tmpa, #SPI_DATA_offset]

    BX LR
    ENDP


    END