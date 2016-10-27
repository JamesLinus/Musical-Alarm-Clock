/*
 * alarmclock.c
*
 * Author: Lilanka udawatta
*
 *  Created on: Dec 5, 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "derivative.h" /* include peripheral declarations */
#include "nokia_LCD.h"
#include "uart.h"
#include "clock.h"
#include "Freedom.h"
#include "utilities.h"

#include "Watch.h"
#include "Music.h"
#include "AlarmClock.h"
#include "Lyrics.h"


extern int seconds, minutes, hours, days, months, years, DoWIdx;
extern int hours_A, minutes_A, seconds_A;
extern int menu, Alarm_set, Alarm_trig, Alarm_tune;
extern char * today[], date[], time[], Alarm[]; //totlly not sure

void AlarmClockSys()
{
	__asm("wfi");
	
	if(menu==1)
	{
		clockMenu();
		menu=0;
	}
	
	if(Alarm_set==1)
	{
		if(hours == hours_A)
		{
			if(minutes == minutes_A)
			{
				if(seconds == seconds_A)
				{
					Alarm_trig = 1;
				}
			}
		}
	}
	
	if(Alarm_trig == 1)
	{
		switch(Alarm_tune)
		{
			case 1:
				music1();
				lcd_clear(BACKGROUND_COLOUR);
				break;
			
			case 2:
				music2();
				lcd_clear(BACKGROUND_COLOUR);
				break;
			
			case 3:
				music3();
				lcd_clear(BACKGROUND_COLOUR);
				break;
		}
	}
	
	if((menu==0)&(Alarm_trig==0))
	{
		DisplayTime();
	}
}
