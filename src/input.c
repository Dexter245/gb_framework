#include "input.h"


UINT8 buttons_down = 0;
UINT8 buttons_been_up = 0;

void refresh_button_states(){
    UINT8 state = joypad();
    buttons_down = state;
    buttons_been_up |= ~state;

}

BOOLEAN is_button_pressed(UINT8 button){
    return buttons_down & button;
}

BOOLEAN is_button_just_pressed(UINT8 button){
    UINT8 value = buttons_been_up & buttons_down & button;
    if(value)
        buttons_been_up ^= value;
    return value;
}




