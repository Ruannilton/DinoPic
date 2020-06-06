#include "p16f877a.inc"
#include "lcd.inc"
#include "input.inc"
#include "display.inc"
#include "tela_app.inc"
#include "tela_game.inc"
    
 __CONFIG _FOSC_EXTRC & _WDTE_OFF & _PWRTE_OFF & _BOREN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _CP_OFF

GPR_VAR	UDATA								        ; INICIA AS VARI�VEIS
 ENTRADA	    RES	1
 PONTUACAO	    RES	1
 JOGO_RODANDO	    RES 1
 TIMER_COUNT	    RES 1
 LIB_VARS
 LCD_VARS
 DISPLAY_VARS
 TELA_GAME_VARS


RES_VECT  CODE    0x0000            
    GOTO    START                   

ISR CODE 0X0004    
 BTFSC INTCON, TMR0IF	;INTERRUP��O DE TEMPO
 CALL TIMER_INT
 RETFIE
 
TIMER_INT:
   BCF INTCON, TMR0IF
   MOVLW D'126'
   MOVF TMR0
  
   CMPFL VOANDO,0
   JE SKIP_INC_TEMPO_VOANDO
   INCF TEMPO_VOANDO
   
   CMPFL TEMPO_VOANDO, 30
   JNE SKIP_INC_TEMPO_VOANDO 
   MOVLF 0,VOANDO
   MOVLF 0,TEMPO_VOANDO
   
SKIP_INC_TEMPO_VOANDO:   
 
   DECFSZ TIMER_COUNT
   RETURN
   
   MOVLW D'60'
   MOVWF TIMER_COUNT
   
   INCF PONTUACAO								; AUMENTA 1 PONTO POR SEGUNDO
   RETURN

MAIN_PROG CODE                      
 
DEFINE_FUNCS:									; DECLARA AS FUN��ES DAS BIBLIOTECAS
 DEFINE_LCD_FUNCS								
 DEFINE_INPUT_FUNCS ENTRADA
 TELAS_DEF
 DEFINE_DISPLAY_FUNCS
 TELA_GAME_DEFINE_FUNCS
 

SETUP_TIMER_INT:								; CONFIGURA CONTADOR
 BANK1
 BCF TRISB, RB1
 BCF OPTION_REG, PSA								; HABILITA PSA PRO TIMER 0
 BSF OPTION_REG, PS2
 BSF OPTION_REG, PS1
 BCF OPTION_REG, PS0
 BANK0
 BCF TRISB, RB1
										
										
 MOVLW D'126'
 MOVWF TMR0
 
 MOVLW D'60'
 MOVWF TIMER_COUNT
 
 BCF INTCON, TMR0IF
 BSF INTCON, TMR0IE
 BSF INTCON, GIE
 RETURN 
 
TELA_INICIAL:															   
 CALL LCD_INIT									; INICIA O LCD
 CALL TELA_AP									; MOSTRA A TELA INICIAL DO JOGO
 DELAY_S D'1'
 DELAY_S D'1'
 DELAY_S D'1'
 DELAY_S D'1'
 DELAY_S D'1'
 RETURN
 
MOSTRAR_PONTUACAO:
 CALL ENABLE_DISPLAY								; ATIVA O DISPLAY DE 7 SEGMENTOS
 DISPLAY_F DISP_4, PONTUACAO							; EXIBE A PONTUA��O DO JOGADOR NO DISPLAY
 RETURN										
 
 
START:
 CALL TELA_INICIAL
 CALL SETUP_TIMER_INT
 
LOOP:
 ;CALL MOSTRAR_PONTUACAO   
 CMPFL JOGO_RODANDO,1								; SE O JOGO N�O ESTIVER RODANDO VAI PARA O MENU, CASO CONTRARIO VAI PRO JOGO
 JE GAME
 
MENU:
 CALL TELA_INSTRUCOES								; MOSTRA A TELA COM INSTRU��ES
 CALL ENABLE_KEYBOARD								; ATIVA O TECLADO
MENU_INP:
 CALL CORNIO_INPUT								; PEGA A ENTRADA DO USU�RIO, SE NADA FOI PRESSIONADO VOLTA PARA MENU
 CMPFL ENTRADA,KEY_NONE
 JE MENU_INP
 MOVLF 1,JOGO_RODANDO
 DELAY_MS D'250'
 ;DELAY_MS D'250'
 CALL LCD_ENABLE
 LCD_CMD L_CLR
 
GAME:
 CALL CORNIO_INPUT
 CMPFL ENTRADA,KEY_NONE
 JE PLAYER_NOT_JUNP
 MOVLF 1,VOANDO
 
PLAYER_NOT_JUNP:
 CALL TELA_GAME
 GOTO LOOP
 END