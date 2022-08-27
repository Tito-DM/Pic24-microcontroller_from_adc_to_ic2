/***************************
 *  Projects Description
 * sistema  de climatização
 ***************************
 * FileName:        config.h
 * Dependencies:   	[p24fxxxx.h]
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

#include <p24fxxxx.h>

#define LDR_pin 2 // ldr on pin AN2
#define NTC_pin 3 //ntc on pin AN3
#define POTMASK 0xfff3 // AN2 AN3 = analog inputs
#define BUF_SIZE 128

// Configuration Bits
#ifdef __PIC24FJ64GA004__ // Defined by MPLAB when using 24FJ64GA004 device
_CONFIG1(JTAGEN_OFF &GCP_OFF &GWRP_OFF &COE_OFF &FWDTEN_OFF &ICS_PGx1 &IOL1WAY_ON)
_CONFIG2(FCKSM_CSDCMD &OSCIOFNC_OFF &POSCMOD_HS &FNOSC_PRI &I2C1SEL_SEC)
#else
_CONFIG1(JTAGEN_OFF &GCP_OFF &GWRP_OFF &COE_OFF &FWDTEN_OFF &ICS_PGx2)
_CONFIG2(FCKSM_CSDCMD &OSCIOFNC_OFF &POSCMOD_HS &FNOSC_PRI)
#endif
