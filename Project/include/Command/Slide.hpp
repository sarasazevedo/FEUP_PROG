#ifndef SLIDE_HPP
#define SLIDE_HPP

#include "Command.hpp"

namespace prog {
    class Slide : public Command {
    public:
        Slide(int x, int y);
        Image *apply(Image *img) override;
    private:
        int x_, y_;
    };
}

#endif //SLIDE_HPP
