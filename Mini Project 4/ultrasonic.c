 /******************************************************************************
 *
 * Module: Ultrasonic
 *
 * File Name: ultrasonic.c
 *
 * Description: Source file for the Ultrasonic Sensor HC-SR04 driver
 *
 * Author: Hussein El-Shamy
 *
 *******************************************************************************/


/********************************************************************************
*						INCLUDING NECESSARY HEADER FILES						*
********************************************************************************/

#include "ultrasonic.h"
#include "icu.h"
#include "gpio.h"
#include "util/delay.h"

/*********************************************************************************
 *                 		  Private Global Variables                               *
 ********************************************************************************/

/* to store the the number of edge detected */
static uint8 g_edgeCount = 0;

/* to store the value of timer when the pulse is high  */
static uint16 g_timeHigh = 0;

/*********************************************************************************
 *                 		   Private Functions Definition                           *
 ********************************************************************************/

static void Ultrasonic_Trigger(void){

	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,LOGIC_LOW);

}

static void Ultrasonic_edgeProcessing(void){
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();
		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = ICU_getInputCaptureValue();
		/* Detect rising edge */
		ICU_setEdgeDetectionType(RAISING);
	}
}

/*********************************************************************************
 *                 		   Public Functions Definition                           *
 ********************************************************************************/

void Ultrasonic_init(void){

	/*
	 * Initialize the ICU driver:
	 * frequency F_CPU/8
	 * detect the raising edge
	 */

	ICU_ConfigType Config ={F_CPU_8,RAISING};

	 /* Sending the address of struct to configure ICU unit */

	ICU_init(&Config);

	 /* set call-back function with Ultrasonic_init */

	ICU_setCallBack(Ultrasonic_edgeProcessing);

	/* Setup the direction for the trigger pin as output pin through the GPIO driver. */

	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID,ULTRASONIC_TRIGGER_PIN_ID,PIN_OUTPUT);

	/* Setup the direction for the echo pin as input pin through the GPIO driver. */

	GPIO_setupPinDirection(ULTRASONIC_ECHO_PORT_ID,ULTRASONIC_ECHO_PIN_ID,PIN_INPUT);

}

uint16 Ultrasonic_readDistance(void){

	/* Initialize the global variables to zero */
	g_edgeCount = 0;
	g_timeHigh = 0;

	/* Clear the timer counter register to start measurements once trigger is sent */
	ICU_clearTimerValue();

	Ultrasonic_Trigger();

	while(g_edgeCount != ULTRASONIC_NUM_OF_EDGES);

	return (((g_timeHigh)/ULTRASONIC_CALBIRATION_FACTOR)+1);
}


