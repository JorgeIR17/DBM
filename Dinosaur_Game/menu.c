#include "menu.h"

void menu_inicio(uint16_t color_fondo, uint16_t color_texto)
{
    int32_t i, j, valor;
		Dinosaurio_t dino_menu;
		dino_menu.x = 63;
		dino_menu.y = 40;
		

    glcd_borrar(color_fondo);

    timer_retardo_ms(TIMER0, 1500);

    for (i = 0; i < MENU_ALTO; i++) 
	{
        for (j = 0; j < MENU_ANCHO; j++) 
		{
            if (tituloMenu[i][j] == 1) 
			{
                bloque_pintar(BLOQUE_TAMANO * (40 + j), BLOQUE_TAMANO * (20 + i), color_texto);
            } 
        }
    }

    glcd_xprintf(50, 210, color_texto, color_fondo, FONT12X24, "PRESIONA EL JOYSTICK PARA JUGAR");
		
		dino_pintar_menu(&dino_menu, color_texto);

    valor = leer_joystick();

    while(valor != JOYSTICK_CENTRO)
    { 
        valor = leer_joystick();
    }

    glcd_borrar(color_fondo);
}
