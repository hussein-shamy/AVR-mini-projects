/*******************************************************************************
 *
 * 	Module: Buzzer
 *
 * 	File Name: buzzer.c
 *
 *	Layer: HAL
 *
 *  Description: need some fixes
 *
 *  Author: Hussein El-Shamy
 *
 *******************************************************************************/

#include "buzzer.h"
#include "gpio.h"
#include "util/delay.h"

void BUZZER_startBeeb(void){
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_HIGH);
}

void BUZZER_stopBeeb(void){
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,LOGIC_LOW);
}

void BUZZER_durationBeeb(uint8 duration_seconds){
	BUZZER_startBeeb();
	_delay_ms(duration_seconds*1000);
	BUZZER_stopBeeb();
}
