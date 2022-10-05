#include <form.h>

int
main (int argc, char *argv[])
{
        FIELD *fields[3];
        FORM *form;
        int ch;

        initscr ();
        cbreak ();
        noecho ();
        keypad (stdscr, TRUE);

        fields[0] = new_field (1, 28, 4, 10, 0, 0);
        fields[1] = new_field (1, 28, 6, 10, 0, 0);
        fields[2] = (FIELD *) NULL;

        set_field_back (fields[0], A_UNDERLINE);
        field_opts_off (fields[0], O_AUTOSKIP);

        set_field_back (fields[1], A_UNDERLINE);
        field_opts_off (fields[1], O_AUTOSKIP);

        form = new_form (fields);
        post_form (form);

        mvprintw (4, 2, "Name : ");
        mvprintw (6, 2, "Email : ");
        refresh ();

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
                        case KEY_RIGHT:
                                form_driver (form, REQ_NEXT_CHAR);
                                break;
                        case KEY_LEFT:
                                form_driver (form, REQ_PREV_CHAR);
                                break;
                        case KEY_BACKSPACE:
                                form_driver (form, REQ_DEL_PREV);
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
