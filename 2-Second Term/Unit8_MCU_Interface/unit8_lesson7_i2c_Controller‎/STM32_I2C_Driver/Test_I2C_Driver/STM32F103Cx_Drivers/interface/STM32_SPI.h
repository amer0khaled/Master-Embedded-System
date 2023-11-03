#ifndef STM32_SPI_H_
#define STM32_SPI_H_


//---------------------------------------------------
//Includes
//---------------------------------------------------


#include "stm32f103x8.h"
#include "STM32_GPIO.h"


//---------------------------------------------------
//User Type Definition (Structures)
//---------------------------------------------------


/*
typedef enum
{
	TXE,
	RXNE,
	ERRI

}S_IRQ_SRC;

 */



typedef struct S_IRQ_SRC
{
	uint8_t TXE      :1	 ; 	/*Tx buffer Empty interrupt*/
	uint8_t RXNE     :1	 ;	/*Rx buffer not Empty interrupt*/
	uint8_t ERRI     :1	 ;	/*Error interrupt*/
	uint8_t Reserved :5  ;

}S_IRQ_SRC;





typedef struct
{

	uint8_t Device_State;			//Specifies the Device State Master or Slave
	//this parameter must be set based on @ref SPI_Device_State_define

	uint8_t Communication_Mode;	//Specifies whether the device operating in 2 Line Data Mode (Full Duplex/Half Duplex)
	//or in 1 Line Data Mode (Receive Only/Transmit Only)
	//this parameter must be set based on @ref SPI_Communication_Mode_define


	uint8_t CLK_Phase;				//Specifies Whether the Sampling at the First or the Second Edge of the Clock Pulse
	//this parameter must be set based on @ref SPI_CLK_Phase_define


	uint8_t CLK_Polarity;			//Specifies whether the Idle State at High Level or Low Level
	//this parameter must be set based on @ref SPI_CLK_Polarity_define


	uint8_t Data_Size;				//Specifies whether the data 8 or 16 Bit
	// this parameter must be set based on @ref SPI_Data_Size_define


	uint8_t BaudRate_Prescaler;	//Specifies the Prescaler that the clock of the System Bus will be divided on it
	//this parameter must be set based on @ref SPI_BaudRate_Prescaler_define
	//Note: You have to Configure RCC to Enter the correct Clock


	uint8_t NSS_Mode;				//Specifies whether the NSS signal managed by HardWare or SoftWare
	//this parameter must be set based on @ref SPI_NSS_Mode_define


	uint8_t LSBFIRST;				//Specifies whether the LSB or MSB will be sent first
	//this parameter must be set based on @ref SPI_LSBFIRST_define


	uint8_t SPI_IRQ_Enable;				//Specifies the methodology of execution Interrupt based or Polling based
	//this parameter must be set based on @ref SPI_IRQ_Enable_define


	void (* P_IRQ_CallBack)(S_IRQ_SRC irq_src);		//Specifies the Function that will be executed when the interrupt occur
	//this parameter must be set by the address of the function

}SPI_Config;



//---------------------------------------------------
//Macros Configuration References
//---------------------------------------------------

//---------------------------------------------------
//@ref Module REF Name define
//---------------------------------------------------

/*
//@ref SPI_Device_Mode_define
#define SPI_Device_Mode_FUllDuplex													0
#define SPI_Device_Mode_HalfDuplex_1CLk_1Data_Line_Bidirection						1
#define SPI_Device_Mode_HalfDuplex_1CLk_1Data_Line_Unidirection_Transmit_Only		2
#define SPI_Device_Mode_HalfDuplex_1CLk_1Data_Line_Unidirection_Receive_Only		3
 */





/*Slave select (NSS) pin management:
Hardware or software slave select management can be set using the SSM bit in the
SPI_CR1 register.
• Software NSS management (SSM = 1)
The slave select information is driven internally by the value of the SSI bit in the
SPI_CR1 register. The external NSS pin remains free for other application uses.
• Hardware NSS management (SSM = 0)
Two configurations are possible depending on the NSS output configuration (SSOE bit
in register SPI_CR2).
– NSS output enabled (SSM = 0, SSOE = 1)
This configuration is used only when the device operates in master mode. The
NSS signal is driven low when the master starts the communication and is kept
low until the SPI is disabled.
– NSS output disabled (SSM = 0, SSOE = 0)
This configuration allows multimaster capability for devices operating in master
mode. For devices set as slave, the NSS pin acts as a classical NSS input: the
slave is selected when NSS is low and deselected when NSS high.*/


//@ref SPI_Device_State_define
#define SPI_Device_State_Master		0
#define SPI_Device_State_Slave		1

//@ref SPI_Communication_Mode_define
#define SPI_Communication_Mode_2Line_FullDuplex		0
#define SPI_Communication_Mode_2Line_ReceiveOnly	1
#define SPI_Communication_Mode_1Line_ReceiveOnly	2
#define SPI_Communication_Mode_1Line_TransmitOnly	3

//@ref SPI_CLK_Phase_define
#define SPI_CLK_Phase_FirstEdge_Capture		0
#define SPI_CLK_Phase_SecondEdge_Capture	1


//@ref SPI_CLK_Polarity_define
#define SPI_CLK_Polarity_IdleLow	0
#define SPI_CLK_Polarity_IdleHigh	1


//@ref SPI_Data_Size_define
#define SPI_Data_Size_8Bits		0
#define SPI_Data_Size_16Bits	1


//@ref SPI_BaudRate_Prescaler_define
#define SPI_BaudRate_Prescaler_2		0
#define SPI_BaudRate_Prescaler_4		1
#define SPI_BaudRate_Prescaler_8		2
#define SPI_BaudRate_Prescaler_16		3
#define SPI_BaudRate_Prescaler_32		4
#define SPI_BaudRate_Prescaler_64		5
#define SPI_BaudRate_Prescaler_128		6
#define SPI_BaudRate_Prescaler_256		7


//@ref SPI_NSS_Mode_define

//NSS is Driven by Hardware
#define SPI_NSS_Master_Mode_HW_Output_Enable		0
#define SPI_NSS_Master_Mode_HW_Output_Disable		1
#define SPI_NSS_Slave_Mode_HW						2

//NSS is Driven by Software
#define SPI_NSS_Mode_SW_SET						3
#define SPI_NSS_Mode_SW_Reset					4



//@ref SPI_LSBFIRST_define
#define SPI_LSBFIRST_Disable		0
#define SPI_LSBFIRST_Enable			1


//@ref SPI_IRQ_Enable_define
#define SPI_IRQ_Enable_None		0
#define SPI_IRQ_Enable_TXE		1
#define SPI_IRQ_Enable_RXNE		2
#define SPI_IRQ_Enable_ERRI		3


typedef enum SPI_Polling_Mechanism
{
	Polling_Disable,
	Polling_Enable

}Polling_Mechanism;




//---------------------------------------------------
//APIs Supported by "MCAL SPI Driver"
//---------------------------------------------------


/*=======================================

 * @fn					-MCAL_SPI_Init
 * @brief				-Initialize the SPI according to specific parameters
 * @param[in]			-SPI_Instant: specifies the SPI instant SPI1 or SPI2
 * @param[in]			-SPI_CFG: All SPI Configurations
 * @retval				-None
 * @note					-Support Only Full Duplex Master/Slave only & NSS HW/SW
 * 						-in case of master you have to configure pin and drive it

=======================================*/

void MCAL_SPI_Init(SPI_TypeDef * SPI_Instant, SPI_Config * SPI_CFG);



/*=======================================

 * @fn					-MCAL_SPI_DeInit
 * @brief				-Reset the SPI Registers to It's Default Values
 * @param[in]			-SPI_Instant: specifies the SPI instant SPI1 or SPI2
 * @retval				-None
 * @note					-None

=======================================*/


void MCAL_SPI_DeInit(SPI_TypeDef * SPI_Instant);



/*=======================================

 * @fn					-MCAL_SPI_GPIO_SetPin
 * @brief				-Configure the GPIO Pins to Work With SPI
 * @param[in]			-SPI_Instant: specifies the SPI instant SPI1 or SPI2
 * @retval				-None
 * @note					-None

=======================================*/


void MCAL_SPI_GPIO_SetPin(SPI_TypeDef * SPI_Instant);




/*=======================================

 * @fn					-MCAL_SPI_SendData
 * @brief				-Send Data to the Receiver
 * @param[in]			-SPI_Instant: specifies the SPI instant SPI1 or SPI2
 * @param[in]			-data: pointer to the data that will be sent
 * @param[in]			-polling: enum value to choose from polling technique or interrupt technique
 * @retval				-None
 * @note					-None

=======================================*/


void MCAL_SPI_SendData(SPI_TypeDef * SPI_Instant, uint16_t * data, Polling_Mechanism polling);



/*=======================================

 * @fn					-MCAL_SPI_ReceiveData
 * @brief				-Receive Data from the Transmitter
 * @param[in]			-SPI_Instant: specifies the SPI instant SPI1 or SPI2
 * @param[in]			-data: pointer to the data that will be sent
 * @param[in]			-polling: enum value to choose from polling technique or interrupt technique
 * @retval				-None
 * @note					-None

=======================================*/


void MCAL_SPI_ReceiveData(SPI_TypeDef * SPI_Instant, uint16_t * data, Polling_Mechanism polling);




/*=======================================

 * @fn					-MCAL_SPI_Tx_Rx
 * @brief				-to Transmit and Receive Data via SPI
 * @param[in]			-SPI_Instant: specifies the SPI instant SPI1 or SPI2
 * @param[in]			-data: pointer to the data that will be sent
 * @param[in]			-polling: enum value to choose from polling technique or interrupt technique
 * @retval				-None
 * @note				-None

=======================================*/




void MCAL_SPI_Tx_Rx(SPI_TypeDef * SPI_Instant, uint16_t * data, Polling_Mechanism polling);



#endif /*STM32_SPI_H_*/
