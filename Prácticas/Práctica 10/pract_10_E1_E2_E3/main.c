/***************************************************************************//**
 * \file    main.c
 *
 * \brief   Funci�n main para la pr�ctica 7 Ejercico 2 y 3.
 */

#include <LPC407x_8x_177x_8x.h>
#include "glcd.h"
#include "adc_lpc40xx.h"
#include "timer_lpc40xx.h"
#include "termistor_ntc.h"



/*EJERCICIO 1*/

/*
int main(void)
{
    uint32_t voltaje;
		float tension;
	
		glcd_inicializar();
	
		timer_inicializar(TIMER0);
		adc_inicializar(1000000, SEL_CANAL_2);
		timer_iniciar_ciclos_ms(TIMER0, 1000);
		while(1)
		{
				voltaje = adc_convertir(2);
				tension = adc_traducir_a_tension(voltaje);
				timer_esperar_fin_ciclo(TIMER0);
			glcd_xprintf(0, 0, BLANCO, NEGRO, FONT16X32, "Resultado ADC: %d \n Tension potenciometro: %.2f", voltaje, tension);
		}
}
*/

/*EJERCICIO 2-3*/


int main(void)
{
		uint32_t voltaje, temp_adc, i;
		float tension, trad, temperatura;
	
		glcd_inicializar();
		timer_inicializar(TIMER0);
		timer_inicializar(TIMER1);
		adc_inicializar(1000000, SEL_CANAL_2);
		adc_inicializar(1000000, SEL_CANAL_0);
		timer_iniciar_ciclos_ms(TIMER0, 10);
		i = 0;
	
		while(1)
		{
				voltaje = adc_convertir(2);
				tension = adc_traducir_a_tension(voltaje);
			
				temp_adc = adc_convertir(0);
				trad = adc_traducir_a_tension(temp_adc);
				temperatura += ntc_traducir_tension_a_temperatura(trad);
				i++;
			
				timer_esperar_fin_ciclo(TIMER0);
			
				if(i == 100)
				{
						glcd_xprintf(0, 0, BLANCO, NEGRO, FONT16X32, "Resultado ADC: %d \n Tension potenciometro: %.2f \n Valor temperatura: %.2f", voltaje, tension, temperatura/100);
						i = 0;
						temperatura = 0;
				}
			
		}
}

