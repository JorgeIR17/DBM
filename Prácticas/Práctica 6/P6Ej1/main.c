#include <immintrin.h>
#include <stdio.h>

int fi_sumar_matrices_4x4_double(const double *ptr_matriz_1, const double *ptr_matriz_2, double *ptr_matriz_suma)
{

	if (ptr_matriz_1 == NULL || ptr_matriz_2 == NULL || ptr_matriz_suma == NULL
		|| ((unsigned long long)ptr_matriz_1 & 0x01F) != 0
		|| ((unsigned long long)ptr_matriz_2 & 0x01F) != 0
		|| ((unsigned long long)ptr_matriz_suma & 0x01F) != 0)
		{
			return 0;
		}

		__m256d fila_matriz1;
		__m256d fila_matriz2;
		__m256d fila_suma;

		for  (int i = 0; i < 4; i++)
		{

			fila_matriz1 = _mm256_load_pd(ptr_matriz_1 + 4 * i);
			fila_matriz2 = _mm256_load_pd(ptr_matriz_2 + 4 * i);

			fila_suma = _mm256_add_pd(fila_matriz1, fila_matriz2);

			_mm256_store_pd(ptr_matriz_suma + 4 * i, fila_suma);
		}

		return 1;
}

int main()
{
	double matriz1[4][4]__attribute__((aligned(32))) = { {9, 5, 4, 5} , {6,3,1,9} , {5,4,2,8} , {2,5,3,7} };
	double matriz2[4][4]__attribute__((aligned(32))) = { {5,2,0,8} , {6,3,4,2} , {3,2,1,6} , {0,6,4,9} };
	double matrizsuma[4][4]__attribute__((aligned(32))) = { {0,0,0,0} , {0,0,0,0} , {0,0,0,0} , {0,0,0,0} };

	printf("Matriz 1: \n\n");
	for (int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%f ",matriz1[i][j]);
		}
		printf("\n");
	}

	printf("\n\nMatriz 2: \n\n");
	for (int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			printf("%f ",matriz2[i][j]);
		}
		printf("\n");
	}

	int correcto = fi_sumar_matrices_4x4_double(*matriz1,*matriz2,*matrizsuma);

	if(correcto != 0)
	{
		printf("\n\nResultado: \n\n");
		for (int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				printf("%f ", matrizsuma[i][j]);
			}
			printf("\n");
		}
	}
	else
		printf ("\n Error");

	return 0;
}
