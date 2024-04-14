/*
Consider a new definition of class Date, given in Date3.h, where the date is represented in a single data member (attribute) of string type, in the format "yyyymmdd" (ex: 20230401, for the 1st of April of 2023):
#include <iostream>
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
    bool is_valid() const;
    void write() const;

  private:
    // compute the number of days of month
    static int num_days(int year, int month);
    // attribute
    std::string yyyymmdd;
};
Rewrite the member functions of the class Date of problem 3, keeping their signature.
Note: the class implementation is changed without requiring changes in the code that uses it (encapsulation).
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Date3.h"
using namespace std;

int Date::get_year() const{
    return (yyyymmdd[0] - '0')*1000 + (yyyymmdd[1] - '0')*100 + (yyyymmdd[2] - '0')*10 + yyyymmdd[3] - '0';
}

int Date::get_month() const{
    return (yyyymmdd[4] - '0')*10 + yyyymmdd[5] - '0';
}

int Date::get_day() const {
    return (yyyymmdd[6] - '0')*10 + yyyymmdd[7] - '0';
}

int Date::num_days(int year, int month) {
    if(((year % 4 == 0) && !((year % 100 == 0) && !(year % 400 == 0))) && (month == 2)){                 
        return 29;                                                                                 
    }
    else if(!((year % 4 == 0) && !((year % 100 == 0) && !(year % 400 == 0))) && (month == 2)){
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
    int year = (*this).get_year();
    int month = (*this).get_month();
    int day = (*this).get_day();
    int number = num_days(year, month);                                                                     

    if((year <= 9999) && (year >= 1) && (month > 0) && (month < 13) && (day > 0) && (day <= number)){
        return true;
    }

    return false;
}


Date::Date(const std::string& year_month_day){ 
    int rec;
    string temp = "";
    bool flag = false;
    char var1, var2;
    int draw = 2;
    istringstream iss(year_month_day);

    if(iss >> rec){
        temp = std::to_string(rec);
        while(temp.size() < 4){
            temp = "0" + temp;
        }
        yyyymmdd = yyyymmdd + temp;
    }else{
        flag = true;
    }

    if(iss >> var1){
        draw--;
    }else{
        flag = true;
    }

    if(iss >> rec){
        temp = std::to_string(rec);
        while(temp.size() < 2){
            temp = "0" + temp;
        }
        yyyymmdd = yyyymmdd + temp;
    }else{
        flag = true;
    }

    if(iss >> var2){
        draw--;
    }else{
        flag = true;
    }

    if(iss >> rec){
        temp = std::to_string(rec);
        while(temp.size() < 2){
            temp = "0" + temp;
        }
        yyyymmdd = yyyymmdd + temp;
    }else{
        flag = true;
    }

    if((!((*this).is_valid())) || (var1 != '/') || (var2 != '/') || (flag == true)){
        yyyymmdd = "00000000";
    }
    
}

Date::Date(int year, int month, int day){
    string a(std::to_string(year));
    while(a.size() != 4){
        a = "0" + a;
    }

    string b = std::to_string(month);
    while(b.size() != 2){
        b = "0" + b;
    }

    string c = std::to_string(day);
    while(c.size() != 2){
        c = "0" + c;
    }

    yyyymmdd = a + b + c;

    if(!((*this).is_valid())){
        yyyymmdd = "00000000";
    }
}

Date::Date(){
    yyyymmdd = "00010101";
}

int main(){
    Date d1; d1.write(); cout << (d1.is_valid() ? "" : "-invalid") << endl;
    Date d2(2022, 4, 31); d2.write(); cout << (d2.is_valid() ? "" : "-invalid") << endl;
    Date d3("2ooo/2/28"); d3.write(); cout << (d3.is_valid() ? "" : "-invalid") << endl;
    Date d4("1900/1/1"); d4.write(); cout << (d4.is_valid() ? "" : "-invalid") << endl;
    Date d5("2022#12#31"); d5.write(); cout << (d5.is_valid() ? "" : "-invalid") << endl;
    return 0;
}