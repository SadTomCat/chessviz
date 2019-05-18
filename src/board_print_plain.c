#include "include/board_print_plain.h"

void print_board(void) 
{
    for (uint32_t i = 0; i < RAWS; ++i) {
        for (uint32_t j = 0; j < COL; ++j) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }
}

