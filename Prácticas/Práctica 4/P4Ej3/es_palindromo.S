%define cadena RCX

global _es_palindromo
section .text

_es_palindromo:
    xor rax, rax
    xor r8, r8
    xor r9, r9
    xor r10, r10

    test cadena, cadena
    jz error

    mov rdx, rcx     ; Guarda el puntero inicial de la cadena
    mov r8, -1       ; Índice final de la cadena (comienza en -1)

longitud:
    cmp byte [rdx], 0  ; Comprueba si hemos llegado al final de la cadena
    je palindromo
    inc rdx            ; Avanza al siguiente byte de la cadena
    inc r8             ; Incrementa el índice final de la cadena
    jmp longitud

palindromo:
    mov rdx, rcx       ; Restaura el puntero al inicio de la cadena
    add rdx, r8        ; Mueve el puntero al último byte de la cadena

bucle:
    cmp byte [rcx], 0  ; Comprueba si hemos llegado al final de la cadena
    je exito
    mov al, byte [rcx]  ; Carga el byte actual de la cadena
    mov r9b, byte [rdx]  ; Carga el byte correspondiente desde el final de la cadena
    cmp al, r9b         ; Compara los bytes
    jne no_palindromo  ; Si no son iguales, salta a no_palindromo
    inc rcx            ; Avanza al siguiente byte de la cadena
    dec rdx            ; Retrocede al byte anterior de la cadena
    jmp bucle

no_palindromo:
    mov rax, 0
    jmp fin

error:
    mov rax, -1
    jmp fin

exito:
    mov rax, 1

fin:
    ret





