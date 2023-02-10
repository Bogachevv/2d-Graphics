#include "figures.h"

figure::figure() : center_() {}

figure::figure(complex center) : center_(center) {}

circle::circle(complex center, double radius) : figure(center), radius_(radius) {}

void circle::move(complex vec) {
    center_ = center_ + vec;
}

void circle::move_to(complex vec) {
    center_ = vec;
}

void circle::stretch(double alpha) {
    radius_ *= alpha;
}

void circle::rotate(double alpha) {
    // doing nothing, ha-ha
}

void circle::transform(complex alpha) {
    stretch(alpha.abs());
}

void circle::draw(screen &scr) {
    double aspect = ((double)scr.get_width()) / scr.get_height();
    aspect *= 8.0 / 16.0;

    for (uint32_t i = 0; i < scr.get_height(); ++i){ // y coord
        for (uint32_t j = 0; j < scr.get_width(); ++j){ // x coord
            double x = ((double)j) / scr.get_width()  * 2.0 - 1.0;
            double y = ((double)i) / scr.get_height() * 2.0 - 1.0;
            x *= aspect;

            x -= center_.re();
            y -= center_.im();
            if (x*x + y*y < radius_ * radius_){
                scr.update(j, i, '*');
            }

        }
    }
}

base_rectangle::base_rectangle(complex center, double width, double height) : figure(center) {
    lu = center - (width / 2.0) + (height / 2.0);
    lu_ru = lu + complex(width, 0.0);
    lu_ld = lu + complex(0.0, -height);
}

void base_rectangle::move(complex vec) {
    center_ += vec;
    lu += vec;
}

void base_rectangle::move_to(complex vec) {
    center_ = vec;
    lu = vec;
}

void base_rectangle::stretch(double alpha) {
    lu_ru *= alpha;
    lu_ld *= alpha;
}

void base_rectangle::rotate(double alpha) {
    lu_ru *= complex::cexp(0.0, alpha);
    lu_ld *= complex::cexp(0.0, alpha);
}

void base_rectangle::transform(complex alpha) {
    lu_ru *= alpha;
    lu_ld *= alpha;
}

void base_rectangle::draw(screen &scr) {

}

rectangle::rectangle(complex center, double width, double height)
: base_rectangle(center, width, height)
{

}

void rectangle::stretch(double width_k, double height_h) {
    lu_ru *= width_k;
    lu_ld *= height_h;
}

square::square(complex center, double a)
: base_rectangle(center, a, a)
{

}