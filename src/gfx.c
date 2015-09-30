#include "gfx.h"

void set_bkg(UINT8 x, UINT8 y, UINT8 value){
    bkg[y][x] = value;
}

void set_bkg_mul(UINT8 x, UINT8 y, UINT8 w, UINT8 h, UINT8 value){
    int i = 0;
    int j = 0;
    for(i = x; i < x+w; i++){
        for(j = y; j < y+h; j++){
            bkg[j][i] = value;
        }
    }
}

void write_bkg(){
    set_bkg_tiles(0, 0, 20, 18, bkg);
}

void set_win(UINT8 x, UINT8 y, UINT8 value){
    win[y][x] = value;
}

void set_win_mul(UINT8 x, UINT8 y, UINT8 w, UINT8 h, UINT8 value){
    int i = 0;
    int j = 0;
    for(i = x; i < x+w; i++){
        for(j = y; j < y+h; j++){
            win[j][i] = value;
        }
    }
}

void write_win(){
    set_win_tiles(0, 0, 20, 18, win);
}






