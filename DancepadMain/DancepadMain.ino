/* DDR USB Dance Pad Code - Super Make Something Episode 9) - https://youtu.be/-qeD2__yK4c
 * by: Alex - Super Make Something
 * date: June 1st, 2016
 * license: Creative Commons - Attribution - Non-Commercial.  More information available at: http://creativecommons.org/licenses/by-nc/3.0/
 */

/*
 * This code contains the folLOW functions:
 * - void setup(): Sets pins 4, 5, 6, 7 to input with pull-up resistors enabled and begins Keyboard functionality
 * - void loop(): Main loop - reads pin voltages and sends out corresponding keystrokes via USB
 */

/* 
 * Pinout:
 * - "HIGH" voltage button contacts - pins 4, 5, 6, 7
 * - "GND" voltage button contacts - GND pin
 */

#include <Keyboard.h>
#include "Arrow.h"
#include "Dancepad.h"

// Consts Player 1
#define KEY_W (uint8_t)'w'
#define KEY_A (uint8_t)'a'
#define KEY_S (uint8_t)'s'
#define KEY_D (uint8_t)'d'

// Consts Player 2
#define KEY_I (uint8_t)'i'
#define KEY_J (uint8_t)'j'
#define KEY_K (uint8_t)'k'
#define KEY_L (uint8_t)'l'

#define ARROW_AMOUNT 4
int readingFrecuency = 40;


Arrow upArrow_1(4, KEY_W), rightArrow_1(5, KEY_D), downArrow_1(6, KEY_S), leftArrow_1(7, KEY_A);//, escButton(3, /*Keyboard.KEY_ESC*/ 0xB1), enterButton(2, /*Keyboard.KEY_KP_ENTER*/ 0x0A);
Arrow upArrow_2(8, KEY_I), rightArrow_2(9, KEY_L), downArrow_2(10, KEY_K), leftArrow_2(11, KEY_J);

Dancepad dancepad_1(upArrow_1, rightArrow_1, downArrow_1, leftArrow_1);
Dancepad dancepad_2(upArrow_2, rightArrow_2, downArrow_2, leftArrow_2);

int rotation_1 = 1;
int rotation_2 = 1;

void setup() {
  dancepad_1.Setup();
  dancepad_2.Setup();
  dancepad_1.SetRotate(rotation_1);
  dancepad_2.SetRotate(rotation_2);
}

void loop()
{
  dancepad_1.Process();
  dancepad_2.Process();

  delay(readingFrecuency);
}
