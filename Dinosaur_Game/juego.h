#ifndef JUEGO_H
#define JUEGO_H

#include "tipos.h"
#include "ldr.h"
#include "sonido.h"
#include "glcd.h"
#include "adc_lpc40xx.h"
#include "timer_lpc40xx.h"
#include "joystick.h"
#include <stdbool.h>
#include "personajes.h"

int32_t juego(uint16_t color_fondo, uint16_t color_personajes, int32_t max);

#endif
