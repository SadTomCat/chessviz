#include "include/board_print_plain.h"

void manual()
{
    char ch = '0';

    do {
        system("clear");
        printf("  --------------------------------------------------------\n");
        printf(" /                      Правила ввода                     \\\n");
        printf("|                                                          |\n");
        printf("| 1.Фигуры не указываются                                  |\n");
        printf("| 2.Использавать '' для шаха. Использавать в конце ввода   |\n");
        printf("| 3.Использавать '' для мата. Использавать в конце ввода.  |\n");
        printf("| 4.Разрешено использовать большие и маленькие буквы.      |\n");
        printf("| 5.Для ввода использовать ТОЛЬКО латинские буквы.         |\n");
        printf("|                                                          |\n");
        printf("|                         Примеры                          |\n");
        printf("|                                                          |\n");
        printf("| 1.E4-E2 или E4-e2 или e4-E2, для ходов без взятия.       |\n");
        printf("| 2.E4xE2 или E4xe2 или e4xE2, для ходов со взятием.       |\n");
        printf("| 2.E4xE2 или E4xe2 или e4xE2, для ходов со взятием.       |\n");
        printf("| 3.E4xE2# или E4xe2# или e4xE2#, шах.                     |\n");
        printf("| 3.E4xE2# или E4xe2# или e4xE2#, мат.                     |\n");
        printf(" \\                                                        /\n");
        printf("  --------------------------------------------------------\n");

        printf("                  1.Продолжить     2.Выйти                \n");

        if (ch == '2') {
            exit(0);
        }

    } while (ch = getchar() != '1');
}

void print_board(uint8_t figure_color) 
{
    system("clear");
    printf("\n");
    printf("Введите свой ход.\n\n");
    for (uint32_t i = 0; i < RAWS; ++i) {
        for (uint32_t j = 0; j < COL; ++j) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }

    if (figure_color == 1) {
        printf("Ход белых: ");
    } else {
        printf("Ход черных: ");
    }
}

