#ifndef CHAIN_HPP
#define CHAIN_HPP

#include "Command.hpp"
#include "ScrimParser.hpp"
#include <string>
#include <vector>

namespace prog {
    class Chain : public Command {
    public:
        Chain(const std::vector<std::string>& scrimFiles);
        ~Chain();
        Image *apply(Image *img) override;
        const std::vector<std::string>& getScrimFiles() const;

    private:
        std::vector<std::string> scrimFiles;
        Image* executeScrimFile(const std::string& filename, Image* img, std::vector<std::string>& visitedFiles);
    };
}
#endif //CHAIN_HPP