#IFNDEF CORNIO_BASE
#DEFINE CORNIO_BASE

#include "p16f877a.inc"    
    
 LIB_VARS MACRO       
 CORNIO_DELAY_FT1   RES	       1
 CORNIO_DELAY_FT2   RES	       1  
 CORNIO_DELAY_FT3   RES	       1
 CORNIO_DELAY_FT4   RES	       1  
 ENDM   
    
BANK0 MACRO
 BCF STATUS, RP1
 BCF STATUS, RP0
 ENDM

BANK1 MACRO
 BCF STATUS, RP1
 BSF STATUS, RP0
 ENDM

BANK2 MACRO
 BSF STATUS, RP1
 BCF STATUS, RP0
 ENDM

BANK3 MACRO
 BSF STATUS, RP1
 BSF STATUS, RP0
 ENDM
 
CMPFL MACRO FILE,LITERAL   ; COMPARE FILE TO LITERAL
 MOVF FILE,W
 SUBLW LITERAL
 ENDM
 
CMPFF MACRO FILE1,FILE2	    ; COMPARE FILE TO FILE
 MOVF FILE1,W
 SUBWF FILE2
 ENDM
 
MOVFF MACRO FILE1,FILE2	    ; MOVE FILE TO FILE
 MOVF FILE1,W
 MOVWF FILE2
 ENDM

MOVLF MACRO LITERAL,FILE    ; MOVE LITERAL TO FILE
 MOVLW LITERAL
 MOVWF FILE
 ENDM
 
JE MACRO IF_TRUE	    ; JUMP EQUAL
 BTFSC STATUS, Z
 GOTO IF_TRUE
 ENDM

JNE MACRO IF_TRUE	    ; JUMP NOT EQUAL
 BTFSS STATUS, Z
 GOTO IF_TRUE
 ENDM
 
DELAY_MS MACRO T	    ; DELAY IN MS
    MOVLW D'165' 
    MOVWF CORNIO_DELAY_FT1 
    
    MOVLW T 
    MOVWF CORNIO_DELAY_FT2
    
    DECFSZ CORNIO_DELAY_FT1,1 
    GOTO $-1 
    DECFSZ CORNIO_DELAY_FT2,1
    GOTO $-3
 ENDM
 
 DELAY_S MACRO T	    ; DELAY IN MS
    MOVLW D'165' 
    MOVWF CORNIO_DELAY_FT1 
    
    MOVLW D'255' 
    MOVWF CORNIO_DELAY_FT2
    
    MOVLW D'4'
    MOVWF CORNIO_DELAY_FT3
    
    MOVLW T
    MOVWF CORNIO_DELAY_FT4
    
    DECFSZ CORNIO_DELAY_FT1,1 
    GOTO $-1 
    DECFSZ CORNIO_DELAY_FT2,1
    GOTO $-3
    DECFSZ CORNIO_DELAY_FT3,1
    GOTO $-5
    DECFSZ CORNIO_DELAY_FT4,1
    GOTO $-7
 ENDM
 
 
 #ENDIF CORNIO_BASE

