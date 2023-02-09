#include "figures.h"

figure::figure() : center_() {}

figure::figure(complex center) : center_(center) {}

circle::circle(complex center, double radius) : figure(center), radius_(radius) {}

void circle::move(complex vec) {
    center_ = center_ + vec;
}

void circle::stretch(double alpha) {
    radius_ *= alpha;
}

void circle::rotate(double alpha) {
    // doing nothing, ha-ha
}

void circle::transform(complex &alpha) {
    stretch(alpha.abs());
}

base_rectangle::base_rectangle(complex center, double width, double height) : figure(center) {
    lu = center - (width / 2.0) + (height / 2.0);
    ru = center + (width / 2.0) + (height / 2.0);
    ld = center - (width / 2.0) - (height / 2.0);
    rd = center + (width / 2.0) - (height / 2.0);
}

void base_rectangle::move(complex vec) {
    center_ += vec;
    lu += vec;
    ru += vec;
    ld += vec;
    rd += vec;
}

void base_rectangle::stretch(double alpha) {
    //TODO:
    // implement base_rectangle::stretch
}

void base_rectangle::rotate(double alpha) {
    //TODO:
    // implement base_rectangle::rotate
}

void base_rectangle::transform(complex &alpha) {
    //TODO:
    // implement base_rectangle::transform
}

rectangle::rectangle(complex center, double width, double height)
: base_rectangle(center, width, height)
{

}

void rectangle::stretch(double width_k, double height_h) {
    //TODO:
    // implement rectangle::stretch
}

square::square(complex center, double a)
: base_rectangle(center, a, a)
{

}