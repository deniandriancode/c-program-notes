#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>

#define HEIGHT 30
#define WIDTH 90
#define TIME_LENGTH 20

void print_time (WINDOW *);
void print_digit (WINDOW *, int, int, char *);
int** get_digit (char);

int
main (int argc, char *argv[])
{
        WINDOW *main_win;
        int ch;
        int starty, startx;

        initscr ();
        if (has_colors () != TRUE) {
                printf ("Your terminal does not support colors\n");
                exit (0);
        }
        start_color ();
        init_pair (1, COLOR_BLUE, COLOR_BLACK);
        init_pair (2, COLOR_BLACK, COLOR_BLUE);

        cbreak ();
        noecho ();
        curs_set (0);

        starty = (LINES - HEIGHT) / 2;
        startx = (COLS - WIDTH) / 2;
        refresh ();

        main_win = newwin (HEIGHT, WIDTH, starty, startx);
        box (main_win, 0, 0);
        keypad (main_win, TRUE);
        wrefresh (main_win);

        print_time (main_win);

        getchar ();

        endwin ();
        return 0;
}

void
print_time (WINDOW *win)
{
        char time_value[TIME_LENGTH];
        char date[TIME_LENGTH];
        time_t current_time;
        int max_y, max_x;
        int starty, startx;

        current_time = time (NULL);
        struct tm *detailed_time = localtime (&current_time);

        strftime (time_value, TIME_LENGTH, "%X", detailed_time);
        strftime (date, TIME_LENGTH, "%Y-%m-%d", detailed_time);

        getmaxyx (win, max_y, max_x);
        starty = 2;
        startx = (max_x - strlen (time_value)) / 2;

        wattron (win, COLOR_PAIR (2));
        print_digit (win, starty, startx, time_value);
        wattroff (win, COLOR_PAIR (2));

        wrefresh (win);
}

void
print_digit (WINDOW *win,
                int starty,
                int startx,
                char *time_value)
{
        int i, j;
        int arr[5][6] = get_digit ('a');

        for (i = 0; i < 5; i++) {
                for (j = 0; j < 6; j++) {
                        if (arr[i][j] == 1)
                                mvwprintw (win, i, j, " ");
                }
        }
}

int**
get_digit (char c_digit)
{
        int **arr = (int *) malloc (5*6*sizeof (int *));
        int arr_src[5][6] = {
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
                {0,0,0,0,0,0},
        };
        memcpy (*arr, *arr_src, sizeof (int *) * 30);
        return arr;
}
