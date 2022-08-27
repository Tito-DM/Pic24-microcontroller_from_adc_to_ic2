/***************************
 *  Projects Description
 * sistema  de climatização
 ***************************
 * FileName:        main.c
 * Dependencies:   	[sytem.h, config.h, stdio.h]
 * Processor:       PIC24
 * Compiler:       	MPLAB C30
 * Linker:          MPLAB LINK30
 * Author
 *~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Nome: Tito Domingos Muanda
 * Nº: 57128
 * Nome:
 * Nº
 * Nome:
 * Nº
 ***************************/



#include <stdio.h>
#include <stdlib.h>
#include "system.h"
#include "config.h"
#include "adc.h"
#include <math.h>
#include <string.h>
#include "i2c.h"

#define LDR_pin 2
#define ANALOG 0xFFFB

int C = 0;

long map(long x, long in_min, long in_max, long out_min, long out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int getldr_light(){
	return map(AnalogRead(LDR_pin),0, 1023, 0, 100);
	//return AnalogRead(LDR_pin);
}

void printLDR(){
	char ldr_s[100];
	sprintf(ldr_s, "light value: %d", getldr_light());
	SerialWrite(ldr_s);
}

void InitTimer(){
	T1CON = 0x00; //Stops the Timer1 and reset control reg.
	TMR1 = 0x00; //Clear contents of the timer register
	PR1 = 0xFFFF; //Load the Period register with the value 0xFFFF
	IPC0bits.T1IP = 0x01; //Setup Timer1 interrupt for desired priority level
	// (This example assigns level 1 priority)
	IFS0bits.T1IF = 0; //Clear the Timer1 interrupt status flag
	IEC0bits.T1IE = 1; //Enable Timer1 interrupts
	T1CONbits.TON = 1; //Start Timer1 with prescaler settings at 1:1 and
	//clock source set to the internal instruction cycle
}

void __attribute__((__interrupt__, __shadow__)) _T1Interrupt(void){
   // Check The Flag Bit
   if (IFS0bits.T1IF)
   {
      C++;
      //if(C==305)
		if(C==170)
      {
        // Code to run
		I2C2_WriteByte(0x0A, getldr_light());
        // Clear The Global Counter
        C = 0;
      }
      IFS0bits.T1IF = 0; // Clear The Flag Bit
   }
}



int main(void)
{
	int i = 0;
   	UART2Init();
	InitI2C2();
	ADCInit(ANALOG);
	InitTimer();	
	while(1){
		//printLDR();
		//I2C2_WriteByte(0x0A, 0x33);
		//for(i = 0; i<1000; i++){}
	}
}


