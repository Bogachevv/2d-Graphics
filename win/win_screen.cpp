#include "win_screen.h"

#include <cstring>

win_screen::win_screen() : win_console_ptr_(win_console::get()) {
    win_console_ptr_->get_size(width, height);
    buffer = new uint8_t[width*height];
    memset(buffer, ' ', width*height*sizeof(uint8_t));

    win_console_ptr_->set_cursor(0, 0);
    win_console_ptr_->hide_cursor();
}

win_screen::win_screen(uint32_t width, uint32_t height) : screen(width, height), win_console_ptr_(win_console::get()) {
    win_console_ptr_->resize(width, height);
    win_console_ptr_->set_cursor(0, 0);
    win_console_ptr_->hide_cursor();
}

void win_screen::redraw() {
    win_console_ptr_->draw((char *)buffer, width, height);
}