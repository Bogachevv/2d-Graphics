#include <cmath>
#include <stdexcept>

#include "./complex.h"

//TODO:
// rewrite complex

complex::complex(double re, double im) {
    re_ = re;
    im_ = im;
    valid_cartesian_ = true;

    abs_ = sqrt(re*re + im*im);
    arg_ = (abs_ == 0.0 ? 0.0 : atan(im / re));
    valid_polar_ = true;

}

complex complex::cexp(double re, double im) {
    double exp_abs = ::fabs(re);
    double exp_arg = im * (re > 0 ? 1.0 : (-1.0));

    return {exp_abs * cos(exp_arg), exp_abs * sin(exp_arg)};
}

complex complex::cexp(const complex &z) {
    return cexp(z.re_, z.im_);
}

void complex::calc_cartesian() {
    if (valid_cartesian_) return;
    if (not valid_polar_) throw std::runtime_error("Complex error: not valid object");

    re_ = abs_ * cos(arg_);
    im_ = abs_ * sin(arg_);
    valid_cartesian_ = true;
}

void complex::calc_polar() {
    if (valid_polar_) return;
    if (not valid_cartesian_) throw std::runtime_error("Complex error: not valid object");

    abs_ = sqrt(re_*re_ + im_*im_);
    arg_ = (abs_ == 0 ? 0.0 :atan(im_ / re_));
    valid_polar_ = true;
}

double complex::re() {
    calc_cartesian();
    return re_;
}

double complex::im() {
    calc_cartesian();
    return im_;
}

void complex::set_re(double re) {
    calc_cartesian();
    re_ = re;
    valid_polar_ = false;
}

void complex::set_im(double im) {
    calc_cartesian();
    im_ = im;
    valid_polar_ = false;
}

double complex::abs() {
    calc_polar();
    return abs_;
}

double complex::arg() {
    calc_polar();
    return arg_;
}

void complex::set_abs(double abs) {
    calc_polar();
    abs_ = abs;
    valid_cartesian_ = false;
}

void complex::set_arg(double arg) {
    calc_polar();
    arg_ = arg;
    valid_cartesian_ = false;
}

complex operator+(const complex &left, const complex &right) {

}

