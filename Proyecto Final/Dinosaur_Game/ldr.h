/***************************************************************************//**
 * \file    ldr.h
 *
 * \brief   Conversión de la tensión en un divisor de tensión con LDR a la
 *          iluminancia en lux correspondiente.
 */

#ifndef LDR_H
#define LDR_H

#include "tipos.h"

#define UMBRAL_LDR 15

/*===== Prototipos de funciones ================================================
 */

float32_t ldr_traducir_a_iluminancia(float32_t V_s);

#endif  /* LDR_H */
