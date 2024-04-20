#include "Point.h"
#include <cmath>
using namespace std;

Point::Point(){
	this->x = 0;
	this->y = 0;
}

Point::Point(int x,int y){
	this->x = x;
	this->y = y;
}

int Point::get_x() const{
	return this->x;
}

int Point::get_y() const{
	return this->y;
}

float Point::distance(const Point& point){
	float final_x, final_y, result;
	final_x = (x - point.get_x())*(x - point.get_x());
	final_y = (y - point.get_y())*(y - point.get_y());
	result = sqrt(final_x + final_y);
	return result;
}