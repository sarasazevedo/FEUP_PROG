#include "Person.h"
using namespace std;

Person::Person(){
    name_ = "NO_NAME";
    Date d;
    birth_date_ = d;
}

Person::Person(const string &name, const Date &birth_date){
    name_ = name;
    birth_date_ = birth_date;
}

string Person::get_name() const{
    return this -> name_;
}

Date Person::get_birth_date() const{
    return this -> birth_date_;
}