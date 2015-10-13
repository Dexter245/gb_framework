#include "timer.h"

UINT16 time16 = 0;

void initialize_timer(){

    TAC_REG = 0x04;
    disable_interrupts();
    add_TIM(timer_isr);
    enable_interrupts();
    set_interrupts(TIM_IFLAG | VBL_IFLAG);




}

void timer_isr(){
    time16++;
    /*printf("time16: %u\n", time16);*/
}


