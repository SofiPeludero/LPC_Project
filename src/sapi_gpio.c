/*
 * gpio.c
 *
 *  Created on: 6 jul. 2021
 *      Author: MARCO
 */
#include <sapi_datatypes.h>
#include <sapi_gpio.h>
#include "stdint.h"
#include "chip.h"

bool_t gpioInit( uint32_t gpioPort, uint32_t gpioPin, gpioInit_t config )
{
	 bool_t ret_val     = 1;
	 /* Initializes GPIO */
	 Chip_GPIO_Init(LPC_GPIO);


   switch(config) {


   case GPIO_INPUT:

	   Chip_GPIO_SetPinDIR( LPC_GPIO, gpioPort, gpioPin, GPIO_INPUT );


      break;

   case GPIO_INPUT_PULLUP:

	   Chip_GPIO_SetPinDIR( LPC_GPIO, gpioPort, gpioPin, GPIO_INPUT );
      break;

   case GPIO_INPUT_PULLDOWN:

	   Chip_GPIO_SetPinDIR( LPC_GPIO, gpioPort, gpioPin, GPIO_INPUT );
      break;
   case GPIO_INPUT_PULLUP_PULLDOWN:

	   Chip_GPIO_SetPinDIR( LPC_GPIO, gpioPort, gpioPin, GPIO_INPUT );
      break;

   case GPIO_OUTPUT:

	   Chip_GPIO_SetPinDIR( LPC_GPIO, gpioPort, gpioPin , GPIO_OUTPUT );
      Chip_GPIO_SetPinState( LPC_GPIO, gpioPort, gpioPin, 0);
      break;

   default:
      ret_val = 0;
      break;
   }

   return ret_val;

}

bool_t gpioWrite( uint32_t gpioPort, uint32_t gpioPin, bool_t value )
{


   bool_t ret_val     = 1;



   Chip_GPIO_SetPinState( LPC_GPIO, gpioPort, gpioPin, value);

   return ret_val;
}

bool_t gpioToggle( uint32_t gpioPort, uint32_t gpioPin )
{
   return gpioWrite(  gpioPort,gpioPin, !gpioRead( gpioPort,gpioPin) );
}

bool_t gpioRead( uint32_t  gpioPort,uint32_t gpioPin )
{

   bool_t ret_val     = OFF;



   ret_val = (bool_t) Chip_GPIO_ReadPortBit( LPC_GPIO, gpioPort, gpioPin );

   return ret_val;
}
