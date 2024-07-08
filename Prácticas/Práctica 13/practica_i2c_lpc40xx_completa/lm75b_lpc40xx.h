/***************************************************************************//**
 * \file    lm75b_lpc40xx.h
 *
 * \brief   Funciones para acceder a un sensor de temperatura LM75B a través de
 *          uno de los interfaces I2C del LPC40xx.
 */

#ifndef LM75B_LPC40XX_H
#define LM75B_LPC40XX_H

#include <LPC407x_8x_177x_8x.h>
#include "tipos.h"

/*===== Constantes =============================================================
 */

/* Dirección I2C del LM75B en la tarjeta Embedded Artists LPC4088
 * Developer's Kit.
 */
#define LM75B_DIR_I2C   0x48

/* Registros del LM75B.
 */
#define LM75B_REG_TEMP  0
#define LM75B_REG_CONF  1
#define LM75B_REG_THYST 2
#define LM75B_REG_TOS   3

/*===== Prototipos de funciones ================================================
 */
 
void lm75b_inicializar(LPC_I2C_TypeDef *i2c_regs,
                       uint32_t frecuencia_scl,                       
                       LPC_GPIO_TypeDef *puerto_sda,
                       uint32_t mascara_pin_sda,
                       LPC_GPIO_TypeDef *puerto_scl,
                       uint32_t mascara_pin_scl,
                       uint8_t direccion_i2c_lm75);

void lm75b_escribir_registro(uint8_t registro_a_escribir,
                             uint16_t dato_a_escribir);
                                 
uint16_t lm75b_leer_registro(uint8_t registro_a_leer);
                                     
float lm75b_leer_temperatura(void);

#endif  /* LM75B_LPC40XX_H */



