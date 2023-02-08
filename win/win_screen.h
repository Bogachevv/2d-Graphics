#pragma once

#include "../screen.h"
#include "win_console.h"

class win_screen : public screen{

public:
    win_screen();
    win_screen(uint32_t width, uint32_t height);

    void redraw() override;

};