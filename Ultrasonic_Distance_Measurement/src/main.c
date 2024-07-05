/****************************************************************************************/
/* !Project         : Ultrasonic Distance Measurement                         			*/
/* !Description     : Implementation of Ultrasonic Distance Measurement using ATmega32 	*/
/* !File            : main.c                                                  			*/
/* !Coding language : C                                                       			*/
/* !Target          : ATmega32                                                			*/
/* !Compiler        : AVR-GCC Tool Chain                                      			*/
/* !Mentor	        : Engineer Mohamed Tarek      							 			*/
/* !Coded by        : Hussein El-Shamy 			  !Date : September 14, 2023  			*/
/****************************************************************************************/

#include "../HAL/ultrasonic.h"
#include "../HAL/lcd.h"
#include "../HAL/buzzer.h"
#include "../HAL/led.h"
#include <avr/io.h>
#include "util/delay.h"

#define APP_THREE_DIGITS_DISPLAY					100
#define APP_OBSTRUCTION_WARNING_DISTANCE_LV1		20
#define APP_OBSTRUCTION_WARNING_DISTANCE_LV2		10
#define APP_OBSTRUCTION_WARNING_DISTANCE_LV3		5

int main(void){

	uint16 distance;

	SREG |=(1<<7);

	LCD_init();

	Ultrasonic_init();

	LCD_displayStringRowColumn(0,1,"Distance= ");

	while(1){

		distance = Ultrasonic_readDistance();

		LCD_moveCursor(0,10);

		if(distance>=APP_THREE_DIGITS_DISPLAY){

		LCD_intgerToString(distance);

		}else if(distance<APP_THREE_DIGITS_DISPLAY){

		LCD_intgerToString(distance);

		LCD_displayCharacter(' ');

		}

		LCD_moveCursor(0,13);
		LCD_displayString("cm");

		if(distance<=APP_OBSTRUCTION_WARNING_DISTANCE_LV1 && distance >APP_OBSTRUCTION_WARNING_DISTANCE_LV2){

			BUZZER_startBeeb();
			LED_GRN_On();
			LED_BLU_Off();
			LED_RED_Off();

		}else if(distance<=APP_OBSTRUCTION_WARNING_DISTANCE_LV2 && distance > APP_OBSTRUCTION_WARNING_DISTANCE_LV3){

			BUZZER_startBeeb();
			LED_BLU_On();
			LED_RED_Off();

		}else if (distance<=APP_OBSTRUCTION_WARNING_DISTANCE_LV3) {

			BUZZER_startBeeb();
			LED_RED_On();

		}else{

			BUZZER_stopBeeb();
			LED_GRN_Off();
			LED_BLU_Off();
			LED_RED_Off();

		}

		_delay_ms(10);

	}

	return 0;
}


