/*
 * STM32 HAL driver for MCP4726 with support for multiple I2C buses
 * Configured for STM32F4
 * 
 *   @file     MCP4726.c
 *   @author   A. Deja
 */

#include "mcp4726.h"
#include "i2c.h"

#include <stdlib.h>

HAL_StatusTypeDef mcp4726_WriteConfiguration(I2C_HandleTypeDef *hi2c, uint8_t byte) {
	return HAL_I2C_Master_Transmit(hi2c, MCP4726_I2C_ADDR, &byte, 1, HAL_MAX_DELAY);
}

HAL_StatusTypeDef mcp4726_WriteOutput(I2C_HandleTypeDef *hi2c, uint16_t data) { //MCP4726_PD as 0b00
	uint8_t byte[2];
	byte[0] = (uint8_t)((data & 0x0f00) >> 8);
	byte[1] = (uint8_t)(data & 0x00ff);
	return HAL_I2C_Master_Transmit(hi2c, MCP4726_I2C_ADDR, byte, 2, HAL_MAX_DELAY);
}

void mcp4726_Init(I2C_HandleTypeDef *hi2c) {

    HAL_Delay(100);

    mcp4726_Reset(hi2c);

}

 void mcp4726_Reset(I2C_HandleTypeDef *hi2c) {
	    uint8_t conf = 0x80 | (MCP4726_VREF << 3) | (MCP4726_PD << 1) | MCP4726_GAIN;

	    mcp4726_WriteConfiguration(hi2c, conf);

	    mcp4726_WriteOutput(hi2c, 0x0000);
 }
