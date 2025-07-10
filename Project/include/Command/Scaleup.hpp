#ifndef SCALEUP_HPP
#define SCALEUP_HPP

#include "Command.hpp"
#include <sstream>
#include <string>

namespace prog {
    class Scaleup : public Command {
    public:
        Scaleup();
        Scaleup(int x, int y);
        ~Scaleup() override;
        Image *apply(Image *img) override;
        std::string toString() const override;
    private:
        int x_, y_;
    };
}
#endif //SCALEUP_HPP
