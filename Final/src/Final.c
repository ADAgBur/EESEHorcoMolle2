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
#include "Final.h"       /* <= own header */



/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/
//extern void RITimerISR2(void);

/** \brief Main function
 *
 * This is the main entry point of the software.
 *
 * \returns 0
 *
 * \remarks This function never returns. Return value is only to avoid compiler
 *          warnings or errors.
 */
int VAL;
float GAN;
int BOT;

void RITimerISR2(void)

{
int LEDN;
char sLD;
int PASO;
int CAN;
int VAD;
int VDAC;

CAN=1;
LEDN=0;
sLD='b';

if (LeerTecla(1)==1)
	{
	GAN=GAN+0.1;
	}
if (LeerTecla(2)==1)
	{
	GAN=GAN-0.1;
	}
if (LeerTecla(3)==1)
	{
	GAN=0;
	}
if (LeerTecla(4)==1)
	{
	GAN=1;
	}
int j;
j=1;
for (j=1;j==10000;j+=1)
{
}

//Parte ADC//
VAD=LeerCanalADC(CAN);
/*
if (VAL==930)
{
	PrenderLED(LEDN,sLD,3);
	VAL=0;
}
else
{
	VAL+=PASO;
}
*/
//Parte DAC//

	if (GAN*VAD<=1023)
	{
		VDAC=GAN*VAD;
	}
	if (GAN*VAD>=1023)
	{
		VDAC=1023;
	}

	PrenderLED(1,'o',3);
	SalDAC((int)VDAC);

//REsetea Interrupcion//
	ResetINT();
}

int main(void)
{
   /* perform the needed initialization here */
	InicioDAC();
	InicializarADC();


	InicioINT();
	InicioLED();
	InicializarTeclas();

	SetTIVAL(100);

	VAL=0;
	GAN=1;
/*
	if (LeerTecla(1)==1)
		{
		GAN=GAN+0.1;
		}
	if (LeerTecla(2)==1)
		{
		GAN=GAN-0.1;
		}
	if (LeerTecla(3)==1)
		{
		GAN=0;
		}
	if (LeerTecla(4)==1)
		{
		GAN=1;
		}

*/
	while(1)
	{
	}

	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

