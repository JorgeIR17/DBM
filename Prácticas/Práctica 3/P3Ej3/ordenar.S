;===============================================================================
;
; Versión para Windows.
;===============================================================================

;*array,longitud
;rcx, rdx


global _ordenar
section .text

;algoritmo Seleccion Directa

_ordenar:
		xor rax,rax

		test rcx,rcx
		jz error

		mov r8,rdx ;tamaño del vector

		xor r10,r10
		xor r11,r11

bucle_externo:
		xor r9,r9  ;indice de inicio del vector

bucle_interno:
		mov eax,[rcx + r9 * 4]
		mov r10, r9 ;indice del minimo

		mov r11, r9
		inc r11

minimo:
		cmp r11,r8
		jge intercambiar

		mov ebx, [rcx + r11 * 4]
		cmp ebx, eax

		jge incrementar_indice

		mov eax,ebx
		mov r10,r11

incrementar_indice:
		inc r11
		jmp minimo

intercambiar:
		mov r11d,[rcx + r9 * 4]
		mov [rcx + r9 * 4], eax
		mov [rcx + r10 * 4], r11d

		inc r9
		cmp r9,r8
		jl bucle_interno

		mov rax,1
		ret

error: 	ret
