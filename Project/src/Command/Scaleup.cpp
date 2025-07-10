#include "Command/Scaleup.hpp"
#include "Image.hpp"
#include <sstream>


namespace prog{
    Scaleup::Scaleup(int x, int y) : Command("scaleup"), x_(x), y_(y) { }

    Scaleup::~Scaleup() {}

	Image *Scaleup::apply(Image *img) {
        //Obter as Larguras e alturas Novas
        int W = img->width();
        int H = img->height();
        int newW = W * x_;
        int newH = H * y_;

        Image* scaled = new Image(newW, newH); //Cria uma nova imagem chamada scaled com as novas dimensões

        for (int y = 0; y < H; y++) { //Itera sobre os pixeis
            for (int x = 0; x < W; x++) {
                Color pixel = img->at(x, y); //Associa a variavel pixel para cada pixel da imagem original

                for (int dy = 0; dy < y_; dy++) {
                    for (int dx = 0; dx < x_; dx++) {
                        scaled->at(x * x_ + dx, y * y_ + dy) = pixel; //Cria o scaled a partir de cada variavel pixel
                    }
                }
            }
        }

        delete img;
        return scaled;

    }

}