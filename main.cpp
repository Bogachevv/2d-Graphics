#include <iostream>
#include <cmath>

#include "./includes.h"
#include "./screen.h"
#include "./complex.h"
#include "./figures.h"
#include "./scene.h"

void draw_circle(screen &scr, double x_c, double y_c){
    double r = 0.25;
    double aspect = ((double)scr.get_width()) / scr.get_height();
    aspect *= 8.0 / 16.0;

    scr.clear();
    for (uint32_t i = 0; i < scr.get_height(); ++i){
        for (uint32_t j = 0; j < scr.get_width(); ++j){
            double x = ((double)j) / scr.get_width()  * 2.0 - 1.0;
            double y = ((double)i) / scr.get_height() * 2.0 - 1.0;
            x *= aspect;

            x -= x_c;
            y_c -= y_c;
            if (x*x + y*y < r){
                scr.update(j, i, '*');
            }

        }
    }

    scr.redraw();
}

int main() {
    std::cout << "Hello, World!" << std::endl;

#ifdef _WIN32
    win_screen scr = win_screen(120, 50);
#else
    linux_screen scr = linux_screen();
#endif
    scene scn = scene(scr);
    scn.reg_figure<rectangle>(figures::rectangle);

    auto &rect = dynamic_cast<rectangle&>(scn.add_figure(figures::rectangle));
    rect.move_to({0.0, 0.0});
    rect.set_width(1.0);
    rect.set_height(1.0);


    for (uint32_t t = 0; t < 10000; ++t){
//        draw_circle(scr, sin(t / (2.0*M_PI * 10.0)), 0.0);

        rect.rotate(0.1);
        rect.set_width(1 + 0.9 * sin(t / (2.0*M_PI * 2.0)));
        rect.set_height(1 + 0.9 * sin(t / (2.0*M_PI * 2.0)));
//        rect.draw(scr);

        scn.redraw_frame();
        sleep(50);
    }

    sleep(50000);

    return 0;
}
