#include "linux_console.h"

#include <ncurses.h>
#include <stdexcept>

uint32_t linux_console_ptr::ref_c = 0;

linux_console_ptr::linux_console_ptr(linux_console *ptr) {
    ptr_ = ptr;
    ++ref_c;
}

linux_console *linux_console_ptr::operator->() {
    return this->ptr_;
}

linux_console_ptr::~linux_console_ptr() {
    --ref_c;
    if (ref_c == 0){
        delete this->ptr_;
        this->ptr_ = nullptr;
    }
}

linux_console_ptr::linux_console_ptr(linux_console_ptr &other) {
    ++ref_c;
    this->ptr_ = other.ptr_;
}

linux_console *linux_console::linux_console_ = nullptr;

linux_console::linux_console() {
    initscr();
    getmaxyx(stdscr, height_, width_);
}

linux_console_ptr linux_console::get() {
    if (linux_console_ == nullptr){
        linux_console_ = new linux_console();
    }

    return linux_console_ptr(linux_console_);
}

void linux_console::get_size(uint32_t &width, uint32_t &height) const {
    width = width_;
    height = height_;
}

void linux_console::draw(char *buf) {
    move(0, 0);
    addstr((char*)buf);
    refresh();
}

void linux_console::hide_cursor() {
    curs_set(0);
}

linux_console::~linux_console(){
    endwin();
}
