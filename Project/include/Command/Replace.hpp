#ifndef REPLACE_HPP
#define REPLACE_HPP

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    class Replace : public Command {
    public:
        Replace(const Color &color, const Color &newColor);
        Image *apply(Image *img) override;
    private:
        Color color_;
        Color newColor_;
    };
}

#endif //REPLACE_HPP
