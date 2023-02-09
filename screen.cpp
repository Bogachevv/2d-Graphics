#include "screen.h"

#include <cstring>
#include <stdexcept>

screen::screen(uint32_t width, uint32_t height) : width(width), height(height) {
    buffer = new uint8_t[width*height];
    memset(buffer, ' ', width*height*sizeof(uint8_t));
}

screen::screen() : width(0), height(0), buffer(nullptr) {}

uint8_t &screen::at(uint32_t x, uint32_t y) {
    if ((x >= width) or (y >= height)){
        throw std::runtime_error("Incorrect position");
    }

    return buffer[width*y + x];
}

void screen::update(uint8_t *new_buffer) {
    std::memcpy(buffer, new_buffer, width*height);
}

void screen::update(uint32_t x, uint32_t y, uint8_t val) {
    at(x, y) = val;
}

void screen::clear() {
    std::memset(buffer, 0, width*height);
}

uint32_t screen::get_width() const{
    return width;
}

uint32_t screen::get_height() const{
    return height;
}

screen::~screen() {
    delete[] buffer;
}