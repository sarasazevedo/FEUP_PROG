/*
The Mandelbrot set recurrence 𝑧0,𝑧1,𝑧2,... of complex numbers is defined for a complex constant 𝑐 by:
𝑧0=0𝑧𝑛=𝑧𝑛−1×𝑧𝑛−1+𝑐∀𝑛>0
Consider again the complex type defined in header complex.h and use the functions you defined in the previous exercise to write a C++ function
void mandelbrot(const complex& c, unsigned int n, complex& z_n)
such that a call to mandelbrot(c, n, z_n) yields in z_n the n-th element of the Mandelbrot set recurrence for c.
*/

#include <iostream>
#include "complex.h"
#include <cmath>
using namespace std;

complex mul(complex a,complex b) {
    complex result;
    result.x = (a.x * b.x - a.y * b.y);
    result.y = (a.x * b.y + a.y * b.x);
    return result;
}

complex add(complex a, complex b) {
    complex result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

void mandelbrot(const complex& c, unsigned int n, complex& z) {
    unsigned int i = 0;
    z = {0.0, 0.0};
    while (i != n) {
        z = add(mul(z,z),c);
        i += 1;
    }
}

int main(){
    { complex z_n;
  mandelbrot({1.2, 3.4}, 0, z_n);
  cout << z_n << '\n'; }
    return 0;
}