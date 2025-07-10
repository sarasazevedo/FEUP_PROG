#ifndef CROP_HPP
#define CROP_HPP

#include "Command.hpp"
#include <sstream>
#include <string>

namespace prog {
    class Crop : public Command {
    public:
        Crop();
        Crop(int x, int y, int w, int h);
        ~Crop() override;
        Image *apply(Image *img) override;
        std::string toString() const override;
    private:
        int x_, y_, w_, h_;
    };
}

#endif //CROP_HPP
