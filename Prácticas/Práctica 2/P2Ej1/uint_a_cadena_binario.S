
global _uint_a_cadena_binario
section .text

_uint_a_cadena_binario:

		push ebp
		mov ebp, esp

%define entero [ebp + 8]
%define buffer [ebp + 12]

		push edi

		xor eax, eax

		mov edi, buffer
		;puntero al buffer
		test edi, edi
		jz 	error

		mov ecx, entero
		mov edx, 32
		;contador

bucle:
		xor al, al
		rol ecx, 1
		adc al, '0'
		;suma 0 en ASCII para obtener el caracter
		mov [edi], al
		;guarda el valor en el puntero
		inc edi
		;pasa al siguiente
		dec edx
		jnz bucle

		mov byte[edi], 0
		mov eax, buffer
		;devuelve el resultado almacenado

error:
		pop edi
		pop ebp
		ret

