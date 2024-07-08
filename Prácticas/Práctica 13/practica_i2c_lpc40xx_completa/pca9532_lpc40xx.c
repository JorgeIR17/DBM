/***************************************************************************//**
 * \file    pca9532_lpc40xx.c
 *
 * \brief   Funciones para acceder a un sensor de temperatura PCA9532 a través de
 *          uno de los interfaces I2C del LPC40xx.
 */

#include "pca9532_lpc40xx.h"
#include "i2c_lpc40xx.h"
#include "error.h"

static LPC_I2C_TypeDef *pca9532_interfaz_i2c;
static uint8_t          pca9532_dir_i2c;

/***************************************************************************//**
 * \brief     Incializar la comunicación con el PCA9532.
 *
 * \param[in] i2c_regs            Puntero a regs. del interfaz a inicializar.
 * \param[in] frecuencia_scl      Frecuencia de la señal SCL.
 * \param[in] puerto_sda          Puerto que se desea para la función SDA.
 * \param[in] pin_sda             Pin que se desea para la función SDA.
 * \param[in] puerto_scl          Puerto que se desea para la función SCL.
 * \param[in] pin_scl             Pin que se desea para la función SCL.
 * \param[in] direccion_i2c_pca9532 Dirección I2C del PCA9532.
 */
void pca9532_inicializar(LPC_I2C_TypeDef *i2c_regs,
                       uint32_t frecuencia_scl,                       
                       LPC_GPIO_TypeDef *puerto_sda,
                       uint32_t mascara_pin_sda,
                       LPC_GPIO_TypeDef *puerto_scl,
                       uint32_t mascara_pin_scl,
                       uint8_t direccion_i2c_pca9532)
{
    i2c_inicializar(i2c_regs,
                    frecuencia_scl,                       
                    puerto_sda,
                    mascara_pin_sda,
                    puerto_scl,
                    mascara_pin_scl);
    
    pca9532_interfaz_i2c = i2c_regs;
    pca9532_dir_i2c = direccion_i2c_pca9532;    
}

/***************************************************************************//**
 * \brief       Escribir en un registro interno del PCA9532.
 *
 * \param[in]   registro_a_escribir     Número del registro a escribir.
 * \param[in]   dato_a_escribir         Dato a escribir en el registro.
 */
void pca9532_escribir_registro(uint8_t registro_a_escribir,
                             uint8_t dato_a_escribir)
{   
/*--------------COMPLETAR-------------------*/
		
}

/***************************************************************************//**
 * \brief       Leer un registro interno del PCA9532.
 *
 * \param[in]   registro_a_leer     Número del registro a leer.
 *
 * \return      Valor leído del registro.
 */
uint8_t pca9532_leer_registro(uint8_t registro_a_leer)
{
/*--------------COMPLETAR-------------------*/
}
