/*Ejercico Andres Aguilar
 */

/*Incorpore al ejercicio anterior la funcionalidad de variar el periodo de parpadeo del led activo.
Tec 1: Selecciona el LED a la izquierda del actual.
Tec 2: Selecciona LED a la derecha del actual.
Tec 3: Disminuye el periodo de parpadeo.
Tec 4: Aumenta el periodo de parpadeo.
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
#include "MiBlinkInterrup-c.h"       /* <= own header */


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
int PER;

void RITimerISR2(void)
{
	int j;
	int BOTP;

	if (FF==0)
	{
		BOTP=LeeBOT();
			for (j=1;j==1000;j+=1)
				{
				}
			switch (BOTP)
				{
				case 1:
					if (LEDN>=0)
						LEDN = LEDN-1;
					else
					{
						LEDN = 3;
					}
				break;
				case 2:
					if (LEDN<=3)
						LEDN = LEDN+1;
					else
					{
						LEDN = 0;
					}
				break;
				case 3:
					PER = PER-100;
					if (PER<=50)
						PER = 50;
				break;
				case 4:
					PER = PER+100;
					if (PER>=5000)
						PER = 5000;
				break;
				}
			SetTIVAL(PER);
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

	PER=250;
	SetTIVAL(PER);

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

