/*
Write a C++ template function
  template <typename T>
  void normalise(vector<T>& v, const T& min, const T& max)
such that a call to normalise(v, min, max) “normalises” all values x contained in vector v as follows:
If x < min then x should be replaced by min;
If x > max then x should be replaced by max; and
Otherwise the value of x should be unchanged.
To run the provided tests, you need to include a header file named print_vector.h (download) that contains an utility function print for printing vector with elements of type T.
*/

#include <iostream>
#include <string>
#include <vector>
#include "print_vector.h"
using namespace std;

template <typename T>
void normalise(vector<T>& v, const T& min, const T& max){
    for (size_t i = 0; i < v.size(); i++){
       if(v[i]<min){
        v[i]=min;
       } 
       else if(v[i]>max){
        v[i]=max;
       }
    }
}

int main(){
    { vector<int> v { 1, 2, 3, 4, 5 }; normalise(v, 3, 4); print(v); }
    return 0;
}
