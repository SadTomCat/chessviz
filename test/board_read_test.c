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

    strcpy(inp, "JijLo"); // Ввод мусора
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