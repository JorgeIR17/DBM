#include<stdio.h>

int _ordenar(int* array, unsigned int longi);

int main(int argc, char *argv[])
{

	int array[10] = {1, 3, 2, 8, 9, 4, 5, 11, 0, 6};
	int ret;
	int i = 0;
	printf(" Array: ");
	for(i = 0; i<10; ++i){
		printf(" %d ", array[i]);
	}

	printf("\n");
	ret = _ordenar(array, 10);

	printf(" Array ordenado: ");
	if (ret){
		for(i = 0; i<10; ++i){
			printf(" %d ", array[i]);
		}
	}

	else
		printf("\nError");

	return 0;
}
