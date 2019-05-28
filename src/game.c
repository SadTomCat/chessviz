#include "include/game.h"

/*  flag - 1.белые 2.черные

*/

extern char board[11][11];

void play()
{
    system("clear");
    Move* white = malloc(sizeof(*white));
    Move* black = malloc(sizeof(*black));
    white->flag = 1;
    black->flag = 2;
    uint8_t err;

    while (1) {
        err = 0;

        // white
        while (1) {
            err = input(white, err);

            if (err == 0) {
                board[white->y2][white->x2] = board[white->y1][white->x1];
                board[white->y1][white->x1] = ' ';
                break;
            }
        }

        err = 0;

        // black
        while (1) {
            err = input(black, err);

            if (err == 0) {
                board[black->y2][black->x2] = board[black->y1][black->x1];
                board[black->y1][black->x1] = ' ';
                break;
            }
        }
    }

    free(white);
    free(black);
}
