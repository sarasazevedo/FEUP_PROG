#include "Command/Slide.hpp"
#include "Image.hpp"

namespace prog {
    //Construtor da class Slide
    Slide::Slide(int x, int y) : Command("slide"), x_(x), y_(y) { }

    Image *Slide::apply(Image *img) {
        // Cria uma imagem de mesmo tamanho original e as cores em branco
        Color fill(255, 255, 255);
        Image *newImage = new Image(img->width(), img->height(), fill);

        for (int y = 0; y < img->height(); y++) {// Itera sobre os pixeis
            for (int x = 0; x < img->width(); x++) {
                //Calcular o deslocamento do pixel
                int imgX = (x + x_) % img->width();
                int imgY = (y + y_) % img->height();
                //Se ambos os indices foram negativos, colocar-los dentro dos limites da imagem
                if (imgX < 0){
                    imgX += img->width();
                }
                if (imgY < 0){
                    imgY += img->height();
                }
                // Copiar o pixel deslocado da imagem original para a nova
                newImage->at(x, y) = img->at(imgX, imgY);
            }
        }
        delete img;
        return newImage;
    }
}