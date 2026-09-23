/*==============================================================================
 * Fichero: main.c
 *------------------------------------------------------------------------------
 * Fichero en C para el programa de ejemplo.
 * =============================================================================
 */
#include <stdio.h>
int logicas(unsigned int a, unsigned int b);
int main(int argc, char *argv[])
{
	unsigned int a = 0xAAAAAAAA;
	unsigned int b = 0xBBBBBBBB;
	unsigned int c;
	setvbuf(stdout, NULL, _IONBF, 0);



	c = logicas(a,b);

	printf("\nEl resultado es %x", c);
	return 0;
}
