/***************************
 *  Projects Description
 * sistema  de climatização
 ***************************
 * FileName:        main.c
 * Dependencies:   	[p24fj128ga010.h,digital.h]
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

#include "p24fj128ga010.h"
#include "digital.h"

void pinsMode(unsigned *tris, int mode)
{
    *tris = mode;
}

void digitalWrite(unsigned *port, int value)
{
    *port = value;
}

int digitalRead(unsigned *port)
{
    int status = 0;
    status = *port;
    return (int) port;
}
