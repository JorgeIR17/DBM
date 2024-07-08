/***************************************************************************//**
 * \file    pca9532_lpc40xx.h
 *
 * \brief   Funciones para acceder a un sensor de temperatura PCA9532 a través de
 *          uno de los interfaces I2C del LPC40xx.
 */

#ifndef PCA9532_LPC40XX_H
#define PCA9532_LPC40XX_H

#include <LPC407x_8x_177x_8x.h>
#include "tipos.h"

/*===== Constantes =============================================================
 */

/* Dirección I2C del PCA9532 en la tarjeta Embedded Artists LPC4088
 * Developer's Kit.
 */

/*--------------COMPLETAR-------------------*/

/* Registros del LM75B.
 */

/*--------------COMPLETAR-------------------*/

/*===== Prototipos de funciones ================================================
 */
 
void pca9532_inicializar(LPC_I2C_TypeDef *i2c_regs,
                       uint32_t frecuencia_scl,                       
                       LPC_GPIO_TypeDef *puerto_sda,
                       uint32_t mascara_pin_sda,
                       LPC_GPIO_TypeDef *puerto_scl,
                       uint32_t mascara_pin_scl,
                       uint8_t direccion_i2c_pca9532);

void pca9532_escribir_registro(uint8_t registro_a_escribir,
                             uint8_t dato_a_escribir);
                                 
uint8_t pca9532_leer_registro(uint8_t registro_a_leer);
                                     

#endif  /* PCA9532_LPC40XX_H */



