#include "include/board_read.h"

/*
    0 - обычный
    1 - невозможное перемещение
    2 - (- x X)
    3 - Неверный ввод
    4 - игра не своей фигурой
    5 - попытка забрать свою фигуру
*/

extern char board[11][11];

void input(Move* move, uint8_t type_err)
{ 
    printf("Нажмите ENTER.\n\n");
    while (getchar() != '\n');
    print_board(move->flag);

    switch (type_err) {
        case 1:
            printf("Нельзя так перемещать фигуры.\n");
            break;

        case 2:
            printf("Неверный тип хода.\n");
            break;
        
        case 3:
            printf("Неверный ввод, попробуйте ещё раз.\n");
            break;
        
        case 4:
            printf("Вы пыпаетесь играть не своей фигурой\n");
            break;

        case 5:
            printf("Вы пытаетесь забрать не свою фигуру\n");
            break;
    }

    if (move->flag == 1) {
        printf("Ход белых: ");
    }

    if (move->flag == 2) {
        printf("Ход черных: ");
    }

    char inp[6];
    
    fgets(inp, 6, stdin);

    if (inp[0] >= 'a' && inp[0] <= 'h') {
        move->x1 = (int)inp[0] - 'a' + 2;
    } else if (inp[0] >= 'A' && inp[0] <= 'H') {
        move->x1 = (int)inp[0] - 'A' + 2;
    } else {
        input(move, 3);
        return;
    }

    if (inp[1] >= '1' && inp[1] <= '8') {
        move->y1 = -((int)inp[1] - '8');
    } else {
        input(move, 3);
        return;
    }

    if (inp[2] == 'X') {
        move->type_move = inp[2];
    } else if (inp[2] == 'x') {
        move->type_move = inp[2];
    } else if (inp[2] == '-') {
        move->type_move = inp[2];
    } else {
        input(move, 2);
        return;
    }

    if (inp[3] >= 'a' && inp[3] <= 'h') {
        move->x2 = (int)inp[3] - 'a' + 2;
    } else if (inp[3] >= 'A' && inp[3] <= 'H') {
        move->x2 = (int)inp[3] - 'A' + 2;
    } else {
        input(move, 3);
        return;
    }

    if (inp[4] >= '1' && inp[4] <= '8') {
        move->y2 = -((int)inp[4] - '8');
    } else {
        input(move, 3);
        return;
    }

    //printf("%d %d %c %d %d\n", move->x1, move->y1, move->type_move, move->x2, move->y2);
    //while (getchar() != '1');  
    check_figure(move);
}

void check_type_move(Move* move)
{
    if (move->type_move == 'x' || move->type_move == 'X') {
        if (board[move->y2][move->x2] == ' ') {
            input(move, 2);
            return;  
        }
    }
    
    if (move->type_move == '-') {
        if (board[move->y2][move->x2] != ' ') {
            input(move, 2);
            return;  
        }
    }   
}    

void check_figure(Move* move) 
{
    if (move->flag == 1) {
        if (board[move->y1][move->x1] < 65 || board[move->y1][move->x1] > 90) {
            input(move, 4);
            return;
        }

        check_type_move(move); 

        if ((board[move->y2][move->x2] < 97 || board[move->y2][move->x2] > 122)
            && (move->type_move == 'x' || move->type_move == 'X')) { 
            input(move, 5);
            return;
        }
    }

    if (move->flag == 2) {
        if (board[move->y1][move->x1] < 97 || board[move->y1][move->x1] > 122) {
            input(move, 4);
            return;
        }

        check_type_move(move); 

        if ((board[move->y2][move->x2] < 65 || board[move->y2][move->x2] > 90)
            && (move->type_move == 'x' || move->type_move == 'X')) {
            input(move, 5);
            return;
        }
    }

    if (move->flag == 1) {
        white(move);
    } else {
        black(move);
    }
}

void white(Move* move) 
{
    switch (board[move->y1][move->x1]) {
    case 'P':
        if ((move->y1 - move->y2) > 2 || (move->y1 - move->y2) < 1) {
            input(move, 1);
            return;
        }

        checkY(move);
        break;
    }
}

void black(Move* move) 
{
    switch (board[move->y1][move->x1]) {
    case 'p':
        if ((move->y1 - move->y2) > 2 || (move->y1 - move->y2) < 1) {
            input(move, 1);
            return;
        }

        checkY(move);
        break;
    }
}

void checkY(Move* move)
{
    int i, c1 = move->y1, c2 = move->y2;
    if (move->x1 != move->x2) {
        input(move, 1);
        return;
    }
    
    if (move->y1 > move->y2) {
        c1 = move->y2;
        c2 = move->y1;
    }

    for (i = c1 + 1; i < c2; i++) {
        if (board[i][move->x1] != ' ') {
            input(move, 1);
            return;
        }
    }
   
}

void checkX(Move* move)
{
    int i, c1 = move->x1, c2 = move->x2;
    if (move->y1 != move->y2) {
        input(move, 1);
        return;
    }
    
    if (move->x1 > move->x2) {
        c1 = move->x2;
        c2 = move->x1;
    }

    for (i = c1 + 1; i < c2; i++) {
        if (board[move->y1][i] != ' ') {
            input(move, 1);
            return;
        }
    }
}

void checkD(Move* move)
{
    int i, j, c1 = move->y2, c2 = move->y1, ci, cj;
    
    if (((move->y2 - move->y1) != (move->x2 - move->x1)) && ((move->y2 - move->y1) != (move->x1 - move->x2))) {
        input(move, 1);
    }
    
    if (move->y2 > move->y1) {
        c1 = move->y1;
        c2 = move->y2;
        ci = 1;
    } else {
        ci = -1;
    }
    
    if (move->x2 > move->x1) {
        cj = 1;
    } else {
        cj = -1;
    }

    i = move->y1 + ci;
    j = move->x1 + cj;
    
    while ((i < c2) && (i > c1)) {
        if (board[i][j] != ' ') {
            input(move, 1);
        }

        i += ci;
        j += cj;
    }
}
