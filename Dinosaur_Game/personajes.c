#include "personajes.h"


void dino_init(Dinosaurio_t *dino)
{
	ASSERT(dino != NULL, "El puntero dino es nulo");
	
	dino->x = 20;
	dino->y = 50;
    dino->alto = DINO_ALTO;
    dino->ancho = DINO_ANCHO;
    dino->saltando = 0;
}

void dino_saltar(Dinosaurio_t *dino, int32_t bajada) 
{
    int32_t valor; 

	ASSERT(dino != NULL, "El puntero dino es nulo");
    valor = leer_joystick();
    if (valor == JOYSTICK_ARRIBA && dino->y == 50) 
		{
			dino->saltando = 1;
			sonido_emitir_pitido(519, 10);
		}

	if(bajada == 0)
	{
		if(dino->saltando == 1 && dino->y > 5) dino->y -= 3;
	    if(dino->y <= 6) dino->saltando = 0;
	    if(dino->saltando == 0 && dino->y < 50) dino->y += 1;
	}
			
	if(bajada == 1)
	{
		if(dino->saltando == 1 && dino->y > 2) dino->y -= 3;
    	if(dino->y <= 3) dino->saltando = 0;
	    if(dino->saltando == 0 && dino->y < 50) dino->y += (1+bajada);
	}
}

void dino_agachar(Dinosaurio_t *dino) 
{
    int32_t valor; 

	ASSERT(dino != NULL, "El puntero dino es nulo");

    valor = leer_joystick();
    if (valor == JOYSTICK_ABAJO && dino->saltando == 0 && dino->y == 50) 
    {
        dino->y = 62;
        dino->alto = DINO_CROUCH_ALTO;
        dino->ancho = DINO_CROUCH_ANCHO;
    }
    if(valor != JOYSTICK_ABAJO && dino->y == 62)
    {
        dino->y = 50;
    }
}

void dino_pintar(Dinosaurio_t *dino, int32_t color_personajes) 
{
    int i, j; 

	ASSERT(dino != NULL, "El puntero dino es nulo");

    if(dino->y <= 50)
	{
        for (i = 0; i < DINO_ALTO; i++) 
		{
            for (j = 0; j < DINO_ANCHO; j++) 
			{
                if (dinoShape[i][j] == 1) 
				{
                    bloque_pintar(BLOQUE_TAMANO * (dino->x + j), BLOQUE_TAMANO * (dino->y + i), color_personajes);
                } 
            }
        }
    }
    if(dino->y == 62)
	{
        for (i = 0; i < DINO_CROUCH_ALTO; i++) 
		{
            for (j = 0; j < DINO_CROUCH_ANCHO; j++) 
			{
                if (dinoCrouchShape[i][j] == 1) 
				{
                    bloque_pintar(BLOQUE_TAMANO * (dino->x + j), BLOQUE_TAMANO * (dino->y + i), color_personajes);
                } 
            }
        }
    }
}

void dino_pintar_menu(Dinosaurio_t *dino, int32_t color_personajes) 
{
    int i, j; 

	ASSERT(dino != NULL, "El puntero dino es nulo");

    for (i = 0; i < DINO_ALTO; i++) 
    {
        for (j = 0; j < DINO_ANCHO; j++) 
        {
            if (dinoShape[i][j] == 1) 
            {
                bloque_pintar(BLOQUE_TAMANO * (dino->x + j), BLOQUE_TAMANO * (dino->y + i), color_personajes);
            }
        }
    }
}

void dino_borrar(Dinosaurio_t *dino, int32_t color_fondo) 
{
	int i, j; 

    ASSERT(dino != NULL, "El puntero dino es nulo");

    if(dino->y <= 50)
	{
        for (i = 0; i < DINO_ALTO; i++) 
		{
            for (j = 0; j < DINO_ANCHO; j++) 
			{
                bloque_pintar(BLOQUE_TAMANO * (dino->x + j), BLOQUE_TAMANO * (dino->y + i), color_fondo);
            }
        }
    }
    if(dino->y == 62)
	{
        for (i = 0; i < DINO_CROUCH_ALTO; i++) 
		{
            for (j = 0; j < DINO_CROUCH_ANCHO; j++) 
			{
                bloque_pintar(BLOQUE_TAMANO * (dino->x + j), BLOQUE_TAMANO * (dino->y + i), color_fondo);
            }
        }
    }
}

void ave_init(Ave_t *ave)
{
	ASSERT(ave != NULL, "El puntero ave es nulo");
	
	ave->x = 180;
}

void ave_mover(Ave_t *ave, int32_t vel) 
{
	ASSERT(ave != NULL, "El puntero ave es nulo");

    if(ave->x > GLCD_X_MINIMO) ave->x -= (1 + vel);
}

void ave_pintar(Ave_t *ave, int32_t color_personajes) 
{
    int i, j; 

	ASSERT(ave != NULL, "El puntero ave es nulo");

    for (i = 0; i < AVE_ALTO; i++) 
	{
        for (j = 0; j < AVE_ANCHO; j++) 
		{
            if (aveShape[i][j] == 1) 
			{
                bloque_pintar(BLOQUE_TAMANO * (ave->x + j), BLOQUE_TAMANO * (ave->y + i), color_personajes);
            } 
        }
    }
}

void ave_borrar(Ave_t *ave, int32_t color_fondo) {
	    int i, j; 

    ASSERT(ave != NULL, "El puntero ave es nulo");

    for (i = 0; i < AVE_ALTO; i++) 
	{
        for (j = 0; j < AVE_ANCHO; j++) 
		{
            bloque_pintar(BLOQUE_TAMANO * (ave->x + j), BLOQUE_TAMANO * (ave->y + i), color_fondo);
        }
    }
}

void cactus_init(Cactus_t *cactus)
{
	ASSERT(cactus != NULL, "El puntero cactus es nulo");
	
	cactus->x = 180;
	cactus->y = 60;
}

void cactus_mover(Cactus_t *cactus, int32_t vel) 
{
	ASSERT(cactus != NULL, "El puntero cactus es nulo");

    if(cactus->x > GLCD_X_MINIMO) cactus->x -= (1 + vel);
}

void cactus_pintar(Cactus_t *cactus, int32_t color_personajes) 
{
    int i, j; 

	ASSERT(cactus != NULL, "El puntero cactus es nulo");

    for (i = 0; i < CACTUS_ALTO; i++) 
	{
        for (j = 0; j < CACTUS_ANCHO; j++) 
		{
            if (cactusShape[i][j] == 1) 
			{
                bloque_pintar(BLOQUE_TAMANO * (cactus->x + j), BLOQUE_TAMANO * (cactus->y + i), color_personajes);
            } 
        }
    }
}

void cactus_borrar(Cactus_t *cactus, int32_t color_fondo) 
{
	int i, j; 

    ASSERT(cactus != NULL, "El puntero cactus es nulo");

    for (i = 0; i < CACTUS_ALTO; i++) 
	{
        for (j = 0; j < CACTUS_ANCHO; j++) 
		{
            bloque_pintar(BLOQUE_TAMANO * (cactus->x + j), BLOQUE_TAMANO * (cactus->y + i), color_fondo);
        }
    }
}

int32_t colision(int32_t x1, int32_t y1, int32_t w1, int32_t h1, int32_t x2, int32_t y2, int32_t w2, int32_t h2)
{
    if(x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2) return 1;
    else return 0;
}
