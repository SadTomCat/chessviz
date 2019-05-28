#ifndef BOARD_READ_H_
#define BOARD_READ_H_

#include "board_print_plain.h"

int input(Move* move, uint8_t type_err);
int check_figure(Move* move);
int check_type_move(Move* move);
int checkX(Move* move);
int checkY(Move* move);
int checkD(Move* move);
int white(Move* move);
int black(Move* move);
int input_converter(Move* move, char* inp);

#endif // BOARD_READ_H_