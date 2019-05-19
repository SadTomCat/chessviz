#include "include/board_read.h"

void input(Move* move)
{ 
    int i = 0;
    char ch;
    char inp[6];
    
    fgets(inp, 6, stdin);

    if (inp[0] >= 'a' && inp[0] <= 'h') {
        move->x1 = (int)inp[i] - 'a' + 2;
    } else if (inp[0] >= 'A' && inp[0] <= 'H') {
        move->x1 = (int)inp[i] - 'A' + 2;
    } else {
        print_board(move->flag + 2);
        input(move);
        return;
    }

    if (inp[1] >= '1' && inp[1] <= '8') {
        move->y1 = -((int)inp[1] - '8');
    } else {
        print_board(move->flag + 2);
        input(move);
        return;
    }

    if (inp[2] == 'X') {
        move->type_move = inp[2];
    } else if (inp[2] == 'x') {
        move->type_move = inp[2];
    } else if (inp[2] == '-') {
        move->type_move = inp[2];
    } else {
        print_board(move->flag + 2);
        input(move);
        return;
    }

    if (inp[3] >= 'a' && inp[3] <= 'h') {
        move->x2 = (int)inp[3] - 'a' + 2;
    } else if (inp[3] >= 'A' && inp[3] <= 'H') {
        move->x2 = (int)inp[3] - 'A' + 2;
    } else {
        print_board(move->flag + 2);
        input(move);
        return;
    }

    if (inp[4] >= '1' && inp[4] <= '8') {
        move->y2 = -((int)inp[4] - '8');
    } else {
        print_board(move->flag + 2);
        input(move);
        return;
    }

    printf("%d %d %c %d %d\n", move->x1, move->y1, move->type_move, move->x2, move->y2);
    while (getchar() != '1');   
}
