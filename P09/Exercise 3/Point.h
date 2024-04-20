#ifndef POINT_H 
#define POINT_H

#include <iostream>
using namespace std;

class Point{
public:
	Point(int x,int y);
	Point();
	float distance(const Point& point);
	int get_x() const ;
	int get_y() const ;
	void show() const {cout << "(" << x << "," << y << ")";}
private:
	int x;
	int y;
};

#endif