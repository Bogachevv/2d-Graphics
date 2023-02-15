#pragma once

#include <cinttypes>

class linux_console;

class linux_console_ptr{
    friend linux_console;

    linux_console *ptr_;
    static uint32_t ref_c;

    explicit linux_console_ptr(linux_console *ptr);

public:
    linux_console_ptr(linux_console_ptr &other);
    linux_console_ptr &operator=(const linux_console_ptr &other) = delete;
    // all pointers to singleton objects are the same,
    // so reassigning a pointer the to singleton object is a logical error

    linux_console *operator->();

    ~linux_console_ptr();

};


class linux_console { //linux_console is the singleton object
    static linux_console *linux_console_;

    uint32_t width_, height_;

    linux_console();

public:
    linux_console(linux_console &other) = delete;
    linux_console &operator=(linux_console &other) = delete;

    static linux_console_ptr get();

    void get_size(uint32_t &width, uint32_t &height) const;

    void draw(char *buf);

    void hide_cursor();

    ~linux_console();

};
