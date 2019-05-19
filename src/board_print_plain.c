#include "include/board_print_plain.h"

/*  flag - 1.белые 2.черные 3.белые с ошибкой 4.черные с ошибкой

*/

extern char board[11][11];

void manual()
{
    char ch = '0';

    do {
        system("clear");
        printf("  --------------------------------------------------------\n");
        printf(" /                         Правила                        \\\n");
        printf("|                                                          |\n");
        printf("| 1.При вводе фигуры не указываются.                       |\n");
        printf("| 2.Разрешено использовать большие и маленькие буквы.      |\n");
        printf("| 3.Для ввода использовать ТОЛЬКО латинские буквы.         |\n");
        printf("| 4.Ход белых - разрешено играть большими фигурами.        |\n");
        printf("| 5.Ход черных - разрешено играть маленькими фигурами.     |\n");
        printf("|                                                          |\n");
        printf("|                           Примеры                        |\n");
        printf("|                                                          |\n");
        printf("| 1.E4-E2 или E4-e2 или e4-E2, для ходов без взятия.       |\n");
        printf("| 2.E4xE2 или E4xe2 или e4xE2, для ходов со взятием.       |\n");
        printf("| 2.E4xE2 или E4xe2 или e4xE2, для ходов со взятием.       |\n");
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
    printf("Нажмите ENTER.\n\n");
    while (getchar() != '\n');
    system("clear");
    printf("\n");
    for (uint32_t i = 0; i < RAWS; ++i) {
        for (uint32_t j = 0; j < COL; ++j) {
            printf("%c ", board[i][j]);
        }

        printf("\n");
    }

    if (figure_color == 1) {
        printf("Ход белых: ");
        return;
    } 

    if (figure_color == 2) {
        printf("Ход черных: ");
    }

    if (figure_color == 3) {
        printf("Неверный ввод, попробуйте ещё раз.\n");
        printf("Ход белых: ");
    }

    if (figure_color == 4) {
        printf("Неверный ввод, попробуйте ещё раз.\n");
        printf("Ход черных: ");
    }
}

