/***************************************************************************//**
 * \file    lm75b_lpc40xx.c
 *
 * \brief   Funciones para acceder a un sensor de temperatura LM75B a través de
 *          uno de los interfaces I2C del LPC40xx.
 */

#include "lm75b_lpc40xx.h"
#include "i2c_lpc40xx.h"
#include "error.h"

static LPC_I2C_TypeDef *lm75b_interfaz_i2c;
static uint8_t          lm75b_dir_i2c;

/***************************************************************************//**
 * \brief     Incializar la comunicación con el LM75B.
 *
 * \param[in] i2c_regs            Puntero a regs. del interfaz a inicializar.
 * \param[in] frecuencia_scl      Frecuencia de la señal SCL.
 * \param[in] puerto_sda          Puerto que se desea para la función SDA.
 * \param[in] pin_sda             Pin que se desea para la función SDA.
 * \param[in] puerto_scl          Puerto que se desea para la función SCL.
 * \param[in] pin_scl             Pin que se desea para la función SCL.
 * \param[in] direccion_i2c_lm75b Dirección I2C del LM75B.
 */
void lm75b_inicializar(LPC_I2C_TypeDef *i2c_regs,
                       uint32_t frecuencia_scl,                       
                       LPC_GPIO_TypeDef *puerto_sda,
                       uint32_t mascara_pin_sda,
                       LPC_GPIO_TypeDef *puerto_scl,
                       uint32_t mascara_pin_scl,
                       uint8_t direccion_i2c_lm75b)
{
    i2c_inicializar(i2c_regs,
                    frecuencia_scl,                       
                    puerto_sda,
                    mascara_pin_sda,
                    puerto_scl,
                    mascara_pin_scl);
    
    lm75b_interfaz_i2c = i2c_regs;
    lm75b_dir_i2c = direccion_i2c_lm75b;    
}

/***************************************************************************//**
 * \brief       Escribir en un registro interno del LM75B.
 *
 * \param[in]   registro_a_escribir     Número del registro a escribir.
 * \param[in]   dato_a_escribir         Dato a escribir en el registro.
 */
void lm75b_escribir_registro(uint8_t registro_a_escribir,
                             uint16_t dato_a_escribir)
{   
	i2c_start(lm75b_interfaz_i2c);
	
	i2c_transmitir_byte(lm75b_interfaz_i2c, lm75b_dir_i2c << 1);
	
	if(i2c_transmitir_byte(lm75b_interfaz_i2c, registro_a_escribir))
	{
			i2c_transmitir_byte(lm75b_interfaz_i2c, dato_a_escribir >> 8);
			i2c_transmitir_byte(lm75b_interfaz_i2c, dato_a_escribir & 0xFF);
	}
	
	i2c_stop(lm75b_interfaz_i2c);
		
}

/***************************************************************************//**
 * \brief       Leer un registro interno del LM75B.
 *
 * \param[in]   registro_a_leer     Número del registro a leer.
 *
 * \return      Valor leído del registro.
 */
uint16_t lm75b_leer_registro(uint8_t registro_a_leer)
{
		uint16_t dato_a_leer = 0;
	
		i2c_start(lm75b_interfaz_i2c);
	
		i2c_transmitir_byte(lm75b_interfaz_i2c, lm75b_dir_i2c << 1);
	
		if(i2c_transmitir_byte(lm75b_interfaz_i2c, registro_a_leer))
		{
				i2c_start(lm75b_interfaz_i2c);
				
				i2c_transmitir_byte(lm75b_interfaz_i2c, (lm75b_dir_i2c << 1) | 0x01);
				
				dato_a_leer |= (uint16_t)i2c_recibir_byte(lm75b_interfaz_i2c, TRUE) << 8;
				
				dato_a_leer |= i2c_recibir_byte(lm75b_interfaz_i2c, FALSE);
		}
		
		i2c_stop(lm75b_interfaz_i2c);
		
		return dato_a_leer;
}

/***************************************************************************//**
 * \brief   Leer el registro TEMP del LM75B y retornar la temperatura
 *          correspondiente en grados centígrados.
 *
 * \return  Temperatura en grados centígrados.
 */
float32_t lm75b_leer_temperatura(void)
{
		uint16_t dato = lm75b_leer_registro(LM75B_REG_TEMP);
	
		float32_t temperatura = (dato >> 7) / 2.0f;
	
		return temperatura;
}
