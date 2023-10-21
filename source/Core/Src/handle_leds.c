/*
 * handle7seg.c
 *
 *  Created on: Oct 19, 2023
 *      Author: olkmphy
 */


#include <handle_leds.h>

int led_buffer[4] = {0, 0, 0, 0};

void clearEN(){
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, SET);
}
//void openAllLEDs();
void blinkLEDs(int traffic, int color){
	if(traffic == TRAFFIC_1){
		switch(color){
			case AUTO_RED:
				HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin | LED_GREEN_1_Pin, RESET);
				break;
			case AUTO_YELLOW:
				HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin | LED_GREEN_1_Pin, RESET);
				break;
			case AUTO_GREEN:
				HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin | LED_RED_1_Pin, RESET);
				break;
			default:
				break;
		}
	}
	else if(traffic == TRAFFIC_2){
		switch(color){
			case AUTO_RED:
				HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_GREEN_2_Pin, RESET);
				break;
			case AUTO_YELLOW:
				HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin | LED_GREEN_2_Pin, RESET);
				break;
			case AUTO_GREEN:
				HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_RED_2_Pin, RESET);
				break;
			default:
				break;
		}
	}
}

void Traffic_setColor(int option, int color){
	if(option == 1){
		switch(color){
			case AUTO_RED:
				HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin | LED_GREEN_1_Pin, RESET);
				break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin | LED_GREEN_1_Pin, RESET);
				break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_1_Pin | LED_RED_1_Pin, RESET);
				break;
			default:
				break;
		}
	}
	else if(option == 2){
		switch(color){
			case AUTO_RED:
				HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_GREEN_2_Pin, RESET);
				break;
			case AUTO_YELLOW:
				HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LED_RED_2_Pin | LED_GREEN_2_Pin, RESET);
				break;
			case AUTO_GREEN:
				HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
				HAL_GPIO_WritePin(GPIOA, LED_YELLOW_2_Pin | LED_RED_2_Pin, RESET);
				break;
			default:
				break;
		}
	}
}

int SEG[7] = {SEG1_0_Pin, SEG1_1_Pin, SEG1_2_Pin, SEG1_3_Pin,  SEG1_4_Pin,  SEG1_5_Pin,  SEG1_6_Pin};
void display7SEG(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5], RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[1] | SEG[2], RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[3] | SEG[4]| SEG[6], RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[6], RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[1] | SEG[2] | SEG[5] | SEG[6], RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[2] | SEG[3] | SEG[5] | SEG[6], RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2], RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[4] | SEG[5] | SEG[6], SET);
		HAL_GPIO_WritePin(GPIOB, SEG[0] | SEG[1] | SEG[2] | SEG[3] | SEG[5] | SEG[6], RESET);
		break;
	default:
		break;
	}
}

void update7SEG(int index){
	switch(index){
		case 0:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, RESET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, RESET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN0_Pin | EN3_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, RESET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, RESET);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
	}
}

void updateBuffer(int duration, int modeNUM){
	led_buffer[0] = duration / 10;
	led_buffer[1] = duration % 10;
	led_buffer[2] = modeNUM / 10;
	led_buffer[3] = modeNUM % 10;
}
