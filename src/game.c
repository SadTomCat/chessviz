#include "include/game.h"

/*  flag - 1.белые 2.черные

*/

extern char board[11][11];

void play() 
{
    system("clear");
    int i = 0;
    Move* white = malloc(sizeof(*white));
    Move* black = malloc(sizeof(*black)); 
    white->flag = 1;
    black->flag = 2;

    while (i < 10) {        
        //white
        input(white, 0);
        board[white->y2][white->x2] = board[white->y1][white->x1];
        board[white->y1][white->x1] = ' ';
                
        //black
        input(black, 0);
        board[black->y2][black->x2] = board[black->y1][black->x1];
        board[black->y1][black->x1] = ' ';

        i++;
    }
    
    free(white);
    free(black);
}

