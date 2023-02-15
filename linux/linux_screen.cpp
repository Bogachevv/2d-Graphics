#include "linux_screen.h"

#include <cstring>

linux_screen::linux_screen() : linux_console_ptr_(linux_console::get()) {
    linux_console_ptr_->get_size(width, height);

    buffer = new uint8_t[width*height + 1];
    memset(buffer, ' ', width*height*sizeof(uint8_t));
    buffer[width*height] = 0;
}

void linux_screen::hide_cursor() {
    linux_console_ptr_->hide_cursor();
}

void linux_screen::clear() {
    memset(buffer, ' ', width*height*sizeof(uint8_t));
    buffer[width*height] = 0;
}

void linux_screen::redraw() {
    linux_console_ptr_->draw((char *)buffer);
}