#ifndef EDITOR_H
#define EDITOR_H

#include <ncurses.h>

#include "Buffer.h"

class Editor
{
        private:
                int x, y;
                char mode;
                Buffer *buff;
                std::string status, filename;

                std::string tos;

                /* cursor movement */
                void moveUp ();
                void moveDown ();
                void moveLeft ();
                void moveRight ();

                void deleteLine ();
                void deleteLine (int);

                void saveFile ();

        public:
                Editor ();
                Editor (std::string);

                char getMode () {return mode;}

                void handleInput (int);
                void printBuff ();
                void printStatusLine ();
                void updateStatus ();

};

#endif
