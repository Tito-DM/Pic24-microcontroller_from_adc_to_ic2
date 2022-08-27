#include <stdio.h>
#include "i2c.h"
#include "system.h"


void InitI2C2(){
	I2C2CON = 0x0;
	I2C2CONbits.I2CEN = 1; //enable I2C2
	I2C2BRG = 0x027;
}

void StartI2C2(){
	I2C2CONbits.SEN = 1;
}

void StopI2C2(){
	I2C2CONbits.PEN = 1;
}

void IdleI2C2(void){
    while(I2C2CONbits.SEN || I2C2CONbits.RSEN || I2C2CONbits.PEN || I2C2CONbits.RCEN ||
          I2C2CONbits.ACKEN || I2C2STATbits.TRSTAT);  
}

void I2C2SendAdress(unsigned int address){
	I2C2TRN = address <<1;	
}

void I2C2SendData(unsigned int data){
	I2C2TRN = data;	
}

void CheckTBF(){
	while(I2C2STATbits.TBF)
		return;
}

void CheckAck(){
	while(I2C2STATbits.ACKSTAT)
		return;
}



void I2C2_WriteByte(int writeAddress, int data){
	StartI2C2();
	IdleI2C2();
	I2C2SendAdress(writeAddress);
	CheckTBF();
	//CheckAck();
	IdleI2C2();
	I2C2SendData(data);
	IdleI2C2();
	//CheckAck();
	StopI2C2();
}

