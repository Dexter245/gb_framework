#include "log.h"

#include <string.h>
#include <stdio.h>//debug only

#include "gfx.h"

INT8 num_lines = 0;
char log_lines[18][20];
INT8 latest_line = -1;

void add_log_line(char* line){
    latest_line++;
    if(latest_line >= num_lines)
        latest_line -= num_lines;
    strcpy(log_lines[latest_line], line);
}

void set_log_num_lines(UINT8 amount){
    num_lines = amount;
}

void render_log_text(UINT8 y){
    INT8 i;
    INT8 pos;
    for(i = 0; i < num_lines; i++){
        pos = (latest_line-i);
        if(pos < 0)
            pos += num_lines;
        render_text(0, y+i, log_lines[pos]);
    }
}






