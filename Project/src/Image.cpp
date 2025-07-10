#include "Image.hpp"
#include <cassert>

namespace prog {
    // Construtor
    Image::Image(int w, int h, const Color &fill) {
        width_ = w;
        height_ = h;
        pixelMatrix_ = std::vector<std::vector<Color>>(height_, std::vector<Color>(width_, fill));
    }

    // Destrutor
    Image::~Image() {
    }

    // Obter a Largura da Imagem
    int Image::width() const {
        return width_;
    }

    // Obter a Altura da Imagem
    int Image::height() const {
        return height_;
    }

  // TODO: remove this DUMMY_color variable once you have appropriate fields for representing image pixels.
  //Color DUMMY_color;

    // Obter referência mutável do pixel
    Color &Image::at(int x, int y) {
		assert(x >= 0 && x < width_ && y >= 0 && y < height_);
        return pixelMatrix_[y][x];
    }

    // Apenas leitura do valor do pixel
    const Color &Image::at(int x, int y) const {
        assert(x >= 0 && x < width_ && y >= 0 && y < height_);
        return pixelMatrix_[y][x];
    }
}
