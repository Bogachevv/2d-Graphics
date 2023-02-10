#pragma once

#include "./complex.h"
#include "./screen.h"

class figure {
protected:
    complex center_;

    figure();

    explicit figure(complex center);

public:
    virtual void move(complex vec) = 0;

    virtual void move_to(complex vec) = 0;

    virtual void stretch(double alpha) = 0;

    virtual void rotate(double alpha) = 0;

    virtual void transform(complex alpha) = 0;

    //TODO:
    // Move screen to the scene
    virtual void draw(screen &scr) = 0;

};

class circle:figure{
protected:
    double radius_;

public:
    circle(complex center, double radius);

    void move(complex vec) override;

    void move_to(complex vec) override;

    void stretch(double alpha) override;

    void rotate(double alpha) override;

    void transform(complex alpha) override;

    void draw(screen &scr) override;
};

class base_rectangle:figure{
protected:
    complex lu; //left-upper corner
    complex lu_ru; //left-upper --> right-upper
    complex lu_ld; //left-upper --> left-down

    /*
     *         lu_ru
     * lu --------------> ru
     *  |                  |
     *  |                  |  lu_ld
     *  |                  |
     * ld --------------> rd
     */

    base_rectangle(complex center, double width, double height);

public:
    void move(complex vec) override;

    void move_to(complex vec) override;

    void stretch(double alpha) override;

    void rotate(double alpha) override;

    void transform(complex alpha) override;

    void draw(screen &scr) override;
};

class rectangle:base_rectangle{
public:
    rectangle(complex center, double width, double height);
    void stretch(double width_k, double height_h);

};

class square:base_rectangle{
public:
    square(complex center, double a);
};