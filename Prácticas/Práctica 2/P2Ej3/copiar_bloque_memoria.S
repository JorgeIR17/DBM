section .text
global _copiar_bloque_memoria

_copiar_bloque_memoria:
    ; Argumentos:
    ;   [esp + 4] = destino
    ;   [esp + 8] = origen
    ;   [esp + 12] = longitud

    mov ecx, [esp + 12]     ; Colocar longitud en ecx
    test ecx, ecx           ; Comprobar si la longitud es cero
    jz .end

    cld                     ; Borrar el bit de dirección para asegurarse de que las operaciones de movimiento se realicen hacia adelante

    mov esi, [esp + 8]      ; Colocar origen en esi
    mov edi, [esp + 4]      ; Colocar destino en edi

    rep movsb               ; Mover bytes de origen a destino

.end:
    mov eax, [esp + 4]      ; Retornar el puntero al destino
    ret
