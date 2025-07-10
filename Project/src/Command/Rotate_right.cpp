#include "Command/Rotate_right.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog{
    Rotate_right::Rotate_right() : Command("rotate_right") { }

    Rotate_right::~Rotate_right() {}

    Image* Rotate_right::apply(Image *img) {
        int w = img->width(); //obtem a largura a imagem
        int h = img->height(); //obtem a altura da imagem

        Image* rotated = new Image(h, w); //cria uma imagem nova chamada rotated que vai ser a imagem virada 90º à direita

        for (int y = 0; y < h; y++) { //Itera sobre os pixeis
            for (int x = 0; x < w; x++) {
                rotated->at(h - 1 - y,x) = img->at(x, y); //colocar os pixeis da imagem para o rotated
            }
        }
        delete img; //apaga a imagem original
        return rotated; //devolver a rotated, a imagem original virada 90º à direita
    }

}