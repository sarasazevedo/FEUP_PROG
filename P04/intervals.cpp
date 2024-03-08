/*
Consider types time_of_day and interval to represent the time of day with a precision of minutes, and time intervals defined by start and end times, as follows:

struct time_of_day {
  unsigned char h; // hours
  unsigned char m; // minutes
};
struct interval {
  time_of_day start; // start time
  time_of_day end;   // end time
};
Consider that an interval value il includes all times that are equal to or later than il.start and (strictly) earlier than il.end. For instance, if il.start = {12, 30} (representing time 12:30) and il.end = {14, 30} (14:30), then {12, 30} and {12, 31} are part of the interval but {14, 30} and {14, 31} are not.

Write a C++ function
int search_intervals(time_of_day t, const interval a[], int n, interval& u)
that searches for all n intervals stored in array a, and:

If there are no intervals that contain t, then the function assigns u with { t, t } and returns 0.
If there are intervals that contain t, it assigns u to the union of all these intervals and returns the total duration of u in minutes.
In your code you should include header file interval.h (you need to download the file) that contains the time_of_day and interval types, along with support for printing interval values using cout (used in tests).
*/

#include <iostream>
#include "interval.h"
using namespace std;

int search_intervals(time_of_day t, const interval a[], int n, interval& u){
    bool found = false;
    time_of_day earliest = {23, 59}; 
    time_of_day latest = {0, 0};  
    
    for (int i = 0; i < n; i++) {
        if (t.h > a[i].start.h || (t.h == a[i].start.h && t.m >= a[i].start.m)) {
            if (t.h < a[i].end.h || (t.h == a[i].end.h && t.m < a[i].end.m)) {
                found = true;
                if (a[i].start.h < earliest.h || (a[i].start.h == earliest.h && a[i].start.m < earliest.m)) {
                    earliest = a[i].start;
                }
                if (a[i].end.h > latest.h || (a[i].end.h == latest.h && a[i].end.m > latest.m)) {
                    latest = a[i].end;
                }
            }
        }
    }
    
    if (!found) {
        u.start = t;
        u.end = t;
        return 0;
    } else {
        u.start = earliest;
        u.end = latest;
        return (latest.h - earliest.h) * 60 + (latest.m - earliest.m);
    }
}


int main(){
    { const int n = 1;
  const time_of_day t = { 13, 00 };
  const interval a[n] { { { 12, 30 }, { 14, 30 } } };
  interval u;
  int d = search_intervals(t, a, n, u);
  cout << d << ' ' << u << '\n'; }
    return 0;
}