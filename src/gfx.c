#include "gfx.h"
#include <gb/font.h>
#include <ctype.h>

const UINT8 FIRST_FREE_TILE = 38;

unsigned char bkg[18][20];
unsigned char win[18][20];

void render_char(UINT8 x, UINT8 y, char c);

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

void initialize_font(){

    font_init();

    /*color(WHITE, DKGREY, SOLID);*/
    font_load(font_min);
}

void render_char(UINT8 x, UINT8 y, char c){
    UINT8 tileNum = 0;
    UINT8 ascii = (UINT8) c;

    if(isdigit(c)){
        tileNum = ascii - 46;
    }
    else{
        c = tolower(c);
        ascii = (UINT8) c;
        tileNum = ascii - 85;
    }

    bkg[y][x] = tileNum;

}

void render_text(UINT8 x, UINT8 y, char* text){
    int i = 0;
    while(1){
        if(text[i] == 0)
            break;
        render_char(x, y, text[i]);
        x++;
        i++;
    }
}





