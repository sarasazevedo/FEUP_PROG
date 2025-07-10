#include "Command/H_Mirror.hpp"
#include "Image.hpp"


namespace prog {
    //Construtor da class H_Mirror
    H_Mirror::H_Mirror() : Command("h_mirror") { }

    Image *H_Mirror::apply(Image *img) {
        int w = img->width();
        int h = img->height();

        for (int y = 0; y < h; y++) { //Itera sobre os pixeis até metade da Largura
            for (int x = 0; x < w / 2; x++) {

                Color &startPixel = img->at(x, y); // Pixel no lugar original
                Color &endPixel = img->at(w-1-x, y); //Pixel no lugar espelhado Horizontalmente
                // Troca dos pixeis
                rgb_value tmpRed = startPixel.red();
                rgb_value tmpGreen = startPixel.green();
                rgb_value tmpBlue = startPixel.blue();
                startPixel.red() = endPixel.red();
                startPixel.green() = endPixel.green();
                startPixel.blue() = endPixel.blue();
                endPixel.red() = tmpRed;
                endPixel.green() = tmpGreen;
                endPixel.blue() = tmpBlue;
            }
        }
        return img;
    }
}