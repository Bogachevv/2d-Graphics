#include "win_console.h"

#include <windows.h>
#include <stdexcept>

uint32_t win_console_ptr::ref_c = 0;

win_console_ptr::win_console_ptr(win_console *ptr) {
    ptr_ = ptr;
    ++ref_c;
}

win_console *win_console_ptr::operator->() {
    return this->ptr_;
}

win_console_ptr::~win_console_ptr() {
    --ref_c;
    if (ref_c == 0){
        delete this->ptr_;
        this->ptr_ = nullptr;
    }
}

win_console *win_console::win_console_ = nullptr;

win_console::win_console() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbInfo;

    GetConsoleScreenBufferInfo(handle, &csbInfo);

    SMALL_RECT srctWindow = csbInfo.srWindow;

    width_ = srctWindow.Right + 1;
    height_ = srctWindow.Bottom + 1;
}

win_console_ptr win_console::get() {
    if (win_console_ == nullptr){
        win_console_ = new win_console();
    }

    return win_console_ptr(win_console_);
}

void win_console::resize(uint32_t width, uint32_t height) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    if (handle == INVALID_HANDLE_VALUE){
        throw std::runtime_error("Console handle error");
    }

    _COORD coord = {(short)width, (short)height};
    int ret = SetConsoleScreenBufferSize(handle, coord);
    if (ret == 0){
        throw std::runtime_error("Resize error 1");
    }

    _SMALL_RECT rect = {0, 0, (short)(width - 1), (short)(height - 1)};
    ret = SetConsoleWindowInfo(handle, TRUE, &rect);

    if (ret == 0){
        throw std::runtime_error("Resize error 2");
    }

    width_ = width;
    height_ = height;
}


void win_console::get_size(uint32_t &width, uint32_t &height) const {
    width = width_;
    height = height_;
}


void win_console::draw(char *buf, uint32_t width, uint32_t height) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD lpNumberOfCharsWritten;

    int ret = WriteConsoleOutputCharacterA(handle, buf, width*height, {0, 0}, &lpNumberOfCharsWritten);

    if (ret == 0){
        throw std::runtime_error("Console draw error");
    }

}

void win_console::set_cursor(uint32_t x, uint32_t y) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    _COORD coord = {(short)x, (short)y};
    int ret = SetConsoleCursorPosition(handle, coord);

    if (ret == 0){
        throw std::runtime_error("Set cursor error");
    }
}

void win_console::hide_cursor() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cInfo = {100, FALSE};

    int ret = SetConsoleCursorInfo(handle, &cInfo);

    if (ret == 0){
        throw std::runtime_error("Hide cursor error");
    }

}