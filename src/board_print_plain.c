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
        printf("| 6.Черные фигуры - обозначаются фиолетовым цветом         |\n");
        printf("|                                                          |\n");
        printf("|                          Примеры                         |\n");
        printf("|                                                          |\n");
        printf("| 1.E4-E2 или E4-e2 или e4-E2, для ходов без взятия.       |\n");
        printf("| 2.E4xE2 или E4xe2 или e4xE2, для ходов со взятием.       |\n");
        printf("| 3.E4xE2 или E4xe2 или e4xE2, для ходов со взятием.       |\n");
        printf("|                                                          |\n");
        printf(" \\                               program by SadTomCat(с)  /\n");
        printf("  --------------------------------------------------------\n");

        printf("                  1.Продолжить     2.Выйти                \n");

        ch = getchar();

        if (ch == '2') {
            exit(0);
        }

    } while (ch != '1');
}

void print_board() 
{
    system("clear");
    printf("\n");
    for (uint32_t i = 0; i < RAWS; ++i) {
        for (uint32_t j = 0; j < COL; ++j) {
            if ((board[i][j] > 'a' && board[i][j] < 'z') && i <= 7 )  {
                printf(KMAG5 "%c ", board[i][j]);
            } else {
                printf(KMAG9 "%c ", board[i][j]);
            }
        }

        printf("\n");
    }
}

