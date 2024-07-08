#include "juego.h"


int32_t juego(uint16_t color_fondo, uint16_t color_personajes, int32_t max)
{

    int32_t puntos = 0;
	int32_t vel = 0;
	int32_t bajada = 0;
	int32_t ave_pasando = 0, cactus_pasando = 1;
	int32_t contador = 2;
    int8_t jugando = 1;

    static Dinosaurio_t dino;
	Dinosaurio_t prev_dino;
	
	static Ave_t ave;
	Ave_t prev_ave;
	
	static Cactus_t cactus;
	Cactus_t prev_cactus;

    dino_init(&dino);
	ave_init(&ave);
	cactus_init(&cactus);
    glcd_borrar(color_fondo);
    timer_iniciar_ciclos_ms(TIMER0, 20);

    while(jugando == 1)
    {
        timer_esperar_fin_ciclo(TIMER0);
			
		if(ave_pasando == 0 && cactus_pasando == 0)
		{
			if(((contador % 3) == 0) || ((contador % 5) == 0)) ave_pasando = 1;
			if(((contador % 3) != 0) && ((contador % 5) != 0)) cactus_pasando = 1;
		}
			
		if(ave_pasando == 1 && ave.x == 180)
		{
			if((contador % 2) == 0) ave.y = 55;
			if((contador % 2) != 0) ave.y = 40;
		}

        dino_pintar(&dino, color_personajes);
		prev_dino = dino;
		dino_saltar(&dino, bajada);
		dino_agachar(&dino);

		if(prev_dino.y != dino.y)
        {
			dino_borrar(&prev_dino, color_fondo);
			dino_pintar(&dino, color_personajes);
		}
			
		if(ave_pasando == 1)
		{
			ave_pintar(&ave, color_personajes);
			prev_ave = ave;
			ave_mover(&ave, vel);
					
            if(prev_ave.x != ave.x)
            {
				ave_borrar(&prev_ave, color_fondo);
				ave_pintar(&ave, color_personajes);
			}
					
			if(colision(dino.x, dino.y, dino.ancho, dino.alto, ave.x, ave.y, AVE_ANCHO, AVE_ALTO)) jugando = 0;
					
					
			if(ave.x == GLCD_X_MINIMO)
            {
				ave_borrar(&ave, color_fondo);
				ave_init(&ave);
				ave_pasando = 0;
				contador++;
			}
		}
			
		if(cactus_pasando == 1)
			{
			cactus_pintar(&cactus, color_personajes);
			prev_cactus = cactus;
			cactus_mover(&cactus, vel);
					
            if(prev_cactus.x != cactus.x)
            {
				cactus_borrar(&prev_cactus, color_fondo);
				cactus_pintar(&cactus, color_personajes);
			}
								
			if(colision(dino.x, dino.y, dino.ancho, dino.alto, cactus.x, cactus.y, CACTUS_ANCHO, CACTUS_ALTO)) jugando = 0;
				
			if(cactus.x == GLCD_X_MINIMO)
            {
				cactus_borrar(&cactus, color_fondo);
				cactus_init(&cactus);
				cactus_pasando = 0;
				contador++;
			}
		}
			
		glcd_linea(GLCD_X_MINIMO, 220, GLCD_X_MAXIMO, 220, color_personajes);
			
        if(puntos < 9999) puntos++;
		if(puntos > max) max = puntos;
		if(max > 9999) max = 9999;
		if((puntos % 500 == 0) && puntos < 2000) vel++;
		if(puntos == 500) bajada = 1;
		if((puntos % 1000) == 0)
		{
			sonido_emitir_pitido(508, 100);
			sonido_emitir_pitido(780, 200);
		}
			
		glcd_xprintf(350, 20, color_personajes, color_fondo, FONT8X16, "HI %04d SC %04d", max, puntos);   
    }

    glcd_xprintf(180, 80, color_personajes, color_fondo, FONT12X24, "GAME OVER");

    sonido_emitir_pitido(65, 100);
	sonido_emitir_pitido(65, 100);

    timer_iniciar_ciclos_ms(TIMER0, 2000);
    timer_esperar_fin_ciclo(TIMER0);

    return max;
}
