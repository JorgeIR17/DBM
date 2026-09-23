#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

int _es_palindromo(const char *cadena);


int main(int argc, char *argv[])
{

	const char *cadena = "girafarig";

	setvbuf(stdout,NULL,_IONBF,0);

	int dato = _es_palindromo(cadena);

	if (dato == 1)
		printf("Es palindromo");
	else
		printf("No es palindromo");

	return 0;
}

#ifdef __cplusplus
}
#endif

