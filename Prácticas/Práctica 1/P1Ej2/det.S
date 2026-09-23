;===============================================================================
; Fichero: mayor.S
;-------------------------------------------------------------------------------
; Fichero con la función mayor en ensamblador que devuelve el mayor de dos
; números enteros pasados como parámetros.
;
; Versión para Windows.
;===============================================================================
global _det
section .text

_det: 	push ebp
		mov ebp, esp
		mov eax, [ebp + 8] ;valor a11
		mov ecx, [ebp + 12] ;valor a12
		imul eax, [ebp + 20] ;a11 * a22
		imul ecx, [ebp + 16] ;a12 * a21
		sub eax, ecx ;resta
		pop ebp
		ret
