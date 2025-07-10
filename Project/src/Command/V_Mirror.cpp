#include "Command/V_Mirror.hpp"
#include "Image.hpp"

namespace prog {
    //Construtor da class V_Mirror
    V_Mirror::V_Mirror() : Command("v_mirror") { }

    Image *V_Mirror::apply(Image *img) {
        //Obter a Largura e a Altura
        int w = img->width();
        int h = img->height();

        for (int y = 0; y < h / 2; y++) {// iterar todos os pixeis até á metade da Altura
            for (int x = 0; x < w; x++) {
                Color &startPixel = img->at(x, y);
                Color &endPixel = img->at(x, h-1-y);
                // Trocar os pixeis
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