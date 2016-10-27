//Program by Group C5

//Authors: NAOMI KAY LIM OON KEI (4305329), CHAMATH KALANAKA VITHANAWASAM (4314670), LILANKA KUSHAN UDAWATTA (4314395)

//Date: 23 November 2014 

//Version: 5.3.4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "derivative.h"
#include "nokia_LCD.h"
#include "uart.h"
#include "Freedom.h"
#include "utilities.h"
#include "clock.h"
#include "Music.h"
//#include "lyrics.c"
#include "Lyrics.h"

/*Declare Function*/ //done
void music1();
void music2();
void music3();
void delay(int time);
void AlarmClockSys();

/*Declare Global Variables*/
/*Set initial value*/
char Alarm[10];
char time[9];
char date[11];
int hours = 0;
int minutes = 0;
int seconds;
int DoWIdx;
int years = 2014;
int months = 11;
int days = 23;
char * today[] = {"Sun","Mon", "Tue", "Wed", "Thur", "Fri", "Sat"};
char selectColour1;
char selectColour2;
char selectColour3;
int hours_A = 0;
int minutes_A = 0;
int seconds_A = 0;
int Clock_Display=1;
int menu=0;
int Alarm_set=1;
int Alarm_trig=0;
int Alarm_tune=3;
int note = 1; 
int tempo = 64;


int main(void)
 {
	
	initialiseClock();
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK | SIM_SCGC5_PORTB_MASK | SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK | SIM_SCGC5_PORTE_MASK;
	lcd_initialise();
	lcd_clear(BACKGROUND_COLOUR);
	switch_initialise();
	initialiseBuzzer();
	initialiseRTC();
	initialiseFTM();
	centreSwitchIRQ();
	
	 while (1)
	 {
	    	AlarmClockSys();
	  }
	
	return 0;
}

void RTC_Seconds_IRQHandler(void)
{
	digitalClock();
}

void PORTD_IRQHandler(void)
{

	delay(100);
	if((menu == 0)&(Alarm_trig==0))
	{
		menu=1;
	}
	
	else if(Alarm_trig == 1 )
	{
		Alarm_trig = 0;
	}
	CENTRE_SWITCH_PCR |= PORT_PCR_ISF_MASK;

}

void FTM0_IRQHandler(void)
{
	//clear all interrupt request from ftm0.ch3
	FTM0_C7SC &= ~FTM_CnSC_CHF_MASK;
	
	//RETRIGGER AT T+HALF PERIOD
	FTM0_C7V += note;
}

void FTM1_IRQHandler(void)
{
	(void)FTM1_SC;
	FTM1_SC &= ~FTM_SC_TOF_MASK;
	tempo--;
}
