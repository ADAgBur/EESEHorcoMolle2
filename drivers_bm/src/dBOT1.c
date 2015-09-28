/* Copyright 2015, Eduardo Filomena, Juan Manuel Reta
 * All rights reserved.
 *
 * This file is part of CIAA Firmware.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/** \brief Blinking Bare Metal example source file
 **
 ** This is a mini example of the CIAA Firmware.
 **
 **/

/** \addtogroup CIAA_Firmware CIAA Firmware
 ** @{ */

/** \addtogroup Examples CIAA Firmware Examples
 ** @{ */
/** \addtogroup Baremetal Bare Metal example source file
 ** @{ */

/*
 * Initials     Name
 * ---------------------------
 *
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * yyyymmdd v0.0.1 initials initial version
 */

/*==================[inclusions]=============================================*/
#include "dBOT1.h"       /* <= own header */

#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)/* Aca me parece que faltar�a incluir los .hpara otros micros*/
#else
#endif


/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */


void InicioBOT(void)
{
   /* perform the needed initialization here */
	Chip_GPIO_Init(LPC_GPIO_PORT);

	Chip_SCU_PinMux(1,0,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_0  en GPIO 0[4], SW1 */
	Chip_SCU_PinMux(1,1,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_1  en GPIO 0[8], SW2 */
	Chip_SCU_PinMux(1,2,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_2  en GPIO 0[9], SW3 */
	Chip_SCU_PinMux(1,6,MD_PUP|MD_EZI|MD_ZI,FUNC0); /* remapea P1_6  en GPIO 1[9], SW4 */

	Chip_GPIO_SetDir(LPC_GPIO_PORT, 0, 1<<4|1<<8|1<<9, 0);
	Chip_GPIO_SetDir(LPC_GPIO_PORT, 1, 1<<9, 0);

	/*return 0;*/
}

int LeeBOT(void) /*PrendeLED(uint8_t LED,uint8_t subled);*/
/* Pasa la funcion (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 4)!=0), si responde algo distinto de cero, devuelve el boton que interrogo.*/
{
	int BOTP;

	if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 4)==0)
	{
		BOTP = 1;
	}
	else if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 8)==0)
	{
		BOTP = 2;
	}
	else if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 9)==0)
	{
		BOTP = 3;
	}
	else if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, 9)==0)
	{
		BOTP = 4;
	}
	else
	{
		BOTP = 0;
	}
	return BOTP;
}

int BOThit(void)
{
	int HIT;
	if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 4)==0)
	{
		HIT = 1;
	}
	else if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 8)==0)
	{
		HIT = 1;
	}
	else if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 0, 9)==0)
	{
		HIT = 1;
	}
	else if (Chip_GPIO_ReadPortBit(LPC_GPIO_PORT, 1, 9)==0)
	{
		HIT = 1;
	}
	else
	{
		HIT = 0;
	}
return HIT;
}
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
