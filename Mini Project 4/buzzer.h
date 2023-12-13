/*******************************************************************************
 *
 * 	Module: Buzzer
 *
 * 	File Name: buzzer.h
 *
 *	Layer: HAL
 *
 *  Description:
 *
 *  Author: Hussein El-Shamy
 *
 *******************************************************************************/

#ifndef BUZZER_H_
#define BUZZER_H_

/********************************************************************************
*						INCLUDING NECESSARY HEADER FILES						*
********************************************************************************/

#include "std_Types.h"
#include "gpio.h"

/********************************************************************************
*						DEFINTIONS and STATIC CONFIGURATION 					*
********************************************************************************/

/* Configuration for the #1 Seven Segment Unit */
#define BUZZER_PORT_ID			PORTC_ID
#define BUZZER_PIN_ID			PIN3_ID

/*********************************************************************************
 *                              Functions Prototypes                             *
 ********************************************************************************/

void BUZZER_startBeeb(void);

void BUZZER_stopBeeb(void);

void BUZZER_durationBeeb(uint8 duration_seconds);


#endif /* BUZZER_H_ */
