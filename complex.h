#pragma once

class complex {
protected:
    double re_, im_;
    bool valid_cartesian_;
    double abs_, arg_;
    bool valid_polar_;

    void calc_cartesian();
    void calc_polar();

public:
    complex(double re = 0.0, double im = 0.0);

    static complex cexp(const complex& z);
    static complex cexp(double re, double im);

    double re();
    double im();

    void set_re(double re);
    void set_im(double im);

    double abs();
    double arg();

    void set_abs(double abs);
    void set_arg(double arg);

    friend complex operator+(const complex &left, const complex &right);
    friend complex operator-(const complex &left, const complex &right);
    friend complex operator*(const complex &left, const complex &right);
    friend complex operator/(const complex &left, const complex &right);

    void operator+=(const complex& other);
    void operator-=(const complex& other);

};

