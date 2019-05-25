#include "../src/include/board_read.h"
#include "../src/include/board_print_plain.h"
#include "../thirdparty/ctest.h"

char board[11][11] = {
    {'8', '|', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'7', '|', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'6', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'5', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'4', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'3', '|', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'2', '|', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'1', '|', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {' ', ' ', '-', '-', '-', '-', '-', '-', '-', '-'},
    {' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}
};

CTEST(inputdata, input_convert)
{
    Move* player = malloc(sizeof(*player));
    char inp[6];
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
}