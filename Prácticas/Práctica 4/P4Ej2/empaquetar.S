%define origen 		RCX
%define destino 	RDX

global _empaquetar
section .text

;desempaqutado: aabbb000ccccdddd
;empaquetado:	aabbbccccdddd

_empaquetar:

		test origen, origen
		jz error

		test destino, destino
		jz error

		;short: 2 bytes

		mov eax, [origen]
		mov [destino], eax

		;char[3]: 3 bytes

		mov eax, [origen + 2]
		mov [destino + 2], eax

		mov eax, [origen + 3]
		mov [destino + 3], eax

		mov eax, [origen + 4]
		mov [destino + 4], eax

		;int: 4 bytes

		mov eax, [origen + 8]
		mov [destino + 5], eax

		;long: 4 bytes

		mov eax, [origen + 12]
		mov [destino + 9], eax

		mov eax, 1
		jmp salir

salir:	ret

error:	xor eax, eax

