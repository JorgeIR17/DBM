/***************************************************************************//**
 * \file    leds.c
 *
 * \brief   Funciones para manejar cuatro de los LEDs de la tarjeta Embedded
 *          Artist LPC4088.
 *
 * Las conexiones entre dos de los LEDs de la tarjeta y el microcontrolador son
 * las siguientes:
 *
 *      P1[5]   --> LED1 (ROJO)
 *      P0[14] 	--> LED2 (VERDE)
 *      P0[13]  --> LED3 (VERDE)
 *		P1[18]  -->	LED4 (VERDE)
 *
 * Los LEDs son activos a nivel bajo: cuando uno de estos pines del
 * microcontrolador se pone a 1 el correspondiente LED se apaga y cuando se
 * pone a 0 el LED se enciende.
 */

#include <LPC407x_8x_177x_8x.h>
#include "leds.h"
#include "gpio_lpc40xx.h"
#include "error.h"

/***************************************************************************//**
 * \brief   Configurar como salidas los pines del microcontrolador que están
 *          conectados a los LEDs y apagar todos los LEDs.
 */
void leds_inicializar(void)
{
		//Configurar pines como salida
    LPC_GPIO0 -> DIR |= (1u << 14);
		LPC_GPIO0 -> DIR |= (1u << 13);
		LPC_GPIO1 -> DIR |= (1u << 5);
		LPC_GPIO1 -> DIR |= (1u << 18);
	
		//Apagar leds
		LPC_GPIO1 -> PIN |= (1u << 5); 
		LPC_GPIO0 -> PIN |= (1u << 14);
		LPC_GPIO0 -> PIN |= (1u << 13);
		LPC_GPIO1 -> PIN |= (1u << 18);
}

/***************************************************************************//**
 * \brief       Encender un LED.
 *
 * \param[in]   numero_led  número del LED a encender. Debe estar entre 1 y 4.
 */
void led_encender(int32_t numero_led)
{
    switch (numero_led)
		{
			case 1: LPC_GPIO1 -> PIN &= (~(1u << 5)); break;
			case 2: LPC_GPIO0 -> PIN &= (~(1u << 14)); break;
			case 3: LPC_GPIO0 -> PIN &= (~(1u << 13)); break;
			case 4: LPC_GPIO1 -> PIN &= (~(1u << 18)); break;
		}
}

/***************************************************************************//**
 * \brief       Apagar un LED.
 *
 * \param[in]   numero_led  número del LED a apagar. Debe estar entre 1 y 4.
 */
void led_apagar(int32_t numero_led)
{
    switch (numero_led)
		{
			case 1: LPC_GPIO1 -> PIN |= (1u << 5); break;
			case 2: LPC_GPIO0 -> PIN |= (1u << 14); break;
			case 3: LPC_GPIO0 -> PIN |= (1u << 13); break;
			case 4: LPC_GPIO1 -> PIN |= (1u << 18); break;
		}
}

/***************************************************************************//**
 * \brief       Invertir el estado de un LED.
 *
 * \param[in]   numero_led  número del LED a invertir. Debe estar entre 1 y 4.
 */
void led_invertir(int32_t numero_led)
{
    switch (numero_led)
		{
			case 1: LPC_GPIO1 -> PIN ^= (1u << 5); break;
			case 2: LPC_GPIO0 -> PIN ^= (1u << 14); break;
			case 3: LPC_GPIO0 -> PIN ^= (1u << 13); break;
			case 4: LPC_GPIO1 -> PIN ^= (1u << 18); break;
		}
}

/***************************************************************************//**
 * \brief       Ajustar el estado de una LED
 *
 * \param[in]   numero_led  número del LED a ajustar. Debe estar entre 1 y 4.
 * \param[in]   estado      estado que debe adoptar el LED. TRUE => encendido
 *                          FALSE => apagado.
 */
void led_ajustar(int32_t numero_led, bool_t estado)
{
    if(estado) //Encender led
		{
			switch (numero_led)
			{
				case 1: LPC_GPIO1 -> PIN |= (1u << 5); break;
				case 2: LPC_GPIO0 -> PIN |= (1u << 14); break;
				case 3: LPC_GPIO0 -> PIN |= (1u << 13); break;
				case 4: LPC_GPIO1 -> PIN |= (1u << 18); break;
			}
	}
	else //Apagar led
	{
		switch (numero_led)
		{
			case 1: LPC_GPIO1 -> PIN &= (~(1u << 5)); break;
			case 2: LPC_GPIO0 -> PIN &= (~(1u << 14)); break;
			case 3: LPC_GPIO0 -> PIN &= (~(1u << 13)); break;
			case 4: LPC_GPIO1 -> PIN &= (~(1u << 18)); break;
		}
	}
}
