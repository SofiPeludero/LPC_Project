/*
 * sapi_dac.h
 *
 *  Created on: 7 jul. 2021
 *      Author: MARCO
 */
#include <sapi_datatypes.h>
#include "chip.h"
#include "stdint.h"

#ifndef SAPI_DAC_H_
#define SAPI_DAC_H_

/*==================[macros and definitions]=================================*/

#define dacConfig dacInit

/*==================[typedef]================================================*/

typedef enum {
   DAC_ENABLE, DAC_DISABLE
} dacInit_t;

/*==================[external data declaration]==============================*/

/*==================[external functions declaration]=========================*/

void dacInit( dacInit_t config );

void dacWrite( dacMap_t analogOutput, uint16_t value );


#endif /* SAPI_DAC_H_ */
