/*
===============================================================================
 Name        : Project_LPCOpen.c
 Author      : Peludero Sofía
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>

// TODO: insert other include files here
#include "sapi_dac.h"
#include "sapi_gpio.h"
#include "sapi_rit.h"
#include "sapi_systick.h"

// TODO: insert other definitions and declarations here
uint16_t t=1000000;
uint16_t n=0;													//numero de muestras comienza en el valor 0
uint16_t signal[9];
uint16_t sierra33[9]={0,130,260,390,520,650,780,910,1023};		//diente de sierra amplitud 3.3V
uint16_t sierra165[9]={0,64,128,192,256,320,384,448,512};		//diente de sierra amplitud 1,65V
//uint16_t sen[10]={0,128,256,511,790,1023,790,511,256,128};			//Senoidal Vp=1,65V

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // Set the LED to the state of "On"
    Board_LED_Set(0, true);
#endif
#endif

    // TODO: insert code here

    int Puls=0;
    int j=0;

    dacInit(DAC_ENABLE);					//Sale por el puerto 0 pin 26


    gpioInit(0,21,0);						//Entradas
    gpioInit(0,27,0);
    gpioInit(0,28,0);
    gpioInit(2,13,0);


    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;

        if(gpioRead(0,21) == 1){Puls=1;}
        if(gpioRead(0,27) == 1){Puls=2;}
        if(gpioRead(0,28) == 1){Puls=3;}
        if(gpioRead(2,13) == 1){Puls=4;}

        switch(Puls){
        case(1):						//onda de Vp=3.3V f=10kHz
        		t=TICK_10US;				//tiempo de interrupcion
        		for(j=0;j<9;j++){
        			signal[j]=sierra33[j];	//La señal toma el valor de la onda diente de sierra
        		}
        		gpioToggle(0,22);
        		Cambia_t_Systick();
        		Puls=0;
        break;
        case(2):							//onda de Vp=3.3V f=1kHz
                t=10000;					//tiempo de interrupcion
        		for(j=0;j<9;j++){
        			signal[j]=sierra33[j];	//La señal toma el valor de la onda diente de sierra
        		}
        		gpioToggle(0,22);
        		Cambia_t_Systick();
                Puls=0;
        break;
        case(3):							//onda de Vp=1.65V f=1kHz
                t=10000;					//tiempo de interrupcion
        		for(j=0;j<9;j++){
        			signal[j]=sierra165[j];	//La señal toma el valor de la onda diente de sierra
        		}
        		gpioToggle(0,22);
        		Cambia_t_Systick();
                Puls=0;
        break;
        case(4):							//onda de Vp=1.65V f=10kHz
                t=TICK_10US;					//tiempo de interrupcion
        		for(j=0;j<9;j++){
        			signal[j]=sierra165[j];	//La señal toma el valor de la onda diente de sierra
        		}
        		gpioToggle(0,22);
        		Cambia_t_Systick();
                Puls=0;
        break;

        }

        // "Dummy" NOP to allow source level single
        // stepping of tight while() loop
        __asm volatile ("nop");
    }
    return 0 ;
}

void Cambia_t_Systick(){
	Init_Tick(t);							//se interrumpe t us
}
void SysTick_Handler(void){
	dacWrite(0,signal[n]);
	if(n<9){
		n++;
	}
	else if(n==9){
		n=0;
	}
}


