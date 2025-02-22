/***************************************************************************//**
 */

#include "bloque.h"
#include "glcd.h"
#include "tipos.h"

static const uint16_t definicion_bloque[BLOQUE_TAMANO][BLOQUE_TAMANO] =
{
    0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF,
    0xFFFF, 0xFFFF, 0xFFFF,
};



/***************************************************************************//**
 */
void bloque_pintar(int32_t x, int32_t y, int16_t color)
{
    int32_t i, j;

    for (i = 0; i < BLOQUE_TAMANO; i++)
    {
        for (j = 0; j < BLOQUE_TAMANO; j++)
        {
            uint16_t c = definicion_bloque[i][j] & color;
            glcd_punto(x + j, y + i, c);                     
        }
    }    
}
