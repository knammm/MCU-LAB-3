/*
 * handle7seg.h
 *
 *  Created on: Oct 19, 2023
 *      Author: olkmphy
 */

#ifndef INC_HANDLE_LEDS_H_
#define INC_HANDLE_LEDS_H_

#include "global.h"

void clearAllLEDs();
void clear7SEGs();
void clearEN();
void blinkLEDs(int, int);
void Traffic_setColor(int, int);
void display7SEG(int);
void update7SEG(int);
void updateBuffer(int, int);


#endif /* INC_HANDLE_LEDS_H_ */
