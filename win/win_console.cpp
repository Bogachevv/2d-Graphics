#include "win_console.h"

#include <windows.h>
#include <stdexcept>


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
}


void win_console::get_size(uint32_t &width, uint32_t &height) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbInfo;

    GetConsoleScreenBufferInfo(handle, &csbInfo);

    SMALL_RECT srctWindow = csbInfo.srWindow;

    width = srctWindow.Right + 1;
    height = srctWindow.Bottom + 1;
}


void win_console::draw(char *buf, uint32_t width, uint32_t height) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD lpNumberOfCharsWritten;

    int ret = WriteConsoleOutputCharacterA(handle, buf, width*height, {0, 0}, &lpNumberOfCharsWritten);

    if (ret == 0){
        throw std::runtime_error("Console draw error");
    }

}