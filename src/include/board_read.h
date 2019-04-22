#ifndef BOARD_READ_H_
#define BOARD_READ_H_

typedef struct {
    char figure;
    char place[5];
    char type_move;
    char check;
    char checkmate;
} Move;

#endif //BOARD_READ_H_