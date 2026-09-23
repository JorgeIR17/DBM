#include <stdio.h>

int _sse_producto_escalar(const float *vector_1, const float *vector_2, unsigned int dimension, float *resultado);

int main(int argc, char* argv[])
{
    // Declaramos los vectores y la variable resultado con alineación de 16 bytes
    float vector_1[6] __attribute__((aligned(16))) = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    float vector_2[6] __attribute__((aligned(16))) = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    float resultado __attribute__((aligned(16))) = 0;

    if(_sse_producto_escalar(vector_1, vector_2, 6, &resultado) == 1){
        printf(" %f ",resultado);
    }
    else {
        printf ("error");
    }
    return 0;
}
