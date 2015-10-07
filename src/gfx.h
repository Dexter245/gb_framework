#ifndef GFX_H_
#define GFX_H_

#include <gb/gb.h>

extern const UINT8 FIRST_FREE_TILE;


void set_bkg(UINT8 x, UINT8 y, UINT8 value);
void set_bkg_mul(UINT8 x, UINT8 y, UINT8 w, UINT8 h, UINT8 value);
void write_bkg();

void set_win(UINT8 x, UINT8 y, UINT8 value);
void set_win_mul(UINT8 x, UINT8 y, UINT8 w, UINT8 h, UINT8 value);
void write_win();

void initialize_font();
void render_text(UINT8 x, UINT8 y, char* text);

#endif
