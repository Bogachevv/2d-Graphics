#include "win_screen.h"

#include <cstring>

win_screen::win_screen() {
    win_console::get_size(width, height);

    buffer = new uint8_t[width*height];
    memset(buffer, ' ', width*height*sizeof(uint8_t));

    win_console::set_cursor(0, 0);
    win_console::hide_cursor();
}

win_screen::win_screen(uint32_t width, uint32_t height) : screen(width, height) {
    win_console::resize(width, height);
    win_console::set_cursor(0, 0);
    win_console::hide_cursor();
}

void win_screen::redraw() {
    win_console::draw((char *)buffer, width, height);
}