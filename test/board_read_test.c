#include "../src/include/board_read.h"
#include "../src/include/board_print_plain.h"
#include "../thirdparty/ctest.h"

char board[11][11] = {
    {'8', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'7', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'2', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'1', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
    {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}
};

char inp[6];

CTEST(input_data, input_convert)
{
    Move* player = malloc(sizeof(*player));

    strcpy(inp, "E2fE4"); // Ввод неправильного формата
    int t1 = input_converter(player, inp);

    strcpy(inp, "E2xE4"); // Ход взятия
    int t2 = input_converter(player, inp);

    strcpy(inp, "E2-E4"); // Обычный ход
    int t3 = input_converter(player, inp);

    strcpy(inp, "E2-E9"); // Ход за пределы поля
    int t4 = input_converter(player, inp);

    strcpy(inp, "z2-E4"); // Ход за пределы поля
    int t5 = input_converter(player, inp);

    strcpy(inp, "E9-E2"); // Ход за пределы поля
    int t6 = input_converter(player, inp);

    strcpy(inp, "E2-z2"); // Ход за пределы поля
    int t7 = input_converter(player, inp);

    strcpy(inp, "JiLoh"); // Ввод мусора
    int t8 = input_converter(player, inp);

    const int exp1 = 2;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 3;
    const int exp5 = 3;
    const int exp6 = 3;
    const int exp7 = 3;
    const int exp8 = 3;

    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);
    ASSERT_EQUAL(exp8, t8);

    free(player);
}

CTEST(take, location_check)
{
    Move* player = malloc(sizeof(*player));

    strcpy(inp, "E2-E3"); //попытка взять фигуру с пустоты(белые)
    player->flag = 1;
    input_converter(player, inp);
    int t1 = check_figure(player);

    strcpy(inp, "E2-E3"); //попытка взять фигуру с пустоты(черные)
    player->flag = 2;
    input_converter(player, inp);
    int t2 = check_figure(player);

    strcpy(inp, "E2-E3"); //попытка взять не свою фигуру(белые)
    player->flag = 1;
    input_converter(player, inp);
    board[player->y1][player->x1] = 'p';
    int t3 = check_figure(player);

    strcpy(inp, "E2-E3"); //попытка взять не свою фигуру(черные)
    player->flag = 2;
    input_converter(player, inp);
    board[player->y1][player->x1] = 'P';
    int t4 = check_figure(player);

    strcpy(inp, "E2xE3"); //неверный тип хода(белые)
    player->flag = 1;
    input_converter(player, inp);
    board[player->y1][player->x1] = 'P';
    int t5 = check_figure(player);

    strcpy(inp, "E2-E3"); //неверный тип хода(белые)
    player->flag = 1;
    input_converter(player, inp);
    board[player->y2][player->x2] = 'p';
    int t6 = check_figure(player);

    strcpy(inp, "E3-E2"); //неверный тип хода(черные)
    player->flag = 2;
    input_converter(player, inp);
    board[player->y1][player->x1] = 'p';
    int t7 = check_figure(player);

    strcpy(inp, "E3xE4"); //неверный тип хода(черные)
    player->flag = 2;
    input_converter(player, inp);
    board[player->y1][player->x1] = 'p';
    int t8 = check_figure(player);

    strcpy(inp, "a2xa3"); //попытка забрыть свою фигуру(белые)
    player->flag = 1;
    input_converter(player, inp);
    board[player->y1][player->x1] = 'P';
    board[player->y2][player->x2] = 'P';
    int t9 = check_figure(player);

    strcpy(inp, "a2-a3"); //попытка пойти на свою фигуру(белые)
    player->flag = 1;
    input_converter(player, inp);
    int t10 = check_figure(player);

    strcpy(inp, "a2xa3"); //попытка забрыть свою фигуру(черные)
    player->flag = 2;
    input_converter(player, inp);
    board[player->y1][player->x1] = 'p';
    board[player->y2][player->x2] = 'p';
    int t11 = check_figure(player);

    strcpy(inp, "a2-a3"); //попытка пойти на свою фигуру(черные)
    player->flag = 2;
    input_converter(player, inp);
    int t12 = check_figure(player);

    const int exp1 = 4;
    const int exp2 = 4;
    const int exp3 = 4;
    const int exp4 = 4;
    const int exp5 = 2;
    const int exp6 = 2;
    const int exp7 = 2;
    const int exp8 = 2;
    const int exp9 = 5;
    const int exp10 = 2;
    const int exp11 = 5;
    const int exp12 = 2;

    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);
    ASSERT_EQUAL(exp8, t8);
    ASSERT_EQUAL(exp9, t9);
    ASSERT_EQUAL(exp10, t10);
    ASSERT_EQUAL(exp11, t11);
    ASSERT_EQUAL(exp12, t12);

    free(player);
}

CTEST(moving, move_white_pawn) // Тест белой пешки
{
    Move* player = malloc(sizeof(*player));
    player->flag = 1;

    strcpy(inp, "c2-c3"); // Первый ход на одну клетку
    input_converter(player, inp);
    board[player->y1][player->x1] = 'P';
    int t1 = white(player);

    strcpy(inp, "c2-c4"); // Первый ход на две клетки
    input_converter(player, inp);
    int t2 = white(player);

    board[player->y1][player->x1] = ' ';

    strcpy(inp, "c3-c5"); // Не первый ход на две клетки
    input_converter(player, inp);
    board[player->y1][player->x1] = 'P';
    int t3 = white(player);

    strcpy(inp, "c3-d5"); // Ход по диагонали
    input_converter(player, inp);
    int t4 = white(player);

    strcpy(inp, "c3-c2"); // Ход назад
    input_converter(player, inp);
    int t5 = white(player);

    strcpy(inp, "c3xd4"); // Взятие чужой фигуры
    input_converter(player, inp);
    board[player->y2][player->x2] = 'p';
    int t6 = white(player);

    board[player->y2][player->x2] = ' ';

    strcpy(inp, "c3xd5"); // Взятие чужой фигуры 2
    input_converter(player, inp);
    board[player->y2][player->x2] = 'p';
    int t7 = white(player);

    board[player->y2][player->x2] = ' ';
    board[player->y1][player->x1] = ' ';

    strcpy(inp, "c2xc4"); // Первый ход через фигуру
    input_converter(player, inp);
    board[player->y1][player->x1] = 'P';
    board[player->y2][player->x2] = 'p';
    int t8 = white(player);

    board[player->y2][player->x2] = ' ';
    board[player->y1][player->x1] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 0;
    const int exp7 = 1;
    const int exp8 = 1;


    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);
    ASSERT_EQUAL(exp8, t8);

    free(player);
}

CTEST(moving, move_black_pawn) // Тест черной пешки
{
    Move* player = malloc(sizeof(*player));
    player->flag = 2;

    strcpy(inp, "d6-D7"); // Первый ход на одну клетку
    input_converter(player, inp);
    board[player->y1][player->x1] = 'P';
    int t1 = black(player);

    strcpy(inp, "D7-d5"); // Первый ход на две клетки
    input_converter(player, inp);
    int t2 = black(player);

    board[player->y1][player->x1] = ' ';

    strcpy(inp, "d6-d4"); // Не первый ход на две клетки
    input_converter(player, inp);
    board[player->y1][player->x1] = 'p';
    int t3 = black(player);

    strcpy(inp, "d6-c5"); // Ход по диагонали
    input_converter(player, inp);
    int t4 = black(player);

    strcpy(inp, "d6-d7"); // Ход назад
    input_converter(player, inp);
    int t5 = black(player);

    strcpy(inp, "d6xc5"); // Взятие чужой фигуры
    input_converter(player, inp);
    board[player->y2][player->x2] = 'p';
    int t6 = black(player);

    board[player->y2][player->x2] = ' ';

    strcpy(inp, "d6xc3"); // Взятие чужой фигуры 2
    input_converter(player, inp);
    board[player->y2][player->x2] = 'P';
    int t7 = black(player);

    board[player->y2][player->x2] = ' ';
    board[player->y1][player->x1] = ' ';

    strcpy(inp, "d7-d5"); // Первый ход через фигуру
    input_converter(player, inp);
    board[player->y1][player->x1] = 'p';
    board[player->y2 - 1][player->x2] = 'P';
    int t8 = black(player);

    board[player->y2][player->x2] = ' ';
    board[player->y1][player->x1] = ' ';

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 0;
    const int exp7 = 1;
    const int exp8 = 1;


    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);
    ASSERT_EQUAL(exp8, t8);

    free(player);
}

CTEST(moving, move_rook) // Тест ладьи
{
    Move* player = malloc(sizeof(*player));

    //очистка пешек
    board[2][5] = ' ';
    board[5][6] = ' ';
    board[5][2] = ' ';
    board[6][6] = ' ';
    board[6][2] = ' ';

    strcpy(inp, "D4-D7"); // Ход вперед
    input_converter(player, inp);
    board[player->y1][player->x1] = 'R';
    int t1 = white(player);

    strcpy(inp, "D4-D2"); // Ход назад
    input_converter(player, inp);
    int t2 = white(player);

    strcpy(inp, "D4-F4"); // Ход вправо
    input_converter(player, inp);
    int t3 = white(player);

    strcpy(inp, "D4-F4"); // Ход вправо
    input_converter(player, inp);
    int t4 = white(player);

    strcpy(inp, "D4-F6"); // Ход по диагонали
    input_converter(player, inp);
    int t5 = white(player);

    strcpy(inp, "D4xD5"); // Взятие чужой фигуры
    input_converter(player, inp);
    board[player->y2][player->x2] = 'r';
    int t6 = white(player);

    strcpy(inp, "D4-D6"); // Ход через фигуру
    input_converter(player, inp);
    int t7 = white(player);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 1;
    const int exp6 = 0;
    const int exp7 = 1;

    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);

    board[player->y1][player->x1] = ' ';
    board[player->y2 + 1][player->x2] = ' ';

    free(player);
}

CTEST(moving, move_knight) // Тест коня
{   
    Move* player = malloc(sizeof(*player));
    
    strcpy(inp, "D4-D7"); // Ход вперед
    input_converter(player, inp);
    board[player->y1][player->x1] = 'N';
    int t1 = white(player);
    
    strcpy(inp, "D4-D2"); // Ход назад
    input_converter(player, inp);
    int t2 = white(player);

    strcpy(inp, "D4-F4"); // Ход вправо
    input_converter(player, inp);
    int t3 = white(player);

    strcpy(inp, "D4-B4"); // Ход влево
    input_converter(player, inp);
    int t4 = white(player);

    strcpy(inp, "D4-F6"); // Ход по диагонали
    input_converter(player, inp);
    int t5 = white(player);

    strcpy(inp, "D4-C6"); // Ход Г вверх влево
    input_converter(player, inp);
    int t6 = white(player);

    strcpy(inp, "D4-E6"); // Ход Г вверх вправо
    input_converter(player, inp);
    int t7 = white(player);

    strcpy(inp, "D4-F5"); // Ход Г вправо вверх
    input_converter(player, inp);
    int t8 = white(player);

    strcpy(inp, "D4-F3"); // Ход Г вправо вниз
    input_converter(player, inp);
    int t9 = white(player);

    strcpy(inp, "D4-E2"); // Ход Г вниз вправо
    input_converter(player, inp);
    int t10 = white(player);

    strcpy(inp, "D4-C2"); // Ход Г вниз влево
    input_converter(player, inp);
    int t11 = white(player);

    strcpy(inp, "D4-B5"); // Ход Г влево вверх
    input_converter(player, inp);
    int t12 = white(player);

    strcpy(inp, "D4-B3"); // Ход Г влево вниз
    input_converter(player, inp);
    int t13 = white(player);

    strcpy(inp, "D4xE6"); // Ход через фигуру и взятие
    input_converter(player, inp);
    board[player->y1 - 1][player->x1] = 'p';
    board[player->y2][player->x2] = 'n';
    int t14 = white(player);

    board[player->y1][player->x1] = ' ';
    board[player->y1 - 1][player->x1] = ' ';
    board[player->y2][player->x2] = ' ';

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 1;
    const int exp6 = 0;
    const int exp7 = 0;
    const int exp8 = 0;
    const int exp9 = 0;
    const int exp10 = 0;
    const int exp11 = 0;
    const int exp12 = 0;
    const int exp13 = 0;
    const int exp14 = 0;

    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);
    ASSERT_EQUAL(exp8, t8);
    ASSERT_EQUAL(exp9, t9);
    ASSERT_EQUAL(exp10, t10);
    ASSERT_EQUAL(exp11, t11);
    ASSERT_EQUAL(exp12, t12);
    ASSERT_EQUAL(exp13, t13);
    ASSERT_EQUAL(exp14, t14);

    free(player);
}

CTEST(moving, move_bishop) // Тест слона
{
    Move* player = malloc(sizeof(*player));
    
    strcpy(inp, "D4-D7"); // Ход вперед
    input_converter(player, inp);
    board[player->y1][player->x1] = 'B';
    int t1 = white(player);
    
    strcpy(inp, "D4-D2"); // Ход назад
    input_converter(player, inp);
    int t2 = white(player);

    strcpy(inp, "D4-F4"); // Ход вправо
    input_converter(player, inp);
    int t3 = white(player);

    strcpy(inp, "D4-B4"); // Ход влево
    input_converter(player, inp);
    int t4 = white(player);

    strcpy(inp, "D4-F6"); // Ход по диагонали вверх вправо
    input_converter(player, inp);
    int t5 = white(player);

    strcpy(inp, "D4-B6"); // Ход по диагонали вверх влево
    input_converter(player, inp);
    int t6 = white(player);

    strcpy(inp, "D4-F2"); // Ход по диагонали вниз вправо
    input_converter(player, inp);
    int t7 = white(player);

    strcpy(inp, "D4xB2"); // Ход по диагонали вверх вправо и взятие
    input_converter(player, inp);
    board[player->y2][player->x2] = 'p';
    int t8 = white(player);

    board[player->y2][player->x2] = ' ';

    strcpy(inp, "D4xB2"); // Ход по диагонали вниз вправо через фигуру
    input_converter(player, inp);
    board[player->y2 -  1][player->x2 + 1] = 'p';
    int t9 = white(player);

    const int exp1 = 1;
    const int exp2 = 1;
    const int exp3 = 1;
    const int exp4 = 1;
    const int exp5 = 0;
    const int exp6 = 0;
    const int exp7 = 0;
    const int exp8 = 0;
    const int exp9 = 1;

    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);
    ASSERT_EQUAL(exp8, t8);
    ASSERT_EQUAL(exp9, t9);

    board[player->y2 -  1][player->x2 + 1] = ' ';
    board[player->y1][player->x1] = ' ';

    free(player);
}

CTEST(moving, move_king) // Тест короля
{
    Move* player = malloc(sizeof(*player));
    
    strcpy(inp, "D4-D5"); // Ход вверх
    input_converter(player, inp);
    board[player->y1][player->x1] = 'K';
    int t1 = white(player);

    strcpy(inp, "D4-D3"); // Ход вниз
    input_converter(player, inp);
    int t2 = white(player);

    strcpy(inp, "D4-C4"); // Ход влево
    input_converter(player, inp);
    int t3 = white(player);

    strcpy(inp, "D4-E4"); // Ход вправо
    input_converter(player, inp);    
    int t4 = white(player);

    strcpy(inp, "D4-E5"); // Ход вверх вправо
    input_converter(player, inp);
    int t5 = white(player);

    strcpy(inp, "D4-C5"); // Ход вверх влево
    input_converter(player, inp);
    int t6 = white(player);

    strcpy(inp, "D4-E3"); // Ход вниз вправо
    input_converter(player, inp);
    int t7 = white(player);

    strcpy(inp, "D4xC3"); // Ход вниз влево и взятие
    board[player->y2][player->x2] = 'p';
    input_converter(player, inp);
    int t8 = white(player);

    board[player->y2][player->x2] = ' ';

    strcpy(inp, "D4-D6"); // Ход вверх на 2 клетки
    input_converter(player, inp);
    int t9 = white(player);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 0;
    const int exp7 = 0;
    const int exp8 = 0;
    const int exp9 = 1;

    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);
    ASSERT_EQUAL(exp8, t8);
    ASSERT_EQUAL(exp9, t9);

    free(player);
}

CTEST(moving, move_queen) // Тест ферзя
{
    Move* player = malloc(sizeof(*player));

    strcpy(inp, "D4-D7"); // Ход вверх
    input_converter(player, inp);
    board[player->y1][player->x1] = 'Q';
    int t1 = white(player);

    strcpy(inp, "D4-D1"); // Ход вниз
    input_converter(player, inp);
    int t2 = white(player);

    strcpy(inp, "D4-A4"); // Ход влево
    input_converter(player, inp);
    int t3 = white(player);

    strcpy(inp, "D4-G4"); // Ход вправо
    input_converter(player, inp);
    int t4 = white(player);

    strcpy(inp, "D4-G7");  // Ход по диагонали вверх вправо
    input_converter(player, inp);
    int t5 = white(player);

    strcpy(inp, "D4-A7"); // Ход по диагонали вверх влево
    input_converter(player, inp);
    int t6 = white(player);

    strcpy(inp, "D4-A1"); // Ход по диагонали вних влево
    input_converter(player, inp);
    int t7 = white(player);

    strcpy(inp, "D4-G1"); // Ход по диагонали вниз вправо через фигуру 
    input_converter(player, inp);
    int t8 = white(player);

    board[player->y1 + 1][player->x1 + 1] = ' ';
    
    strcpy(inp, "D4xG1"); // Ход по диагонали вниз вправо через фигуру 
    input_converter(player, inp);
    board[player->y2][player->x2] = 'p';
    int t9 = white(player);

    const int exp1 = 0;
    const int exp2 = 0;
    const int exp3 = 0;
    const int exp4 = 0;
    const int exp5 = 0;
    const int exp6 = 0;
    const int exp7 = 0;
    const int exp8 = 1;
    const int exp9 = 0;

    ASSERT_EQUAL(exp1, t1);
    ASSERT_EQUAL(exp2, t2);
    ASSERT_EQUAL(exp3, t3);
    ASSERT_EQUAL(exp4, t4);
    ASSERT_EQUAL(exp5, t5);
    ASSERT_EQUAL(exp6, t6);
    ASSERT_EQUAL(exp7, t7);
    ASSERT_EQUAL(exp8, t8);
    ASSERT_EQUAL(exp9, t9);

    free(player);
}