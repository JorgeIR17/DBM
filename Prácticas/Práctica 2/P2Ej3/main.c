#include <stdio.h>
#include <stdint.h>

void * copiar_bloque_memoria(void * destino, void * origen, unsigned int longitud);

int main(int argc, char *argv[]) {
    uint32_t origen[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    uint32_t destino[10];
    uint32_t longitud = 10;

    printf("COPIA DE MEMORIA CON LONGITUD DE %u\n", longitud);

    copiar_bloque_memoria(destino, origen, longitud * sizeof(uint32_t));

    printf("ORIGEN: ");
    for(int i = 0; i < longitud; i++)
        printf("%u ", origen[i]);

    printf("\nDESTINO: ");
    for(int i = 0; i < longitud; i++)
        printf("%u ", destino[i]);

    printf("\n");

    return 0;
}
