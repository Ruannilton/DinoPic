#ifndef TELA_AP_INC
#define TELA_AP_INC

#include "lib.inc"

   TELAS_DEF MACRO
     TELA_AP:									;Exibe uma tela com os nomes dos desenvolvedores no inicio do jogo
	CALL LCD_ENABLE
	LCD_CMD L_CLR
	LCD_CMD L_L1	;LINHA 1
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	
	LCD_CMD L_L3	;LINHA 4
	LCD_DAT '*'	;DESENHA *
	LCD_DAT ' '	;DESENHA ' '
	LCD_DAT 'R'	;DESENHA R
	LCD_DAT 'U'	;DESENHA U
	LCD_DAT 'A'	;DESENHA A
	LCD_DAT 'N'	;DESENHA N
	LCD_DAT ' '	;DESENHA ' '
	LCD_DAT 'A'	;DESENHA A
	LCD_DAT 'Z'	;DESENHA Z
	LCD_DAT 'E'	;DESENHA E
	LCD_DAT 'V'	;DESENHA V
	LCD_DAT 'E'	;DESENHA E
	LCD_DAT 'D'	;DESENHA D
	LCD_DAT 'O'	;DESENHA O
	LCD_DAT ' '	;DESENHA ' '
	LCD_DAT '*'	;DESENHA *
	
	LCD_CMD L_L2	;LINHA 4
	LCD_DAT '*'	;DESENHA *
	LCD_DAT ' '	;DESENHA ' '
	LCD_DAT 'J'	;DESENHA J
	LCD_DAT 'A'	;DESENHA A
	LCD_DAT 'N'	;DESENHA N
	LCD_DAT 'D'	;DESENHA D
	LCD_DAT 'E'	;DESENHA E
	LCD_DAT 'R'	;DESENHA R
	LCD_DAT ' '	;DESENHA ' '
	LCD_DAT 'S'	;DESENHA S
	LCD_DAT 'I'	;DESENHA I
	LCD_DAT 'L'	;DESENHA L
	LCD_DAT 'V'	;DESENHA V
	LCD_DAT 'A'	;DESENHA A
	LCD_DAT ' '	;DESENHA ' '
	LCD_DAT '*'	;DESENHA *
	
	LCD_CMD L_L4	;LINHA 4
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	
	RETURN
	
    TELA_INSTRUCOES:								; EXIBE INSTRUÇÕES DO JOGO
	CALL LCD_ENABLE
	LCD_CMD L_CLR
	LCD_CMD L_L1	;LINHA 1
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	
	LCD_CMD L_L2	;LINHA 4
	LCD_DAT '*'	
	LCD_DAT ' '	
	LCD_DAT 'A'	
	LCD_DAT 'P'	
	LCD_DAT 'E'	
	LCD_DAT 'R'	
	LCD_DAT 'T'	
	LCD_DAT 'E'	
	LCD_DAT ' '	
	LCD_DAT 'A'	
	LCD_DAT 'L'	
	LCD_DAT 'G'	
	LCD_DAT 'O'	
	LCD_DAT ' '	
	LCD_DAT ' '	
	LCD_DAT '*'	
	
	LCD_CMD L_L3	
	LCD_DAT '*'	
	LCD_DAT ' '	
	LCD_DAT ' '	
	LCD_DAT 'P'	
	LCD_DAT 'A'	
	LCD_DAT 'R'	
	LCD_DAT 'A'	
	LCD_DAT ' '	
	LCD_DAT 'J'	
	LCD_DAT 'O'	
	LCD_DAT 'G'	
	LCD_DAT 'A'	
	LCD_DAT 'R'	
	LCD_DAT ' '	
	LCD_DAT ' '	
	LCD_DAT '*'	
	
	LCD_CMD L_L4	
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	LCD_DAT D'42'
	
	RETURN
	ENDM
    
    
#endif


