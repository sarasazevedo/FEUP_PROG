/*
Consider the following interface of a class named Date given in header Date.h:
class Date {
public:
  Date(int year = 1, int month = 1, int day = 1) 
     : year_(year), month_(month), day_(day) {}
  int getYear() const { return year_; }
  int getMonth() const { return month_; }
  int getDay() const { return day_; }
private:
  int year_, month_, day_;
};
Overload the implementation of the operators necessary for sorting and showing on the screen the contents of a vector<Date> dates, using the following statements:
sort(dates.begin(), dates.end());
for (const auto& d : dates) cout << d << endl;
The sorting of the dates must be done in ascending order (older dates come first).
Note: the year, month and day must always be written with 4, 2 and 2 digits, respectively, filling each number with zeros, on the left side, when necessary, and must be separated by ‘/’ (see test examples).
*/

#include "Date.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

bool operator<(const Date& date1, const Date& date2) {
    if (date1.getYear() > date2.getYear()) {
        return false;
    }
    if(date1.getYear() == date2.getYear() && date1.getMonth() > date2.getMonth()){
        return false;
    }
    if(date1.getYear() == date2.getYear() && date1.getMonth() == date2.getMonth() && date1.getDay() > date2.getDay()){
        return false;
    }     
    return true;   
}


ostream& operator<<(ostream& os, const Date& date) {
    int year = to_string(date.getYear()).length();
    int month = to_string(date.getMonth()).length();
    int day = to_string(date.getDay()).length();

    os << string(4 - year, '0') << date.getYear() << '/';
    os << string(2 - month, '0') << date.getMonth() << '/';
    os << string(2 - day, '0') << date.getDay();
    return os;
}

int main() {
    { vector<Date> dates = { {2023,11,15}, {2021,12,8}, {2023,11,14} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }

{ vector<Date> dates = { {2000,1,1}, {2000,2,1}, {2000,12,31} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }

{ vector<Date> dates = { {2001,10,31}, {2005,10,31}, {2010,10,31}, {1992,10,31} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }

{ vector<Date> dates = { {2023,4,28}, {999,1,1} };
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }
{ vector<Date> dates = { {2075,2,2}, {2077,10,10}, {2075,2,2}};
  sort(dates.begin(), dates.end());
  for (const auto& d : dates) cout << d << " ";
  cout << '\n'; }
  return 0;
}