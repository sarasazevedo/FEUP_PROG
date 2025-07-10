#include "Command/Replace.hpp"
#include "Image.hpp"

namespace prog {
    //Construtor da class Replace
    Replace::Replace(const Color &color, const Color &newColor) : Command("replace"), color_(color), newColor_(newColor) { }

    Image *Replace::apply(Image *img) {
        for(int y=0; y<img->height(); y++) { //Itera sobre os pixeis
            for(int x=0; x<img->width(); x++) {
                Color &pixel = img ->at(x, y);
                //Se o pixel tem a mesma cor que color_, então
                if (pixel.red() == color_.red() && pixel.green() == color_.green() && pixel.blue() == color_.blue()) {
                    // Substitui pela nova cor
                    pixel.red() = newColor_.red();
                    pixel.green() = newColor_.green();
                    pixel.blue() = newColor_.blue();
                }
            }
        }
        return img;
    }
}