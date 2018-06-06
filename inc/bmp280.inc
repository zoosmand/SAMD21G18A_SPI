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

    BL SPI_START
	
	LDR trPacket, =0xd0
	BL SPI_TX_PACKET
    BL SPI_RX_PACKET
    ADDS bmp280, #1
	LDR trPacket, =0
	BL SPI_TX_PACKET
    BL SPI_RX_PACKET
    STRB trPacket, [bmp280]
    ADDS bmp280, #1
    BL SPI_STOP

	;BMP280_ADDR "read"
	;BL I2CM_START
	;FLAG_CHK "set", _I2CREG_, _I2CERRF_, _BMP280_INIT_stop_error
	;STRB trPacket, [bmp280]
	;BL I2CM_STOP_NACK
	
;----------------------------------------------------;
	;; Collect Calibration Data 1
	;LDR bmp280, =BMP280_calib1
	
	;BMP280_ADDR "write"
	;BL I2CM_START
	;FLAG_CHK "set", _I2CREG_, _I2CERRF_, _BMP280_INIT_stop_error
	;LDR trPacket, =0x88 ; calib00 address
	;BL I2CM_TX_BYTE

	;BMP280_ADDR "read"
	;BL I2CM_START
	;FLAG_CHK "set", _I2CREG_, _I2CERRF_, _BMP280_INIT_stop_error
	
	;LDR tmp, =(0xa1 - 0x88 + 1) ; calib25..calib00
	;MOV R8, tmp
	;LDR R0, =0
;_BMP280_INIT_collect_calib1
	;STRB trPacket, [bmp280, R0]
	;BL I2CM_RX_BYTE
	;ADDS R0, #1
	;CMP R0, R8
	;BNE _BMP280_INIT_collect_calib1
	
	;BL I2CM_STOP_NACK
	
;;----------------------------------------------------;
	;; Config to Collect Humidity
	;BMP280_ADDR "write"
	;BL I2CM_START
	;FLAG_CHK "set", _I2CREG_, _I2CERRF_, _BMP280_INIT_stop_error

	;LDR trPacket, =0xf2
	;BL I2CM_TX_BYTE
	;LDR trPacket, =0x01
	;BL I2CM_TX_BYTE

	;BL I2CM_STOP
	
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
	
	;FLAG_CHK "clear", _I2CREG_, _I2CERRF_, _BMP280_MEASURMENT_start
	;BL BMP280_INIT

	;FLAG_CHK "clear", _EREG_, _DEV0_, _BMP280_MEASURMENT_exit

;_BMP280_MEASURMENT_start
	;I2CM_SERCOM_SELECT SERCOM0
	;FLAG "set", _I2CREG_, (1<<_I2C0DEV_)
;;----------------------------------------------------;
	;; Set Forced Power Mode.
	;BMP280_ADDR "write"
	;BL I2CM_START
	;FLAG_CHK "set", _I2CREG_, _I2CERRF_, _BMP280_MEASURMENT_stop_error

	;LDR trPacket, =0xf4
	;BL I2CM_TX_BYTE
	;LDR trPacket, =0x25
	;BL I2CM_TX_BYTE

	;BL I2CM_STOP
	
	;DELAY 12
;;----------------------------------------------------;
	;; Collect Measurment Data
	;LDR bmp280, =BMP280_data
	
	;BMP280_ADDR "write"
	;BL I2CM_START
	;FLAG_CHK "set", _I2CREG_, _I2CERRF_, _BMP280_MEASURMENT_stop_error
	;LDR trPacket, =0xf7 ; press_msb address
	;BL I2CM_TX_BYTE

	;BMP280_ADDR "read"
	;BL I2CM_START
	;FLAG_CHK "set", _I2CREG_, _I2CERRF_, _BMP280_MEASURMENT_stop_error
	
	;LDR tmp, =(0xfe - 0xf7 + 1) ; hum_lsb..press_msb
	;MOV R8, tmp
	;LDR R0, =0
;_BMP280_MEASURMENT_collect_data
	;STRB trPacket, [bmp280, R0]
	;BL I2CM_RX_BYTE
	;ADDS R0, #1
	;CMP R0, R8
	;BNE _BMP280_MEASURMENT_collect_data
	
	;BL I2CM_STOP_NACK
	
	;B _BMP280_MEASURMENT_exit

;_BMP280_MEASURMENT_stop_error
	;BL I2CM_STOP
	
;_BMP280_MEASURMENT_exit
	;REG "clear", _I2CREG_, 0xffffffff & ~(1<<_I2CERRF_) ; clear all except error flag
	
	POP {PC}
	ENDP



	END

