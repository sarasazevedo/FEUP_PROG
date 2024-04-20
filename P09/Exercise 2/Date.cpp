#include "Date.h"

Date::Date(){
   year_ = 1;
   month_ = 1;
   day_ = 1;
}

Date::Date(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
}

bool Date::is_before(const Date &date) const{
    if(this->year_ < date.year_){
        return true;
    } else if(this->year_ == date.year_){
        if(this->month_ < date.month_){
            return true;
        }else if(this -> month_ == date.month_ && this -> day_ < date.day_){
            return true;
        }
    }
    return false;
}