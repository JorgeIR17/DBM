#include <immintrin.h>
#include <stdio.h>

int fi_media_floats(float *ptr_datos,unsigned int longitud_array,float *ptr_resultado)
{

	if 	(ptr_datos == NULL || ((unsigned long long)ptr_datos & 0x01F) || ptr_resultado == NULL || longitud_array == 0)
			return 0;

		unsigned int n_bloques = longitud_array/8;
		unsigned int n_sueltos =  longitud_array % 8;
		__m256 bloque = _mm256_set1_ps(0);

		for(int i = 0; i<n_bloques; i++)
		{
			bloque = _mm256_add_ps(bloque, _mm256_load_ps(ptr_datos));
			ptr_datos+=8;
		}

		bloque = _mm256_hadd_ps(bloque, bloque);
		bloque = _mm256_hadd_ps(bloque, bloque);
		bloque = _mm256_add_ps(bloque, _mm256_permute2f128_ps(bloque, bloque, 1));
		__m128 aux = _mm256_castps256_ps128(bloque);
		_mm_store_ss(ptr_resultado, aux); //suma de los elementos de los bloques

		for(int i = 0; i<n_sueltos; i++) //elementos sueltos
		{
			*ptr_resultado += *ptr_datos;
			ptr_datos++;
		}

		*ptr_resultado = *ptr_resultado/longitud_array;

		return 1;
}

int main()
{
	float array[22] __attribute__ ((aligned (32))) = {3.0, 5.0, 2.0, 9.0, 1.0, 4.0, 7.0, 2.0, 6.0, 9.0, 1.0, 2.0, 5.0, 4.0, 7.0, 6.0, 3.0, 8.0, 2.0, 4.0, 1.0, 5.0};
	unsigned int longitud_array = 22;
	float resultado;


	    int comprobar = fi_media_floats(array, longitud_array, &resultado);

		printf("Elementos: ");
		for(int i = 0; i<longitud_array; i++)
		{
				printf(" %f ",array[i]);
		}

		printf("\n");

		if (comprobar != 0)
		{
			printf("\n\nMedia: %f",resultado);
		}

		else
			printf("\nError");

		return 0;
}
