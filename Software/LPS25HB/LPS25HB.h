/*

LPS25HB.h

This is a basic interface to the LPS25HB I2C absolute digital output barometer. The IC can be found in
the SparkFun Qwiic series of sensors

Created: May 2018
Last Updated: May 2018

Authors:
Owen Lyke

*/

#ifndef LPS25HB_H
#define LPS25HB_H


/////////////////////////////////////
//				Defines
/////////////////////////////////////

// Register Configuration Options

// Resolution Configuration
#define LPS25HB_RES_CONF_DEFAULT 	0x0F 	// Default 
#define LPS25HB_RES_CONF_T_8		0x00	// Temperature 8 internal averages
#define LPS25HB_RES_CONF_T_16		0x04	// Temperature 16 internal averages
#define LPS25HB_RES_CONF_T_32		0x08	// Temperature 32 internal averages
#define LPS25HB_RES_CONF_T_64		0x0C	// Temperature 64 internal averages
#define LPS25HB_RES_CONF_P_8		0x00 	// Pressure 8 internal averages
#define LPS25HB_RES_CONF_P_32		0x01 	// Pressure 32 internal averages
#define LPS25HB_RES_CONF_P_128 		0x02 	// Pressure 128 internal averages
#define LPS25HB_RES_CONF_P_512 		0x03	// Pressure 512 internal averages

// Control Register 1
#define LPS25HB_CTRL_REG1_DEFAULT	0x00 	// Default
#define LPS25HB_CTRL_REG1_PD_ACTIVE 0x80 	// Active mode - needed to turn on sensor
#define LPS25HB_CTRL_REG1_ODR_OS	0x00 	// One shot mode
#define LPS25HB_CTRL_REG1_ODR_1HZ 	0x10 	// Both T and P at 1Hz
#define LPS25HB_CTRL_REG1_ODR_7HZ	0x20 	// Both T and P at 7Hz
#define LPS25HB_CTRL_REG1_ODR_12HZ5 0x30 	// Both T and P at 12.5Hz
#define LPS25HB_CTRL_REG1_ODR_25HZ 	0x40 	// Both T and P at 25Hz
#define LPS25HB_CTRL_REG1_DIFF_EN	0x08 	// Enable diff interrupt generation (though the datasheet conflicts with itself and also says this enables computation of differential pressure output)
#define LPS25HB_CTRL_REG1_BDU_EN	0x04 	// Sets Block Data Update so that output registers not updated until MSB and LSB have been read (otherwise registters are in continuous update)
#define LPS25HB_CTRL_REG1_RESET_AZ  0x02 	// Reset Autozero function 
#define LPS25HB_CTRL_REG1_SIM_4W	0x00 	// Select Interface Method : 4 Wire
#define LPS25HB_CTRL_REG1_SIM_4W	0x01 	// Select Interface Method : 3 Wire

// Control Register 2
#define LPS25HB_CTRL_REG2_DEFAULT 		0x00 	// Default
#define LPS25HB_CTRL_REG2_REBOOT_MEM	0x80 	// Reboots memory content, bit is self-cleared when BOOT complete
#define LPS25HB_CTRL_REG2_FIFO_EN		0x40 	// Enable FIFO
#define LPS25HB_CTRL_REG2_STOP_ON_FTH	0x20 	// Enable the FTH_FIFO bit in FIFO_STATUS for monitoring of FIFO level
#define LPS25HB_CTRL_REG2_FIFO_MEAN_DEC 0x10 	// Enable to deimate the output pressure to 1Hz with FIFO Mean mode
#define LPS25HB_CTRL_REG2_I2C_DIS 		0x08 	// Disable I2C interface
#define LPS25HB_CTRL_REG2_SWRESET		0x04 	// Perform software reset
#define LPS25HB_CTRL_REG2_AUTOZERO		0x02 	// Enable autozero
#define LPS25HB_CTRL_REG2_ONE_SHOT		0x01 	// Acquire a new dataset

// Control Register 3
#define LPS25HB_CTRL_REG3_DEFAULT 		0x00	// Default
#define LPS25HB_CTRL_REG3_INT_H			0x00	// Interrupts are active high
#define LPS25HB_CTRL_REG3_INT_L			0x80 	// Interrupts are active low
#define LPS25HB_CTRL_REG3_PP 			0x00 	// Interrupt pads are Push/Pull
#define LPS25HB_CTRL_REG3_OD 			0x40 	// Interrupt pads are Open Drain
#define LPS25HB_CTRL_REG3_INT_S_DATA	0x00 	// Data signal on interrupt 
#define LPS25HB_CTRL_REG3_INT_S_P_H 	0x01 	// Interrupt on pressure high 
#define LPS25HB_CTRL_REG3_INT_S_P_L 	0x02 	// Interrupt on pressure low
#define LPS25HB_CTRL_REG3_INT_S_P_E		0x03 	// Interrupt on pressure either high or low

// Control Register 4
#define LPS25HB_CTRL_REG4_DEFAULT 		0x00 	// Default
#define LPS25HB_CTRL_REG4_F_EMPTY		0x08 	// Enable FIFO empty flag on INT_DRDY pin
#define LPS25HB_CTRL_REG4_F_FTH			0x04 	// Enable FIFO threshold (watermark) status on INT_DRDY pin to indicate that FIFO is filled up to the threshold level
#define LPS25HB_CTRL_REG4_F_OVR 		0x02 	// Enable FIFO overrun interrupt on INT_DRDY pin to indicate that FIFO is full in FIFO mode or that an overrun occurred in Stream mode
#define LPS25HB_CTRL_REG4_DRDY 			0x01 	// Enable Data-ready signal on INT_DRDY pin

// Interrupt Configuration
#define LPS25HB_INTERRUPT_CFG_DEFFAULT 	0x00 	// Default
#define LPS25HB_INTERRUPT_CFG_LIR 		0x04  	// Latch interrupt request
#define LPS25HB_INTERRUPT_CFG_PL_E		0x02 	// Enable interrupt generation on differential pressure low event
#define LPS25HB_INTERRUPT_CFG_PH_E 		0x01 	// Enable interrupt generation on differential pressure high event

// FIFO Control
#define LPS25HB_FIFO_CTRL_DEFAULT		0x00 	// Default
#define LPS25HB_FIFO_CTRL_BYPASS		0x00	// Bypass FIFO
#define LPS25HB_FIFO_CTRL_FIFO			0x20 	// Use FIFO
#define LPS25HB_FIFO_CTRL_STREAM 		0x40 	// Stream mode
#define LPS25HB_FIFO_CTRL_SF			0x60 	// Stream to FIFO mode
#define LPS25HB_FIFO_CTRL_BS 			0x80 	// Bypass to stream mode
#define LPS25HB_FIFO_CTRL_MEAN			0xC0 	// FIFO Mean mode
#define LPS25HB_FIFO_CTRL_BF 			0xE0 	// Bypass to FIFO mode
#define LPS25HB_FIFO_CTRL_M_2			0x01 	// 2 sample moving average
#define LPS25HB_FIFO_CTRL_M_4			0x03 	// 4 sample moving average
#define LPS25HB_FIFO_CTRL_M_8			0x07 	// 8 sample moving average
#define LPS25HB_FIFO_CTRL_M_16			0x0F 	// 16 sample moving average
#define LPS25HB_FIFO_CTRL_M_32			0x1F 	// 32 sample moving average





/////////////////////////////////////
//				TypeDefs
/////////////////////////////////////

// Register Addresses
typedef enum{
	LPS25HB_REG_REF_P_XL = 0x08,
	LPS25HB_REG_REF_P_L,
	LPS25HB_REG_REF_P_H,
	LPS25HB_REG_WHO_AM_I,
	LPS25HB_REG_RES_CONF,
	// Reserved 0x11-0x1F
	LPS25HB_REG_CTRL_REG1 = 0x20,
	LPS25HB_REG_CTRL_REG2,
	LPS25HB_REG_CTRL_REG3,
	LPS25HB_REG_CTRL_REG4,
	LPS25HB_REG_INTERRUPT_CFG,
	LPS25HB_REG_INT_SOURCE,
	// Reserved 0x26
	LPS25HB_REG_STATUS_REG = 0x27,
	LPS25HB_REG_PRESS_OUT_XL,
	LPS25HB_REG_PRESSS_OUT_L,
	LPS25HB_REG_PRESS_OUT_H,
	LPS25HB_REG_TEMP_OUT_L,
	LPS25HB_REG_TEMP_OUT_H,
	// Reserved 0x2D
	LPS25HB_REG_FIFO_CTRL = 0x2E,
	LPS25HB_REG_FIFO_STATUS,
	LPS25HB_REG_THS_P_L,
	LPS25HB_REG_THS_P_H,
	// Reserved 0x32-38
	LPS25HB_REG_RPDS_L = 0x39
}LPS25HB_RegistersTypeDef;

class LPS25HB
{
public:


private:

};






#endif /* LPS25HB_H */