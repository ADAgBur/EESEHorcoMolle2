/*Andres Aguilar
 * Incorpore al ejercicio anterior la funcionalidad de variar el periodo y la amplitud de la se~nal.
Tec 1: Aumenta la amplitud de la se~nal.
Tec 2: Disminuye la amplitud de la se~nal.
Tec 3: Aumenta el periodo de la se~nal.
Tec 4: Disminuye el periodo de la se~na
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
#include "TestDACb.h"       /* <= own header */



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
int PER;
int LIM;

void RITimerISR2(void)

{
	int LEDN;
	char sLD;
	int PASO;
	int BOTP;
	int j;

	LEDN=0;
	sLD='b';
	PASO=10;

	BOTP=LeeBOT();
	for (j=1;j==1000;j+=1)
	{
	}
	switch (BOTP)
	{
	case 1:
		if (LIM<=930)
			LIM += 31;
		else
		{
			LIM = 930;
		}
	break;
	case 2:
		if (LIM>=31)
			LIM = LIM-31;
		else
		{
			LIM = 31;
		}
	break;
	case 3:
		PER += 10;
		if (PER>=1000)
			PER = 1000;
	break;
	case 4:
		PER -= 10;
		if (PER<=10)
			PER = 10;
	break;
	}

	if (VAL+PASO>=LIM)
	{
		PrenderLED(LEDN,sLD,3);
		VAL=0;
	}
	else
	{
		VAL+=PASO;
	}

	SetTIVAL(PER);

	PrenderLED(1,'o',3);
	SalDAC(VAL);
	ResetINT();
}

int main(void)
{
   /* perform the needed initialization here */
	int k;
	InicioDAC();
	InicioINT();
	InicioBOT();
	InicioLED();

	PER=10;
	VAL=0;
	LIM=930;

	SetTIVAL(10);

	//SetInt();

	while(1)
	{
		//ooo
	}

	return k;
}

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

