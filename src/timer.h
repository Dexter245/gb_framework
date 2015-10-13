#ifndef TIMER_H
#define TIMER_H

#include <gb/gb.h>

extern UINT16 time16;

void initialize_timer();
void timer_isr();


#endif
