/*
 ================================================================================================
 Name        : temp_sensor_example.c
 Author      : Mohamed Tarek
 Description : Test the ADC driver designed with polling technique using LM35 Temperature Sensor
 Date        : 5/9/2015
 ================================================================================================
 */

#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dcmotor.h"

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
