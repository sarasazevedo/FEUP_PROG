#include "Command/Add.hpp"
#include "PNG.hpp"
#include "Image.hpp"

namespace prog {
    //Construtor da class Add
    Add::Add(const std::string &filename, rgb_value r, rgb_value g, rgb_value b, int x, int y) : Command("add"), filename_(filename), neutralColor_(r, g, b), x_(x), y_(y) { }

    Image *Add::apply(Image *img) {
        Image* image = loadFromPNG(filename_); // Carrega a imagem a partir de um ficheiro

        //Largura e Altura
        int w = image->width();
        int h = image->height();

        for (int y = 0; y < h; y++) { //itera sobre os pixeis
            for (int x = 0; x < w; x++) {
                const Color& pixel = image->at(x, y);

                //Se a cor do pixel for neutra, ignorar
                if (pixel.red() == neutralColor_.red() && pixel.green() == neutralColor_.green() && pixel.blue() == neutralColor_.blue()) {
                    continue;
                }
                int destX = x_ + x;
                int destY = y_ + y;

                //Se o pixel dest estiver dentro dos limites da imagem original,
                if (destX >= 0 && destX < img->width() && destY >= 0 && destY < img->height()) {
                    //Então copia os valores RGB da Imagem para o destino
                    Color& destPixel = img->at(destX, destY);
                    destPixel.red() = pixel.red();
                    destPixel.green() = pixel.green();
                    destPixel.blue() = pixel.blue();
                }
            }
        }

        delete image;
        return img;
    }
}