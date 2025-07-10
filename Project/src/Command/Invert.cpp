#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    //Construtor da class Invert
    Invert::Invert() : Command("invert") { }

    Image *Invert::apply(Image *img) {

        for(int y=0; y<img->height(); y++) { //Itera sobre todos os pixeis
            for(int x=0; x<img->width(); x++) {
                //Inverte as cores dos pixeis
                Color &pixel = img ->at(x, y);
                pixel.red() = 255 - pixel.red();
                pixel.green() = 255 - pixel.green();
                pixel.blue() = 255 - pixel.blue();
            }
        }
        return img;
    }
}
