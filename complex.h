#pragma once
#include <iostream>

class complex {
protected:
    double re_, im_;
    double abs_, arg_;

    void update_polar();
    void update_cartesian();

public:
    complex(double re = 0.0, double im = 0.0);

    static complex cexp(const complex& z);
    static complex cexp(double re, double im);

    double re() const {return re_;}
    double im() const {return im_;}

    void set_re(double re);
    void set_im(double im);

    double abs() const {return abs_;}
    double arg() const {return arg_;}

    void set_abs(double abs);
    void set_arg(double arg);

    double dot(complex &other) const;
    friend double dot(complex &left, complex &right);

    friend complex operator+(const complex &left, const complex &right);
    friend complex operator-(const complex &left, const complex &right);
    friend complex operator*(const complex &left, const complex &right);
    friend complex operator/(const complex &left, const complex &right);

    const complex& operator+=(const complex& other);
    const complex& operator-=(const complex& other);
    const complex& operator*=(const complex& other);
    const complex& operator/=(const complex& other);

    friend std::ostream &operator<<(std::ostream& ostream, const complex& val);
};

