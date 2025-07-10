#include "Command/Rotate_left.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog{
    Rotate_left::Rotate_left() : Command("rotate_left") { }

    Rotate_left::~Rotate_left() {}

    Image* Rotate_left::apply(Image *img) {
        int w = img->width(); //obtem a largura a imagem
        int h = img->height(); //obtem a altura da imagem

        Image* rotated = new Image(h, w); //cria uma imagem nova chamada rotated que vai ser a imagem virada 90º à esquerda

        for (int y = 0; y < h; y++) { //itera sober os pixeis
            for (int x = 0; x < w; x++) {
                rotated->at(y, w - 1 - x) = img->at(x, y); //colocar os pixeis da imagem para o rotated
                }
        }
        delete img; //apaga a imagem original
        return rotated; //devolver a rotated, a imagem original virada 90º à esquerda
    }

}