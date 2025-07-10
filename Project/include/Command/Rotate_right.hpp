#ifndef ROTATE_RIGHT_HPP
#define ROTATE_RIGHT_HPP

#include "Command.hpp"
#include <sstream>
#include <string>

namespace prog {
    class Rotate_right : public Command {
    public:
        Rotate_right();
        ~Rotate_right() override;
        Image *apply(Image *img) override;
        std::string toString() const override;
    };
}

#endif //ROTATE_RIGHT_HPP
