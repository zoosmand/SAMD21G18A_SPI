__BMP280

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    AREA |.rodata|, DATA, READONLY
    ALIGN


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    AREA |.bss|, DATA, NOINIT, READWRITE
    ALIGN

BMP280_calib1   FILL 28, 0, 4
BMP280_data     FILL 8, 0, 4
BMP280_id       DCD 0
	


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
    AREA |.text|, CODE, READONLY
    ALIGN

read_mask   EQU 0xff
write_mask  EQU 0x7f


;----------------------------------------------------;
BMP280_INIT PROC
bmp280  RN R4
    PUSH {LR}
    FLAG "set", _EREG_, (1<<_DEV0_) ; mark the device as ready
    FLAG "set", _SPIREG_, (1<<_SPI1DEV_) ; mark the device is busy
    DELAY 2

    MOVS R0, #0
    LDR tmpa, =BMP280_calib1
    MOVS R4, #7
    BL ZEROED_DATA

    LDR tmpa, =BMP280_data
    MOVS R4, #2
    BL ZEROED_DATA

    LDR tmpa, =BMP280_id
    STR R0, [tmpa]

    ; Define SERCOM
    SPI_SERCOM_SELECT SERCOM1
    ; Define SS Pin 
    SPI_SS_SELECT 0, 2 ; PORT0, PA02
    
    LDR tmpa, =_SERCOM_
    LDR tmpa, [tmpa]
    LDR tmpd, =\
      SPI_INTENSET_RXC \
    | SPI_INTENSET_ERROR
    STRH tmpd, [tmpa, #SPI_INTENSET_offset]

;----------------------------------------------------;
    ; Get Sensor ID, BMP280 - 0x58, BMP280 - 0x60
    LDR bmp280, =BMP280_id

    LDR trPacket, =0xd0 ; id address
    LDR R0, =read_mask
    ANDS trPacket, R0

    BL SPI_START
    BL SPI_RX_PACKET
    FLAG_CHK "set", _SPIREG_, _ERRF_, _BMP280_INIT_stop_error

    LDR trPacket, =0
    BL SPI_RX_PACKET
    FLAG_CHK "set", _SPIREG_, _ERRF_, _BMP280_INIT_stop_error

    STRB trPacket, [bmp280]
    ADDS bmp280, #1
    BL SPI_STOP

;----------------------------------------------------;
    ; Collect Calibration Data 1
    LDR bmp280, =BMP280_calib1

    LDR trPacket, =0x88 ; calib00 address
    LDR R0, =read_mask
    ANDS trPacket, R0

    BL SPI_START
    BL SPI_RX_PACKET
    FLAG_CHK "set", _SPIREG_, _ERRF_, _BMP280_INIT_stop_error

    LDR tmp, =(0xa1 - 0x88 + 1) ; calib25..calib00
    MOV R8, tmp
    LDR R0, =0
_BMP280_INIT_collect_calib1
    LDR trPacket, =0
    BL SPI_RX_PACKET
    FLAG_CHK "set", _SPIREG_, _ERRF_, _BMP280_INIT_stop_error
    STRB trPacket, [bmp280, R0]
    ADDS R0, #1
    CMP R0, R8
    BNE _BMP280_INIT_collect_calib1

    BL SPI_STOP
	
;----------------------------------------------------;
    ; Config to Collect Humidity
    BL SPI_START

    LDR trPacket, =0xf2
    LDR R0, =write_mask
    ANDS trPacket, R0
    BL SPI_TX_PACKET

    LDR trPacket, =0x01
    LDR R0, =write_mask
    ANDS trPacket, R0
    BL SPI_TX_PACKET

    BL SPI_STOP

    B _BMP280_INIT_exit

_BMP280_INIT_stop_error
    FLAG "clear", _EREG_, (1<<_DEV0_) ; mark the device as not ready
    BL SPI_STOP
	
_BMP280_INIT_exit
    FLAG "clear", _SPIREG_, (1<<_SPI1DEV_) ; mark the device is free

    POP {PC}
    ENDP








BMP280_MEASURMENT PROC
    PUSH {LR}

    FLAG_CHK "clear", _EREG_, _DEV0_, _BMP280_MEASURMENT_exit
    FLAG "set", _SPIREG_, (1<<_SPI1DEV_) ; mark the device is busy

    ; Define SERCOM
    SPI_SERCOM_SELECT SERCOM1
    ; Define SS Pin 
    SPI_SS_SELECT 0, 2 ; PORT0, PA02

    LDR tmpa, =_SERCOM_
    LDR tmpa, [tmpa]
    LDR tmpd, =\
      SPI_INTENSET_RXC \
    | SPI_INTENSET_ERROR
    STRH tmpd, [tmpa, #SPI_INTENSET_offset]

;----------------------------------------------------;
    ; Set Forced Power Mode.
    BL SPI_START

    LDR trPacket, =0xf4
    LDR R0, =write_mask
    ANDS trPacket, R0
    BL SPI_RX_PACKET

    LDR trPacket, =0x25
    LDR R0, =write_mask
    ANDS trPacket, R0
    BL SPI_RX_PACKET

    BL SPI_STOP

    DELAY 12
;----------------------------------------------------;
    ; Collect Measurment Data
    LDR bmp280, =BMP280_data

    BL SPI_START

    LDR trPacket, =0xf7
    LDR R0, =read_mask
    ANDS trPacket, R0
    BL SPI_RX_PACKET
    FLAG_CHK "set", _SPIREG_, _ERRF_, _BMP280_MEASURMENT_stop_error

    LDR tmp, =(0xfc - 0xf7 + 1) ; temp_xlsb..press_msb
    MOV R8, tmp
    LDR R0, =0
_BMP280_MEASURMENT_collect_data
    LDR trPacket, =0
    BL SPI_RX_PACKET
    FLAG_CHK "set", _SPIREG_, _ERRF_, _BMP280_MEASURMENT_stop_error
    STRB trPacket, [bmp280, R0]
    ADDS R0, #1
    CMP R0, R8
    BNE _BMP280_MEASURMENT_collect_data

    BL SPI_STOP

    B _BMP280_MEASURMENT_exit

_BMP280_MEASURMENT_stop_error
    BL SPI_STOP
	
_BMP280_MEASURMENT_exit
    FLAG "clear", _SPIREG_, (1<<_SPI1DEV_) ; mark the device is free	
    POP {PC}
    ENDP



    END

