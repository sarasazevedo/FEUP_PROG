/*
Consider a class named MovingAverage in header MovingAverage.h with the following interface:
class MovingAverage {
public:
  MovingAverage(std::size_t n); 
  void update(double value);
  double get() const;
private:
  std::size_t n_;
  std::list<double> values_;
};
As the name indicates, the purpose of the class is to allow the computation of moving averages:
The values calculated will be the average of (at most) n_ values, where the initial value for n_ is specified using the constructor.
A call to update(v) sets the most recent value to consider for the moving average, adding v to the values_ list. If there are already n_ values stored, the least recent value must be discarded (removed from values_).
A call to get() returns the value of the moving average considering the currently stored values.
Provide the implementation of the class in a file called MovingAverage.cpp.
Hint: consider the use of pop_front() and push_back() to manipulate the list.
*/

#include "MovingAverage.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

MovingAverage::MovingAverage(std::size_t n): n_(n) {}

void MovingAverage::update(double value) {
    if(values_.size() >= n_)
        values_.pop_front();
    values_.push_back(value);
}

double MovingAverage::get() const {
    double sum = 0;
    double result = 0;
    for(auto it = values_.begin(); it != values_.end(); ++it) {
        sum += *it;
    }
    result = sum / values_.size();
    return result;
}

int main(){
    { MovingAverage ma(1); 
  const MovingAverage& r = ma;
  ma.update(1.0); 
  cout << fixed << setprecision(2) << r.get() << '\n'; }

{ MovingAverage ma(1); 
  double a[] { 1.2, 3.4, 5.0 };
  for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
  }
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }

{ MovingAverage ma(2); 
  double a[] { 1.2, 3.4, 5.0 };
  for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
  }
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }

{ MovingAverage ma(3); 
  double a[] { 1.2, 3.4, 5.0 };
  for (double x : a) { 
    ma.update(x); 
    cout << fixed << setprecision(2) <<  ma.get() << ' ';
  }
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }

{ MovingAverage ma(4); 
  double a[] { 0.1, 1.2, -1.2, 3.4, 5.6, -2.3, 3.7 };
  for (double x : a) ma.update(x);
  cout << fixed << setprecision(2) <<  ma.get() << '\n'; }

    return 0;
}