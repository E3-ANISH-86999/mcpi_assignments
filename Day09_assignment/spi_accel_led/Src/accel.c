/*
 * lis3dsh.c
 *
 *  Created on: Apr 3, 2024
 *      Author: Nilesh
 */

#include "accel.h"

void SPI_WriteIO(uint8_t regr, uint8_t data[], uint8_t size){
	SPI_CS_ENABLE();

	regr &= ~BV(7);
	SPI_TRANSMIT(regr);

	for(int i=0; i<size; i++)
		SPI_TRANSMIT(data[i]);

	SPI_CS_DISABLE();
}

void SPI_ReadIO(uint8_t regr, uint8_t data[], uint8_t size){
	SPI_CS_ENABLE();

	regr |= BV(7);
	SPI_TRANSMIT(regr);

	for(int i=0; i<size; i++)
		data[i] = SPI_RECEIVE();

	SPI_CS_DISABLE();
}


void LIS_Init(void){
	SPI_Init();
	DelayMs(3);

	uint8_t config = LIS_CR4_RATE_25 | LIS_CR4_XYZ_EN;
	SPI_WriteIO(LIS_CTRL_ADDR, &config, 1);
}

int LIS_IsDataAvail(void){
	uint8_t status;
	do{
		SPI_ReadIO(LIS_STATUS_ADDR, &status, 1);
	}while(!(status & LIS_SR_XYZDA));
	return 1;
}

LIS_Data LIS_GetData(void){
	uint8_t data[2];

	LIS_Data val;

	SPI_ReadIO(LIS_XL_ADDR, data, 2);
	val.x = ((uint16_t)data[1] << 8) | data[0];

	SPI_ReadIO(LIS_YL_ADDR, data, 2);
	val.y = ((uint16_t)data[1] << 8) | data[0];

	SPI_ReadIO(LIS_ZL_ADDR, data, 2);
	val.z = ((uint16_t)data[1] << 8) | data[0];
	return val;

}







