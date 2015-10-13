#include <gb/gb.h>
#include <stdio.h>

#include "main.h"
#include "gfx.h"
#include "sound.h"
#include "timer.h"

#include "tiles/colorRects.h"


int main(){

    /*initialize_font();*/
    initialize_timer();

    /*sound2_test();*/
    /*sound1_test();*/
    /*sound4_test();*/


    while(1){
        wait_vbl_done();
        timer_test();
        /*test_single_gfx();*/
        /*font_test();*/
        /*wait_vbl_done();*/
        /*write_bkg();*/

        /*test_mul_gfx();*/
        /*font_test();*/
        /*wait_vbl_done();*/
        /*write_bkg();*/
    }

    /*test_single_gfx();*/
    /*test_mul_gfx();*/
    /*font_test();*/
    /*font_gfx_test();*/





}

void timer_test(){

    /*printf("time16: %u, secs: %u\n", time16, time16/16);*/
    printf("t16: %u, secs: %u\n", time16, time16/16);

}

void sound2_test(){

    initialize_sound();

    /*sound2_envelope(7, 1500, 1, 3);*/
    /*sound2_envelope(7, 1500, 1, 0);*/
    /*sound2_length(7, 1500, 64);*/
    /*sound2(7, 2044);*/
    /*sound2(7, 200);*/
    /*sound2_envelope_length(7, 200,*/
            /*1, 3, 64);*/
    /*sound2_envelope_length(7, 200,*/
            /*1, 3, 63);*/




}

void sound1_test(){

    initialize_sound();

    /*sound1_envelope_length_swee(7, 500,*/
        /*0, 0, 64,*/
        /*2, 1, 7);*/
    /*sound1_envelope_length(7, 500,*/
        /*2, 2, 63);*/
    /*sound1_length_sweep(7, 500, 64,*/
        /*2, 1, 7);*/
    /*sound1_length(7, 500, 63);*/
    /*sound1_envelope_sweep(7, 500,*/
        /*1, 1,*/
        /*2, 1, 7);*/
    /*sound1_envelope(7, 500,*/
        /*1, 3);*/
    /*sound1_sweep(7, 500,*/
        /*2, 1, 7);*/
    sound1(7, 440);
    sound2(7, 880);

}

void sound4_test(){

    initialize_sound();

    /*UINT8 volume = 7;*/
    /*UINT8 s = 5;//0-15*/
    /*UINT8 blob = 0;//0-1*/
    /*UINT8 r = 4;//0-7*/

    /*initialize_sound();*/

    /*NR42_REG = volume << 4;*/
    /*NR43_REG = (s << 4) | (blob << 3) | r;*/
    /*NR44_REG = 0x80;*/

    /*sound4_envelope_length(7, 5,*/
        /*0, 4,*/
        /*2, 0,*/
        /*64);*/
    /*sound4_envelope(7, 5, 0,*/
        /*4, 2, 2);*/
    /*sound4_length(7, 5, 0,*/
        /*4, 63);*/
    sound4(7, 5, 1,
        4);




}

void font_test(){

    render_text(2, 1, "AbcdeFghijklmnopqrstuvwxyz0123456789");

}

void test_single_gfx(){

    int i = 0;
    int j = 0;
    int tileNum = 0;

    int TILE_WHITE = FIRST_FREE_TILE;
    int TILE_LIGHT_GREY = FIRST_FREE_TILE + 1;
    int TILE_DARK_GREY = FIRST_FREE_TILE + 2;
    int TILE_BLACK = FIRST_FREE_TILE + 3;

    SHOW_BKG;
    /*SHOW_WIN;*/

    set_bkg_data(TILE_WHITE, 4, colorRects);

    for(i = 0; i < 18; i++){
        for(j = 0; j < 20; j++){
            set_bkg(j, i, (tileNum+i)%4 + 1 + FIRST_FREE_TILE-1);
            set_win(j, i, (tileNum+i)%4 + 0);
            tileNum++;
        }
    }

    /*wait_vbl_done();*/

    /*write_bkg();*/
    /*write_win();*/

}

void test_mul_gfx(){

    int i = 0;
    int j = 0;

    int TILE_WHITE = FIRST_FREE_TILE;
    int TILE_LIGHT_GREY = FIRST_FREE_TILE + 1;
    int TILE_DARK_GREY = FIRST_FREE_TILE + 2;
    int TILE_BLACK = FIRST_FREE_TILE + 3;

    SHOW_BKG;
    /*SHOW_WIN;*/

    set_bkg_data(TILE_WHITE, 4, colorRects);


    set_bkg_mul(0, 0, 10, 9, TILE_DARK_GREY);//top left
    set_bkg_mul(10, 0, 10, 9, TILE_LIGHT_GREY);//top right
    set_bkg_mul(0, 9, 10, 9, TILE_WHITE);//bottom left
    set_bkg_mul(10, 9, 10, 9, TILE_BLACK);//bottom right

    set_win_mul(0, 0, 10, 9, TILE_DARK_GREY);//top left
    set_win_mul(10, 0, 10, 9, TILE_LIGHT_GREY);//top right
    set_win_mul(0, 9, 10, 9, TILE_WHITE);//bottom left
    set_win_mul(10, 9, 10, 9, TILE_BLACK);//bottom right


    /*wait_vbl_done();*/

    /*write_bkg();*/
    /*write_win();*/

}









