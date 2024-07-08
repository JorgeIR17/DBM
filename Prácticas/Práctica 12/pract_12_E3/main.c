/***************************************************************************//**
 * \file    main.c
 *
 * \brief   Función main para el Ejercicio 3.
 */

#include <LPC407x_8x_177x_8x.h>
#include <stdlib.h>
#include <string.h>
#include "glcd.h"
#include "adc_lpc40xx.h"
#include "timer_lpc40xx.h"
#include "ldr.h"
#include "leds.h"
#include "teclado_4x4.h"
#include "sonido.h"

int main(void)
{
    uint32_t voltaje, umbral;
		float valor_ldr;
		char cadena_recibida[20];
	
		glcd_inicializar();
		timer_inicializar(TIMER0);
		adc_inicializar(1000000, SEL_CANAL_0);
		tec4x4_inicializar();
	
		timer_iniciar_ciclos_ms(TIMER0, 1000);
	
		glcd_xprintf(0, 0, BLANCO, NEGRO, FONT16X32, "\nEscribe el valor del umbral");
		tec4x4_leer_cadena_numeros(cadena_recibida, 20);
	
		umbral = atoi(cadena_recibida);
	
		glcd_borrar(NEGRO);
	
		while(1)
		{
				voltaje = adc_convertir(0);
				valor_ldr = adc_traducir_a_tension(voltaje);
				valor_ldr = ldr_traducir_a_iluminancia(valor_ldr);
			
				if(valor_ldr < umbral)
						sonido_emitir_pitido(415, 100);
			
				timer_esperar_fin_ciclo(TIMER0);
				glcd_xprintf(0, 0, BLANCO, NEGRO, FONT16X32,
				"Valor umbral: %04d\nValor ADC: %04d\nValor LDR: %9.2f", umbral, voltaje, valor_ldr);
		}
}
