/*==============================================================================
 * Fichero: main.c
 *------------------------------------------------------------------------------
 * Fichero en C para el programa de ejemplo.
 * =============================================================================
 */
#include <stdio.h>

char * uint_a_cadena_binario(unsigned int dato, char * buffer);

int main(int argc, char *argv[])
{
	unsigned int a = 20;
	char buffer[33];
	char * c;

	setvbuf(stdout, NULL, _IONBF, 0);

	c = uint_a_cadena_binario(a, buffer);

	printf("%s",c);
	return 0;
}
