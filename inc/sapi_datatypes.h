/*
 * datatypes.h
 *
 *  Created on: 6 jul. 2021
 *      Author: MARCO
 */
#include "chip.h"

#ifndef DATATYPES_H_
#define DATATYPES_H_

// Functional states
#ifndef OFF
#define OFF    0
#endif
#ifndef ON
#define ON     (!OFF)
#endif

// Electrical states
#ifndef LOW
#define LOW    0
#endif
#ifndef HIGH
#define HIGH   (!LOW)
#endif

// Logical states

#ifndef FALSE
#define FALSE  0
#endif
#ifndef TRUE
#define TRUE   (!FALSE)
#endif

#ifndef false
#define false  0
#endif
#ifndef true
#define true   (!false)
#endif

//==================[typedef]==================================================

// Define Boolean Data Type
typedef uint8_t bool_t;

// Define real Data Types (floating point)
typedef float  real32_t;
typedef double real64_t;

typedef float  float32_t;
typedef double float64_t; // In LPC4337 float = double (Floating Point single precision, 32 bits)

// Define Tick Data Type
typedef uint64_t tick_t;

/* Defined for sapi_adc.h */
typedef enum {

	   CH0 = 0, // CH0 ---- P0_24
	   CH1 = 1, // CH1 ---- P0_23
	   CH2 = 2, // CH2 ---- P0_25
	   CH4 = 4, // CH4 ---- P1_30
	   CH5 = 5	// CH5 ---- P1_31

} adcMap_t;

/* Defined for sapi_dac.h */
typedef enum {
		DAC  = 0,

} dacMap_t;

typedef enum {
	   UART_0 = 0,
	   UART_485 = 1,
       UART_2 = 2,
	   UART_3 = 3,
	   UART_MAXNUM,
} uartMap_t;

#endif /* DATATYPES_H_ */
