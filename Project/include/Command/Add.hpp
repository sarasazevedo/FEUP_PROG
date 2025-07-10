#ifndef ADD_HPP
#define ADD_HPP
#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    class Add : public Command {
    public:
        Add(const std::string &filename, rgb_value r, rgb_value g, rgb_value b, int x, int y);
        Image *apply(Image *img) override;
    private:
        std::string filename_;
        Color neutralColor_;
        int x_, y_;
    };
}

#endif //ADD_HPP
