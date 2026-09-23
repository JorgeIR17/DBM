#include <stdio.h>


int _sse_sumar_filas(const float *ptr_matriz, float *ptr_suma);

int main(int argc, char* argv[])
{
    float ptr_matriz[16] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0};
    float ptr_suma[4];

    if(_sse_sumar_filas(ptr_matriz, ptr_suma) == 1){
    	for (int i=0; i<4; i++){
    		printf(" %.1f ",ptr_suma[i]);
    	}
    }

    else printf ("error");
	return 0;
}
