#ifndef V_MIRROR_HPP
#define V_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    class V_Mirror : public Command {
    public:
        V_Mirror();
        Image *apply(Image *img) override;
    };
}

#endif //V_MIRROR_HPP
