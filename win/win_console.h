#pragma once

#include <cinttypes>

class win_console;

class win_console_ptr{
    friend win_console;

    win_console *ptr_;
    static uint32_t ref_c;

    explicit win_console_ptr(win_console *ptr);
public:
    win_console_ptr(win_console_ptr &other) = delete;
    win_console_ptr &operator=(win_console_ptr &other) = delete;

    win_console *operator->();

    ~win_console_ptr();

};

class win_console{
    static win_console *win_console_;

    uint32_t width_, height_;

    win_console();

public:
    win_console(win_console &other) = delete;
    win_console &operator=(win_console &other) = delete;

    static win_console_ptr get();

    void get_size(uint32_t &width, uint32_t &height) const;

    void resize(uint32_t width, uint32_t height);

    void draw(char *buf, uint32_t width, uint32_t height);

    void set_cursor(uint32_t x, uint32_t y);

    void hide_cursor();

    ~win_console() = default;
};