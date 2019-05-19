#ifndef BOARD_PRINT_PLAIN_H_
#define BOARD_PRINT_PLAIN_H_

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RAWS 11
#define COL 11
#define KMAG1  "\x1B[31m" //красный
#define KMAG2  "\x1B[32m" //зеленый
#define KMAG3  "\x1B[33m" //убогий
#define KMAG4  "\x1B[34m" //синий
#define KMAG5  "\x1B[35m" //фиолетовый
#define KMAG6  "\x1B[36m" //голубой
#define KMAG9  "\x1B[39m" //белый

void print_board();
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