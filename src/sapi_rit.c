/*
 * interrupciones.c
 *
 *  Created on: 22/9/2015
 *      Author: MarcosDario
 */
#include <sapi_rit.h>
#include "stdint.h"
#include "chip.h"

/*Timer de Interrupciones Repetitivas*/
void Init_RITimer(uint32_t intervalo_ms){

	Chip_RIT_Init(LPC_RITIMER);
	Chip_RIT_SetTimerInterval(LPC_RITIMER,intervalo_ms);
	NVIC_EnableIRQ(RITIMER_IRQn);
}


void Clear_RITimer(void){

	Chip_RIT_ClearInt(LPC_RITIMER);
}

