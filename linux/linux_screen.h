#pragma once

#include "../screen.h"

class linux_screen : public screen{
public:
    linux_screen();

    void redraw() override;

    void hide_cursor();

    ~linux_screen();
};

