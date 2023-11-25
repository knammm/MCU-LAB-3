/*
 * fsm_manual.c
 *
 *  Created on: Oct 21, 2023
 *      Author: olkmphy
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
		case MOD_RED:
			if(timerFlag[1] == 1){
				setTimer(1, 250); // blink every 0.25s
				blinkLEDs(TRAFFIC_1, AUTO_RED);
				blinkLEDs(TRAFFIC_2, AUTO_RED);
			}
			// ADD BUTTON
			if(isButtonPressed(1) == 1){
				RED_sec++;
				if(RED_sec >= 100) {
					RED_sec = 1;
					timerTraffic1 = 1;
				}
				else{
					timerTraffic1++;
				}
			}
			// SET BUTTON
			if(isButtonPressed(2) == 1){
				durationRED = RED_sec * 1000;
			}
			// MODE BUTTON
			if(isButtonPressed(0) == 1){
				setTimer(1, 10);
				status = MOD_YELLOW;
				timerTraffic1 = durationYELLOW / 1000;
				timerTraffic2 = 3;
			}
			break;
		case MOD_YELLOW:
			if(timerFlag[1] == 1){
				setTimer(1, 250); // blink every 0.25s
				blinkLEDs(TRAFFIC_1, AUTO_YELLOW);
				blinkLEDs(TRAFFIC_2, AUTO_YELLOW);
			}
			// ADD BUTTON
			if(isButtonPressed(1) == 1){
				YELLOW_sec++;
				if(YELLOW_sec >= 100) {
					YELLOW_sec = 1;
					timerTraffic1 = 1;
				}
				else{
					timerTraffic1++;
				}
			}
			// SET BUTTON
			if(isButtonPressed(2) == 1){
				durationYELLOW = YELLOW_sec * 1000;
			}
			// MODE BUTTON
			if(isButtonPressed(0) == 1){
				setTimer(1, 10);
				status = MOD_GREEN;
				timerTraffic1 = durationGREEN / 1000;
				timerTraffic2 = 4;
			}
			break;
		case MOD_GREEN:
			if(timerFlag[1] == 1){
				setTimer(1, 250); // blink every 0.25s
				blinkLEDs(TRAFFIC_1, AUTO_GREEN);
				blinkLEDs(TRAFFIC_2, AUTO_GREEN);
			}
			// ADD BUTTON
			if(isButtonPressed(1) == 1){
				GREEN_sec++;
				if(GREEN_sec >= 100){
					GREEN_sec = 1;
					timerTraffic1 = 1;
				}
				else{
					timerTraffic1++;
				}
			}
			// SET BUTTON
			if(isButtonPressed(2) == 1){
				durationGREEN = GREEN_sec * 1000;
				durationYELLOW = durationRED - durationGREEN;
			}
			// MODE BUTTON
			if(isButtonPressed(0) == 1){
				status = RED_GREEN;
				// Modify to get the logic correct
				durationGREEN = durationRED - durationYELLOW;
				timerTraffic1 = durationRED / 1000;
				timerTraffic2 = durationGREEN / 1000;
				// Update buffer
				setTimer(0, durationGREEN);
				setTimerSecond(1000);
				setTimer7SEG(10);
				led_index = 0;
				updateBuffer();
				clearEN();
			}
			break;
		default:
			break;
	}
}
