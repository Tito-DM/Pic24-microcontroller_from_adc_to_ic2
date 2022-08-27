/***************************
 *  Projects Description
 * sistema  de climatização
 ***************************
 * FileName:        adc.h
 * Dependencies:   	none
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
 * Function: ADCInit
 *
 *
 *
 * descreption: perform adc initialization.
 *
 * Input: None.
 *
 * Output: Byte received.
 *
 *****************************************************************************/
extern void ADCInit();

/*****************************************************************************
 * Function: AnalogWrite
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
extern void AnalogWrite(unsigned char Dec);

/*****************************************************************************
 * Function: AnalogRead
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
extern int AnalogRead(int ch);

/*****************************************************************************
 * EOF
 *****************************************************************************/
