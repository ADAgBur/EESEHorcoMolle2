/*Ejercicio Andres Aguilar
 *
 */
/**Adquisicion de datos
 **Incorpore al ejercicio anterior la funcionalidad de variar los umbrales maximo y mnimo, y ajuste la frecuencia de conversion en 100Hz empleando temporizador e interrupciones. La lectura del conversor, tambien
 **debe hacerse por interrupciones.
 **-Tec 1: Aumenta el valor del umbral.
 **-Tec 2: Disminuye el valor del umbral.
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
#include "TestADCb.h"       /* <= own header */



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
int LSUP;
void RITimerISR2(void)

{
int CAN;
uint16_t VAD;
CAN=1;

int BOTP;
	int j;
	BOTP=LeeBOT();
	for (j=1;j==1000;j+=1)
	{
	}
	switch (BOTP)
	{
	case 1:
		if (LSUP+20 <=1020)
			{
			LSUP += 20;
			}
		else
			LSUP = 1020;
	break;
	case 2:
		if (LSUP-20 >=0)
				{
				LSUP -= 20;
				}
		else
			LSUP=0;
		break;
	}

//Parte ADC//
VAD=LeerCanalADC(CAN);

	if (VAD>=LSUP)
	{
		PrenderLED(2,'r',1);
		PrenderLED(3,'g',2);
	}
	if (VAD<=30)
	{
		PrenderLED(2,'r',2);
		PrenderLED(3,'g',1);
	}
	if (VAD>30 && VAD<LSUP)
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
	InicioBOT();

	SetTIVAL(100);

	LSUP=1020;

	while(1)
	{
	}

	return 0;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

