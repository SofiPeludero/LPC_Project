/*
 * gpio.h
 *
 *  Created on: 6 jul. 2021
 *      Author: MARCO
 */
#include <sapi_datatypes.h>
#include "chip.h"
#ifndef GPIO_H_
#define GPIO_H_

/* Pin modes */
/*
 *  INPUT  =  0    (No PULLUP or PULLDOWN)
 *  OUTPUT =  1
 *  INPUT_PULLUP
 *  INPUT_PULLDOWN
 *  INPUT_REPEATER (PULLUP and PULLDOWN)
 *  INITIALIZE
 */
typedef enum {
   GPIO_INPUT, GPIO_OUTPUT,
   GPIO_INPUT_PULLUP, GPIO_INPUT_PULLDOWN,
   GPIO_INPUT_PULLUP_PULLDOWN
} gpioInit_t;

bool_t gpioInit( uint32_t gpioPort, uint32_t gpioPin, gpioInit_t config );
bool_t gpioWrite( uint32_t gpioPort, uint32_t gpioPin, bool_t value );
bool_t gpioToggle( uint32_t gpioPort, uint32_t gpioPin );
bool_t gpioRead( uint32_t  gpioPort, uint32_t  gpioPin );

#endif /* GPIO_H_ */
