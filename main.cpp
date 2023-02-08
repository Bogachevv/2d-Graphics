#include <iostream>
#include <chrono>
#include <thread>

#include "screen.h"
#include "win/win_screen.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    win_screen scr = win_screen(120, 50);

    for (int i = 5; i < 25; ++i){
        scr.update(i, i, '*');
    }

    scr.redraw();


    std::this_thread::sleep_for(std::chrono::seconds(2));

    scr.clear();

    for (int i = 5; i < 25; ++i){
        scr.update(i, 5, '*');
    }

    scr.redraw();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    return 0;
}
