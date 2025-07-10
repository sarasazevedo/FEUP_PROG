#include "Command/ToGrayScale.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    //Construtor da class ToGrayScale
    ToGrayScale::ToGrayScale() : Command("to_gray_scale") { }

    Image *ToGrayScale::apply(Image *img) {
        for(int y=0; y<img->height(); y++) {// Itera sobre todos os pixeis
            for(int x=0; x<img->width(); x++) {

                Color &pixel = img ->at(x, y);
                //Calcular o tom cinzento v
                rgb_value v = (pixel.red() + pixel.green() + pixel.blue()) / 3;
                //Atribuir v às 3 cores
                pixel.red() = v;
                pixel.green() = v;
                pixel.blue() = v;
            }
        }
        return img;
    }
}