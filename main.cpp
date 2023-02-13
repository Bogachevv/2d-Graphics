#include <iostream>
#include <cmath>

#include "./includes.h"
#include "./complex.h"
#include "./figures.h"
#include "./scene.h"

void c_sleep(int msec){
#ifdef _WIN32
    Sleep(msec);
#else
    usleep(msec * 1000);
#endif
}

int main() {
    std::cout << "Hello, World!" << std::endl;

#ifdef _WIN32
    win_screen scr = win_screen(120, 50);
#else
    linux_screen scr = linux_screen();
    scr.hide_cursor();
#endif
    scene scn = scene(scr);
    scn.reg_figure<rectangle>(figures::rectangle);

    auto &rect = dynamic_cast<rectangle&>(scn.add_figure(figures::rectangle));
    rect.move_to({0.0, 0.0});
    rect.set_width(1.0);
    rect.set_height(1.0);


    for (uint32_t t = 0; t < 10000; ++t){
        rect.rotate(0.1);
        rect.set_width(1 + 0.9 * sin(t / (2.0*M_PI * 2.0)));
        rect.set_height(1 + 0.9 * sin(t / (2.0*M_PI * 2.0)));

        scn.redraw_frame();
        c_sleep(50);
    }

    c_sleep(50000);

    return 0;
}
