/* Ejercico Andrés Aguilar
 */

/*Dise~ne e implemente un rmware sobre la EDU-CIAA que haga parpadear un led con un
 * periodo de 250ms.
 * El sistema debe permitir seleccionar uno de entre 4 de los leds disponibles
 * empleando una tecla para cada led.
Tec 1: Selecciona LED RGB (uno de los tres colores)
Tec 2: Selecciona LED 1.
Tec 3: Selecciona LED 2.
Tec 4: Selecciona LED 3.
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
#include "MiBlinkInterrup-b.h"       /* <= own header */


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
int FF;

void RITimerISR2(void)
{
	int j;
	int BOTP;

	if (FF==0)
	{
		BOTP=LeeBOT();
			for (j=1;j==10000;j+=1)
				{
				}
			switch (BOTP)
				{
				case 1:
					LEDN=0;
					sLD='b';
				break;
				case 2:
					LEDN=1;
					sLD='o';
				break;
				case 3:
					LEDN=2;
					sLD='r';
				break;
				case 4:
					LEDN=3;
					sLD='g';
				break;
				}
			PrenderLED(LEDN,sLD,1);
			FF=1;
	}
	else
	{
		PrenderLED(0,'w',2);
		PrenderLED(0,'b',2);
		PrenderLED(1,'o',2);
		PrenderLED(2,'r',2);
		PrenderLED(3,'g',2);
		FF=0;
	}


	ResetINT();
}

int main(void)
{
   /* perform the needed initialization here */
	InicioINT();
	InicioLED();
	InicioBOT();

	SetTIVAL(125);

	LEDN=0;
	sLD='w';
	FF=0;

	while(1)
	{
	}

	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

