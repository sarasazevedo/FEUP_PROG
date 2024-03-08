/*
Consider types time_of_day and interval to represent the time of day with a precision of minutes, and time intervals defined by start and end times, as follows:

struct time_of_day {
  unsigned char h; // Hours [0,23]
  unsigned char m; // Minutes [0,59]
};
struct interval {
  time_of_day start; // Start time
  time_of_day end;   // End time
};

Consider that an interval value il includes all times that are equal to or later than il.start and (strictly) earlier than il.end. For instance, if il.start = {12, 30} (representing time 12:30) and il.end = {14, 30} (14:30), then {12, 30} and {12, 31} are part of the interval but {14, 30} and {14, 31} are not.

Write a C++ function interval intersection(interval a, interval b) to compute the intersection of intervals. When the intersection is empty, the function should return the interval with the start time and the end time both equal to { 0, 0 }.

In your code you should include header file interval.h (you need to download the file) that contains the declaration of the above function and the time_of_day and interval types, along with support for printing interval values using cout (used in tests).

Hint: it may be convenient to define an auxiliary function to check if a < b for times a and b represented by time_of_day.
*/

#include "interval.h"
#include <iostream>
using namespace std;

bool less_than(time_of_day a, time_of_day b){
    if (a.h==b.h && a.m>b.m)
        return false;    
    if (a.h>b.h)
        return false;    
    return true;    
}

interval intersection(interval a, interval b){
    interval result = {{00,00}, {00,00}};
    if (less_than(a.end, b.start) || less_than(b.end, a.start)) {
        return result;
    } else {
        if (less_than(a.start, b.start)) {
            result.start = b.start;
            if (less_than(a.end, b.end)) {
                result.end = a.end;
            } else {
                result.end = b.end;
            }
        } else {
            result.start = a.start;
            if (less_than(b.end, a.end)) {
                result.end = b.end;
            } else {
                result.end = a.end;
            }
        }
    }
    return result;
}

int main(){
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                        { { 17, 30 }, { 18, 30 } } ) << '\n';
    cout << intersection( { { 12, 30 }, { 14, 30 } },
                      { { 14, 30 }, { 18, 30 } } ) << '\n';
    cout << intersection( { { 12, 30 }, { 14, 31 } },
                      { { 14, 30 }, { 18, 30 } } ) << '\n';
                      cout << intersection( { { 14, 30 }, { 15, 59 } },
                      { { 11, 30 }, { 14, 31 } } ) << '\n';
    cout << intersection( { {  4, 30 }, {  7, 59 } },
                      { {  4,  0 }, {  7, 29 } } ) << '\n';
    cout << intersection( { { 23,  0 }, { 23, 58 } },
                      { { 22, 45 }, { 23, 59 } } ) << '\n';
    cout << intersection( { { 17,  0 }, { 19,  0 } },
                      { { 15,  0 }, { 17,  0 } } ) << '\n';
    return 0;
}