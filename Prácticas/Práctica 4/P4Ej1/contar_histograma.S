%define ptr_datos	RCX
%define num_datos	RDX
%define ptr_hist	R8


global _calcular_histograma
section .text

_calcular_histograma:

		test ptr_datos, ptr_datos
		jz error

		test ptr_hist, ptr_hist
		jz error

		mov r9, 256 ;tamaño del histograma
		mov r10, ptr_hist

bucle_inicial:
		mov dword[ptr_hist], 0
		add ptr_hist, 4 ;relleno a 0 las posiciones del array
		dec r9
		jnz bucle_inicial

		xor r11, r11

bucle:
		mov r11b, [ptr_datos]
		add dword[r10+r11*4], 1 ;incremento la posicion del array del histograma correspondiente al valor
		inc ptr_datos ;paso a la siguiente posicion del array
		dec num_datos
		jnz bucle

		mov eax,1
		jmp salir

salir:	ret

error:	xor eax, eax

