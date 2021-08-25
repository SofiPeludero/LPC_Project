/*
 * systick.c
 *
 *  Created on: 18/10/2015
 *      Author: MarcosDario
 */
#include <sapi_systick.h>
#include "chip.h"


void Init_Tick(uint32_t tick){

	SystemCoreClockUpdate();
	// Setup SysTick Timer to interrupt at 1 usec intervals
		if (SysTick_Config(SystemCoreClock /  tick)) {
		    while (1);  // Captura el error
		}
}



