#include <cmath>
#include <stdexcept>

#include "./complex.h"

complex::complex(double re, double im) : abs_(0), arg_(0) {
    re_ = re;
    im_ = im;
    update_polar();
}

complex complex::cexp(double re, double im) {
    double exp_abs = ::fabs(re);
    double exp_arg = im * (re > 0 ? 1.0 : (-1.0));

    return {exp_abs * cos(exp_arg), exp_abs * sin(exp_arg)};
}

complex complex::cexp(const complex &z) {
    return cexp(z.re_, z.im_);
}

void complex::update_polar() {
    abs_ = sqrt(re_*re_ + im_*im_);
    arg_ = atan2(im_, re_);
}

void complex::update_cartesian() {
    re_ = abs_ * cos(arg_);
    im_ = abs_ * sin(arg_);
}

void complex::set_re(double re) {
    re_ = re;
    update_polar();
}

void complex::set_im(double im) {
    im_ = im;
    update_polar();
}

void complex::set_abs(double abs) {
    abs_ = abs;
    update_cartesian();
}

void complex::set_arg(double arg) {
    arg_ = arg;
    update_cartesian();
}

double complex::dot(complex &other) const{
    return re_*other.re_ + im_*other.im_;
}

double dot(complex &left, complex &right) {
    return left.re_ * right.re_ + left.im_ * right.im_;
}

complex operator+(const complex &left, const complex &right) {
    return {left.re_ + right.re_, left.im_ + right.im_};
}

complex operator-(const complex &left, const complex &right) {
    return {left.re_ - right.re_, left.im_ - right.im_};
}

complex operator*(const complex &left, const complex &right) {
    complex res;
    res.abs_ = left.abs_ * right.abs_;
    res.arg_ = left.arg_ + right.arg_;
    res.update_cartesian();

    return res;
}

complex operator/(const complex &left, const complex &right) {
    if (right.abs_ == 0.0) throw std::runtime_error("Complex: division zero");

    complex res;
    res.abs_ = left.abs_ / right.abs_;
    res.arg_ = left.arg_ - right.arg_;
    res.update_cartesian();

    return res;
}

const complex& complex::operator+=(const complex &other) {
    re_ += other.re_;
    im_ += other.im_;

    return *this;
}

const complex& complex::operator-=(const complex &other) {
    re_ -= other.re_;
    im_ -= other.im_;

    return *this;
}

const complex& complex::operator*=(const complex &other) {
    abs_ *= other.abs_;
    arg_ += other.arg_;
    update_cartesian();

    return *this;
}

const complex& complex::operator/=(const complex &other) {
    if (other.abs_ == 0.0) throw std::runtime_error("Complex: division zero");

    abs_ /= other.abs_;
    arg_ -= other.arg_;
    update_cartesian();

    return *this;
}

std::ostream &operator<<(std::ostream &ostream, const complex &val) {
    ostream << val.re_ << " + "  << val.im_ << "i";

    return ostream;
}
