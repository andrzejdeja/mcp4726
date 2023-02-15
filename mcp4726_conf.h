#ifndef __MCP4726_CONF_H__
#define __MCP4726_CONF_H__

// Choose a microcontroller family
#define STM32F4

/*
 * 7-bit I2C Address
 * 0x60 MCP47x6A0-E/xx & MCP47x6A0T-E/xx
 * 0x61 MCP47x6A1-E/xx & MCP47x6A1T-E/xx
 * 0x62 MCP47x6A2-E/xx & MCP47x6A2T-E/xx
 * 0x63 MCP47x6A3-E/xx & MCP47x6A3T-E/xx
 * 0x64 MCP47x6A4-E/xx & MCP47x6A4T-E/xx
 * 0x65 MCP47x6A5-E/xx & MCP47x6A5T-E/xx
 * 0x66 MCP47x6A6-E/xx & MCP47x6A6T-E/xx
 * 0x67 MCP47x6A7-E/xx & MCP47x6A7T-E/xx
 */

// I2C Configuration
#define MCP4726_I2C_PORT_1        hi2c1
#define MCP4726_I2C_PORT_2        hi2c2
#define MCP4726_I2C_ADDR        (0x61 << 1)

/* MCP4726_VREF
 * Resistor Ladder Voltage Reference (VRL) Selection bits
 * 0x00 =VDD (Unbuffered)
 * 0x02 =VREF pin (Unbuffered)
 * 0x03 =VREF pin (Buffered)
 */
#define MCP4726_VREF 0x03

/* MCP4726_PD
 * Power-Down Selection bits
 * When the DAC is powered down, most of the internal circuits are powered off and the op amp is
 * disconnected from the VOUT pin.
 * 0x00 = Not Powered Down (Normal operation)
 * 0x01 = Powered Down – VOUT is loaded with 1 kΩ resistor to ground.
 * 0x02 = Powered Down – VOUT is loaded with 100 kΩ resistor to ground.
 * 0x03 = Powered Down – VOUT is loaded with 500 kΩ resistor to ground.
 */
#define MCP4726_PD 0x00

/* MCP4726_GAIN
 * Gain Selection bit
 * 0x00 = 1x (gain of 1)
 * 0x01 = 2x (gain of 2). Not applicable when VDD is used as VRL
 */
#define MCP4726_GAIN 0x00


#endif /* __MCP4726_CONF_H__ */
