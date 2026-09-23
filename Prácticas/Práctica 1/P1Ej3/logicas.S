;===============================================================================
; Fichero: mayor.S
;-------------------------------------------------------------------------------
; Fichero con la función mayor en ensamblador que devuelve el mayor de dos
; números enteros pasados como parámetros.
;
; Versión para Windows.
;===============================================================================
global _logicas
section .text

_logicas: 	push ebp
		mov ebp, esp
		mov eax, [ebp + 8]
		mov ecx, [ebp + 12]
		and eax, 0xFF000000 ;dejo a 0 todo menos los 8 primeros bits
		and ecx, 0x00FFFFFF ;a la inversa en el segundo
		or eax, ecx
		pop ebp
		ret
