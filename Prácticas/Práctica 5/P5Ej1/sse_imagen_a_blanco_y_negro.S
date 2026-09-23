section .text
global _sse_imagen_a_blanco_y_negro

_sse_imagen_a_blanco_y_negro:

    test rdi, rdi
    jz .error
    test rsi, rsi     
    jle .error
    test rdx, rdx     
    jle .error
    test rdi, 0xF
    jnz .error

    ; Inicializar registros SSE
    movd xmm1, ecx          
    punpcklbw xmm1, xmm1    

    ; Procesamiento de la imagen
    mov r8, rdx              ; r8 = alto
.loop_height:
    mov r9, rsi             ; r9 = ancho
.loop_width:
    movdqu xmm0, [rdi]      
    pcmpgtb xmm0, xmm1      
    pcmpeqb xmm0, xmm1     
    movdqu [rdi], xmm0      

    add rdi, 16             
    sub r9, 16              
    jg .loop_width         

    add rdi, rsi            
    dec r8                 
    jg .loop_height         

    mov eax, 1              
    ret

.error:
    xor eax, eax           
    ret
