/***************************
 *  Projects Description
 * sistema  de climatização
 ***************************
 * FileName:        system.h
 * Dependencies:   	nome
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

// External oscillator frequency

// Comment the line if PIC24 is installed directly on board
//#define PIM_SWAP
#include "p24fj128ga010.h"
#include "uart2.h"
#include "digital.h"

#define SYSCLK 16000000

// Comment the line for 3rd board version
#define BOARD_VERSION4
#define BUFFER_SIZE 103
#define TEMP PORTAbits.RA2
#define LDR PORTAbits.RA3

/***************************
 * EOF
 ***************************/
