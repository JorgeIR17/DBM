/*==============================================================================
 * Fichero: main.c
 *------------------------------------------------------------------------------
 * Fichero en C para el programa de ejemplo.
 * =============================================================================
 */
#include <stdio.h>
int det(int a11, int a12, int a21, int a22);
int main(int argc, char *argv[])
{
	int a = 4, b = 6, c = 3, d = 2, resul;
	setvbuf(stdout, NULL, _IONBF, 0);


	resul = det(a,b,c,d);

	printf("\nEl determinante de la matriz es %d", resul);
	return 0;
}
