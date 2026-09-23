#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif


int _calcular_histograma(const unsigned char *ptr_datos, unsigned int num_datos, unsigned int *ptr_histograma);


int main(int argc, char *argv[])
{
	unsigned char array[10] = {1, 5, 4, 4, 4, 4, 1, 2, 1, 0};
	unsigned int histograma[256];


	int i,ret;

	for (i=0;i<10;i++)
	{
		printf(" %d ",array[i]);
	}

	ret = _calcular_histograma(array, 10, histograma);

	printf("\n\nHistograma\n");

	if (ret)
	{
		for (i=0;i<10;i++)
		{
			printf(" %d ",histograma[i]);
		}
	}

	else printf("error");

	return 0;
}

#ifdef __cplusplus
}
#endif

