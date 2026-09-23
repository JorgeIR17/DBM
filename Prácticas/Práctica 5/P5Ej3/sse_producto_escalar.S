section .text
global _sse_producto_escalar

_sse_producto_escalar:
    mov rax, rdi  ;vector_1
    mov rcx, rsi  ;vector_2
    mov rdx, rdx  ;dimension
    mov r8, r8    ;resultado
    mov r9, r9   

    and rax, 0xF
    jnz error
    and rcx, 0xF
    jnz error

    test rdx, rdx
    jz exito

    xorps xmm0, xmm0 
    xor r11, r11      

bucle:
    movaps xmm1, [rdi + r11*4]

    movaps xmm2, [rcx + r11*4]

    mulps xmm1, xmm2
    addps xmm0, xmm1

    add r11, 4
    cmp r11, rdx
    jl bucle

    haddps xmm0, xmm0
    haddps xmm0, xmm0

    movss [r8], xmm0

exito:
    mov rax, 1
    ret

error:
    mov rax, 0
    ret
