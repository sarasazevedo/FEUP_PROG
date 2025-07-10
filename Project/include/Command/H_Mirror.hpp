#ifndef H_MIRROR_HPP
#define H_MIRROR_HPP

#include "Command.hpp"

namespace prog {
    class H_Mirror : public Command {
    public:
        H_Mirror();
        Image *apply(Image *img) override;
    };
}

#endif //H_MIRROR_HPP
