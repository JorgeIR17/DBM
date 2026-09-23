#include <stdio.h>

int convertir_celsius_fahrenheit(int temperatura_entrada, int sentido_conversion, int *temperatura_salida);

int main(int argc, char *argv[]) {

    int entrada = 96;
    int sentido = 1;
    int salida;
    int resultado;

    setvbuf(stdout, NULL, _IONBF, 0);

    printf("Conversion de temperatura\n");

    resultado = convertir_celsius_fahrenheit(entrada, sentido, &salida);

    if (sentido == 1)
        printf("\nDe Fahrenheit a Celsius: %i °F ---> %i °C", entrada, salida);
    else
        printf("\nDe Celsius a Fahrenheit: %i °C ---> %i °F", entrada, salida);

    return 0;
}
