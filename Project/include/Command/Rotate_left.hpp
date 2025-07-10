#ifndef ROTATE_LEFT_HPP
#define ROTATE_LEFT_HPP

#include "Command.hpp"
#include <sstream>
#include <string>

namespace prog {
    class Rotate_left : public Command {
    public:
        Rotate_left();
        ~Rotate_left() override;
        Image *apply(Image *img) override;
        std::string toString() const override;
    };
}

#endif //ROTATE_LEFT_HPP
