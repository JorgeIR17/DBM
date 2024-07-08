/***************************************************************************//**
 * \file    main.c
 *
 * \brief   Ejemplo de uso de interrupciones que usa la interrupci�n del timer 0
 *          para mostrar un cron�metro con horas, minutos y segundos.
 */

#include <LPC407x_8x_177x_8x.h>
#include <stdio.h>
#include "tipos.h"
#include "glcd.h"
#include "timer_lpc40xx.h"
#include "joystick.h"
#include "leds.h"

/* Los nombres de los registros de las interrupciones de los pines de los
 * puertos P0 y P2 del fichero LPC407x_8x_177x_8x.h no est�n actualizados
 * a la �ltima versi�n del manual del microcontrolador.
 *
 * Aqu� se redefinen de forma que coincidan con el manual.
 */

typedef struct
{
    __I  uint32_t STATUS;
    __I  uint32_t STATR0;
    __I  uint32_t STATF0;
    __O  uint32_t CLR0;
    __IO uint32_t ENR0;
    __IO uint32_t ENF0;
       uint32_t RESERVED0[3];
    __I  uint32_t STATR2;
    __I  uint32_t STATF2;
    __O  uint32_t CLR2;
    __IO uint32_t ENR2;
    __IO uint32_t ENF2;
} LPC_GPIOINT_TypeDef_corregido;

#undef  LPC_GPIOINT
#define LPC_GPIOINT ((LPC_GPIOINT_TypeDef_corregido   *) LPC_GPIOINT_BASE  )

/* Variables globales para mantener el tiempo.
 */
static uint32_t horas = 0;
static uint32_t minutos = 0;
static uint32_t segundos = 0;

int main(void)
{
    // Inicializar el LCD.
	
    glcd_inicializar();

    // Inicializar las variables horas, minutos y segundos.
     
    horas = 0;
    minutos = 0;
    segundos = 0;
    	
	// Borrar peticiones de interrupci�n del timer 0 pendientes.
     		
	
    NVIC_ClearPendingIRQ(TIMER0_IRQn);
    
    // Asignar prioridad 1 a la interrupci�n del timer 0.
     
     
    NVIC_SetPriority(TIMER0_IRQn, 1);

    // Habilitar la interrupci�n del timer 0.
     
     
    NVIC_EnableIRQ(TIMER0_IRQn);

    // Habilitar globalmente las interrupciones.
     
     
    __enable_irq();
                 
    // Inicializar el timer 0.
     
     
    timer_inicializar(TIMER0);
    
    // Iniciar la generaci�n de ciclos de 1 segundo con el timer 0.
     // (funci�n timer_iniciar_ciclos_ms de la pr�ctica anterior).
     
     
    timer_iniciar_ciclos_ms(TIMER0, 1000);
    
    // Imprimir el reloj por primera vez.
     
    glcd_xprintf(0, 0, WHITE, BLACK, FONT16X32, "%02u:%02u:%02u",
                 horas, minutos, segundos);
    

    // Inicializar los LEDs.
     
    leds_inicializar();
		
		NVIC_ClearPendingIRQ(GPIO_IRQn);
		
		LPC_GPIOINT->CLR2 |= (1<<25) | (1<<27); //flags de peticion de interrupcion de los pines a 0
		LPC_GPIOINT->ENF2 |= (1<<25) | (1<<27); //permitir interrupciones por flancos de bajada
		
		NVIC_SetPriority(GPIO_IRQn, 0);
		NVIC_EnableIRQ(GPIO_IRQn);
		
   
    while (TRUE)
    {
        // Si el joystick se pulsa hacia el centro, encender el LED 1,
         // si no, apagarlo.
         
         
        if(leer_joystick() == JOYSTICK_CENTRO)
						led_encender(LED1);
				else
						led_apagar(LED1);
    }
}

/***************************************************************************//**
 * \brief   Rutina de servicio de interrupci�n del timer 0.
 */
void TIMER0_IRQHandler(void)
{
    segundos++;
		if(segundos == 60)
		{
				segundos = 0;
				minutos++;
				if(minutos == 60)
				{
						minutos = 0;
						horas++;
						if(horas == 24)
								horas = 0;
				}
		}
		
		glcd_xprintf(0, 0, WHITE, BLACK, FONT16X32, "%02u:%02u:%02u",
                 horas, minutos, segundos);
		TIMER0->IR = 1;
		NVIC_ClearPendingIRQ(TIMER0_IRQn);
}

/***************************************************************************//**
 * \brief   Manejador de interrupci�n de las interrupciones de los pines
 *          de los puertos P0 y P2.
 */
/*******************************************************************************
 * PARA EL EJERCICIO 2. NO ES NECESARIO COMPLETAR PARA EL EJERCICIO 1.
 */
void GPIO_IRQHandler(void)
{
    if(LPC_GPIOINT->STATF2 & (1<<27)) //hacia abajo -> para
		{
				LPC_GPIOINT->CLR2 = (1<<27);
				TIMER0->TCR = 0;
				NVIC_ClearPendingIRQ(TIMER0_IRQn);
		}
		if(LPC_GPIOINT->STATF2 & (1<<25)) //hacia arriba -> continua
		{
				LPC_GPIOINT->CLR2 = (1<<25);
				TIMER0->TCR = 1;
				NVIC_ClearPendingIRQ(TIMER0_IRQn);
		}
}
