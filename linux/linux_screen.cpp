#include "linux_screen.h"

#include <ncurses.h>
#include <cstring>

linux_screen::linux_screen() {
    initscr();

    getmaxyx(stdscr, width, height);
    buffer = new uint8_t[width*height];
    memset(buffer, ' ', width*height*sizeof(uint8_t));
}

void linux_screen::hide_cursor() {
    curs_set(0);
}

linux_screen::~linux_screen() {
    endwin();
}

void linux_screen::redraw() {
    move(0, 0);
    addstr((char*)buffer);
    refresh();
}