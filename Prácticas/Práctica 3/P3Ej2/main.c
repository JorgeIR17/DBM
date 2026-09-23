/*==============================================================================
* Fichero: main.c
*------------------------------------------------------------------------------
* Fichero en C para el programa de ejemplo.
* =============================================================================
*/
#include <stdio.h>

int _sumar_diagonal(long long *matriz, unsigned int num_filas_columnas, long long *resultado);


int main(int argc, char *argv[])
{
	long long array [3][3] = {{3,2,1},{3,5,7},{4,4,8}};
	unsigned int num_fil_col = 3;
	long long ret;
	int comprobar;

	comprobar = _sumar_diagonal(array [0],num_fil_col,&ret);

	if(comprobar) printf("%lld",ret);
	else printf("error");
	return 0;
}
