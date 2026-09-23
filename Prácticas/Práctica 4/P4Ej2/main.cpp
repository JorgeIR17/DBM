#include <stdio.h>
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
	{
		short a;
		char b[3];
		int c;
		long d;
	} estructura;

typedef struct __attribute((packed))__
	{
		short a;
		char b[3];
		int c;
		long d;
	} estructura_empaquetada;

int _empaquetar(const estructura *origen, estructura_empaquetada *destino);
int _desempaquetar(const estructura_empaquetada *origen, estructura *destino);



int main(int argc, char *argv[])
{
	estructura a;
	estructura_empaquetada b;

	a.a = 1;
	a.b[0] = 'a';
	a.b[1] = 'b';
	a.b[2] = '\0';
	a.c = 3;
	a.d = 1327;

	if(_empaquetar(&a,&b)){
		printf ("Estructura empaquetada: \n");
		printf (" %i \n %s \n %d \n %li \n",b.a,b.b,b.c,b.d);
	}

	if(_desempaquetar(&b,&a)){
			printf ("\nEstructura desempaquetada: \n");
			printf (" %i \n %s \n %d \n %li \n",a.a,a.b,a.c,a.d);
	}

	return 0;
}

#ifdef __cplusplus
}
#endif

