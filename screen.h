#pragma once

#include <cinttypes>

class screen {
protected:
    uint32_t width, height;
    uint8_t *buffer;

    screen();

    uint8_t &at(uint32_t x, uint32_t y);

public:
    screen(uint32_t width, uint32_t height);

    void update(uint8_t *new_buffer);
    void update(uint32_t x, uint32_t y, uint8_t val);

    virtual void redraw() = 0;

    uint32_t get_width() const  { return width;}

    uint32_t get_height() const { return height;}

    virtual void clear();

    ~screen();

};