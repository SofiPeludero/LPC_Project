/*
 * sapi_dac.h
 *
 *  Created on: 7 jul. 2021
 *      Author: MARCO
 */

#include <sapi_dac.h>
#include "chip.h"
#include "stdint.h"
/*
 * @brief:  enable/disable the ADC and DAC peripheral
 * @param:  DAC_ENABLE, DAC_DISABLE
 * @return: none
*/
void dacInit( dacInit_t config )
{

   switch(config) {

   case DAC_ENABLE:
      /* Initialize the DAC peripheral */
      Chip_DAC_Init(LPC_DAC);

      /* Set update rate to 400 KHz */
      Chip_DAC_SetBias(LPC_DAC, DAC_MAX_UPDATE_RATE_400kHz);

      /* Enables the DMA operation and controls DMA timer */
      Chip_DAC_ConfigDAConverterControl(LPC_DAC, DAC_DMA_ENA);
      /* DCAR DMA access */
      /* Update value to DAC buffer*/
      Chip_DAC_UpdateValue(LPC_DAC, 0);
      break;

   case DAC_DISABLE:
      /* Disable DAC peripheral */
      Chip_DAC_DeInit( LPC_DAC );
      break;
   }

}


/*
 * @brief   Write a value in the DAC.
 * @param   analogOutput: AO0 ... AOn
 * @param   value: analog value to be writen in the DAC, from 0 to 1023
 * @return  none
 */
void dacWrite( dacMap_t analogOutput, uint16_t value )
{
   if( analogOutput == 0 ) {
      if( value > 1023 ) {
         value = 1023;
      }
      Chip_DAC_UpdateValue( LPC_DAC, value );
   }
}
