#IFNDEF CORNIO_LCD
#DEFINE CORNIO_LCD
    
#include "lib.inc"
    
#define LENA  RE1
#define LDAT  RE2
#define LPORT PORTD 
    
L_ON  EQU	B'00001111'
L_OFF EQU	B'00001000'
L_CLR EQU	B'00000001'
L_L1  EQU	B'10000000'
L_L2  EQU	B'11000000'
L_L3  EQU	B'10010000'
L_L4  EQU	B'11010000'
L_CR  EQU	B'00001111'	
L_NCR EQU	B'00001100'
L_CFG EQU	B'00111000'
 
L_SHIFT_LEFT  EQU	B'00011000'
L_SHIFT_RIGHT EQU	B'00011100'


;+++++++++++++++++++++++++++++++++++++++++++++++++++
LCD_VARS MACRO       
 LCD_CMD_INPUT   RES	       1
 LCD_DAT_INPUT   RES	       1  
 ENDM
 
;++++++++++++++++++++++++++++++++++++++++++++++++++++
LCD_CMD MACRO VAL
 MOVLW VAL
 MOVWF LCD_CMD_INPUT
 CALL DEF_LCD_CMD
 ENDM
 
;+++++++++++++++++++++++++++++++++++++++++++++++++++++
LCD_DAT MACRO VAL
 MOVLW VAL
 MOVWF LCD_DAT_INPUT
 CALL DEF_LCD_DAT
 ENDM
 
LCD_DAT_F MACRO VAL
 MOVF VAL,0
 MOVWF LCD_DAT_INPUT
 CALL DEF_LCD_DAT
 ENDM
 
 ;++++++++++++++++++++++++++++++++++++++++++++++++++++
DEFINE_LCD_FUNCS MACRO
 LCD_ENABLE:
 BANK1
 CLRF TRISD
 CLRF TRISE
 BANK0
 RETURN
 
 LCD_CLEAR:
    LCD_CMD L_CLR
    RETURN
 
 DEF_LCD_CMD:			; void lcd_cmd(unsigned char val)
    BSF PORTE,LENA		; LENA = 1;
 
    MOVF LCD_CMD_INPUT,0	; lcd_wr(val);
    MOVWF LPORT			;
 
    BCF PORTE,LDAT		; LDAT = 0;
    DELAY_MS D'3'		; atraso_ms(3);
    BCF PORTE,LENA		; LENA = 0;
    DELAY_MS D'3'		; atraso_ms(3);
    BSF PORTE,LENA		; LENA = 1;
    RETURN
 
 DEF_LCD_DAT:			; void lcd_dat(unsigned char val)
    BSF PORTE,LENA		; LENA = 1;
    
    MOVF LCD_DAT_INPUT,0	; lcd_wr(val);
    MOVWF LPORT	                ;
    
    BSF PORTE,LDAT		; LDAT = 1;
    DELAY_MS D'3'		; atraso_ms(3);
    BCF PORTE,LENA		; LENA = 0;
    DELAY_MS D'3'		; atraso_ms(3);
    BSF PORTE,LENA		; LENA = 1;
    RETURN
 
 LCD_INIT:
    CALL LCD_ENABLE
    BCF PORTE,LENA		; LENA = 0;
    BCF PORTE,LDAT		; LDAT = 0;
    DELAY_MS D'20'		; atraso_ms(20);
    BSF PORTE,LENA		; LENA = 1;
    
    LCD_CMD L_CFG		; lcd_cmd(L_CFG);
    DELAY_MS D'5'		; atraso_ms(5);
    LCD_CMD L_CFG		; lcd_cmd(L_CFG);
    DELAY_MS D'1'		; atraso_ms(1);
    LCD_CMD L_CFG		; lcd_cmd(L_CFG); configura
    LCD_CMD L_OFF		; lcd_cmd(L_OFF);
    LCD_CMD L_ON		; lcd_cmd(L_ON);  liga
    LCD_CMD L_CLR		; lcd_cmd(L_CLR); limpa
    LCD_CMD L_CFG		; lcd_cmd(L_CFG); configura
    LCD_CMD L_L1		; lcd_cmd(L_L1);
    RETURN
 
 ENDM
    
#ENDIF