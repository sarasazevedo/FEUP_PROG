#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"

class Rectangle : public Shape {
    public:
        Rectangle(const point& center, double width, double height) : Shape(center), width_(width), height_(height) {}
        double area() const override { return width_ * height_; }
        double perimeter() const override { return 2 * (width_ + height_);}
        bool contains(const point& p) const override {
            double half_width = width_ / 2;
            double half_height = height_ / 2;
            if (p.x >= get_center().x - half_width && p.x <= get_center().x + half_width) {
                if (p.y >= get_center().y - half_height && p.y <= get_center().y + half_height) {
                    return true;
                }
            }
            return false;
        }

    private:
        double width_;
        double height_;
};

#endif 