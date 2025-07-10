#include "Command/Move.hpp"
#include "Image.hpp"

namespace prog {
    // Construtor da class Move
    Move::Move(int x, int y) : Command("move"), x_(x), y_(y) { }

    Image *Move::apply(Image *img) {
        // Cria uma imagem de mesmo tamanho original e as cores em branco
        Color fill(255, 255, 255);
        Image *newImage = new Image(img->width(), img->height(), fill);

        for (int y = 0; y < img->height(); y++) { //Itera sobre os pixeis
            for (int x = 0; x < img->width(); x++) {
                // Novas posições dos pixeis
                int newX = x + x_;
                int newY = y + y_;
                // Se o pixel tiver dentro do limite da Imagem, então
                if (newX >= 0 && newX < img->width() && newY >= 0 && newY < img->height()) {
                    // Mover o pixel para nova posição
                    newImage->at(newX, newY) = img->at(x, y);
                }
            }
        }

        delete img;
        return newImage;
    }
}