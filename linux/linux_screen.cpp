#include "linux_screen.h"

#include <ncurses.h>
#include <cstring>

linux_screen::linux_screen() {
    initscr();

    getmaxyx(stdscr, height, width);
    buffer = new uint8_t[width*height + 1];
    memset(buffer, ' ', width*height*sizeof(uint8_t));
    buffer[width*height] = 0;
}

void linux_screen::hide_cursor() {
    curs_set(0);
}

void linux_screen::clear() {
    memset(buffer, ' ', width*height*sizeof(uint8_t));
    buffer[width*height] = 0;
}

linux_screen::~linux_screen() {
    endwin();
}

void linux_screen::redraw() {
    move(0, 0);
    addstr((char*)buffer);
    refresh();
}