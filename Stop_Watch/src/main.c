/******************************************************************************/
/* !Project         : Stop Watch				                              */
/* !Description     : Implementation of stop watch using ATmega32             */
/* !File            : main.c                                                  */
/* !Coding language : C                                                       */
/* !Target          : ATmega32                                                */
/* !Compiler        : AVR-GCC Tool Chain                                      */
/* !Mentor	        : Engineer Mohamed Tarek      							  */
/* !Coded by        : Hussein El-Shamy 			  !Date : September 14, 2023  */
/******************************************************************************/

#include <avr/io.h>

/******************************************************************************/
/*! \Description: This header file includes the useful I/O definitions        */
/******************************************************************************/

#include <avr/interrupt.h>

/******************************************************************************/
/*! \Description: This header file can be used to handle ISRs                 */
/******************************************************************************/

#include <util/delay.h>

/******************************************************************************/
/*! \Description: This header file includes some delay functions that		  */
/* used in the project                                                        */
/******************************************************************************/

/******************************************************************************/
/*! \Function Name: timer1_Init                                               */
/*! \Description: Initialize timer1 parameters to work on compare mode        */
/******************************************************************************/

void timer1_Init(void) {

	TCNT1 = 0;  	// Starting count from 0

	OCR1A = 976; 	// Compare match equal 976 tick to count (1 Second)

	SREG |= (1 << 7);	// Enable I-Bit in status register

	TIMSK |= (1 << OCIE1A);	// Enable Compare A match interrupt

	// 	CTC mode with normal port operation
	// 	1024 Pre-scaler

	TCCR1A = (1 << FOC1A);
	TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10); // Starting count
}

//Global variable to indicate that the timer count successfully one second
unsigned char second_flag = 0;

/******************************************************************************/
/*! \Function Name: ISR(TIMER1_COMPA_vect)                                    */
/*! \Description: Interrupt service routine of Timer1 CTC mode                */
/******************************************************************************/

ISR(TIMER1_COMPA_vect) {
	// Enable second flag to to indicate that the timer count successfully one second
	second_flag = 1;
}

/******************************************************************************/
/*! \Function Name: INT0_Init                                                 */
/*! \Description: to configure external interrupt 0 as required featured      */
/******************************************************************************/

void INT0_Init(void) {
	// Dealing with Falling Edge
	MCUCR |= (1 << ISC01);
	// Module Interrupt Enable
	GICR |= (1 << INT0);
	// I-Bit Enable in status register
	SREG |= (1 << 7);
}

unsigned char reset_flag = 0; //Global variable work as flag to indicate about reset clock

/******************************************************************************/
/*! \Function Name: ISR(INT0_vect)                                            */
/*! \Description: Interrupt service routine of external interrupt 0 [RESET]   */
/******************************************************************************/

ISR(INT0_vect) {
	// enable the flag
	reset_flag = 1;
	//reset the count register to Start count from 0
	TCNT1 = 0;
	//also reset the Compare match equal 976 tick to count 1 Second [as a safe consideration]
	OCR1A = 976;
}

/******************************************************************************/
/*! \Function Name: INT1_Init                                                 */
/*! \Description: to configure external interrupt 1 as required featured      */
/******************************************************************************/

void INT1_Init(void) {
	//Dealing with Rising Edge
	MCUCR |= (1 << ISC11) | (1 << ISC10);
	// Module Interrupt Enable
	GICR |= (1 << INT1);
	// I-Bit Enable in status register
	SREG |= (1 << 7);
}

/******************************************************************************/
/*! \Function Name: ISR(INT1_vect)                                            */
/*! \Description: Interrupt service routine of external interrupt 1 [PAUSE]   */
/******************************************************************************/

ISR(INT1_vect) {
	// Disable module interrupt
	TIMSK &= ~(1 << OCIE1A);
}

/******************************************************************************/
/*! \Function Name: INT2_Init                                                 */
/*! \Description: to configure external interrupt 2 as required featured      */
/******************************************************************************/

void INT2_Init(void) {
	//Dealing with Falling Edge
	MCUCSR |= (1 << ISC2);
	//Module Interrupt Enable
	GICR |= (1 << INT2);
	// I-Bit Enable in status register
	SREG |= (1 << 7);
}

/******************************************************************************/
/*! \Function Name: ISR(INT1_vect)                                            */
/*! \Description: Interrupt service routine of external interrupt 1 [RESUME]   */
/******************************************************************************/

ISR(INT2_vect) {
	// Enable module interrupt to resume
	TIMSK |= (1 << OCIE1A);
}

/******************************************************************************/
/*! \Function Name: sevenSgementDisp                                          */
/*! \Description: to display numbers on 7 segments by generate BCD code       */
/******************************************************************************/

void sevenSgementDisp(unsigned char num) {

	//Note that the 7 segments is common anode

	switch (num) {
	case 0:
		PORTC = 0x00;  //0b00000000
		break;
	case 1:
		PORTC = 0x01;  //0b00000001
		break;
	case 2:
		PORTC = 0x02;  //0b00000010
		break;
	case 3:
		PORTC = 0x03;  //0b00000011
		break;
	case 4:
		PORTC = 0x04;  //0b00000100
		break;
	case 5:
		PORTC = 0x05;  //0b00000101
		break;
	case 6:
		PORTC = 0x06;  //0b00000110
		break;
	case 7:
		PORTC = 0x07;  //0b00000111
		break;
	case 8:
		PORTC = 0x08;  //0b00001000
		break;
	case 9:
		PORTC = 0x09;  //0b00001001
		break;
	default:
		// if not out of the range (0-9) break the switch without writing any thing
		break;
	}
}

/******************************************************************************/
/*! \Function Name: main                                                      */
/*! \Description: contain the core of functionalities                         */
/******************************************************************************/

int main(void) {

	unsigned char seconds = 0;  //Initiate variable to store seconds
	unsigned char minutes = 0;  //Initiate variable to store minutes
	unsigned char hours = 0;    //Initiate variable to store hours

	DDRC = 0x0F;				//Enable the first 4-pins in PORTC to be output
	sevenSgementDisp(0);		//Initialize 7 segments to display zeros
	DDRA = 0x3F;				//Enable the first 6-pins in PORTA to be output
	PORTA = 0x3F;				//Initialize PORTA with LOW logic output

	DDRD &= (1 << PD2) & (1 << PD3);	//PD2 & PD3 to be input pin
	PORTD |= (1 << PD2);			//PD2 to configure as internal pull up

	DDRB &= (1 << PB2);			//PB2 to be input pin
	PORTB |= (1 << PB2);			//PB2 to configure as internal pull up

	timer1_Init();				//Call timer_Init function
	INT0_Init();				//Call INT0_Init function
	INT1_Init();				//Call INT1_Init function
	INT2_Init();				//Call INT2_Init function

	while (1) {					//Super loop to maintain in the program

		// to converting from seconds to minutes and hours in case the interrupt is emitted
		if (second_flag) {
			seconds++;
			if (seconds == 60) {
				seconds = 0;
				minutes++;
			}
			if (minutes == 60) {
				minutes = 0;
				hours++;
			}
			// return the flag to disable state
			second_flag = 0;
		}

		//to reset all count time stored in variables in case the interrupt is emitted
		if (reset_flag) {
			seconds = 0;
			minutes = 0;
			hours = 0;
			// return the flag to disable state
			reset_flag = 0;
		}

		//looping (pooling technique) on every 7-segment of the six
		//[1] enable the 7-segment
		PORTA = 0x01;
		//[2] display the number in the 7-segment
		//the first 7-segment will take the first digit so we need to
		//get the 10 modulus of the seconds
		sevenSgementDisp(seconds % 10);
		//[3] delay with 100 micro-seconds to display the number (notice it)
		//and so on to every 7-segment unit
		_delay_us(100);
		PORTA = 0x02;
		sevenSgementDisp(seconds / 10);
		_delay_us(100);

		PORTA = 0x04;
		sevenSgementDisp(minutes % 10);
		_delay_us(100);
		PORTA = 0x08;
		sevenSgementDisp(minutes / 10);
		_delay_us(100);

		PORTA = 0x10;
		sevenSgementDisp(hours % 10);
		_delay_us(100);
		PORTA = 0x20;
		sevenSgementDisp(hours / 10);
		_delay_us(100);

	}

	return 0;
}

/******************************************************************************/
/*                            END OF FILE                                     */
/******************************************************************************/
