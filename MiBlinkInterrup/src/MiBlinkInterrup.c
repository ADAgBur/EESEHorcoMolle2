/* Ejercicio Andres Aguilar
 */

/*Temporizador e Interrupciones.
 * Dise~ne e implemente un rmware sobre la EDU-CIAA que encienda de a un led por vez y de manera
secuencial. El tiempo de encendido de cada led ser 250ms. Se debera temporizar mediante interrupciones
sin usar funciones de retardo por software.
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
#include "MiBlinkInterrup.h"       /* <= own header */


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
int LEDN;
char sLD;

void RITimerISR2(void)
{
	PrenderLED(0,'b',2);
	PrenderLED(1,'o',2);
	PrenderLED(2,'r',2);
	PrenderLED(3,'g',2);

	switch (LEDN)
		{
		case 0:
			sLD='b';
		break;
		case 1:
			sLD='o';
		break;
		case 2:
			sLD='r';
		break;
		case 3:
			sLD='g';
		break;
		}
	PrenderLED(LEDN,sLD,1);
	if (LEDN<=3)
		LEDN = LEDN+1;
	else
	{
		LEDN = 0;
	}
	ResetINT();
}

int main(void)
{
   /* perform the needed initialization here */
	InicioINT();

	SetTIVAL(250);

	InicioLED();

	//SetInt();
	LEDN=0;


	while(1)
	{
	}

	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

