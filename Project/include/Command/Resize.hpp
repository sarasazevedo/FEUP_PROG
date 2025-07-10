#ifndef RESIZE_HPP
#define RESIZE_HPP

#include "Command.hpp"
#include <sstream>
#include <string>

namespace prog {
    class Resize : public Command {
    public:
        Resize();
        Resize(int x, int y, int w, int h);
        ~Resize() override;
        Image *apply(Image *img) override;
        std::string toString() const override;
    private:
        int x_, y_, w_, h_;
    };
}


#endif //RESIZE_HPP
