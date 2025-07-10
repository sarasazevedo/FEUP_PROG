#ifndef FILL_H
#define FILL_H

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    class Fill : public Command {
    public:
        Fill(int x, int y, int w, int h, const Color &color);
        Image *apply(Image *img) override;
    private:
        int x_, y_, w_, h_;
        Color color_;
    };
}

#endif //FILL_H
