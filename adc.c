/***************************
 *  Projects Description
 * sistema  de climatização
 ***************************
 * FileName:        adc.h
 * Dependencies:   	[system.h,stdio.h]
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

#include "system.h"
#include <stdio.h>

void ADCInit(int anpins)
{
    AD1PCFG = anpins; // AN5 as analog, all other pins are digital
    AD1CON1 = 0x0000; // SAMP bit = 0 ends sampling and starts converting
                      // AD1CHS = 0x0002;  // Connect AN2 as S/H+ input
    // in this example AN2 is the input
    AD1CSSL = 0;
    AD1CON3 = 0x0002; // Manual Sample, Tad = 3Tcy
    AD1CON2 = 0;
    AD1CON1bits.ADON = 1; // turn ADC ON
}

int AnalogRead(int ch)
{
    AD1CHS = ch;          // 1. select analog input channel
    AD1CON1bits.SAMP = 1; // 2. start sampling
    AD1CON1bits.SAMP = 0;                      // 3. wait for sampling time
    //delay(10);           // 6.25 us
   
    while (AD1CON1bits.DONE)
        ; // 5. wait for the conversion to complete
AD1CON1bits.DONE =0;
    return ADC1BUF0;
}
