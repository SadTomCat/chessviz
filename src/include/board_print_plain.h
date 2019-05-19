#ifndef BOARD_PRINT_PLAIN_H_
#define BOARD_PRINT_PLAIN_H_

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAWS 11
#define COL 11

void print_board(uint8_t figure_color);
void manual();

typedef struct {
    //char figure;
    int x1;
    int y1;
    int x2;
    int y2;
    int flag;
    char type_move;
} Move;

#endif //BOARD_PRINT_PLAIN_H_