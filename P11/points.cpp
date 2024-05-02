/*
Consider the following interface of a class named Point given in header Point.h:
class Point {
public:
  Point(); // builds (0,0)
  Point(int x, int y); // builds (x,y)
  Point(const Point& p); // copy constructor
  int get_x() const; // get x coordinate
  int get_y() const; // get y coordinate
  Point& operator=(const Point& p); // assignment operator
  Point operator+(const Point& p) const; // sum
  Point& operator+=(const Point& p); // composed assignment and sum
  Point operator*(int v) const; // "right" multiplication by scalar
private:
  int x_, y_;
};
Point operator*(int x, const Point& p); // "left" multiplication by scalar
std::ostream& operator<<(std::ostream& os, const Point& p);
Provide an implementation of all functions, including those related to operator overloading. For an output stream os, points a and b, and an int value v:
os << a should output to os the coordinates x and y of a with the format (x,y) and (as usual) return os as a result (for chained calls using the << operator).
a = b should assign the coordinates of b to a and (as usual) the implementation of operator= should return *this (for chained assignments);
a += b should assign to a the sum of its coordinates with b and (as usual) the implementation of operator+= should return *this (for chained assignments);
a + b should return a point with the coordinates corresponding to the sum of a and b;
a * v and v * a should return a point with the coordinates of a both multiplied by v.
*/

#include <iostream>
using namespace std;

class Point {
public:
  Point() : x_(0), y_(0) {} // builds (0,0)
  Point(int x, int y) : x_(x), y_(y) {} // builds (x,y)
  Point(const Point& p) : x_(p.x_), y_(p.y_) {} // copy constructor
  
  int get_x() const { return x_; } // get x coordinate
  int get_y() const { return y_; } // get y coordinate
  
  Point& operator=(const Point& p) { // assignment operator
    if (this != &p) {
      x_ = p.x_;
      y_ = p.y_;
    }
    return *this;
  }
  
  Point operator+(const Point& p) const { // sum
    return Point(x_ + p.x_, y_ + p.y_);
  }
  
  Point& operator+=(const Point& p) { // composed assignment and sum
    x_ += p.x_;
    y_ += p.y_;
    return *this;
  }
  
  Point operator*(int v) const { // "right" multiplication by scalar
    return Point(x_ * v, y_ * v);
  }

  friend Point operator*(int x, const Point& p); // "left" multiplication by scalar
  friend ostream& operator<<(ostream& os, const Point& p);

private:
  int x_, y_;
};

Point operator*(int x, const Point& p) { // "left" multiplication by scalar
  return Point(p.x_ * x, p.y_ * x);
}

ostream& operator<<(ostream& os, const Point& p) {
  os << "(" << p.x_ << "," << p.y_ << ")";
  return os;
}

int main(){
    { Point a, b(1,2), c(b), d(3,4); 
  b = a;
  cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }
    return 0;

    { Point a, b(1,2), c(b), d(3,4); 
  c = b = a;
  cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }

  { Point a(1,2), b(3,4), c = a + b, d(5,6);
    b += d;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }

  { Point a(1,2), b(3,4), c = a * 2, d(5,6);
    b = 2 * d;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }

  { Point a(1,1), b(0,1), c(1,0), d(1,1);
    d += c += b += a += {1,2};
    d = 2 * d * 2;
    cout << a << ' ' << b << ' ' << c << ' ' << d << '\n'; }

  return 0;
}