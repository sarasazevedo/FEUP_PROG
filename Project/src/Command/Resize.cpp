#include "Command/Resize.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog{
    Resize::Resize(int x, int y, int w, int h) : Command("resize"), x_(x), y_(y), w_(w), h_(h) { }

    Resize::~Resize() {}

    Image *Resize::apply(Image *img){

        Image *resized = new Image(w_,h_); //Cria uma nova imagem chamada croped com nova largura W e altura H

        int oldW = img->width();
        int oldH = img->height();

        for (int y = 0; y < h_; y++) { //Itera sobre os pixeis
            for (int x = 0; x < w_; x++) {
                int resizeX = x_ + x;
                int resizeY = y_ + y;
                if ( resizeX < oldW && resizeY < oldH){  //Se o os pixeis do resized tiverem dentro do tamanho da imagem original,
                    resized->at(x,y) = img->at(resizeX, resizeY);  //Vai colocar o pixel da imagem original no resized
                }
            }
        }
        delete img;
        return resized;
    }

}