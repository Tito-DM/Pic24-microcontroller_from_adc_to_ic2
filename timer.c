#include <stdio.h>
#include "timer.h"
#include "system.h"

void InitTimer(){
	T1CONbits.TON = 1;	//starts timer
	T1CONbits.TCKPS1 = 0;
	T1CONbits.TCKPS0 = 1;
	T1CONbits.TCS = 0;
	PR1 = 0xFF;
	IEC0bits.T1IE = 1; //enable interrupts
}

