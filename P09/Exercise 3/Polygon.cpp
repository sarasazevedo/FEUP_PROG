#include "Polygon.h"
using namespace std;

Polygon::Polygon(){
	this->points = {}; 
}

Polygon::Polygon(vector<Point> points){
	this->points = points;
}

int Polygon::get_number_vertices() const{
	return points.size();
}

bool Polygon::get_vertex(int index,Point& p){
	if (index >= 1 && index <= get_number_vertices()) { 
        p = points[index - 1];
        return true;
	}else{
        return false;
    }
}

float Polygon::perimeter(){
	float result = points[0].distance(points[get_number_vertices()-1]);
	for(int i = 0; i < get_number_vertices() - 1; i++){
		result += points[i].distance(points[i+1]);
	}
	return result;
}

void Polygon::show() const{
	cout << "{";
	for(Point p: points){	
		p.show();
	}
	cout << "}";
}

bool Polygon::add_vertex(int index,Point& p ){
	if(index >= 1 && index <= get_number_vertices() + 1){
		points.insert(points.begin()+(index-1), p);
		return true;
	}
	return false;
}