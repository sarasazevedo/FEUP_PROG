/*
Write a C++ function void advance(int delta, int& d, int& m, int& y) to update a date, implicitly defined by d/m/y, by delta days.
You can assume that delta is greater or equal to 0 and that the values of d, m, and y define a valid date when the function is called. On exit, d, m, and y should represent an elapse of delta days over the original date.
Note that you should account for leap years: y is a leap year (“bissexto'') if it is divisible by 4, except when it is divisible by 100 but not 400 (e.g., 2004 and 2000 are leap years, but 2100 is not).
*/

#include <iostream>
using namespace std;

bool isLeap(int y) {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        return true;
    }
    else {
        return false;
    }
}

int lastDayOfTheMonth(int m, int y){
    int result = 0;
    switch (m) {
        case 2:
            result = isLeap(y) ? 29:28; 
            break;
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            result=31; 
            break;
        default:
            result=30;
            break;
    }
    return result;
}


void advance(int delta, int& d, int& m, int& y){
    while(delta > 0){
        d++;
        delta--;
        if(d > lastDayOfTheMonth(m,y)){
            d = 1;
            m++;
            if(m>12){
                m = 1;
                y++;
            }
        }
    }
}

int main(){
    int d = 2, m = 6, y = 2022; 
  advance(31, d, m, y); 
  cout << d << ' ' << m << ' ' << y << '\n';
  return 0;
}