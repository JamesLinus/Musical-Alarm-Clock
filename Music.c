/*
 * music.c
 * Author: Lilanka Udawatta
 *  Created on: Nov 29, 2014
 */

#include <stdio.h>
#include <math.h>
#include <derivative.h>
#include "Music.h"
#include "Freedom.h"
#include "utilities.h"

extern int note;
extern int tempo;

void initialiseFTM(void)
{
	SIM_SCGC6 |= SIM_SCGC6_FTM0_MASK|SIM_SCGC6_FTM1_MASK;
	
	//COMMON REGISTERS
	FTM0_SC = FTM_SC_CLKS(0);
	FTM0_CNTIN = 0;
	FTM0_CNT =0;
	FTM0_MOD = 0XFFFF;
	
	FTM1_SC = FTM_SC_CLKS(0);
	FTM1_CNTIN = 0;
	FTM1_CNT = 0;
	FTM1_MOD = 0X5B8D;
	
	//CHANNEL REGISTER - OC-TOGGLE FOR NOTE PLAYING
	FTM0_C7SC |= FTM_CnSC_MSA_MASK|FTM_CnSC_ELSA_MASK;
	FTM0_C7V = note; //trigger
	
	enableFTM0IRQ();
	enableFTM1IRQ();
	
}

void initialiseBuzzer(void)
{
	SIM_SCGC5 |= SIM_SCGC5_PORTD_MASK;
	BUZZER_PCR = PORT_PCR_MUX(4)|PORT_PCR_DSE_MASK;
	BUZZER_PDDR = BUZZER_MASK;	
}

void delay (int time)
{
	int delayCount;
		for(delayCount = 0; delayCount < time*10000; delayCount++)
		{
			asm("nop"); //no-operation
		}
}

void playnote(int frequency, int beat)
{
	note = frequency;
	tempo = beat*32;
	
	if(note == 0)
	{
		FTM0_SC = FTM_SC_CLKS(0)|FTM_SC_PS(1);
		FTM1_SC |= FTM_SC_CLKS(1)|FTM_SC_PS(3);
	}
	
	else
	{
		FTM0_SC = FTM_SC_CLKS(1)|FTM_SC_PS(1);
		FTM1_SC |= FTM_SC_CLKS(1)|FTM_SC_PS(3);
	}
	
	while(tempo>=0);
	
	FTM0_SC = FTM_SC_CLKS(0);
	BUZZER_PCOR = BUZZER_MASK;
	
	tempo = 1;
	while(tempo>=0);
	FTM1_SC &= ~FTM_SC_CLKS_MASK;
}

void enableFTM0IRQ(void)
{
	FTM0_C7SC |= FTM_CnSC_CHIE_MASK;
	NVIC_EnableIrq(INT_FTM0);
}

void enableFTM1IRQ(void)
{
	FTM1_SC |= FTM_SC_TOIE_MASK;
	NVIC_EnableIrq(INT_FTM1);
}

void disableFTM0IRQ(void)
{
	FTM0_C7SC &= ~FTM_CnSC_CHIE_MASK;
	NVIC_DisableIrq(INT_FTM0);
}

void disableFTM1IRQ(void)
{
	FTM1_SC &= ~FTM_SC_TOIE_MASK;
	NVIC_DisableIrq(INT_FTM1);
}
