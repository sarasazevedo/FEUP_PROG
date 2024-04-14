/*
Consider the code given in Point2d.h containing the definition of class Point2d to represent 2D-coordinates of type double:
class Point2d {
  public:
    Point2d();                   // default constructor (builds origin)
    Point2d(const Point2d& p);   // copy constructor
    Point2d(double x, double y); // constructor using supplied coordinates
    double get_x() const;  // accessor for X coordinate
    double get_y() const;  // accessor for Y coordinate
    void set_x(double x);  // mutator for X coordinate
    void set_y(double y);  // mutator for Y coordinate
    void translate(const Point2d& t);           // translate coordinates
    double distance_to(const Point2d& p) const; // get distance to given point
  private: 
    double x;  // X coordinate
    double y;  // Y coordinate
};
Write the C++ code for the translate() and distance_to() member functions (not yet implemented), such that:
a.translate(t) changes a with a translation by coordinates t, i.e., if a has coordinates (x,y) on entry, then a should have coordinates (x + t.x, y + t.y) on exit; and
a.distance_to(b) returns the Euclidean distance between a and b, i.e., sqrt((𝑎.𝑥−𝑏.𝑥)2+(𝑎.𝑦−𝑏.𝑦)2)
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Point2d.h"
using namespace std;

void Point2d::translate(const Point2d& t) {
    x += t.get_x();
    y += t.get_y();
}

double Point2d::distance_to(const Point2d& p) const {
    double dx = x - p.get_x();
    double dy = y - p.get_y();
    return sqrt(dx * dx + dy * dy);
}

int main() {
    { Point2d a { 1.0, 2.1 };
  a.translate({ -0.3, 0.5 });
  cout << fixed << setprecision(2) << a.get_x() << ' ' << a.get_y() << '\n'; }
  { Point2d a { 1.0, 2.1 }, b { 2.0, 3.1 };
  cout << fixed << setprecision(2) 
       << a.distance_to(b) << '\n'; }
    { Point2d a { 0, 0 }; Point2d b = a;
  a.translate({ 0, 0 });
  cout << fixed << setprecision(2) 
       << a.get_x() << ' ' << a.get_y() << ' '
       << a.distance_to(b) << '\n'; }
       { Point2d a { 0, 1 }; Point2d b = a;
  a.translate({ 1.5, 0 });
  cout << fixed << setprecision(2) 
       << a.get_x() << ' ' << a.get_y() << ' '
       << a.distance_to(b) << '\n'; }
       { Point2d a { 1, 0 }; Point2d b = a;
  a.translate({ -1, 2.5 });
  cout << fixed << setprecision(2) 
       << a.get_x() << ' ' << a.get_y() << ' '
       << a.distance_to(b) << '\n'; }
    return 0;
}