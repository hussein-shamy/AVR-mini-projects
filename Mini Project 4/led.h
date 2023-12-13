/*******************************************************************************
 *
 * 	Module: LED
 *
 * 	File Name: led.h
 *
 *	Layer: HAL
 *
 *  Description:
 *
 *  Author: Hussein El-Shamy
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

/********************************************************************************
*						INCLUDING NECESSARY HEADER FILES						*
********************************************************************************/

#include "std_Types.h"
#include "gpio.h"

/********************************************************************************
*						DEFINTIONS and STATIC CONFIGURATION 					*
********************************************************************************/

/* The connection type of the led */
#define NEGATIVE_lOGIC	0
#define POSTIVE_lOGIC	1

/* Configuration for Red LED  */
#define LED_RED_LOGIC		POSTIVE_lOGIC
#define LED_RED_PORT_ID		PORTC_ID
#define LED_RED_PIN_ID		PIN0_ID

/* Configuration for Green LED  */
#define LED_GRN_LOGIC		POSTIVE_lOGIC
#define LED_GRN_PORT_ID		PORTC_ID
#define LED_GRN_PIN_ID		PIN1_ID

/* Configuration for Blue LED  */
#define LED_BLU_LOGIC		POSTIVE_lOGIC
#define LED_BLU_PORT_ID		PORTC_ID
#define LED_BLU_PIN_ID		PIN2_ID


/*********************************************************************************
 *                              Functions Prototypes                             *
 ********************************************************************************/

void LED_RED_On(void);

void LED_RED_Off(void);

void LED_RED_BLink(uint8 timesPerSec, uint8 durationSec);


void LED_GRN_On(void);

void LED_GRN_Off(void);

void LED_GRN_Start_BLink(void);


void LED_BLU_On(void);

void LED_BLU_Off(void);

void LED_BLU_Start_BLink(void);


#endif /* LED_H_ */
