#ifndef STM32_USART_H_
#define STM32_USART_H_

//---------------------------------------------------
//Includes
//---------------------------------------------------

#include "STM32_GPIO.h"
#include "STM32_RCC.h"
#include "stm32f103x8.h"

//---------------------------------------------------
//User Type Definition (Configuration Structures)
//---------------------------------------------------


typedef struct
{

	uint8_t USART_Mode;				//Specifies TX/RX Enable/Disable
	//this parameter must be set based on @ref USART_Mode_define


	uint32_t USART_BaudRate;			//Specifies the baud rate
	//this parameter must be set based on @ref USART_BaudRate_define


	uint8_t USART_DataLength;		//Specifies the Effective Data length
	//this parameter must be set based on @ref USART_DataLength_define


	uint8_t USART_StopBits;			//Specifies the number of Stop Bits
	//this parameter must be set based on @ref USART_StopBits_define


	uint8_t USART_ParityMode;		//Specifies the Parity bit mode whether it even/odd/none
	//this parameter must be set based on @ref USART_ParityMode_define


	uint8_t HW_FlowCTRL;			//Specifies whether the hardware flow control is enabled or disabled
	//this parameter must be set based on @ref USART_HW_FlowCTRL_define


	uint8_t USART_IRQ_EN;			//Specifies whether enabled or disabled the USART IRQ TX/RX
	//this parameter must be set based on @ref USART_IRQ_EN_define


	void(* P_IRQ_CallBack)(void);	/*set this pointer with the address of C function
										which will be called one the IRQ happen*/


}USART_Config;





//---------------------------------------------------
//Macros Configuration References
//---------------------------------------------------


//@ref USART_Mode_define

#define USART_Mode_Rx			0
#define USART_Mode_Tx			1
#define USART_Mode_Rx_Tx		2


//@ref USART_BaudRate_define


#define USART_BaudRate_2400BPS			2400
#define USART_BaudRate_9600BPS			9600
#define USART_BaudRate_19200BPS			19200
#define USART_BaudRate_57600BPS			57600
#define USART_BaudRate_115200BPS		115200
#define USART_BaudRate_230400BPS		230400
#define USART_BaudRate_460800BPS		460800
#define USART_BaudRate_921600BPS		921600
#define USART_BaudRate_2250000BPS		2250000
#define USART_BaudRate_4500000BPS		4500000


//@ref USART_DataLength_define

#define USART_DataLength_8Bits			0
#define USART_DataLength_9Bits			1


//@ref USART_StopBits_define

#define USART_StopBits_1Bit			0
#define USART_StopBits_2Bit			1


//@ref USART_ParityMode_define

#define USART_ParityMode_Even		0
#define USART_ParityMode_Odd		1
#define USART_ParityMode_None		2


//@ref USART_HW_FlowCTRL_define

#define USART_HW_FlowCTRL_None			0
#define USART_HW_FlowCTRL_CTS			1
#define USART_HW_FlowCTRL_RTS			2
#define USART_HW_FlowCTRL_CTS_RTS		3


//@ref USART_IRQ_EN_define

#define USART_IRQ_EN_None			0
#define USART_IRQ_EN_TXE			1
#define USART_IRQ_EN_TC				2
#define USART_IRQ_EN_RXNE			3
#define USART_IRQ_EN_PE				4



enum Polling_Mechanism
{
	Disable,
	Enable
};



//Baud Rate Calculations

#define USARTDIV(_PCLK_, _BAUD_)							(uint32_t)( (_PCLK_) / (16*_BAUD_) )
#define USARTDIV_MULT100(_PCLK_, _BAUD_)					(uint32_t)( (25*_PCLK_) / (4*_BAUD_) )
#define Mantissa(_PCLK_, _BAUD_)							(uint32_t)( USARTDIV(_PCLK_, _BAUD_) )
#define Mantissa_MULT100(_PCLK_, _BAUD_)					(uint32_t)( USARTDIV(_PCLK_, _BAUD_) * 100 )
#define Fraction(_PCLK_, _BAUD_)							(uint32_t)( ( ( ( USARTDIV_MULT100(_PCLK_, _BAUD_) ) - ( Mantissa_MULT100(_PCLK_, _BAUD_) ) ) * 16) / 100)
#define USART_BRR_Register(_PCLK_, _BAUD_)					(uint32_t)( ( Mantissa(_PCLK_, _BAUD_) << 4 ) | ( Fraction(_PCLK_, _BAUD_) ) & 0xF )





//---------------------------------------------------
//APIs Supported by "MCAL GPIO Driver"
//---------------------------------------------------


/*
 * @Fn					-MCAl_USART_Init
 * @brief				-Initializes USART in Asynchronous mode only
 * @param [in]			-USART_Insatant: to specifies USART 1 or 2 or 3
 * @param [in]			-USART_CFG:All USART Configuration Parameters
 * @retval				-none
 * Note					-Supports for now ASynchronous mode And System CLock 8MHz
 */

void MCAl_USART_Init(USART_TypeDef * USART_Insatant, USART_Config * USART_CFG);






/*
 * @Fn					-MCAL_USART_DeInit
 * @brief				-Reset USART
 * @param [in]			-USART_Insatant: to specifies USART 1 or 2 or 3
 * @retval				-none
 * Note					-Reset the module by RCC
 */


void MCAL_USART_DeInit(USART_TypeDef * USART_Insatant);

void MCAL_USART_GPIO_SetPins(USART_TypeDef * USART_Insatant, USART_Config * USART_CFG);

void MCAL_USART_SendData(USART_TypeDef * USART_Insatant, USART_Config * USART_CFG, uint16_t * P_TxBuffer, enum Polling_Mechanism PollingEN);

void MCAL_USART_ReceiveData(USART_TypeDef * USART_Insatant, USART_Config * USART_CFG, uint16_t * P_TxBuffer, enum Polling_Mechanism PollingEN);

void MCAL_USART_Wait_TC(USART_TypeDef * USART_Insatant);



//to do MCAL_USART_LIN_Init()		//LIN
//to do MCAL_USART_Init()			//In Synchronous mode
//To do MCAL_USART_DMA_Init()		//Multibuffer Communication




#endif /*STM32_USART_H_*/
