/* Ejercicio Andres Aguilar
 */

/** Dise~ne e implemente un rmware sobre la EDU-CIAA que haga parpadear un led con
 * un periodo que permita visualizar el proceso. Mediante las cuatro teclas
 * disponibles se debe poder seleccionar el led activo. Emplear retardo por software
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
#include "MiBlink2.h"       /* <= own header */


#ifndef CPU
#error CPU shall be defined
#endif
#if (lpc4337 == CPU)
#include "chip.h"
#elif (mk60fx512vlq15 == CPU)
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



int main(void)
{
   /* perform the needed initialization here */

	InicioLED();
	InicioBOT();

	int i;
	int j;
	int LEDN;
	LEDN=0;
	char SLD;
	SLD	= 'w';
	int BOTP;

	for (i=1 ; i<=1000000; i = i+1)
    {
		BOTP=LeeBOT();
		for (j=1;j==10000;j+=1)
		{
		}
		switch (BOTP)
		{
		case 1:
	    	LEDN=0;
	    	SLD	= 'b';
	    	PrenderLED(0,'w',2);
		break;
		case 2:
			LEDN=1;
			SLD	= 'o';
			PrenderLED(0,'w',2);
		break;
		case 3:
			LEDN=2;
			SLD	= 'r';
			PrenderLED(0,'w',2);
		break;
		case 4:
			LEDN=3;
			SLD	= 'g';
			PrenderLED(0,'w',2);
		break;
		}
		PrenderLED(LEDN,SLD,1);

		for (j=1 ; j<=500000; j = j+1)
		{
			asm("nop");
		}
		PrenderLED(0,'b',2);
		PrenderLED(1,'o',2);
		PrenderLED(2,'r',2);
		PrenderLED(3,'g',2);

		for (j=1 ; j<=500000; j = j+1)
		{
			asm("nop");
		}
    }
	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

