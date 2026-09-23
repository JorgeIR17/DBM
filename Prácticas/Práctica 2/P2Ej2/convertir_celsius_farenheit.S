section .text
global _convertir_celsius_fahrenheit

_convertir_celsius_fahrenheit:
    push ebp
    mov ebp, esp
    push ebx
    push ecx
    push edx

    mov eax, [ebp+8]  ; temperatura_entrada
    mov ebx, [ebp+12] ; sentido_conversion
    mov ecx, [ebp+16] ; temperatura_salida

    cmp ebx, 0        ; Comprobamos el sentido de la conversión
    je celsius_to_fahrenheit

fahrenheit_to_celsius:
    ; Fórmula: T(oC) = (T(oF) - 32) * 5 / 9
    sub eax, 32       ; Restamos 32 para obtener los grados Fahrenheit en base 0
    mov ecx, 5        ; Preparamos para la multiplicación
    imul ecx          ; Multiplicamos por 5
    mov edx, 0        ; Limpiamos EDX para la división
    mov ecx, 9        ; Preparamos para la división
    idiv ecx          ; Dividimos por 9
    mov ebx, [ebp+16] ; Cargamos la dirección de temperatura_salida
    mov [ebx], eax    ; Almacenamos el resultado en temperatura_salida
    jmp conversion_done


celsius_to_fahrenheit:
    ; Fórmula: T(oF) = T(oC) * 9 / 5 + 32
    mov eax, [ebp+8]  ; Cargamos la temperatura_entrada en eax
    mov edx, 0        ; Limpiamos EDX
    mov ebx, 9        ; Preparamos para la multiplicación
    imul ebx          ; Multiplicamos por 9
    mov ebx, 5        ; Preparamos para la división
    idiv ebx          ; Dividimos por 5
    add eax, 32       ;s Sumamos 32 para obtener los grados Fahrenheit
    mov [ecx], eax    ; Almacenamos el resultado en temperatura_salida
    jmp conversion_done

conversion_done:
    pop edx
    pop ecx
    pop ebx
    mov esp, ebp
    pop ebp
    ret
