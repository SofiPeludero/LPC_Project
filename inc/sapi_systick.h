/*
 * systick.h
 *
 *  Created on: 18/10/2015
 *      Author: MarcosDario
 */
#include "stdint.h"
#include "chip.h"

#ifndef SYSTICK_H_
#define SYSTICK_H_


#define TICK_1MS	1000

#define TICK_10US	100000



void Init_Tick(uint32_t tick);


#endif /* SYSTICK_H_ */
