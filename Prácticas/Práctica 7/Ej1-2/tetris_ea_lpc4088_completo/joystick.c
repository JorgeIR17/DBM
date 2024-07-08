/***************************************************************************//**
 * \file    joystick.c
 *
 * \brief   Función básica de lectura del joystick de la tarjeta Embedded
 *          Artist LPC4088.
 *
 * Las conexiones entre el joystick el microcontrolador son las siguientes:
 *
 *     	ARRIBA  	--> P2[25]
 *      ABAJO   	--> P2[27]
 *      IZQUIERDA	--> P2[23]
 *      DERECHA		--> P2[26]
 *      CENTRAL		--> P2[22]
 *
 *
 * Los pulsadores del joystick son activos a nivel bajo: cuando se pulsan ponen
 * el correspondiente pin del microcontrolador a 0 y cuando están sin pulsar
 * ponen el correspondiente pin a 1.
 */

#include <LPC407x_8x_177x_8x.h>
#include "joystick.h"
#include "gpio_lpc40xx.h"
#include "leds.h"
#include "tipos.h"

/***************************************************************************//**
 *
 * \brief   Leer el joystick y retornar un número diferente según la dirección
 *          que se esté pulsando.
 *
 * \return  0 si no se está pulsando ningúna dirección.
 *          1 si el joystick está pulsado hacia ARRIBA.
 *          2 si el joystick está pulsado hacia ABAJO.
 *          3 si el joystick está pulsado hacia la IZQUIERDA.
 *          4 si el joystick está pulsado hacia la DERECHA.
 *          5 si el joystick está pulsado hacia el CENTRO.
 */
int32_t leer_joystick(void)
{
    int32_t valor;
		led_apagar(1);
		led_apagar(2);
		led_apagar(3);
		led_apagar(4);
		
	  if		 (!(LPC_GPIO2 -> PIN &(1u<<25))) valor = JOYSTICK_ARRIBA;
		else if(!(LPC_GPIO2 -> PIN &(1u<<26))) valor = JOYSTICK_DERECHA;
		else if(!(LPC_GPIO2 -> PIN &(1u<<27))) valor = JOYSTICK_ABAJO;
		else if(!(LPC_GPIO2 -> PIN &(1u<<23))) valor = JOYSTICK_IZQUIERDA;
		else if(!(LPC_GPIO2 -> PIN &(1u<<22))) 
		{
			valor = JOYSTICK_CENTRO;
			led_encender(1);
			led_encender(2);
			led_encender(3);
			led_encender(4);
		}
		else 																	 
			valor = JOYSTICK_NADA;
	
		return valor;
}
