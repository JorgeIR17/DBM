;===============================================================================
;
; Versión para Windows.
;===============================================================================

;*matriz, num_filas_columnas,*resultado
;RCX, RDX, R8


global _sumar_diagonal
section .text

_sumar_diagonal:

			xor rax, rax

			test rdx, rdx
			jz error ;que la matriz no sea de dimension 1

			test r8, r8
			jz error ;puntero resultado no nulo

			xor r9, r9	 ;contador diagonales
			xor r10, r10 ;acumulador
			xor r11, r11 ;indice

bucle:		cmp r9d, EDX ;si hemos llegado al ultimo numero de la diagonal
			je fin_bucle

			add r10, [rcx + r11 * 8] ;sumar el numero
			add r11d, edx
			inc r11
			inc r9 ;aumentamos diagonal
			jmp bucle ;repetir

fin_bucle:	mov [r8], r10 ;mover a resultado
			mov rax , 1 ;exito


error:		ret
