/************************************************************************************/
/* !Project         : Temperature Controlled Fan                              		*/
/* !Description     : Implementation of Temperature Controlled Fan using ATmega32  	*/
/* !File            : main.c                                                  		*/
/* !Coding language : C                                                       		*/
/* !Target          : ATmega32                                                		*/
/* !Compiler        : AVR-GCC Tool Chain                                      		*/
/* !Mentor	        : Engineer Mohamed Tarek      							  		*/
/* !Coded by        : Hussein El-Shamy 			  !Date : September 14, 2023  		*/
/************************************************************************************/

#include "../MCAL/adc.h"
#include "../HAL/lcd.h"
#include "../HAL/lm35_sensor.h"
#include "../HAL/dcmotor.h"

int main(void) {

	ADC_ConfigType ConfigPtr = {F_CPU_8,INTERNAL};

	uint8 temp;
	LCD_init(); /* initialize LCD driver */
	ADC_init(&ConfigPtr); /* initialize ADC driver */
	DcMotor_Init();


	while (1) {

		temp = LM35_getTemperature();

		if (temp < 30) {
			DcMotor_Rotate(Stop, 0);
			LCD_displayStringRowColumn(0,4,"Fan is OFF");
		} else if (temp >= 30 && temp < 60) {
			DcMotor_Rotate(CW, 25);
			LCD_displayStringRowColumn(0,4,"Fan is ON ");
		} else if (temp >= 60 && temp < 90) {
			DcMotor_Rotate(CW, 50);
			LCD_displayStringRowColumn(0,4,"Fan is ON ");
		} else if (temp >= 90 && temp < 120) {
			DcMotor_Rotate(CW, 75);
			LCD_displayStringRowColumn(0,4,"Fan is ON ");
		} else if (temp >= 120) {
			DcMotor_Rotate(CW, 100);
			LCD_displayStringRowColumn(0,4,"Fan is ON ");
		}

				LCD_displayStringRowColumn(1, 4, "Temp = ");
				LCD_intgerToString(temp);

				if (temp < 100) {
					LCD_displayCharacter(' ');
				}
				LCD_displayString("C");
}
}
