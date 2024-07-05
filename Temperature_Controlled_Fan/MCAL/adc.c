 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: hussein el-shamy
 *
 *******************************************************************************/

#include "avr/io.h"
#include "adc.h"
#include "../Common/common_macros.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType *Config_Ptr)
{
	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt) << 6);

	ADCSRA = (ADCSRA & 0xF8) | ((Config_Ptr->prescaler) & 0x07) | (1 << ADEN);
}


/*
 * Description :
 * Function to set the ADC pre-scaler
 * */
void ADC_setPrescaler(const ADC_Prescaler divisionFactor)
{
	ADCSRA = (ADCSRA & 0xF8) | (divisionFactor & 0x07);
}
/*
 * Description :
 * Function to set the ADC Reference Volt
 * */
void ADC_setReferenceVolt(const ADC_ReferenceVolatge ref)
{
	ADMUX = (ADMUX & 0x3F) | (ref << 6);
}
uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX = (ADMUX & 0xE0) | (0x07 & channel_num);
	SET_BIT(ADCSRA,ADSC);
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}
/*
 * Description :
 * Function to disable ADC and reset its registers
 */
void ADC_deInit(void)
{
	ADMUX = 0;
	ADCSRA = 0;
}
/*
 * Description :
 * Function to enable ADC interrupt
 */
void ADC_interruptsEnable(void)
{
	ADCSRA = (ADCSRA & 0xF7) | (1<<ADIE);
}

/*
 * Description :
 * Function to enable ADC Auto Trigger
 */
void ADC_autoTriggerEnable(void)
{
	ADCSRA = (ADCSRA & 0xDF) | (1<<ADATE);
}

