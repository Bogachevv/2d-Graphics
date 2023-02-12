#include "figures.h"

figure::figure() : center_() {}

figure::figure(complex center) : center_(center) {}

circle::circle(complex center, double radius) : figure(center), radius_(radius) {}
circle::circle()
: figure({0.0, 0.0}), radius_(1.0) {}

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

    for (uint32_t i = 0; i < scr.get_height(); ++i){ // y_ coord
        for (uint32_t j = 0; j < scr.get_width(); ++j){ // x_ coord
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
    x_ = complex(width / 2.0, 0.0);
    y_ = complex(0.0, -height / 2.0);
}

void base_rectangle::move(complex vec) {
    center_ += vec;
}

void base_rectangle::move_to(complex vec) {
    center_ = vec;
}

void base_rectangle::stretch(double alpha) {
    x_ *= alpha;
    y_ *= alpha;
}

void base_rectangle::rotate(double alpha) {
    x_ *= complex::cexp(1.0, alpha);
    y_ *= complex::cexp(1.0, alpha);
}

void base_rectangle::transform(complex alpha) {
    x_ *= alpha;
    y_ *= alpha;
}

void base_rectangle::draw(screen &scr) {
//    double  aspect = 1.0;
    double aspect = ((double)scr.get_width()) / scr.get_height();
    aspect *= 8.0 / 16.0;

    for (uint32_t i = 0; i < scr.get_height(); ++i){ // y_ coord
        for (uint32_t j = 0; j < scr.get_width(); ++j){ // x coord
            double x = ((double)j) / scr.get_width()  * 2.0 - 1.0;
            double y = ((double)i) / scr.get_height() * 2.0 - 1.0;
            x *= aspect;

            complex point = {x, y};
            point -= center_;
            double x_comp = x_.dot(point);
            double y_comp = y_.dot(point);

            if ((std::abs(x_comp) <= x_.abs() * x_.abs())
            and (std::abs(y_comp) <= y_.abs() * y_.abs())){
                scr.update(j, i, '*');
            }
        }
    }
}

rectangle::rectangle(complex center, double width, double height)
: base_rectangle(center, width, height)
{

}

rectangle::rectangle()
: base_rectangle({0.0, 0.0}, 1.0, 1.0)
{

}

void rectangle::stretch(double width_k, double height_h) {
    x_ *= width_k;
    y_ *= height_h;
}

void rectangle::set_width(double width) {
    x_.set_abs(width / 2.0);
}

void rectangle::set_height(double height) {
    y_.set_abs(height / 2.0);
}

square::square(complex center, double a)
: base_rectangle(center, a, a)
{

}

square::square()
: base_rectangle({0.0, 0.0}, 1.0, 1.0)
{

}