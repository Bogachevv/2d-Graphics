#pragma once

#include "../screen.h"
#include "./linux_console.h"

class linux_screen : public screen{
    linux_console_ptr linux_console_ptr_;

public:
    linux_screen();

    void redraw() override;

    void clear() override;

    void hide_cursor();
};

