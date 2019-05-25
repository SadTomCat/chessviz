#ifndef BOARD_READ_H_
#define BOARD_READ_H_

#include "board_print_plain.h"

int input(Move* move, uint8_t type_err);
int check_figure(Move* move);
int check_type_move(Move* move);
void checkX(Move* move);
void checkY(Move* move);
void checkD(Move* move);
void white(Move* move);
void black(Move* move);
void check_pawn(Move* move);
int input_converter(Move* move, char* inp);

#endif //BOARD_READ_H_