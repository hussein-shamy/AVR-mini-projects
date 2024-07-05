/*******************************************************************************
 *
 * 	Module: LED
 *
 * 	File Name: led.c
 *
 *	Layer: HAL
 *
 *  Description:
 *
 *  Author: Hussein El-Shamy
 *
 *******************************************************************************/

#include "led.h"
#include "../MCAL/gpio.h"
#include "util/delay.h"

void LED_RED_On(void) {

	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_RED_LOGIC);

}

void LED_RED_Off(void) {

	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, !LED_RED_LOGIC);

}

void LED_RED_BLink(uint8 timesPerSec, uint8 durationSec) {

	GPIO_setupPinDirection(LED_RED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	while(1){
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, LED_RED_LOGIC);
		_delay_ms(100);
		GPIO_writePin(LED_RED_PORT_ID, LED_RED_PIN_ID, !LED_RED_LOGIC);
		_delay_ms(1000/timesPerSec);
	}
}

void LED_GRN_On(void) {

	GPIO_setupPinDirection(LED_GRN_PORT_ID, LED_GRN_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, LED_GRN_LOGIC);

}

void LED_GRN_Off(void) {

	GPIO_setupPinDirection(LED_GRN_PORT_ID, LED_GRN_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, !LED_GRN_LOGIC);

}

void LED_GRN_Start_BLink(void) {

	GPIO_setupPinDirection(LED_GRN_PORT_ID, LED_GRN_PIN_ID, PIN_OUTPUT);
	while (1) {
		GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, LED_GRN_LOGIC);
		_delay_ms(50);
		GPIO_writePin(LED_GRN_PORT_ID, LED_GRN_PIN_ID, !LED_GRN_LOGIC);
		_delay_ms(50);
	}
}

void LED_BLU_On(void) {

	GPIO_setupPinDirection(LED_BLU_PORT_ID, LED_BLU_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, LED_BLU_LOGIC);

}

void LED_BLU_Off(void) {

	GPIO_setupPinDirection(LED_BLU_PORT_ID, LED_BLU_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, !LED_BLU_LOGIC);

}

void LED_BLU_Start_BLink(void) {

	GPIO_setupPinDirection(LED_BLU_PORT_ID, LED_BLU_PIN_ID, PIN_OUTPUT);
	while (1) {
		GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, LED_BLU_LOGIC);
		_delay_ms(50);
		GPIO_writePin(LED_BLU_PORT_ID, LED_BLU_PIN_ID, !LED_BLU_LOGIC);
		_delay_ms(50);
	}
}
