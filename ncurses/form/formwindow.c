#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <form.h>

void print_in_middle (WINDOW *, int, int, int, char *, chtype);

int
main (int argc, char *argv[])
{
        FIELD *field[3];
        FORM *form;
        WINDOW *win;
        int ch, rows, cols;

        initscr ();
        if (!has_colors ()) {
                printf ("Your terminal does not support color\n");
                exit (0);
        }
        start_color ();
        init_pair (1, COLOR_RED, COLOR_BLACK);
        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);

        field[0] = new_field (1, 10, 6, 18, 0, 0);
        field[1] = new_field (1, 10, 8, 18, 0, 0);
        field[2] = (FIELD *) NULL;

        set_field_back (field[0], A_UNDERLINE);
        field_opts_off (field[0], O_AUTOSKIP);

        set_field_back (field[1], A_UNDERLINE);
        field_opts_off (field[1], O_AUTOSKIP);

        form = new_form (field);

        scale_form (form, &rows, &cols);

        win = newwin (rows + 4, cols + 4, 4, 4);
        keypad (win, TRUE);

        set_form_win (form, win);
        set_form_sub (form, derwin (win, rows, cols, 2, 2));

        box (win, 0, 0);
        print_in_middle (win, 1, 0, cols + 4, "My Form", COLOR_PAIR (1));
        refresh ();

        post_form (form);
        wrefresh (win);

        while ((ch = getch ()) != KEY_F (2)) {
                switch (ch) {
                        case KEY_DOWN:
                                form_driver (form, REQ_NEXT_FIELD);
                                form_driver (form, REQ_END_LINE);
                                break;
                        case KEY_UP:
                                form_driver (form, REQ_PREV_FIELD);
                                form_driver (form, REQ_END_LINE);
                                break;
                        default:
                                form_driver (form, ch);
                }
                wrefresh (win);
        }

        unpost_form (form);
        free_form (form);
        free_field (field[0]);
        free_field (field[1]);

        endwin ();
        return 0;
}

void
print_in_middle (WINDOW *win,
                int starty, int startx, int width,
                char *string, chtype color)
{
        int x, y, length;
        float temp;

        if (win == NULL)
                win = stdscr;
        getyx (win, y, x);
        if (starty != 0)
                y = 0;
        if (startx != 0)
                x = 0;
        if (width == 0)
                width = 80;

        length = strlen (string);
        temp = (width - length) / 2;
        x = startx  + (int) temp;
        wattron (win, color);
        mvwprintw (win, y, x, "%s", string);
        wattroff (win, color);
        refresh ();
}
