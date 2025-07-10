#include "Command/Crop.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog{
    //Construtor da class Crop
    Crop::Crop(int x, int y, int w, int h) : Command("crop"), x_(x), y_(y), w_(w), h_(h) { }

    Crop::~Crop() {}

    Image *Crop::apply(Image *img){

        Image *cropped = new Image(w_,h_); //cria uma nova imagem chamada croped com nova largura W e altura H

        int oldW = img->width();
        int oldH = img->height();

        for (int y = 0; y < h_; y++) {
            for (int x = 0; x < w_; x++) {
            	int cropX = x_ + x;
                int cropY = y_ + y;
                if ( cropX < oldW && cropY < oldH){  //se o o pixel do cropped tiverem dentro do tamanho da imagem original,
					cropped->at(x,y) = img->at(cropX, cropY);  //vai colocar o pixel da imagem original no cropped
                }
            }
        }
    delete img;
    return cropped;
    }

}