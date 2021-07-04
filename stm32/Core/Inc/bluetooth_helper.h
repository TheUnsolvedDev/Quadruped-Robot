/*
 * bluetooth_helper.h
 *
 *  Created on: Jul 4, 2021
 *      Author: shuvrajeet
 */

#ifndef INC_BLUETOOTH_HELPER_H_
#define INC_BLUETOOTH_HELPER_H_

#include "main.h"
#include "string.h"

extern char buffer[50];
extern uint8_t timer_count, buffer_index;
extern UART_HandleTypeDef huart2;

uint8_t string_compare(char array1[], char array2[], uint16_t length);
void Message_handler();

#endif /* INC_BLUETOOTH_HELPER_H_ */
