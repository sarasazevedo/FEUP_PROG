/*
Consider Solid, an abstract class to represent three-dimensional solids with an associated center and surface area. The declaration of the class is given in Solid.h.
struct point {
  double x, y, z;
};
class Solid {
public:
  Solid(const point& c) : center_(c) { }
  const point& center() const { return center_; }
  virtual double area() const = 0;
private: 
  point center_; 
};
cylinder
Submit a file called Cylinder.h containing the definition of class Cylinder, a derived class of Solid to represent cylinder solids (illustrated above), such that:
Cylinder has a constructor that takes as arguments a cylinder's 𝑐𝑒𝑛𝑡𝑒𝑟, of type point, plus its 𝑟𝑎𝑑𝑖𝑢𝑠, and its ℎ𝑒𝑖𝑔ℎ𝑡 of type double (in this order);
Cylinder defines const methods to obtain a cylinder's radius and height, named radius() and height();
Cylinder appropriately implements area() — bear in mind that a cylinder with radius 𝑟 and height ℎ has a surface area equal to 2×𝜋×𝑟×(𝑟+ℎ)
Use constant M_PI defined in header cmath for the value of 𝜋
Note: Solid.h also contains the implementation of function ostream& operator<<(ostream& os, const point& p) used in tests.
*/

#include <iostream>
#include "Cylinder.h"
#include "Solid.h"
#include <vector>
using namespace std;

int main(){
    { const Cylinder c({0, 0, 0}, 1, 1);
  cout << c.center() << ' ' 
       << c.radius() << ' ' 
       << c.height() << ' ' 
       << c.area() << endl; }

    { const Cylinder c({0.1, 2.3, 4.5}, 1.2, 3.4);
    cout << c.center() << ' ' 
        << c.radius() << ' ' 
        << c.height() << ' ' 
        << c.area() << endl; }
    
    { const Solid& s = Cylinder({-1.2, -3.4, -5.6}, 1.2, 0.34);
    cout << s.center() << ' ' << s.area() << endl; }

    { const Solid& s = Cylinder({12.3, 34.5, 56.7}, 12.3, 0.51);
    cout << s.center() << ' ' << s.area() << endl; }

    return 0;
}