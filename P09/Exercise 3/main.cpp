/*
A polygon is made up of a set of vertices. Develop the following 2 classes to deal with polygons:
Point: represents a point in 2D space with two integer attributes, x and y, which are the coordinates of the point.
Polygon: represents the set of vertices of the polygon as a vector of objects of type Point.
You must decide which member functions of each class must be implemented and their signatures from the calls of the public tests. Other auxiliary functions may be necessary (for example, for calculating the distance between 2 points).
For the users of class Polygon, the vertices are numbered starting with 1 (see the examples of usage of the member functions get_vertex and add_vertex in the tests).
The functions get_vertex and add_vertex have as first parameter the number of the vertex to get from or to add to the polygon.
For get_vertex this number must be in the range [1 .. total_number_of_vertices].
For add_vertex it must be in the range [1 .. total_number_of_vertices+1]; when a vertex is inserted in the middle of the set, the vertices that are after its position must be relocated to their new positions.
The perimeter of a polygon is the sum of the length of its sides, which connect the points in order, with the last point connecting to the first.
The show member function for Point’s must write the 2 coordinates between parenthesis and separated by a comma, for example: (3,1).
The show member function for Polygon’s must write the coordinates of the vertices consecutively, between brackets, for example: {(1,1)(2,3)(0,1)}.
The show member functions, both for Point and Polygon, must not write any end line character at the end of their output.
Use the const qualifier in member functions and parameters whenever you find it adequate.
The code must be written in separate files: Point.h and Polygon.h for the class declarations, and Point.cpp and Polygon.cpp, for the implementations.
In your local workspace, to compile a program in a file containing the tests, named for instance main.cpp, you should use the supplied Makefile and execute the following command in the Terminal:
make PROG=main CPP_FILES="Point.cpp Polygon.cpp main.cpp" HEADERS="Point.h Polygon.h"
*/

#include <iostream>
#include <iomanip>
#include "Polygon.h"
using namespace std;

int main(){
    { Point p1, p2(0, 1); 
  p1.show(); p2.show(); cout << '\n'; }

{ Polygon poly1;
  Point p1, p2(0, 1), p3(1, 0);
  Polygon poly2(vector<Point>{ p1, p2, p3 });
  poly1.show(); cout << " "; poly2.show(); cout << '\n'; }

{ Point p1, p2(0, 1), p3(1, 0);
  Polygon poly1(vector<Point>{ p1, p2, p3 });
  cout << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n'; }

{ Point p1, p2(0, 1), p3(1, 0);
  Polygon poly1(vector<Point>{ p1, p2, p3 });
  Point p;
  if (poly1.get_vertex(2, p)) { p.show(); cout << ' '; }
  else cout << "vertex not found! ";
  if (poly1.get_vertex(0, p)) { p.show(); cout << ' '; }
  else cout << "vertex not found! ";
  cout << '\n'; }

{ Point p1, p2(0, 1), p3(1, 0), p4(1, 1);
  Polygon poly1 = vector<Point>{ p1, p2, p3 };
  poly1.add_vertex(3, p4); 
  poly1.show(); 
  cout << ' ' << fixed << setprecision(3) << poly1.perimeter() << setprecision(0) << '\n'; }

    return 0;
}