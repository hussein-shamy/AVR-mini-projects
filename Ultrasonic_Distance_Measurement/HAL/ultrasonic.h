 /******************************************************************************
 *
 * Module: ICU
 *
 * File Name: icu.h
 *
 * Description: Header file for the AVR ICU driver
 *
 * Author: Hussein El-Shamy
 *
 *******************************************************************************/


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../Common/std_types.h"
#include "../MCAL/gpio.h"

/*******************************************************************************
 *                         Static Configuration                                   *
 *******************************************************************************/

#define ULTRASONIC_TRIGGER_PORT_ID		PORTB_ID
#define ULTRASONIC_TRIGGER_PIN_ID		PIN5_ID

#define ULTRASONIC_ECHO_PORT_ID			PORTD_ID
#define ULTRASONIC_ECHO_PIN_ID			PIN6_ID

#define ULTRASONIC_NUM_OF_EDGES			2
#define ULTRASONIC_CALBIRATION_FACTOR	58


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Ultrasonic_init(void);

uint16 Ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */
