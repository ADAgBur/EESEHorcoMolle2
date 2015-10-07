/* Ejercicio Andres Aguilar
/** Adquisicion de datos
 **Dise~ne e implemente un Firmware sobre la EDU-CIAA que permita adquirir una se~nal analogica de excursion entre 0 y 3.3V, presente en el pin CH1 del conector P1. El sistema debe encender el led rojo si la se~nal
 **toma su valor maximo (>1020 d) y led verde si la se~nal toma su valor mnimo (<5 d). Puede resolverlo
 **por pooling.
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
#include "TestADC.h"       /* <= own header */



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

void RITimerISR2(void)

{
int CAN;
uint16_t VAD;

CAN=1;

//Parte ADC//
VAD=LeerCanalADC(CAN);

	if (VAD>=1020)
	{
		PrenderLED(2,'r',1);
		PrenderLED(3,'g',2);
	}
	if (VAD<=30)
	{
		PrenderLED(2,'r',2);
		PrenderLED(3,'g',1);
	}
	if (VAD>30 && VAD<1020)
	{
		PrenderLED(2,'r',2);
		PrenderLED(3,'g',2);
	}

//REsetea Interrupcion//
	ResetINT();
}

int main(void)
{
   /* perform the needed initialization here */
	InicializarADC();
	InicioINT();
	InicioLED();

	SetTIVAL(100);
	//VAD=0;

	while(1)
	{
	}

	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

