/*Ejercico Andres Aguilar
 *
 Dise~ne e implemente un rmware sobre la EDU-CIAA que genera una se~nal tipo diente de sierra de periodo
100 ms y excursion de 0 a 3V.
*/

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
#include "TestDAC.h"       /* <= own header */



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

void RITimerISR2(void)

{
int LEDN;
char sLD;
int PASO;

LEDN=0;
sLD='b';
PASO=10;


if (VAL==930)
{
	PrenderLED(LEDN,sLD,3);
	VAL=0;
}
else
{
	VAL+=PASO;
}

	PrenderLED(1,'o',3);
	SalDAC(VAL);
	ResetINT();
}

int main(void)
{
   /* perform the needed initialization here */
	InicioDAC();
	InicioINT();

	SetTIVAL(10);

	InicioLED();

	VAL=0;

	//SetInt();

	while(1)
	{
		//ooo
	}

	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

