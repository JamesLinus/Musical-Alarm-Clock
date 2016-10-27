/*
 * Watch.c
 *
 *  Created on: May 15, 2016
 *      Author: LiLShRedDer
 */


/*
 * watch.c
 *
 *  Created on: Dec 5, 2014
 *      Author: Naomi Lim
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
extern char selectColour1, selectColour2, selectColour3; //done
extern void delay (int time); //done


void initialiseRTC(void)
{
	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;
	
	RTC_LR |= RTC_LR_LRL_MASK | RTC_LR_SRL_MASK | RTC_LR_CRL_MASK | RTC_LR_TCL_MASK; //enabling all registers
	RTC_SR &= ~RTC_SR_TCE_MASK; //switch off status register
	
	RTC_CR |= RTC_CR_OSCE_MASK; //enable oscillator register
	//RTC_TPR = 0;
	RTC_TSR = 0; //clear the time invalid flag
	//RTC_TAR = 0;
	
	RTC_SR |= RTC_SR_TCE_MASK;
	RTC_IER |= RTC_IER_TSIE_MASK;
	
	
	NVIC_EnableIrq(INT_RTC_Seconds);	
}

//Initialising switch inputs
void switch_initialise(void)
{
	
	
	//SETTINGS FOR PORTS
	CENTRE_SWITCH_PCR = PORT_PCR_MUX(1) | PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	CENTRE_SWITCH_PDDR &= ~(1<<CENTRE_SWITCH_NUM);
	RIGHT_SWITCH_PCR = PORT_PCR_MUX(1)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
	RIGHT_SWITCH_PDDR &= ~(1<<NORTH_SWITCH_NUM);
	LEFT_SWITCH_PCR = PORT_PCR_MUX(1)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
	LEFT_SWITCH_PDDR &= ~(1<<SOUTH_SWITCH_NUM);
	DOWN_SWITCH_PCR = PORT_PCR_MUX(1)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
	DOWN_SWITCH_PDDR &= ~(1<<EAST_SWITCH_NUM);
	UP_SWITCH_PCR = PORT_PCR_MUX(1)|PORT_PCR_PE_MASK|PORT_PCR_PS_MASK;
	UP_SWITCH_PDDR &= ~(1<<WEST_SWITCH_NUM);	
}

void digitalClock()
{
	seconds ++;
	if(seconds == 60)
	{
		seconds = 0;
		minutes++;	
	}
	
	if(minutes == 60)
	{
		minutes = 0;
		hours++;
		
	}
	
	if(hours == 24)
	{
		hours = 0;
		days++;
	}
	
		//DisplayTime();
	CurrentDate();	
}

void CurrentDate()//combine with time
{
	if(months == 1 || months ==3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12)
	{
		if(days > 31)
		{
			days = 1;
			months ++;
		}
	}
		
	if(months == 2)
	{
		if(days > 28)
		{
				days = 1;
				months ++;
		}
	}
	
	if(days > 30)
	{
		days = 1;
		months ++;
	}
	
	if(months == 13)
	{
		months = 1;
		years ++;
	}
	
	DoWIdx = dow(years, months, days);
		
}

void DisplayTime()
{
	
		lcd_drawCircle(ORIGIN_X, ORIGIN_Y, RADIUS, CIRCLE_COLOUR, FULLCIRCLE);
		
		lcd_drawLine(ORIGIN_X, ORIGIN_Y, ORIGIN_X + HOUR*sin(PI/180*30*(hours-1)), ORIGIN_Y + HOUR*cos(PI/180*30*(hours-1)), BACKGROUND_COLOUR);
		lcd_drawLine(ORIGIN_X, ORIGIN_Y, ORIGIN_X + MINUTE*sin(PI/180*6*(minutes-1)), ORIGIN_Y + MINUTE*cos(PI/180*6*(minutes-1)), BACKGROUND_COLOUR);
		lcd_drawLine(ORIGIN_X, ORIGIN_Y, ORIGIN_X + SECOND*sin(PI/180*6*(seconds-1)), ORIGIN_Y + SECOND*cos(PI/180*6*(seconds-1)), BACKGROUND_COLOUR);
			
		lcd_drawLine(ORIGIN_X, ORIGIN_Y, ORIGIN_X + HOUR*sin(PI/180*30*hours), ORIGIN_Y + HOUR*cos(PI/180*30*hours), CLOCK_COLOUR);
		lcd_drawLine(ORIGIN_X, ORIGIN_Y, ORIGIN_X + MINUTE*sin(PI/180*6*minutes), ORIGIN_Y + MINUTE*cos(PI/180*6*minutes), SLATE);
		lcd_drawLine(ORIGIN_X, ORIGIN_Y, ORIGIN_X + SECOND*sin(PI/180*6*seconds), ORIGIN_Y + SECOND*cos(PI/180*6*seconds), GRAY);
		
		
		Display();
		
}

void Display()
{
	sprintf(date, "%s %02d.%02d.%04d", today[DoWIdx], days, months, years);
	lcd_putStr(date, 15, 30, FontMedium, DATE_COLOUR, BACKGROUND_COLOUR);
			
	sprintf(time, "%02d:%02d:%02d", hours, minutes, seconds);
	lcd_putStr(time, 33, 49, FontMedium, CLOCK_COLOUR, BACKGROUND_COLOUR);
			
	sprintf(Alarm,"Alarm %02d:%02d",hours_A, minutes_A);
	lcd_putStr(Alarm, 20, 10, FontLarge, ALARM_COLOUR, BACKGROUND_COLOUR);//Display Alarm on the screen
					
}

void clockMenu()
{
	int exit = 0;
	int submenu = 1;
	
	DisableCentreSwitchIRQ();
	
	lcd_clear(BACKGROUND_COLOUR);
	delay(100);
	
	while(exit == 0)
	{
		lcd_putStr("Settings", TITLE_X, TITLE_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
		
		if(getUpSwitch())
		{
			submenu--;
			if(submenu < 1)
			{
				submenu = 5;
			}
			delay(100);
		}
		
		if(getDownSwitch())
		{
			submenu++;
			if(submenu > 5)
			{
				submenu = 1;
			}
			delay(100);
		}
		
		switch(submenu)
		{
		case 1:
			lcd_putStr("Set Time", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
			lcd_putStr("Set Date", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Alarm", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Alarm Tune", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
						
			lcd_putStr("Exit", SUBMENU_X, SUBMENU5_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			
			if(getCentreSwitch())
			{
				delay(100);
				setTime();
			}
			
			break;
		
		case 2:
			lcd_putStr("Set Time", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Date", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
			lcd_putStr("Set Alarm", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Alarm Tune", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
						
			lcd_putStr("Exit", SUBMENU_X, SUBMENU5_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
						
			if(getCentreSwitch())
			{
				delay(100);
				setDate();
			}
			break;
			
		case 3:
			lcd_putStr("Set Time", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Date", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Alarm", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
			lcd_putStr("Set Alarm Tune", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
									
			lcd_putStr("Exit", SUBMENU_X, SUBMENU5_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
									
			if(getCentreSwitch())
			{
				delay(100);
				setAlarm();
			}
			break;
			
		case 4:
			lcd_putStr("Set Time", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Date", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Alarm", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Alarm Tune", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
												
			lcd_putStr("Exit", SUBMENU_X, SUBMENU5_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
												
			if(getCentreSwitch())
			{
				delay(100);
				setAlarmTune();
			}
			break;
			
		case 5:
			lcd_putStr("Set Time", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Date", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Alarm", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("Set Alarm Tune", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
															
			lcd_putStr("Exit", SUBMENU_X, SUBMENU5_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
															
			if(getCentreSwitch())
			{
				delay(100);
				exit = 1;
			}
			break;
		}
	}
	lcd_clear(BACKGROUND_COLOUR);//NEW
	centreSwitchIRQ();
	
	
}

void setDate()
{
	int exit = 0;
	int submenu = 1;
	char temp[20];
	lcd_clear(BACKGROUND_COLOUR);
	selectColour1 = BACKGROUND_COLOUR;
	selectColour2 = BACKGROUND_COLOUR;
	selectColour3 = BACKGROUND_COLOUR;
	
	while(exit == 0)
	{
		lcd_putStr("Date Settings", 13, 110, FontLarge, WHITE, BACKGROUND_COLOUR);
		sprintf(temp, "%02d", days);				
		lcd_putStr (temp, DATE_X, 58, FontLarge, WHITE, selectColour1	);
		
		
		lcd_putChar('.'	, DATE_X + 18, 58, FontLarge, WHITE, BACKGROUND_COLOUR);
		sprintf(temp, "%02d", months );
		lcd_putStr (temp, DATE_X + 27, 58, FontLarge, WHITE, selectColour2	);
		
		
		lcd_putChar('.'	, DATE_X + 45, 58, FontLarge, WHITE, BACKGROUND_COLOUR);
		sprintf(temp, "%04d" , years );
		lcd_putStr (temp, DATE_X + 54, 58, FontLarge, WHITE, selectColour3	);		
		if (getRightSwitch())
		{
			submenu ++;
			if (submenu > 3)
				submenu = 1;
			delay(100);
		}
		if (getLeftSwitch())
		{
			submenu --;
			if (submenu < 1)
				submenu = 3;
			delay(100);
		}
		if (getCentreSwitch())
		{
			delay(100);
			exit = 1;
		}
		if (getUpSwitch())
		{
			if (submenu == 1)
			{
				days++;
				if((months==1)|(months==3)|(months==5)|(months==7)|(months==8)|(months==10)|(months==12))
				{
					if(days > 31)
					{
						days = 1;
					}
				}
				if((months==4)|(months==6)|(months==9)|(months==11))
				{
					if(days > 30)
					{
						days = 1;
					}
				}
				if(months==2)
				{
					if(years%4 || 0)
					{
						if(days > 28)
						{
							days = 1;
						}
					}
					if(days > 29)
					{
						days = 1;
					}
				}			
			}
			if (submenu == 2)
			{
				months++;
				if (months > 12)
				{
					months = 1;
				}
			}
			if (submenu == 3)
			{
				years++;
			}
			delay(100);
		}
		if (getDownSwitch())
		{
			if (submenu == 1)
			{
				days--;
				if((months==1)|(months==3)|(months==5)|(months==7)|(months==8)|(months==10)|(months==12))
				{
					if(days < 1)
					{
						days = 31;
					}
				}
				if((months==4)|(months==6)|(months==9)|(months==11))
				{
					if(days < 1)
					{
						days = 30;
					}
				}
				if(months==2)
				{
					if(years%4==0)
					{
						if(days < 1)
						{
							days = 29;
						}
					}
					if(days < 1)
					{
						days = 28;
					}
				}			
			}
			if (submenu == 2)
			{
				months--;
				if (months < 1)
				{
					months = 12;
				}
			}
			if (submenu == 3)
			{
				years--;
			}
			delay(100);
		}
		
		switch (submenu)
		{
			case 1:
			selectColour2 = BACKGROUND_COLOUR;
			selectColour3 = BACKGROUND_COLOUR;
			selectColour1 = SELECT_COLOUR;
			break;
			
			case 2:
			selectColour1 = BACKGROUND_COLOUR;
			selectColour3 = BACKGROUND_COLOUR;
			selectColour2 = SELECT_COLOUR;
			break;
			
			case 3:
			selectColour1 = BACKGROUND_COLOUR;
			selectColour2 = BACKGROUND_COLOUR;
			selectColour3 = SELECT_COLOUR;
			break;
		}
	}
	lcd_clear(BACKGROUND_COLOUR);
}

void setTime()
{
	int exit = 0;
	int submenu = 1;
	char temphour[3], tempmin[3], tempsec[3];
	lcd_clear(BACKGROUND_COLOUR);
	lcd_putStr("Time Settings", SUBMENU_X, TITLE_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
	seconds = 0;
	
	while(exit == 0)
	{
		sprintf(tempsec, "%02d",seconds);
		sprintf(tempmin, "%02d",minutes);
		sprintf(temphour, "%02d",hours);
		
		if(getRightSwitch())
		{
			submenu++;
			if(submenu > 2)
			{
				submenu = 1;
			}
			delay(100);
		}
		if(getLeftSwitch())
		{
			submenu--;
			if(submenu < 1)
			{
				submenu = 2;
			}
			delay(100);
		}
		switch(submenu)
		{
			case 1:
				lcd_putStr(tempsec, CLOCK_X+54, CLOCK_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
				lcd_putStr(tempmin, CLOCK_X+27, CLOCK_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
				lcd_putStr(temphour, CLOCK_X, CLOCK_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
		
				if(getCentreSwitch())
				{
					delay(100);
					exit = 1;
				}
		
				if(getDownSwitch())
				{
					hours++;
					if(hours > 23)
					{
						hours = 0;
					}
					delay(100);
				}
				if(getUpSwitch())
				{
					hours--;
					if(hours < 0)
					{
						hours = 23;
					}
					delay(100);
				}
			break;
			
			case 2:
				lcd_putStr(tempsec, CLOCK_X+54, CLOCK_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
				lcd_putStr(tempmin, CLOCK_X+27, CLOCK_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
				lcd_putStr(temphour, CLOCK_X, CLOCK_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
		
				if(getCentreSwitch())
				{
					delay(100);
					exit = 1;
				}
		
				if(getDownSwitch())
				{
					minutes++;
					if(minutes > 59)
					{
						minutes = 0;
					}
					delay(100);
				}
				if(getUpSwitch())
				{
					minutes--;
					if(minutes < 0)
					{
						minutes = 59;
					}
					delay(100);
				}
			break;				
		}
	}
	lcd_clear(BACKGROUND_COLOUR);
}

void setAlarm() //from other source file
{
	lcd_clear(BACKGROUND_COLOUR);
	
	int exit = 0;
	int submenu = 1;
	
	char temphours[3], tempmins[3], tempsecs[3];
	lcd_clear(BACKGROUND_COLOUR);
	
	lcd_putStr("Alarm Settings", SUBMENU_X, TITLE_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
	
	
	while(exit == 0)
	{
		sprintf(tempsecs, "%02d",seconds_A);
		sprintf(tempmins, "%02d",minutes_A);
		sprintf(temphours, "%02d",hours_A);
				
		if(getRightSwitch())
		{
			submenu++;
			
			if(submenu > 2)
			{
				submenu = 1;
			}
			delay(100);
		}
		
		if(getLeftSwitch())
		{
			submenu++;
			
			if(submenu < 1)
			{
				submenu = 2;
			}
			delay(100);
		}
		
		
		switch(submenu)
		{
			case 1:
				lcd_putStr(tempsecs, CLOCK_X+54, CLOCK_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
				lcd_putStr(tempmins, CLOCK_X+27, CLOCK_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
				lcd_putStr(temphours, CLOCK_X, CLOCK_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
				
				if(getCentreSwitch())
				{
					delay(100);
					exit = 1;
				}
				
				if(getDownSwitch())
				{
					hours_A++;
					if(hours_A > 23)
					{
						hours_A = 0;
					}
					delay(100);
				}
				
				if(getUpSwitch())
				{
					hours_A--;
					if(hours_A < 0)
					{
						hours_A = 23;
					}
					delay(100);
				}
				break;
					
			
			case 2:
				lcd_putStr(tempsecs, CLOCK_X+54, CLOCK_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
				lcd_putStr(tempmins, CLOCK_X+27, CLOCK_Y, FontLarge, CHARACTER_COLOUR, SELECT_COLOUR);
				lcd_putStr(temphours, CLOCK_X, CLOCK_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR);
				
				if(getCentreSwitch())
				{
					delay(100);
					exit = 1;
				}
				
				if(getDownSwitch())
				{
					minutes_A++;
					if(minutes_A > 59)
					{
						minutes_A = 0;
					}
					delay(100);
				}
				
				if(getUpSwitch())
				{
					minutes_A--;
					if(minutes_A < 0)
					{
						minutes_A = 59;
					}
					delay(100);
				}
			break;				
		}
	}
	Alarm_set = 1;
	lcd_clear(BACKGROUND_COLOUR);
}

void setAlarmTune()
{
	lcd_clear(BACKGROUND_COLOUR);
	int exit = 0;
	int submenu = 1;
	
	while(exit == 0)
	{
		if(getUpSwitch())
		{
			delay(100);
			submenu--;
			
			if(submenu == 0)
			{
				submenu = 3;
			}
		}
		
		if(getDownSwitch())
		{
			delay(100);
			submenu++;
			
			if(submenu == 4)
			{
				submenu = 1;
			}
		}
		
		switch(submenu)
		{
		case 1:
			lcd_putStr("We wish you a ", SUBMENU_X, SUBMENU1_Y, FontMedium,SELECT_COLOUR,BACKGROUND_COLOUR);
			lcd_putStr("Merry Christmas", SUBMENU_X, SUBMENU2_Y, FontMedium, SELECT_COLOUR,BACKGROUND_COLOUR);
			lcd_putStr("Deck the halls", SUBMENU_X, SUBMENU3_Y, FontMedium, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
			lcd_putStr("Santa Claus is  ", SUBMENU_X, SUBMENU4_Y, FontMedium, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("coming to town", SUBMENU_X, SUBMENU5_Y, FontMedium, CHARACTER_COLOUR,BACKGROUND_COLOUR);
			
			if(getCentreSwitch())
			{
				Alarm_tune = 1;
				exit = 1;
				delay(100);
			}
			
			break;
			
		case 2:	
			lcd_putStr("We wish you a ", SUBMENU_X, SUBMENU1_Y, FontMedium,CHARACTER_COLOUR,BACKGROUND_COLOUR);
			lcd_putStr("Merry Christmas", SUBMENU_X, SUBMENU2_Y, FontMedium, CHARACTER_COLOUR,BACKGROUND_COLOUR);
			lcd_putStr("Deck the halls", SUBMENU_X, SUBMENU3_Y, FontMedium, SELECT_COLOUR, BACKGROUND_COLOUR) ;
			lcd_putStr("Santa Claus is  ", SUBMENU_X, SUBMENU4_Y, FontMedium, CHARACTER_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("coming to town", SUBMENU_X, SUBMENU5_Y, FontMedium, CHARACTER_COLOUR,BACKGROUND_COLOUR);
			
			if(getCentreSwitch())
			{
				Alarm_tune = 2;
				exit = 1;
				delay(100);
			}
			
			break;
		
		case 3:
			lcd_putStr("We wish you a ", SUBMENU_X, SUBMENU1_Y, FontMedium,CHARACTER_COLOUR,BACKGROUND_COLOUR);
			lcd_putStr("Merry Christmas", SUBMENU_X, SUBMENU2_Y, FontMedium, CHARACTER_COLOUR,BACKGROUND_COLOUR);
			lcd_putStr("Deck the halls", SUBMENU_X, SUBMENU3_Y, FontMedium, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
			lcd_putStr("Santa Claus is  ", SUBMENU_X, SUBMENU4_Y, FontMedium, SELECT_COLOUR, BACKGROUND_COLOUR);
			lcd_putStr("coming to town", SUBMENU_X, SUBMENU5_Y, FontMedium, SELECT_COLOUR,BACKGROUND_COLOUR);
			
			if(getCentreSwitch())
			{
				Alarm_tune = 3;
				exit = 1;
				delay(100);
			}
			
			break;
		}
	}
	lcd_clear(BACKGROUND_COLOUR);
	delay(100);
	Alarm_set = 1;
	
}

int dow(int y, int m, int d)
{
	static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

//Checking if centre-switch is pressed
int getCentreSwitch(void)
{
	return (CENTRE_SWITCH_PDIR & CENTRE_SWITCH_MASK) == 0;
}

//Checking if up-switch is pressed
int getUpSwitch(void)
{
	return (UP_SWITCH_PDIR & UP_SWITCH_MASK) == 0;
}

//Checking if down-switch is pressed
int getDownSwitch(void)
{
	return (DOWN_SWITCH_PDIR & DOWN_SWITCH_MASK) == 0;
}

//Checking if left-switch is pressed
int getLeftSwitch(void)
{
	return (LEFT_SWITCH_PDIR & LEFT_SWITCH_MASK) == 0;
}

//Checking if right-switch is pressed
int getRightSwitch(void)
{
	return (RIGHT_SWITCH_PDIR & RIGHT_SWITCH_MASK) == 0;
}

void centreSwitchIRQ(void)
{
	CENTRE_SWITCH_PCR |= PORT_PCR_IRQC(0xA);
	NVIC_EnableIrq(INT_PORTD);
	NVIC_SetIrqPriority(INT_PORTD,1); // this line is error IRQn
	
}

void DisableCentreSwitchIRQ(void)
{
	CENTRE_SWITCH_PCR &= ~PORT_PCR_IRQC(0xA);
	NVIC_DisableIrq(INT_PORTD);//
	
}

void enableRTC_Seconds_IRQHandler(void)
{
	RTC_IER |= RTC_IER_TSIE_MASK;
	NVIC_EnableIrq(INT_RTC_Seconds);
	NVIC_SetIrqPriority(INT_RTC_Seconds,8);
	
	
}

void disableRTC_Seconds_IRQHandler(void)
{
	RTC_IER &= ~RTC_IER_TSIE_MASK;
	NVIC_DisableIrq(INT_RTC_Seconds);
}
