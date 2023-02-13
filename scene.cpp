#include "scene.h"

figure &scene::add_figure(figures fig_type) {
    figures_.push_back(factory.create(fig_type));
    return *(*(figures_.end()-1)); //*(figures_.end()-1) -- pointer to the new figure
}

void scene::redraw_frame() {
    scr.clear();
    for (auto it = figures_.begin(); it < figures_.end(); ++it){
        (*it)->draw(scr);
    }

    scr.redraw();
}

scene::~scene() {
    for (auto it = figures_.begin(); it < figures_.end(); ++it){
        delete *it;
    }
}