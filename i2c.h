#include <stdio.h>
#include "system.h"

extern void InitI2C2();

extern void StartI2C2();

extern void StopI2C2();

extern void IdleI2C2(void);

extern void I2C2SendAdress(unsigned int address);

extern void I2C2SendData(unsigned int data);

extern void CheckTBF();

extern void CheckAck();

extern void I2C2_WriteByte(int writeAddress, int data);