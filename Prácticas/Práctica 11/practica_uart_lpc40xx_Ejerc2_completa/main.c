/***************************************************************************//**
 * \file    main.c
 * \brief   Función main para la práctica sobre UART.
 */
#include <LPC407x_8x_177x_8x.h>
#include "glcd.h"
#include "joystick.h"
#include "leds.h"
#include "error.h"
#include "uart_lpc40xx.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "adc_lpc40xx.h"
#include "termistor_ntc.h"

int main(void)
{ // Declaración de las variables necesarias.    
		uint32_t voltaje, temp_adc;
		float tension, trad, temperatura;
		char orden[20];
		char envio[20];
	
	// Inicializar la UART0:
  // 9600 baudios, datos de 8 bits, sin paridad y un bit de stop.
  // Usar el pin P0[2] para TxD y el pin P0[3] para RxD.
    
		uart_inicializar(UART0,UART_BAUDRATE_9600, UART_BITS_DATOS_8, 
		UART_PARIDAD_NINGUNA,UART_BITS_STOP_1, PUERTO0, 
		PIN2, PUERTO0, PIN3, NULL);	
	
		glcd_inicializar();

		adc_inicializar(1000000, SEL_CANAL_2);
		adc_inicializar(1000000, SEL_CANAL_0);
	
		while(1)
		{
				uart_recibir_cadena(UART0, orden, 20);
				if(strcmp(orden, "tension") == 0)
				{
					voltaje = adc_convertir(2);
					tension = adc_traducir_a_tension(voltaje);
					snprintf(envio, 20, "\n\nTension: %4.2f\n\n", tension);
					uart_transmitir_cadena(UART0, envio);
				}
				
				else if(strcmp(orden, "temperatura") == 0)
				{
					temp_adc = adc_convertir(0);
					trad = adc_traducir_a_tension(temp_adc);
					temperatura = ntc_traducir_tension_a_temperatura(trad);
					snprintf(envio, 20, "\n\nTemperatura: %4.2f\n\n", temperatura);
					uart_transmitir_cadena(UART0, envio);
				}
		}
}
  
    

