/*
Consider that you want to develop an application for drawing figures, for simplicity only rectangles and circles.
The application must use three classes, Figure, FRectangle and FCircle, such that:
Figure is an abstract class whose definition is given in Figure.h
Classes FRectangle and FCircle must be derived from Figure and be defined in header files FRectangle.h and FCircle.h respectively
The data members of class Figure are the coordinates of the center of the figure x_center_, y_center_
Define classes FRectangle and FCircle, taking into account that:
FRectangle has two additional data members, the width and height of the rectangle width_, height_
FCircle has one additional data member, the radius of the circle radius_
Member functions draw() do not effectively draws the figures on the screen, they are just “stubs” that write a message indicating the type (R or C), the attributes of the rectangle or circle (coordinates of the center) and, for the rectangle, the length of the sides, for the circle, its radius. 
For example:
R(10,20)(200,100) — rectangle centered at (x=10,y=20) with (width=200, height=100)
C(-10,0)(50) — circle rectangle centered at (x=-10,y=0) with (radius=50)
*/

#include <iostream>
#include "FRectangle.h"
#include "FCircle.h"
#include "Figure.h"
#include <vector>
using namespace std;

int main(){
    { FRectangle r(10, 10, 200, 100);
    r.draw(); cout << endl; }

    { FCircle c (20, 20, 500);
    c.draw(); cout << endl; }

    { FRectangle * r = new FRectangle(10, 10, 200, 100);
    r->draw(); cout << endl; delete r; }

    { vector<Figure*> figures = {
    new FRectangle(10,10,200,100),
    new FCircle(20,20,500),
    new FRectangle(-10,-20,150,250),
    new FCircle(0,0,100) };
    for (const auto& f : figures) f->draw(); 
    cout << endl; for (const auto& f : figures) delete f; }

    { vector<Figure*> figures = {
    new FRectangle(-10,-10,5,15),
    new FRectangle(0,0,20,10),
    new FCircle(5,0,25) };
    for (const auto& f : figures) f->draw(); 
    cout << endl; for (const auto& f : figures) delete f; }
    
    return 0;
}