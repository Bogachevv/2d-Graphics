#pragma once

#include <cinttypes>

namespace win_console{
    void get_size(uint32_t &width, uint32_t &height);

    void resize(uint32_t width, uint32_t height);

    void draw(char *buf, uint32_t width, uint32_t height);

    void set_cursor(uint32_t x, uint32_t y);

    void hide_cursor();
}


