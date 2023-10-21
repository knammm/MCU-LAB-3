/*
 * fsm_automatic.c
 *
 *  Created on: Oct 19, 2023
 *      Author: olkmphy
 */


#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		//TODO
		status = RED_GREEN;
		setTimer(0, durationGREEN);
		setTimerSecond(1000);
		break;
	case RED_GREEN:
		//TODO
		Traffic_setColor(1, AUTO_RED);
		Traffic_setColor(2, AUTO_GREEN);
		if (timerSecond == 1){
			setTimerSecond(1000);
			timerTraffic1--;
			timerTraffic2--;
			if (timerTraffic2 <= 0) timerTraffic2 = durationYELLOW / 1000;
		}
		// State update
		if (timerFlag[0] == 1){
			setTimer(0, durationYELLOW);
			status = RED_YELLOW;
		}
		break;
	case RED_YELLOW:
		//TODO
		Traffic_setColor(1, AUTO_RED);
		Traffic_setColor(2, AUTO_YELLOW);
		if (timerSecond == 1){
			setTimerSecond(1000);
			timerTraffic1--;
			if (timerTraffic1 <= 0) timerTraffic1 = durationGREEN / 1000;
			timerTraffic2--;
			if (timerTraffic2 <= 0) timerTraffic2 = durationRED / 1000;
		}
		// State update
		if(timerFlag[0] == 1){
			setTimer(0, durationGREEN);
			status = GREEN_RED;
		}
		break;
	case GREEN_RED:
		Traffic_setColor(1, AUTO_GREEN);
		Traffic_setColor(2, AUTO_RED);
		if (timerSecond == 1){
			setTimerSecond(1000);
			timerTraffic1--;
			if (timerTraffic1 <= 0) timerTraffic1 = durationYELLOW / 1000;
			timerTraffic2--;
		}
		// State update
		if(timerFlag[0] == 1){
			setTimer(0, durationYELLOW);
			status = YELLOW_RED;
		}
		break;
	case YELLOW_RED:
		Traffic_setColor(1, AUTO_YELLOW);
		Traffic_setColor(2, AUTO_RED);
		if (timerSecond == 1){
			setTimerSecond(1000);
			timerTraffic1--;
			if (timerTraffic1 <= 0) timerTraffic1 = durationRED / 1000;
			timerTraffic2--;
			if (timerTraffic2 <= 0) timerTraffic2 = durationGREEN / 1000;
		}
		// State update
		if (timerFlag[0] == 1){
			setTimer(0, durationGREEN);
			status = RED_GREEN;
		}
		break;
	default:
		break;
	}
	// MODE BUTTON
	if (isButtonPressed(0) == 1){
		status = MOD_RED;
		setTimer(1, 100); // timer for blinky
		Traffic_setColor(1, AUTO_RED);
		Traffic_setColor(2, AUTO_RED);
		RED_sec = durationRED / 1000;
		YELLOW_sec = durationYELLOW / 1000;
		GREEN_sec = durationGREEN / 1000;
		timerTraffic1 = RED_sec;
		timerTraffic2 = 2;
	}
}
