#ifndef GFX_H_
#define GFX_H_

#include <gb/gb.h>

unsigned char bkg[18][20];
unsigned char win[18][20];

void set_bkg(UINT8 x, UINT8 y, UINT8 value);
void set_bkg_mul(UINT8 x, UINT8 y, UINT8 w, UINT8 h, UINT8 value);
void write_bkg();

void set_win(UINT8 x, UINT8 y, UINT8 value);
void set_win_mul(UINT8 x, UINT8 y, UINT8 w, UINT8 h, UINT8 value);
void write_win();

#endif
