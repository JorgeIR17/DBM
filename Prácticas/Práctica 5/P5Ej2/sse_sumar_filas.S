; int _sse_sumar_filas(const float *ptr_matriz, float *ptr_suma)


%define ptr_matriz 	RCX
%define ptr_suma 	RDX

        global      _sse_sumar_filas

        section    .text

_sse_sumar_filas:

		xor eax, eax

		test ptr_matriz, ptr_matriz
		jz error

		test ptr_matriz, 15
		jnz error

		test ptr_suma, ptr_suma
		jz error

		test ptr_suma ,15
		jnz error

		movaps xmm0,[ptr_matriz] ;fila 1
		movaps xmm1,[ptr_matriz + 16] ;fila 2
		movaps xmm2,[ptr_matriz + 32] ;fila 3
		movaps xmm3,[ptr_matriz + 48] ;fila 4

		addps  xmm0,xmm1
		addps  xmm0,xmm2
		addps  xmm0,xmm3

		movaps [ptr_suma], xmm0

salida: mov eax, 1
		jmp fin

error: xor eax, eax

fin:   ret
