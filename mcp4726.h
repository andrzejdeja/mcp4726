/*
 * STM32 HAL driver for MCP4726 with support for multiple I2C buses
 * Configured for STM32F4
 * 
 *   @file     MCP4726.h
 *   @author   A. Deja
 */

#ifndef __MCP4726_H__
#define __MCP4726_H__

#include <stddef.h>
#include <_ansi.h>

_BEGIN_STD_C

#include "mcp4726_conf.h"

#ifdef STM32F4
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#endif

void mcp4726_Init(I2C_HandleTypeDef *hi2c);
void mcp4726_Reset(I2C_HandleTypeDef *hi2c);

HAL_StatusTypeDef mcp4726_WriteConfiguration(I2C_HandleTypeDef *hi2c, uint8_t byte);
HAL_StatusTypeDef mcp4726_WriteOutput(I2C_HandleTypeDef *hi2c, uint16_t data);

_END_STD_C

#endif // __MCP4726_H__
