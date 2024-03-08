/*
Consider a type for the time of day expressed in hours and minutes defined as:

struct time_of_day {
  unsigned char h; // Hours [0,23]
  unsigned char m; // Minutes [0,59]
};

Write a C++ function time_of_day tick(time_of_day t) such that the result of tick(t) represents the elapse of one minute over a given t.

In your code you should include header file time_of_day.h (you need to download the file) that contains the declaration of the above function and the time_of_day type, along with support for printing time_of_day values using cout (used in tests).
*/

#include "time_of_day.h"
#include <iostream>
using namespace std;

time_of_day tick(time_of_day t){
    t.m++;
    if (t.m == 60){
        t.m = 0;
        t.h = (t.h + 1) % 24;
    }
    return t;
}

int main(){
    cout << tick({ 12, 59 }) << '\n';
    cout << tick(tick(tick({ 23, 59 }))) << '\n';
    return 0;
}