global _contar_valor_en_array
section .text

%define valor       ECX
%define array       RDX
%define longitud    R8
%define resultado   R9

_contar_valor_en_array:

    test array, array
    jz error

    test resultado, resultado
    jz error

    xor eax, eax ; contador

bucle:

    cmp [array], valor ; compara el contenido de la posición del array con el valor
    jne no_incr
    inc eax ; aumenta el contador

no_incr:
    add array, 4 ; pasa al siguiente elemento (ajusta según el tamaño del elemento)
    dec longitud
    jnz bucle

    mov [resultado], eax ; guarda el resultado
    mov eax, 1 ; indica éxito

error:
    ret
