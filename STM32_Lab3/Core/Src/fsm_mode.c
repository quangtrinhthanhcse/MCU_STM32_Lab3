/*
 * fsm_mode.c
 *
 *  Created on: Oct 29, 2026
 *      Author: Trinh Thanh Quang
 */
#include "main.h"
#include "input_reading.h"
#include "fsm_mode.h"

int mode = 1;
int temp_red_time = 5;

enum ButtonState {BUTTON_RELEASED, BUTTON_PRESSED};
enum ButtonState btn1State = BUTTON_RELEASED;
enum ButtonState btn2State = BUTTON_RELEASED;
enum ButtonState btn3State = BUTTON_RELEASED;

void fsm_mode_run(void) {
	// Nút 1: chuyển trạng thái máy 1 -> 2-> 3-> 4-> 1
    switch (btn1State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(0)) { // Nút 1 (Mode) được nhấn
                btn1State = BUTTON_PRESSED;
                mode++;
                if (mode > 4) mode = 1;

                if (mode == 2){
                	temp_red_time = red_time;
                }
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) { // Chờ người dùng thả tay ra
                btn1State = BUTTON_RELEASED;
            }
            break;
    }
    // Xử lý nút BTN2 và BTN3 khi đang ở mode 2 (sửa thời gian đèn đỏ)
    if(mode == 2){
    	switch(btn2State){
    	case BUTTON_RELEASED:
    		if(is_button_pressed(1)){
    			btn2State = BUTTON_PRESSED;
    			temp_red_time++;
    			if(temp_red_time > 99) temp_red_time = 1;
    		}
    		break;
    	case BUTTON_PRESSED:
    		if(!is_button_pressed(1)){
    			btn2State = BUTTON_RELEASED;
    		}
    		break;
    	}

    	switch(btn3State){
    	case BUTTON_RELEASED:
    		if(is_button_pressed(2)){
    			btn3State = BUTTON_PRESSED;
    			red_time = temp_red_time;
    		}
    		break;
    	case BUTTON_PRESSED:
    		if(!is_button_pressed(2)){
    			btn3State = BUTTON_RELEASED;
    		}
    		break;
    	}
    }
}


