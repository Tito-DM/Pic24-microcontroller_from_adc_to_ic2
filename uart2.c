/***************************
 *  Projects Description
 * sistema  de climatização
 ***************************
 * FileName:        uart2.c
 * Dependencies:   	[sytem.h, config.h, stdio.h]
 * Processor:       PIC24
 * Compiler:       	MPLAB C30
 * Linker:          MPLAB LINK30
 * Author
 *~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Nome: Tito Domingos Muanda
 * Nº: 57128
 * Nome: Rui Nascimento
 * Nº: 55941
 * Nome: Diogo Catarrinho
 * Nº:
 ***************************/

#include "system.h"
#include <stdio.h>
/*****************************************************************************
 * U2BRG register value and baudrate mistake calculation
 *****************************************************************************/
#define BAUDRATEREG2 25
#define BACKSPACE 0x8 // ASCII backspace character code

/*#if BAUDRATEREG2 > 255
#error Cannot set up UART2 for the SYSCLK and BAUDRATE.\
 Correct values in main.h and uart2.h files.
#endif

#define BAUDRATE_MISTAKE 1000*(BAUDRATE2-SYSCLK/64/(BAUDRATEREG2+1))/BAUDRATE2
#if (BAUDRATE_MISTAKE > 2)||(BAUDRATE_MISTAKE < -2)
#error UART2 baudrate mistake is too big  for the SYSCLK\
 and BAUDRATE2. Correct values in uart2.c file.
#endif */

/*****************************************************************************
 * Function: UART2Init
 *
 * Precondition: None.
 *
 * Overview: Setup UART2 module.
 *
 * Input: None.
 *
 * Output: None.
 *
 *****************************************************************************/
void UART2Init()
{
	// Set directions of UART IOs
	UART2_TX_TRIS = 0;
	UART2_RX_TRIS = 1;
	U2BRG = BAUDRATEREG2;
	U2MODE = 0;
	U2STA = 0;
	U2MODEbits.UARTEN = 1;
	U2STAbits.UTXEN = 1;
	// reset RX flag
	IFS1bits.U2RXIF = 0;
}

/*****************************************************************************
 * Function: UART2PutChar
 *
 * Precondition: UART2Init must be called before.
 *
 * Overview: Wait for free UART transmission buffer and send a byte.
 *
 * Input: Byte to be sent.
 *
 * Output: None.
 *
 *****************************************************************************/
void  UART2PutChar(char Ch){
    // wait for empty buffer  
    while(U2STAbits.UTXBF == 1);
      U2TXREG = Ch;
}

void SerialWrite(char *Ch)
{
 while( *Ch) // loop until *s == '\0' the end of the string
 UART2PutChar( *Ch++); // send the character and point to the next one
 UART2PutChar( '\r'); // terminate with a cr / line feed
 UART2PutChar( '\n');
}



/*****************************************************************************
 * Function: UART2IsPressed
 *
 * Precondition: UART2Init must be called before.
 *
 * Overview: Check if there's a new byte in UART reception buffer.
 *
 * Input: None.
 *
 * Output: Zero if there's no new data received.
 *
 *****************************************************************************/
char UART2IsPressed()
{
	if (IFS1bits.U2RXIF == 1)
		return 1;
	return 0;
}

char UART2GetChar()
{
	char Temp;
	while (IFS1bits.U2RXIF == 0)
		;
	Temp = U2RXREG;
	IFS1bits.U2RXIF = 0;
	return Temp;
}

/*****************************************************************************
 * Function: UART2GetChar
 *
 * Precondition: UART2Init must be called before.
 *
 * Overview: Wait for a byte.
 *
 * Input: None.
 *
 * Output: Byte received.
 *
 *****************************************************************************/
char *SerialRead(char *s, int len)
{
 char *p = s; // copy the buffer pointer
 do{
 *s =  UART2GetChar(); // wait for a new character
 UART2PutChar( *s); // echo character
 if (( *s==BACKSPACE)&&( s>p))
 {
  UART2PutChar( ' '); // overwrite the last character
  UART2PutChar( BACKSPACE);
 len++;
 s--; // back the pointer
 continue;
 }
 if ( *s=='\n') // line feed, ignore it
 continue;
 if ( *s=='\r') // end of line, end loop
 break;
 s++; // increment buffer pointer
 len--;
 } while ( len>1 ); // until buffer full
 *s = '\0'; // null terminate the string
 return p; // return buffer pointer
}

/*****************************************************************************
 * Function: UART2PutDec
 *
 * Precondition: UART2Init must be called before.
 *
 * Overview: This function converts decimal data into a string
 * and outputs it into UART.
 *
 * Input: Binary data.
 *
 * Output: None.
 *
 *****************************************************************************/
