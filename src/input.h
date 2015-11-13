#ifndef INPUT_H
#define INPUT_H

#include <gb/gb.h>

void refresh_button_states();

BOOLEAN is_button_pressed(UINT8 button);
BOOLEAN is_button_just_pressed(UINT8 button);

#endif
