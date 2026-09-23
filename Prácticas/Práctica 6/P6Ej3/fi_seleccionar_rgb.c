//-----------------------------------------------------------------------------------------------------
/// \file	fi_seleccionar_rgb.h
//

#include "fi_seleccionar_rgb.h"
#include <immintrin.h>

//-----------------------------------------------------------------------------------------------------
/// \brief          Seleccionar componentes de color de una imagen RGB.
///
/// \param[in,out]  ptr_imagen      Puntero a los datos de la imagen. Cada pixel ocupa tres bytes
///                                 con las componentes azul, verde y roja (en ese orden). El puntero
///                                 debe estar alineado a una posici�n divisible entre 32. 
///
/// \param[in]      ancho           ancho de la imagen en pixels.
///
/// \param[in]      alto            alto de la imagen en pixels.
///
/// \param[in]      seleccion_rgb   m�scara para seleccionar qu� componentes de color se conservan:
///                                 Si el bit 0 de seleccion_rgb est� a 1 se conserva la componente azul.
///                                 Si est� a 0 se elimina.
///                                 Si el bit 1 de seleccion_rgb est� a 1 se conserva la componente verde.
///                                 Si est� a 1 se elimina.
///                                 Si el bit 2 de seleccion_rgb est� a 1 se conserva la componente roja.
///                                 Si est� a 2 se elimina.
///
/// \return			0 => error (ptr_imagen nulo o no alineado o ancho == 0 o alto == 0), 1 => �xito.
//

int fi_seleccionar_rgb(unsigned char *ptr_imagen,
                       unsigned int ancho,
                       unsigned int alto,
                       unsigned char seleccion_rgb)
{
	if (((uintptr_t)ptr_imagen) % 32 != 0 || ancho == 0 || alto == 0)
	{
		return 0;
	}

	__m256i mascara_azul1 = _mm256_set_epi8(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	__m256i mascara_azul2 = _mm256_set_epi8(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,0,0,0,0,0,0,0);
	__m256i mascara_azul3 = _mm256_set_epi8(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1);
	__m256i mascara_verde = _mm256_set1_epi8((seleccion_rgb & SELECCIONAR_VERDE) ? -1 : 0);
	__m256i mascara_roja = _mm256_set1_epi8((seleccion_rgb & SELECCIONAR_ROJO) ? -1 : 0);

	for (unsigned int i = 0; i < alto * ancho * 3; i += 96)
	{
	    __m256i pixels = _mm256_load_si256((__m256i*)(ptr_imagen + i));

	    __m256i azul1 = _mm256_and_si256(pixels, mascara_azul1);
	    __m256i azul2 = _mm256_and_si256(pixels, mascara_azul2);
	    __m256i azul3 = _mm256_and_si256(pixels, mascara_azul3);
	    __m256i verde = _mm256_and_si256(pixels, mascara_verde);
	    __m256i roja = _mm256_and_si256(pixels, mascara_roja);

	    __m256i resultado = _mm256_or_si256(azul1, azul2);
	    resultado = _mm256_or_si256(resultado, azul3);
	    resultado = _mm256_or_si256(resultado, verde);
	    resultado = _mm256_or_si256(resultado, roja);

	    _mm256_store_si256((__m256i*)(ptr_imagen + i), resultado);
	}
	return 1;
}

