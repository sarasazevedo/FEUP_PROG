#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "Point.h"
using namespace std;

class Polygon{
public:
	Polygon();
	Polygon(vector<Point> points);
	bool get_vertex(int index,Point& p);
	bool add_vertex(int index,Point& p);
	float perimeter();
	void show() const;
private:
	vector<Point> points;
	int get_number_vertices() const;
};

#endif