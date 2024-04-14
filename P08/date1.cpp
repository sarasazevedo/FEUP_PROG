/*
Consider the code given in Date1.h containing the definition of class Date:
// A simple class Date definition
class Date {
  public:
    Date();                             // Default constructor
    Date(int year, int month, int day); // Constructor with parameters
    int get_year() const;               // Year accessor
    int get_month() const;              // Month accessor
    int get_day() const;                // Day accessor
    void write() const;                 // Writes the date as "yyyy/mm/dd"
  private:
    int year;   // Private attribute year
    int month;  // Private attribute month
    int day;    // Private attribute day
};
Write the C++ code for all member functions not yet implemented:
The default constructor must build the date 1/1/1;
For the constructor with parameters, assume that the supplied arguments always define a valid date and that the year value is between 1 and 9999;
Write also the code of the accessors that return the private attributes of the class.
Finally, write a function (not part of class Date), bool is_before(const Date& date1, const Date& date2) that returns true if date1 is before date2, and false otherwise.
*/

#include <iostream>
#include "Date1.h"
using namespace std;

Date::Date() : year(1), month(1), day(1) {
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

bool is_before(const Date& date1, const Date& date2) {
    if (date1.get_year() < date2.get_year())
        return true;
    else if (date1.get_year() > date2.get_year())
        return false;
    else {
        if (date1.get_month() < date2.get_month())
            return true;
        else if (date1.get_month() > date2.get_month())
            return false;
        else {
            if (date1.get_day() < date2.get_day())
                return true;
            else
                return false;
        }
    }
}

int main() {
    Date d1; d1.write(); cout << '\n';
    Date d2(2020, 2, 29); d2.write(); cout << '\n';
    Date d3(1925, 4, 30); d3.write(); cout << '\n';
    Date d4, d5(2022,4,29); d4.write(); cout << '-' << boolalpha << is_before(d4, d5) << '\n';
    Date d6(2023,10,31), d7(2022, 4, 29); d6.write(); cout << '-' << boolalpha << is_before(d6, d7) << '\n';
    return 0;
}