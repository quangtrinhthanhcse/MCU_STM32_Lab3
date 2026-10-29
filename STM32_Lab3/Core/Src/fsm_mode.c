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
enum ButtonState {BUTTON_RELEASED, BUTTON_PRESSED};
enum ButtonState btn1State = BUTTON_RELEASED;

void fsm_mode_run(void) {
    switch (btn1State) {
        case BUTTON_RELEASED:
            if (is_button_pressed(0)) { // Nút 1 (Mode) được nhấn
                btn1State = BUTTON_PRESSED;
                mode++;
                if (mode > 4) mode = 1;
            }
            break;
        case BUTTON_PRESSED:
            if (!is_button_pressed(0)) { // Chờ người dùng thả tay ra
                btn1State = BUTTON_RELEASED;
            }
            break;
    }
}


