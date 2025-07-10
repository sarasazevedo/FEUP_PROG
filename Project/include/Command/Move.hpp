#ifndef MOVE_HPP
#define MOVE_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    class Move : public Command {
    public:
        Move(int x, int y);
        Image *apply(Image *img) override;
    private:
        int x_, y_;
    };
}

#endif //MOVE_HPP
