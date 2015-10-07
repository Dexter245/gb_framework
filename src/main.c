#include <gb/gb.h>

#include "main.h"
#include "gfx.h"

#include "tiles/colorRects.h"


int main(){

    initialize_font();

    while(1){
        test_single_gfx();
        font_test();
        wait_vbl_done();
        write_bkg();

        test_mul_gfx();
        font_test();
        wait_vbl_done();
        write_bkg();
    }

    /*test_single_gfx();*/
    /*test_mul_gfx();*/
    /*font_test();*/
    /*font_gfx_test();*/





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









