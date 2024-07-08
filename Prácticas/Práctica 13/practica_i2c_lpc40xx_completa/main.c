/***************************************************************************//**
 * Ejemplo de acceso a un sensor de temperatura LM75B mediante el interfaz I2C 0
 * del LPC4088.
 */

#include <LPC407x_8x_177x_8x.h>
#include "i2c_lpc40xx.h"
// #include "pca9532_lpc40xx.h"
#include "lm75b_lpc40xx.h"
#include "gpio_lpc40xx.h"
#include "timer_lpc40xx.h"
#include "uart_lpc40xx.h"
#include "glcd.h"
#include <stdio.h>

/*EJERCICIO 1*/

/*
int main(void)
{
	
	glcd_inicializar();
	timer_inicializar(TIMER0);
	
	lm75b_inicializar(I2C0, 100000, 
	PORT0, (1<<27), PORT0, (1<<28), LM75B_DIR_I2C);
	
	while(1)
	{
			glcd_xprintf(0, 0, BLANCO, NEGRO, FONT16X32,
				"Valor temperatura: %2.1f ºC", lm75b_leer_temperatura());
			timer_retardo_ms(TIMER0, 1000);
	}
}
*/

/*EJERCICIO 2*/

int main(void)
{
	char temperatura[20];
	
	glcd_inicializar();
	timer_inicializar(TIMER0);
	
	uart_inicializar(UART0, UART_BAUDRATE_9600, UART_BITS_DATOS_8, 
	UART_PARIDAD_NINGUNA, UART_BITS_STOP_1, 
	PUERTO0, PIN2, PUERTO0, PIN3, NULL);
	
	lm75b_inicializar(I2C0, 100000, 
	PORT0, (1<<27), PORT0, (1<<28), LM75B_DIR_I2C);
	
	while(1)
	{
			snprintf(temperatura, 20, "\n\nTemperatura: %2.1f\n\n", lm75b_leer_temperatura());
			uart_transmitir_cadena(UART0, temperatura);
			glcd_xprintf(0, 0, BLANCO, NEGRO, FONT16X32,
				"Valor temperatura: %2.1f ºC", lm75b_leer_temperatura());
			timer_retardo_ms(TIMER0, 1000);
	}
}