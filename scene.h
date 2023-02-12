#pragma once

#include <map>
#include <vector>

#include "./figures.h"
#include "./figure_factory.h"
#include "./screen.h"

class scene {
protected:
    std::vector<figure*> figures_;
    screen &scr;
    figure_factory factory;

public:
    explicit scene(screen &scr) : scr(scr) {};

    template<class C>
    void reg_figure(figures fig) { factory.reg_figure<C>(fig);}

    figure &add_figure(figures fig_type);

    void redraw_frame();

    ~scene();

};
