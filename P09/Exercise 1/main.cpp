/*
Write a C++ class named Color to represent colors using the Red-Green-Blue (RGB) color model such that each RGB component is an 8-bit unsigned integer (unsigned char, values from 0 to 255).
You must submit only two files as attachments: Color.h and Color.cpp. The Color.h file should contain only the class declaration, and Color.cpp should contain the actual implementation.
In your local workspace, to compile a program in a file containing the tests, named for instance main.cpp, you should use the supplied Makefile and execute the following command in the Terminal:
make PROG=main CPP_FILES="Color.cpp main.cpp" HEADERS="Color.h"
The Color class should have:
A constructor
Color(unsigned char red, unsigned char green, unsigned char blue);
that takes as argument the RGB values to use for the color
A copy constructor
Color(const Color& c);
Accessors:
unsigned char red() const;
unsigned char green() const;
unsigned char blue() const;
Static class constants
static const Color RED, GREEN, BLUE, BLACK, WHITE;
corresponding to colors red (255-0-0 in RGB), green (0-255-0), blue (0-0-255), black (0-0-0), and white (255-255-255)
a member function to test equality between colors
bool equal_to(const Color& other) const;
such that a.equal_to(b) for Color objects a and b returns true if and only if the RGB components of a and b are equal
a member function
void invert();
to invert a color each RGB component x should be changed to 255-x
*/

#include <iostream>
#include "Color.h"
using namespace std;

int main(){
    { Color c (1, 2, 3);
      const Color& r = c;
      cout << (int) r.red() << ' '  
       << (int) r.green() << ' '  
       << (int) r.blue() << ' '
       << boolalpha << r.equal_to(r) << '\n'; }

    { cout << boolalpha 
       << Color::WHITE.equal_to(Color::WHITE) << ' '
       << Color::BLACK.equal_to(Color::RED) << ' '
       << Color::BLUE.equal_to(Color::GREEN) << '\n'; }

    { Color c(Color::WHITE); 
      cout << (int) c.red() << ' '
       << (int) c.green() << ' '  
       << (int) c.blue() << ' '
       << boolalpha << c.equal_to(Color::WHITE) << ' '
       << c.equal_to(Color::BLACK) << '\n'; }

    { Color c(Color::WHITE); 
      c.invert();
      cout << (int) c.red() << ' '  
       << (int) c.green() << ' '  
       << (int) c.blue() << ' ' 
       << boolalpha << c.equal_to(Color::WHITE) << ' '
       << c.equal_to(Color::BLACK) << '\n'; }

    { Color c(255, 128, 12); 
      c.invert();
      Color c2(c);
      c2.invert();
      cout << (int) c.red() << ' ' 
       << (int) c.green() << ' '  
       << (int) c.blue() << ' ' 
       << boolalpha << c.equal_to({ 0, 127, 243 }) << ' '
       << (int) c2.red() << ' ' 
       << (int) c2.green() << ' '  
       << (int) c2.blue() << ' ' 
       << boolalpha << c2.equal_to({ 255, 128, 12 }) << '\n'; }

    return 0;
}