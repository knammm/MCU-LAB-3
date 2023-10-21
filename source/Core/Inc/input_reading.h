/*
 * button.h
 *
 *  Created on: Oct 19, 2023
 *      Author: olkmphy
 */
#include "main.h"
#include "global.h"

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NO_OF_BUTTONS		3
#define BUTTON_IS_RELEASED	SET
#define BUTTON_IS_PRESSED	RESET

void button_reading();
int isButtonPressed(int);

#endif /* INC_BUTTON_H_ */
