/*
Consider the code given in Date2.h containing the definition of class Date :
#include <iostream>
#include <iomanip>
#include <string>

class Date {
  public:
    // constructors
    Date();
    Date(int year, int month, int day);
    Date(const std::string& year_month_day);
    // accessors
    int get_year() const;
    int get_month() const;
    int get_day() const;
    // other methods
    bool is_valid() const; // tests date validity
    void write() const;    // writes the date as "yyyy/mm/dd"
  private:
    // attributes
    int year;
    int month;
    int day;
    // compute the number of days of month
    static int num_days(int year, int month);
};
Write the C++ code for the member functions of the class not yet implemented, observing the following requirements:
The default constructor must build the date 1/1/1;
When the parameters of the other constructors constitute an invalid date, the values of the attributes must take the value zero (consider that a date is valid for years between 1 and 9999);
The parameter of the constructor Date(const std::string& year_month_day) must be in the format: y/m/d, where y, m and d can have a variable number of digits (examples of valid dates: "2022/04/01", "2022/4/13",  "899/1/1"); the separator must always be the character '/';
The member function is_valid() returns false if one of the attributes is equal to zero.
Hint: use a istringstream object to decompose the string year_month_day.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Date2.h"
using namespace std;


Date::Date(const std::string& year_month_day){
    int rec;
    bool flag = false;
    char var1, var2;
    istringstream iss(year_month_day);

    if(iss >> rec){
        year = rec;
    }
    else{
        flag = true;
    }
    iss >> var1;

    if(iss >> rec){
        month = rec;
    }
    else{
        flag = true;
    }
    iss >> var2;

    if(iss >> rec){
        day = rec;
    }
    else{
        flag = true;
    }

    if((!((*this).is_valid())) || (var1 != '/') || (var2 != '/') || (flag == true)){
        year = 0;
        month = 0;
        day = 0;
    }
    
}

int Date::get_year() const{
    return year;
}

int Date::get_month() const{
    return month;
}

int Date::get_day() const {
    return day;
}

Date::Date(int year, int month, int day){
    (*this).year = year;
    (*this).day = day;
    (*this).month = month;

    if(!((*this).is_valid())){
        (*this).year = 0;
        (*this).month = 0;
        (*this).day = 0;
    }
}

Date::Date() : year(1), month(1), day(1) {
}

int Date::num_days(int year, int month) {
    if(((year%4 == 0) && !((year%100 == 0) && !(year%400 == 0))) && (month == 2)){                 
        return 29;                                                                                 
    }
    else if(!((year%4 == 0) && !((year%100 == 0) && !(year%400 == 0))) && (month == 2)){
        return 28;
    }
    else if((month == 11) || (month == 4) || (month == 6) || (month == 9)){
        return 30;
    }
    else{
        return 31;
    }
}

bool Date::is_valid() const{
    int number = num_days(year, month);                                                                                                                                      
    if((year <= 9999) && (year >= 1) && (month > 0) && (month < 13) && (day > 0) && (day <= number)){
        return true;
    }

    return false;
}

int main() {
    Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
    Date d2(2022, 4, 31); d2.write(); cout << (d2.is_valid() ? "" : "-invalid") << endl;
    Date d3("2ooo/2/28"); d3.write(); cout << (d3.is_valid() ? "" : "-invalid") << endl;
    Date d4("1900/1/1"); d4.write(); cout << (d4.is_valid() ? "" : "-invalid") << endl;
    Date d5("2022#12#31"); d5.write(); cout << (d5.is_valid() ? "" : "-invalid") << endl;
    return 0;
}
