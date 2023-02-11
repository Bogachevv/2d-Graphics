#include <iostream>
#include <cmath>
#include <windows.h>

#include "screen.h"
#include "win/win_screen.h"
#include "./complex.h"
#include "./figures.h"

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
//TODO:
// Test complex arg
void test_complex(){
    complex c1(-1, 0);

    std::cout << c1 << std::endl;
    std::cout << "|z| = " << c1.abs() << ", arg(z) = " << c1.arg() << std::endl;

    exit(0);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

//    test_complex();

    win_screen scr = win_screen(120, 50);
    rectangle rect = rectangle({0.0, 0.0}, 1.0, 1.0);

    for (uint32_t t = 0; t < 10000; ++t){
//        draw_circle(scr, sin(t / (2.0*M_PI * 10.0)), 0.0);
        scr.clear();

        rect.rotate(0.1);
        rect.set_width(1 + 0.9 * sin(t / (2.0*M_PI * 2.0)));
        rect.set_height(1 + 0.9 * sin(t / (2.0*M_PI * 2.0)));
        rect.draw(scr);

        scr.redraw();

        Sleep(50);
    }

    Sleep(50000);

    return 0;
}
