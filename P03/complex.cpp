/*
For two complex numbers 𝑐1=𝑥1+𝑦1𝑖 and 𝑐2=𝑥2+𝑦2𝑖 we have that:
𝑐1+𝑐2=(𝑥1+𝑥2)+(𝑦1+𝑦2)𝑖𝑐1×𝑐2=(𝑥1𝑥2−𝑦1𝑦2)+(𝑥1𝑦2+𝑥2𝑦1)𝑖

Additionally, for a complex number 𝑐=𝑥+𝑦𝑖, the Euclidean norm is given by:
|𝑥|=𝑥2+𝑦2‾‾‾‾‾‾‾√

Consider a type for complex numbers defined by
struct complex {
   double x; // Real part
   double y; // Imaginary part
};

Write three C++ functions for calculating complex number addition, multiplication, and Euclidean norm
void add(const complex& a, const complex& b, complex& r);
void mul(const complex& a, const complex& b, complex& r);
double norm(const complex& c);

In your code you should include header file complex.h (you need to download the file) that contains the declarations of functions above and the complex type, along with support for printing complex values using cout.
*/
#include "complex.h"
#include <iostream>
#include <cmath>
using namespace std; 

void add(const complex& a, const complex& b, complex& r){ 
    r.x = a.x + b.x;
    r.y = a.y + b.y;
}

void mul(const complex& a, const complex& b, complex& r){
    r.y = (a.x*b.y) + (b.x*a.y);
    r.x = (a.x*b.x) - (a.y*b.y);
}

double norm(const complex& c){
    double s;
    double m;
    s = sqrt(c.x*c.x+c.y*c.y);
    m = sqrt(c.x*c.x+c.y*c.y);
    return s;
    return m;
}

int main(){
    { complex a { 0, 1 }, b { 2, 1}, s, m;
  add(a, b, s); 
  mul(a, b, m);
  cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }

{ complex a { 1.2, 3.4 }, b { -1.2, 2.3}, s, m;
  add(a, b, s); 
  mul(a, b, m);
  cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }

{ complex a { -1.5, 1 }, b { -1, 2}, s, m;
  add(a, b, s); 
  mul(a, b, m);
  cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }

{ complex a { -2, 2 }, b { 2, -2}, s, m;
  add(a, b, s); 
  mul(a, b, m);
  cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }

{ complex a { 0, 0 }, b { 1.2, -3.4}, s, m;
  add(a, b, s); 
  mul(a, b, m);
  cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }

{ complex a { 2, 0 }, b { 2.5, -3.1}, s, m;
  add(a, b, s); 
  mul(a, b, m);
  cout << s << ' ' << m << ' ' << norm(s) << ' ' << norm(m) << '\n'; }

  return 0;
}