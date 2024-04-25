#ifndef FCIRCLE_H
#define FCIRCLE_H
#include "Figure.h"
using namespace std;

class FCircle : public Figure {
    public:
        FCircle(double x_center, double y_center, double radius) : Figure(x_center, y_center), radius_(radius) {}
        void draw() const override { cout << "C(" << x_center_ << "," << y_center_ << ")(" << radius_ << ")";}

    private:
        double radius_;
};

#endif 
