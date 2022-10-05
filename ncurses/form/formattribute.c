#include <stdio.h>
#include <stdlib.h>
#include <form.h>

int
main (int argc, char *argv[])
{
        FIELD *fields[3];
        FORM *form;
        int ch;

        initscr ();
        if (!has_colors ()) {
                printf ("Your terminal does not support color\n");
                exit (1);
        }
        start_color ();
        init_pair (1, COLOR_BLACK, COLOR_YELLOW);
        init_pair (2, COLOR_BLACK, COLOR_YELLOW);
        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);

        fields[0] = new_field (LINES, COLS, 0, 0, 0, 0);
        /*fields[1] = new_field (5, 10, 6, 18, 0, 0);*/
        fields[1] = (FIELD *) NULL;
        fields[2] = (FIELD *) NULL;

        set_field_fore (fields[0], COLOR_PAIR (1));
        set_field_back (fields[0], COLOR_PAIR (2));
        field_opts_off (fields[0], O_AUTOSKIP);
        field_opts_off (fields[0], O_STATIC);

        /*set_field_back (fields[1], A_UNDERLINE);*/
        /*field_opts_off (fields[1], O_AUTOSKIP);*/

        form = new_form (fields);
        post_form (form);

        /*mvprintw(4, 10, "Value 1:");*/
	/*mvprintw(6, 10, "Value 2:");*/
	/*mvprintw(LINES - 2, 0, "Use UP, DOWN arrow keys to switch between fields");*/
        refresh ();

        while ((ch = getch ()) != KEY_F (2)) {
                switch (ch) {
                        case KEY_DOWN:
                                form_driver (form, REQ_DOWN_CHAR);
                                form_driver (form, REQ_END_LINE);
                                break;
                        case KEY_UP:
                                form_driver (form, REQ_UP_CHAR);
                                form_driver (form, REQ_END_LINE);
                                break;
                        case KEY_RIGHT:
                                form_driver (form, REQ_NEXT_CHAR);
                                break;
                        case KEY_LEFT:
                                form_driver (form, REQ_PREV_CHAR);
                                break;
                        case KEY_BACKSPACE:
                                form_driver (form, REQ_DEL_PREV);
                                break;
                        case 10:
                                form_driver (form, REQ_NEW_LINE);
                                break;
                        default:
                                form_driver (form, ch);
                }
        }

        unpost_form (form);
        free_form (form);
        free_field (fields[0]);
        free_field (fields[1]);

        endwin ();
        return 0;
}
