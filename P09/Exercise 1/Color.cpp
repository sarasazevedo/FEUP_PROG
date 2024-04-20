#include "Color.h"

Color::Color(unsigned char red, unsigned char green, unsigned char blue): r_(red), g_(green), b_(blue) {}

Color::Color(const Color& b): r_(b.red()), g_(b.green()), b_(b.blue()) {}

unsigned char Color::red() const { return r_; }

unsigned char Color::green() const { return g_; }

unsigned char Color::blue() const { return b_; }

const Color Color::RED(255, 0, 0);

const Color Color::GREEN(0, 255, 0);

const Color Color::BLUE(0, 0, 255);

const Color Color::BLACK(0, 0, 0);

const Color Color::WHITE(255, 255, 255);

bool Color::equal_to(const Color& other) const {
    return r_ == other.red() && g_ == other.green() && b_ == other.blue();
}

void Color::invert() {
    r_ = 255 - r_;
    g_ = 255 - g_;
    b_ = 255 - b_;
}