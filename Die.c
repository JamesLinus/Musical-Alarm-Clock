/*
 * Die.c
 *
 *  Created on: Sep 28, 2013
 *      Author: podonoghue
 */
#include "die.h"
#include "derivative.h"
#include "nokia_LCD.h"
#include "uart.h"
#include "Freedom.h"

#define ORIGIN_X     66    // Centre of screen
#define ORIGIN_Y     66
#define DOT_RADIUS   10    // Size of cie dots
#define DOT_SPACING  32    // Spacing between dots
#define DIE_WIDTH    100   // Width of die face

#define DIE_COLOUR        WHITE   // Colour of die body
#define DOT_COLOUR        BLACK   // Colour of die dots
#define BACKGROUND_COLOUR TEAL    // Background colour of screen

#define DIE_CORNER_RADIUS 10      // Corner radius of die body

/*!
 * Draw a filled circle
 * 
 * @param centre_x   X coordinate of circle centre
 * @param centre_y   Y coordinate of circle centre
 * @param radius     radius of circle 
 * @param colour     colour of circle
 * 
 */
static void drawFilledCircle(int centre_x, int centre_y, int radius, int colour) {
   int radius_squared = radius*radius;
   int x, y;
   for (x = -radius; x <= radius; x++) {
      for (y = -radius; y <= radius; y++) {
         if ((x*x+y*y) <= radius_squared) {
            // Pixel inside circle - draw it
            lcd_drawPixel(centre_x+x,centre_y+y,colour);
         }
      }
   }
}

/*!
 * Draw die body
 */
static void drawDieBackground(void) {
   lcd_drawRect(ORIGIN_X-(DIE_WIDTH/2-DIE_CORNER_RADIUS), ORIGIN_Y-(DIE_WIDTH/2),
                ORIGIN_X+(DIE_WIDTH/2-DIE_CORNER_RADIUS), ORIGIN_Y+(DIE_WIDTH/2), DIE_COLOUR, DIE_COLOUR);
   lcd_drawRect(ORIGIN_X-(DIE_WIDTH/2), ORIGIN_Y-(DIE_WIDTH/2-DIE_CORNER_RADIUS),
                ORIGIN_X+(DIE_WIDTH/2), ORIGIN_Y+(DIE_WIDTH/2-DIE_CORNER_RADIUS), DIE_COLOUR, DIE_COLOUR);
   drawFilledCircle(ORIGIN_X-(DIE_WIDTH/2-DIE_CORNER_RADIUS), ORIGIN_Y-(DIE_WIDTH/2-DIE_CORNER_RADIUS), DIE_CORNER_RADIUS, DIE_COLOUR);
   drawFilledCircle(ORIGIN_X+(DIE_WIDTH/2-DIE_CORNER_RADIUS), ORIGIN_Y-(DIE_WIDTH/2-DIE_CORNER_RADIUS), DIE_CORNER_RADIUS, DIE_COLOUR);
   drawFilledCircle(ORIGIN_X-(DIE_WIDTH/2-DIE_CORNER_RADIUS), ORIGIN_Y+(DIE_WIDTH/2-DIE_CORNER_RADIUS), DIE_CORNER_RADIUS, DIE_COLOUR);
   drawFilledCircle(ORIGIN_X+(DIE_WIDTH/2-DIE_CORNER_RADIUS), ORIGIN_Y+(DIE_WIDTH/2-DIE_CORNER_RADIUS), DIE_CORNER_RADIUS, DIE_COLOUR);
}

/*!
 * Draw given number of die dots
 * 
 * @param roll - number of dots to draw
 * 
 */
static void drawDieDots(int roll) {
   enum masks { A = 1<<0, B = 1<<2, C = 1<<3, D = 1<<4};
   static const int patterns[] = { 0, D, C, A|D, A|B, A|B|D, A|B|C, 0};
   int rollMask = patterns[roll&0x07];
   int aColour, bColour, cColour, dColour;

   aColour = ((rollMask&A)!= 0)?DOT_COLOUR:DIE_COLOUR;
   bColour = ((rollMask&B)!= 0)?DOT_COLOUR:DIE_COLOUR;
   cColour = ((rollMask&C)!= 0)?DOT_COLOUR:DIE_COLOUR;
   dColour = ((rollMask&D)!= 0)?DOT_COLOUR:DIE_COLOUR;

   // D - centre
   drawFilledCircle(ORIGIN_X,             ORIGIN_Y,              DOT_RADIUS, dColour);
   // C - horizontal
   drawFilledCircle(ORIGIN_X-DOT_SPACING, ORIGIN_Y,              DOT_RADIUS, cColour);
   drawFilledCircle(ORIGIN_X+DOT_SPACING, ORIGIN_Y,              DOT_RADIUS, cColour);
   // B - diagonal
   drawFilledCircle(ORIGIN_X-DOT_SPACING, ORIGIN_Y+DOT_SPACING,  DOT_RADIUS, bColour);
   drawFilledCircle(ORIGIN_X+DOT_SPACING, ORIGIN_Y-DOT_SPACING,  DOT_RADIUS, bColour);
   // A - diagonal
   drawFilledCircle(ORIGIN_X-DOT_SPACING, ORIGIN_Y-DOT_SPACING,  DOT_RADIUS, aColour);
   drawFilledCircle(ORIGIN_X+DOT_SPACING, ORIGIN_Y+DOT_SPACING,  DOT_RADIUS, aColour);
}

/*!
 *   Roll the die once
 *   
 *   @note - The die face will be drawn if this is the first call
 */
void rollOnce(void) {
   static int dieRoll = 0; // 0 indicates init. required
   
   if (dieRoll == 0) {
      drawDieBackground();
   }
   dieRoll++;
   if (dieRoll>6) {
      dieRoll = 1;
   }
   drawDieDots(dieRoll);
//   printf("Roll = %d\n", dieRoll);
}
