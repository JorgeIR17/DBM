/***************************************************************************//**
 * \file    main.c
 *
 * \brief   
 */

#include <LPC407x_8x_177x_8x.h>
#include <stdlib.h>
#include <string.h>
#include "glcd.h"
#include "adc_lpc40xx.h"
#include "timer_lpc40xx.h"
#include "ldr.h"
#include "sonido.h"
#include "juego.h"
#include "menu.h"

int main(void)
{
    int32_t max = 0;
    uint16_t color_fondo, color_personajes;
    uint32_t voltaje;
	float valor_ldr;

    glcd_inicializar();
    timer_inicializar(TIMER0);
    adc_inicializar(1000000, SEL_CANAL_0); //LDR

    voltaje = adc_convertir(0);
	valor_ldr = adc_traducir_a_tension(voltaje);
	valor_ldr = ldr_traducir_a_iluminancia(valor_ldr);

    if(valor_ldr < UMBRAL_LDR)
    {
        color_fondo = NEGRO;
        color_personajes = BLANCO;
    }
    else
    {
        color_fondo = BLANCO;
        color_personajes = NEGRO;
    }

    while(1)
    {
        glcd_borrar(color_fondo);
        menu_inicio(color_fondo, color_personajes);
        max = juego(color_fondo, color_personajes, max);
    }
}
