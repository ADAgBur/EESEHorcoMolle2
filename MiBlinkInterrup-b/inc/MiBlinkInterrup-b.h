/*EEjercicio Andres Aguilar
 */

#ifndef MiBlinkInterrup-b_H
#define MiBlinkInterrup-b_H
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
#include "stdint.h"
#include "dLED1.h"
#include "dINT1.h"
#include "dBOT1.h"
void RITimerISR2(void);
/*==================[macros]=================================================*/
#define lpc4337            1
#define mk60fx512vlq15     2

/*==================[typedef]================================================*/

/*==================[external data declaration]==============================*/
#if (CPU == mk60fx512vlq15)
/* Reset_Handler is defined in startup_MK60F15.S_CPP */
void Reset_Handler( void );

extern uint32_t __StackTop;
#elif (CPU == lpc4337)
/** \brief Reset ISR
 **
 ** ResetISR is defined in cr_startup_lpc43xx.c
 **
 ** \remark the definition is in
 **         externals/drivers/cortexM4/lpc43xx/src/cr_startup_lpc43xx.c
 **/
extern void ResetISR(void);

/** \brief Stack Top address
 **
 ** External declaration for the pointer to the stack top from the Linker Script
 **
 ** \remark only a declaration is needed, there is no definition, the address
 **         is set in the linker script:
 **         externals/base/cortexM4/lpc43xx/linker/ciaa_lpc4337.ld.
 **/
extern void _vStackTop(void);



void RIT_IRQHandler(void);


#else
#endif

/*==================[external functions declaration]=========================*/

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef MI_NUEVO_PROYECTO_H */
