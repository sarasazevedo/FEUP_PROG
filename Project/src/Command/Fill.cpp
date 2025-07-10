#include "Command/Fill.hpp"
#include "Image.hpp"

namespace prog {
    // Construtor da class Fill
    Fill::Fill(int x, int y, int w, int h, const Color &color) : Command("fill"), x_(x), y_(y), w_(w), h_(h), color_(color) { }

    Image *Fill::apply(Image *img) {
        for (int j = y_; j < y_ + h_ && j < img->height(); j++) { //Iterar sobre os pixeis
                //Se o pixel passar dos limites verticais, ignorar
            if (j < 0){
              continue;
            }
            for (int i = x_; i < x_ + w_ && i < img->width(); i++) {
                //Se o pixel passar dos limites horizontais, ignorar
                if (i < 0){
                  continue;
                }
                //Alterar a cor do pixel
                Color &pixel = img->at(i, j);
                pixel.red() = color_.red();
                pixel.green() = color_.green();
                pixel.blue() = color_.blue();
            }
        }
        return img;
    }
}