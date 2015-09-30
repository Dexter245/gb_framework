#include <gb/gb.h>

#include "gfx.h"

#include "tiles/colorRects.h"


int main(){

    while(1){
        wait_vbl_done();
        test_single_gfx();
        wait_vbl_done();
        test_mul_gfx();

    }
    /*test_single_gfx();*/
    /*test_mul_gfx();*/









}

void test_single_gfx(){

    int i = 0;
    int j = 0;
    int tileNum = 0;

    int TILE_WHITE = 1;
    int TILE_LIGHT_GREY = 2;
    int TILE_DARK_GREY = 3;
    int TILE_BLACK = 4;

    SHOW_BKG;
    SHOW_WIN;

    set_bkg_data(TILE_WHITE, 4, colorRects);

    for(i = 0; i < 18; i++){
        for(j = 0; j < 20; j++){
            set_bkg(j, i, (tileNum+i)%4 + 1);
            set_win(j, i, (tileNum+i)%4 + 0);
            tileNum++;
        }
    }

    wait_vbl_done();

    write_bkg();
    write_win();

}

void test_mul_gfx(){

    int i = 0;
    int j = 0;

    int TILE_WHITE = 1;
    int TILE_LIGHT_GREY = 2;
    int TILE_DARK_GREY = 3;
    int TILE_BLACK = 4;

    SHOW_BKG;
    SHOW_WIN;

    set_bkg_data(TILE_WHITE, 4, colorRects);


    set_bkg_mul(0, 0, 10, 9, TILE_DARK_GREY);//top left
    set_bkg_mul(10, 0, 10, 9, TILE_LIGHT_GREY);//top right
    set_bkg_mul(0, 9, 10, 9, TILE_WHITE);//bottom left
    set_bkg_mul(10, 9, 10, 9, TILE_BLACK);//bottom right

    set_win_mul(0, 0, 10, 9, TILE_DARK_GREY);//top left
    set_win_mul(10, 0, 10, 9, TILE_LIGHT_GREY);//top right
    set_win_mul(0, 9, 10, 9, TILE_WHITE);//bottom left
    set_win_mul(10, 9, 10, 9, TILE_BLACK);//bottom right


    wait_vbl_done();

    write_bkg();
    write_win();

}









