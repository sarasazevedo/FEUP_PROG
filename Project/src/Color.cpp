#include "Color.hpp"
#include <iostream>

using std::istream;

namespace prog {
    Color::Color() : r(0), g(0), b(0) {} //Construtor
    

    Color::Color(const Color& c) : r(c.r), g(c.g), b(c.b) {} //Copia Construtor
    

    Color::Color(rgb_value red, rgb_value green, rgb_value blue) : r(red), g(green), b(blue) {} //Constructor com os valores RGB



    rgb_value Color::red() const { //Obter o valor do Red
        return r;
    }

    rgb_value Color::green() const { //Obter o valor do Green
        return g;
    }

    rgb_value Color::blue() const { //Obter o valor do Blue
        return b;
    }



    rgb_value &Color::red() { //Obter o valor mutavel do Red
        return r;
    }

    rgb_value &Color::green() { //Obter o valor mutavel do Green
        return g;
    }

    rgb_value &Color::blue() { //Obter o valor mutavel do Blue
        return b;
    }
}


// Use to read color values from a script file.
istream &operator>>(istream &input, prog::Color &c) { //Ler os valores das cores
    int r, g, b;
    input >> r >> g >> b;
    c.red() = r;
    c.green() = g;
    c.blue() = b;
    return input;
}

std::ostream &operator<<(std::ostream &output, const prog::Color &c) { //Escrever os valores das cores no formato "r:g:b"
    output << (int) c.red() << ":" << (int) c.green() << ":" << (int) c.blue();
    return output;
}
