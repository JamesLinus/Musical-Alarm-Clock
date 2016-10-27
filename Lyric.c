/*
 * lyrics.c
 *
 *  Created on: Dec 4, 2014
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


#include "Music.h"
#include "Lyrics.h"
#include "Watch.h"
#include "AlarmClock.h"



extern int Alarm_trig;

void music1()
{
		lcd_clear(BACKGROUND_COLOUR); //background colour
		lcd_putStr("We wish you a   ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("Merry Christmas,", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("we wish you a   ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("Merry Christmas,", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
		 
		lcd_putStr("We", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,4);
		lcd_putStr("We wish", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		playnote(0,1);
		lcd_putStr("We wish you", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("We wish you a   ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("Me", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,2);
		lcd_putStr("Merry", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,2);
		lcd_putStr("Merry Christ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		playnote(0,1);
		lcd_putStr("Merry Christmas,", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		playnote(0,1);
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("we", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("we wish", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
		playnote(0,1);
		lcd_putStr("we wish you", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		lcd_putStr("we wish you a   ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E7,2);
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("Me", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		lcd_putStr("Merry", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,2);
		lcd_putStr("Merry Christ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		lcd_putStr("Merry Christmas,", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1); //confirm finish
		

		lcd_clear(BACKGROUND_COLOUR);
		
		lcd_putStr("We wish you a   ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("Merry Christmas,", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("and a Happy     ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("New Year!       ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
		
		if(Alarm_trig==0)
			return;
		
		lcd_putStr("We", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,4);
		lcd_putStr("We wish", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E7,4);
		playnote(0,1);
		lcd_putStr("We wish you", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E7,4);
		lcd_putStr("We wish you a   ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F7,2);
				
		if(Alarm_trig==0)
				return;
				
		lcd_putStr("Me", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E7,2);
		lcd_putStr("Merry", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		lcd_putStr("Merry Christ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("Merry Christmas,", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		
		if(Alarm_trig==0)
		return;
						
		lcd_putStr("and", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,2);
		playnote(0,1);
		lcd_putStr("and a", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("and a Hap", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("and a Happy     ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
				
		if(Alarm_trig==0)
			return;
						
		lcd_putStr("New", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		lcd_putStr("New Year!       ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,8); //confirmed
		
		lcd_clear(BACKGROUND_COLOUR);
		
		lcd_putStr("Good tidings    ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("to you,         ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("wherever        ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("you are         ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		
		if(Alarm_trig==0)
			return;
		
		lcd_putStr("Good", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("Good ti", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		playnote(0,1);
		lcd_putStr("Good tidings    ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		playnote(0,1);
		
		if(Alarm_trig==0)
			return;
		
		lcd_putStr("to", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("to you,         ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,8);
		playnote(0,1);
		
		if(Alarm_trig==0)
			return;
		
		lcd_putStr("where", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		lcd_putStr("wherev", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("wherever        ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);

		if(Alarm_trig==0)
			return;
		
		lcd_putStr("you", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("you are,        ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,8);
		playnote(0,1); //CONFIRMED

		lcd_clear(BACKGROUND_COLOUR);
				
		lcd_putStr("we wish you a   ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("Merry Christmas,", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("and a Happy     ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("New Year!       ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("we", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(D7,4);
		lcd_putStr("we wish", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E7,4);
		lcd_putStr("we wish you", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		playnote(0,1);
		lcd_putStr("we wish you a   ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
						
		if(Alarm_trig==0)
				return;
						
		lcd_putStr("Me", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,2);
		playnote(0,1);
		lcd_putStr("Merry", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,2);
		lcd_putStr("Merry Christ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G7,4);
		lcd_putStr("Merry Christmas,", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
				
		if(Alarm_trig==0)
				return;
								
		lcd_putStr("and", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,2);
		playnote(0,1);
		lcd_putStr("and a", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("and a Hap", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("and a Happy     ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
						
		if(Alarm_trig==0)
			return;
								
		lcd_putStr("New", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		lcd_putStr("New Year!       ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,8);
}

void music2()
{
 
		lcd_clear(BACKGROUND_COLOUR); //background colour
		lcd_putStr("Deck the halls  ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("with boughs of  ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("holly, Fa la la ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("la la la la la  ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
		 
		lcd_putStr("Deck", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(C7,6);
		lcd_putStr("Deck the", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6s,2);
		lcd_putStr("Deck the halls  ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("with", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("with boughs", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
		lcd_putStr("with boughs of  ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);

		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("hol", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("holly,", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
		lcd_putStr("holly, Fa", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("holly, Fa la", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,2);
		lcd_putStr("holly, Fa la la ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6s,2);
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,6);
		lcd_putStr("la la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("la la la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
		lcd_putStr("la la la la la  ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4);
		
		lcd_clear(BACKGROUND_COLOUR);
		
		lcd_putStr("la~ 'Tis the    ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("season to be    ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("jolly, Fa la la ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("la la la la la  ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
				 
		lcd_putStr("la~", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(F6,8);
		playnote(0,1);
		lcd_putStr("la~ 'Tis", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("la~ 'Tis the    ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6s,2);
				
		if(Alarm_trig==0)
				return;
				
		lcd_putStr("sea", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("season", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("season to", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
		lcd_putStr("season to be    ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		
		if(Alarm_trig==0)
		return;
						
		lcd_putStr("jol", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(A6,4);
		lcd_putStr("jolly,", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
		lcd_putStr("jolly, Fa", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("jolly, Fa la", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,2);
		lcd_putStr("jolly, Fa la la ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6s,2);
				
		if(Alarm_trig==0)
			return;
						
		lcd_putStr("la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,6); 
		lcd_putStr("la la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2); 
		lcd_putStr("la la la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4); 
		lcd_putStr("la la la la la  ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4); 
		playnote(0,1);
		
		lcd_clear(BACKGROUND_COLOUR);
		
		lcd_putStr("la~ Troul the   ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("ancient Christ- ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("mas carol, Fa la", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("la la la la la  ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		
		lcd_putStr("la~", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
		playnote(0,1);
		lcd_putStr("la~ Troul", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,6);
		lcd_putStr("la~ Troul the   ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,2);

		if(Alarm_trig==0)
			return;
		
		lcd_putStr("an", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6s,4);
		lcd_putStr("ancient", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("ancient Christ- ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,6);		
		
		if(Alarm_trig==0)
			return;
		
		lcd_putStr("mas", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6s,2);
		lcd_putStr("mas ca", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("mas carol,", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("mas carol, Fa", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,2);
		lcd_putStr("mas carol, Fa la", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,2);

		if(Alarm_trig==0)
			return;
		
		lcd_putStr("la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,3);
		playnote(0,1);
		lcd_putStr("la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		lcd_putStr("la la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E7,2);
		lcd_putStr("la la la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F7,4);
		lcd_putStr("la la la la la  ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E7,5);

		lcd_clear(BACKGROUND_COLOUR);
				
		lcd_putStr("la la~ See the  ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("flowing bowl    ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("before us, Fa la", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("la la la la la  ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
						 
		lcd_putStr("la", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(D7,5);
		lcd_putStr("la la~", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,8);
		playnote(0,1);
		lcd_putStr("la la~ See", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,6);
		lcd_putStr("la la~ See the  ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6s,4);
						
		if(Alarm_trig==0)
				return;
						
		lcd_putStr("flo", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("flowing", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("flowing bowl    ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
				
		if(Alarm_trig==0)
				return;
								
		lcd_putStr("be", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,4);
		lcd_putStr("before", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("before us", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
		playnote(0,1);
		lcd_putStr("before us, Fa", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		playnote(0,1);
		lcd_putStr("before us, Fa la", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		playnote(0,1);
						
		if(Alarm_trig==0)
			return;
								
		lcd_putStr("la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		playnote(0,1);
		lcd_putStr("la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,2);
		lcd_putStr("la la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,6);
		lcd_putStr("la la la la", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6s,3);
		lcd_putStr("la la la la la  ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,5);
		
		lcd_clear(BACKGROUND_COLOUR);
						
		lcd_putStr("la la~          ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR	
		
		
		lcd_putStr("la", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,5);
		lcd_putStr("la la~          ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
		
		
														
}
void music3()
{

		lcd_clear(BACKGROUND_COLOUR); //background colour
		lcd_putStr("You better watch", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("out, you better,", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("not cry, better ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("not pout I'm,   ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
		 
		lcd_putStr("You", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,2);
		lcd_putStr("You bet", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,2);
		playnote(0,1);
		lcd_putStr("You better", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,2);
		lcd_putStr("You better watch", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("out,", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		playnote(0,1);
		lcd_putStr("out, you", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("out, you bet", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,2);
		lcd_putStr("out, you better ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,2);
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("not", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		playnote(0,1);
		lcd_putStr("not cry", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,8);
		lcd_putStr("not cry, bet", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,2);
		lcd_putStr("not cry, better ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,2);
		
		if(Alarm_trig==0)
				return;
		
		lcd_putStr("not", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
		lcd_putStr("not pout", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
		lcd_putStr("not pout I'm    ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		
		lcd_clear(BACKGROUND_COLOUR);
		
		lcd_putStr("telling you why,", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("Santa Claus is  ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("coming to town! ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("He's making a   ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
				 
		lcd_putStr("tel", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(A6,2);
		lcd_putStr("telling", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		playnote(0,1);
		lcd_putStr("telling you", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
		playnote(0,1);
		lcd_putStr("telling you why,", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
				
		if(Alarm_trig==0)
				return;
				
		lcd_putStr("San", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4);
		lcd_putStr("Santa", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("Santa Claus", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C6,4);
		lcd_putStr("Santa Claus is  ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4);
		
		if(Alarm_trig==0)
		return;
						
		lcd_putStr("co", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(D6,4);
		lcd_putStr("coming", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
		lcd_putStr("coming to", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B5,4);
		lcd_putStr("coming to town! ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C6,8);
				
		if(Alarm_trig==0)
			return;
						
		lcd_putStr("He's", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("He's ma", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,2); 
		lcd_putStr("He's making", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,2); 
		lcd_putStr("He's making a   ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4); 
		playnote(0,1);
		
		lcd_clear(BACKGROUND_COLOUR);
		
		lcd_putStr("list and check- ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("ing it twice,   ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("Gonna find out  ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		lcd_putStr("who's naughty   ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ;
		
		lcd_putStr("list", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,6);
		playnote(0,1);
		lcd_putStr("list and", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("list and check- ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,2);

		if(Alarm_trig==0)
			return;
		
		lcd_putStr("ing", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,2);
		lcd_putStr("ing it", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		playnote(0,1);
		lcd_putStr("ing it twice    ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,8);		
		
		if(Alarm_trig==0)
			return;
		
		lcd_putStr("Gon", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,2);
		lcd_putStr("Gonna", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,2);
		lcd_putStr("Gonna find", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
		lcd_putStr("Gonna find out  ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);

		if(Alarm_trig==0)
			return;
		
		lcd_putStr("who's", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("who's naugh", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,2);
		lcd_putStr("who's naughty   ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);

		lcd_clear(BACKGROUND_COLOUR);
				
		lcd_putStr("and nice, Santa ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("Claus is coming,", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("to town! He     ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("sees you when   ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
						 
		lcd_putStr("and", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(F6,4);
		playnote(0,1);
		lcd_putStr("and nice,", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
		lcd_putStr("and nice, San", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4);
		lcd_putStr("and nice, Santa ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
						
		if(Alarm_trig==0)
				return;
						
		lcd_putStr("Claus", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C6,4);
		lcd_putStr("Claus is", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4);
		lcd_putStr("Claus is co", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D6,4);
		lcd_putStr("Claus is coming ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
				
		if(Alarm_trig==0)
				return;
								
		lcd_putStr("to", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(B5,4);
		lcd_putStr("to town!", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C6,16);
		playnote(0,2);
		lcd_putStr("to town! He     ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
						
		if(Alarm_trig==0)
			return;
								
		lcd_putStr("sees", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
		lcd_putStr("sees you", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("sees you when   ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		
		lcd_clear(BACKGROUND_COLOUR);
						
		lcd_putStr("you're sleeping,", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("he knows when   ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("you're awake,   ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("He knows if     ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y							 
		
		lcd_putStr("you're", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(C7,4);
		lcd_putStr("you're sleep", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		playnote(0,1);
		lcd_putStr("you're sleeping,", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,8);
								
		if(Alarm_trig==0)
				return;
								
		lcd_putStr("he", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("he knows", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
		lcd_putStr("he knows when   ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
						
		if(Alarm_trig==0)
				return;
										
		lcd_putStr("you're", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(B6,4);
		lcd_putStr("you're a", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		lcd_putStr("you're awake    ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,12);
		
		if(Alarm_trig==0)
				return;
										
		lcd_putStr("He", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
		lcd_putStr("He knows", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E7,4);
		lcd_putStr("He knows if     ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
				
		lcd_clear(BACKGROUND_COLOUR);
		//lyric input						
		lcd_putStr("you've been bad ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("or good, so be  ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("good for        ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; 
		lcd_putStr("goodness sake!  ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
										 
		lcd_putStr("you've", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(C7s,4);
		lcd_putStr("you've been", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
		lcd_putStr("you've been bad ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		playnote(0,1);
										
		if(Alarm_trig==0)
				return;
										
		lcd_putStr("or", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		playnote(0,1);
		lcd_putStr("or good,", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		playnote(0,1);
		lcd_putStr("or good, so", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		lcd_putStr("or good, so be  ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,2);
								
		if(Alarm_trig==0)
				return;
												
		lcd_putStr("good", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(D7,4);
		lcd_putStr("good for        ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
										
		if(Alarm_trig==0)
				return;
												
		lcd_putStr("good", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,4);
		lcd_putStr("goodness", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,4);
		lcd_putStr("goodness sake!  ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
						
		lcd_clear(BACKGROUND_COLOUR);
										
		lcd_putStr("Oh! You better  ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("watch out! You  ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("better not cry, ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("better not pout ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
												 
		lcd_putStr("Oh!", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,6);
		playnote(0,1);
		lcd_putStr("Oh! You", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		lcd_putStr("Oh! You bet", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,2);
		lcd_putStr("Oh! You better  ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,2);
												
		if(Alarm_trig==0)
				return;
												
		lcd_putStr("watch", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
		lcd_putStr("watch out!", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,6);
		playnote(0,1);
		lcd_putStr("watch out! You  ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
					
		if(Alarm_trig==0)
				return;
														
		lcd_putStr("bet", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(A6,2);
		lcd_putStr("better", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B6,2);
		lcd_putStr("better not", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,4);
		playnote(0,1);
		lcd_putStr("better not cry, ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,8);
												
		if(Alarm_trig==0)
				return;
														
		lcd_putStr("bet", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,2);
		lcd_putStr("better", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,2);
		lcd_putStr("better not", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
		lcd_putStr("better not pout ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		playnote(0,1);
								
		lcd_clear(BACKGROUND_COLOUR);
												
		lcd_putStr("I'm telling you ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("why, Santa Claus", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
		lcd_putStr("is coming to    ", SUBMENU_X, SUBMENU3_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU3_Y
		lcd_putStr("town, Santa     ", SUBMENU_X, SUBMENU4_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU4_Y
														 
		lcd_putStr("I'm", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(G6,4);
		lcd_putStr("I'm tel", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(A6,2);
		lcd_putStr("I'm telling", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,2);
		playnote(0,1);
		lcd_putStr("I'm telling you ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,4);
		playnote(0,1);
														
		if(Alarm_trig==0)
				return;
														
		lcd_putStr("why,", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
		lcd_putStr("why, San", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4);
		lcd_putStr("why, Santa", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);
		lcd_putStr("why, Santa Claus", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C6,4);
												
		if(Alarm_trig==0)
				return;
																
		lcd_putStr("is", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(E6,4);
		lcd_putStr("is co", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D6,4);
		lcd_putStr("is coming", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
		lcd_putStr("is coming to    ", SUBMENU_X, SUBMENU3_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(B5,4);
														
		if(Alarm_trig==0)
				return;
																
		lcd_putStr("town,", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C6,16);
		playnote(0,2);
		lcd_putStr("town, San", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4);
		lcd_putStr("town, Santa     ", SUBMENU_X, SUBMENU4_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(G6,4);	
									
		lcd_clear(BACKGROUND_COLOUR);
														
		lcd_putStr("Claus is coming ", SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, CHARACTER_COLOUR,BACKGROUND_COLOUR
		lcd_putStr("to town!!       ", SUBMENU_X, SUBMENU2_Y, FontLarge, CHARACTER_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU2_Y
												
																 
		lcd_putStr("Claus", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ; //SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR
		playnote(C6,4);
		lcd_putStr("Claus is", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(E6,4);
		lcd_putStr("Claus is co", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D6,4);
		lcd_putStr("Claus is coming ", SUBMENU_X, SUBMENU1_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(F6,8);
																
		if(Alarm_trig==0)
				return;
																
		lcd_putStr("to", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(D7,4);
		lcd_putStr("to town!!       ", SUBMENU_X, SUBMENU2_Y, FontLarge, SELECT_COLOUR, BACKGROUND_COLOUR) ;
		playnote(C7,16);
		playnote(0,0);
														
}

