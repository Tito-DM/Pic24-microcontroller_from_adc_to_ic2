/***************************
 *  Projects Description
 * sistema  de climatização
 ***************************
 * FileName:        uart2.h
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

/*****************************************************************************
 * DEFINITIONS
 *****************************************************************************/
// Baudrate
#define BAUDRATE2 19200
// UART IOs
#define UART2_TX_TRIS TRISFbits.TRISF5
#define UART2_RX_TRIS TRISFbits.TRISF4

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
extern void UART2Init();

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
extern void SerialWrite(char *Ch);
extern void  UART2PutChar(char Ch);

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
extern char UART2IsPressed();

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
extern char *SerialRead(char *s, int len);
extern char UART2GetChar();

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
extern void UART2PutDec(unsigned char Dec);

/*****************************************************************************
 * EOF
 *****************************************************************************/
