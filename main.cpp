#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>

#include "screen.h"
#include "win/win_screen.h"

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

    win_screen scr = win_screen(120, 50);

//    for (int i = 5; i < 25; ++i){
//        scr.update(i, i, '*');
//    }
//
//    scr.redraw();
//
//
//    std::this_thread::sleep_for(std::chrono::seconds(2));

    for (uint32_t t = 0; t < 1000; ++t){
        draw_circle(scr, sin(t / (2.0*M_PI)), 0.0);
        std::this_thread::sleep_for(std::chrono::milliseconds (250));
    }

    std::this_thread::sleep_for(std::chrono::seconds(500));

    return 0;
}
