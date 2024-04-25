/*
Consider the definition of an abstract class for bidimensional geometric shapes given in header Shape.h:
struct point {
  double x, y;
};
class Shape {
public:
  Shape(const point& center) : center_(center) { }
  const point& get_center() const { return center_; }
  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  virtual bool contains(const point& p) const = 0;
private:
  point center_;
};
A shape has a geometric center, returned by get_center(). Abstract functions area() and perimeter() should return a shape’s area and perimeter, respectively. Finally, abstract function contains() should be used to determine if a shape contains a given point.
To represent circles and rectangles, write the corresponding definition of classes Circle and Rectangle, defined in header files Circle.h and Rectangle.h respectively, that should both be subclasses of Shape. Circle should have a constructor that takes two arguments: the center of the circle and its radius (a double value). Rectangle has a constructor that takes 3 arguments: the geometric center of the rectangle, the rectangle’s width and the rectangle’s height (double values).
Note: use the M_PI constant defined by header <cmath> for the value of Pi.
*/

#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
#include <vector>
using namespace std;

int main(){
    { Circle c({1.0, 2.0}, 1.0); 
    const point& p = c.get_center();
    cout << fixed << setprecision(2) 
       << '(' << p.x << ',' << p.y << ')' << ' '
       << c.area() << ' ' << c.perimeter() << '\n'; }

    { Rectangle r({3.4, 4.5}, 1, 2); 
    const point& p = r.get_center();
    cout << fixed << setprecision(2) 
       << '(' << p.x << ',' << p.y << ')' << ' '
       << r.area() << ' ' << r.perimeter() << '\n'; }

    { const Shape& s1 = Circle({1, 2}, 3); 
    const Shape& s2 = Rectangle({4, 5}, 6, 7); 
    cout << fixed << setprecision(2) << boolalpha
       << s1.area() << ' ' << s1.perimeter() << ' '
       << s1.contains({1, 2}) << ' ' << s1.contains({ 4, 5 }) << ' '
       << s2.area() << ' ' << s2.perimeter() <<  ' '
       << s2.contains({1, 2}) << ' ' << s2.contains({ 4, 5 }) << '\n'; }

    { Circle c({1, 2}, 3);
    point a [] { 
        { -2.1,  2.0 }, { -1.9,  2.0 }, { 4.1,  2.0 }, { 3.9,  2.0 }, 
        {  1.0,  4.9 }, {  1.0, -0.9 }, { 1.0,  5.1 }, { 1.0, -1.1 }, 
        {  1.2, -0.3 }, {  5.2,  5.1 }, { 2.1, -0.5 }, { 3.2,  5.5 } };
    cout << fixed << setprecision(2);
    for (point& p : a)  
        if (c.contains(p))
        cout << '(' << p.x << ',' << p.y << ')';
    cout << '\n';  } 

    { Rectangle r({1, 2}, 6, 8);
    point a [] { 
        { -2.1,  2.0 }, { -1.9,  2.0 }, { 4.1,  2.0 }, { 3.9,  2.0 }, 
        {  1.0,  4.9 }, {  1.0, -0.9 }, { 1.0,  5.1 }, { 1.0, -1.1 }, 
        {  1.2, -0.3 }, {  5.2,  5.1 }, { 2.1, -0.5 }, { 3.2,  5.5 } };
    cout << fixed << setprecision(1);
    for (point& p : a)  
        if (r.contains(p)) 
        cout << '(' << p.x << ',' << p.y << ')';
    cout << '\n'; }
    
    return 0;
}