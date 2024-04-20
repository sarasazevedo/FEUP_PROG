/*
Consider the classes Date and Person whose declarations are given in Date.h and Person.h.
In the file named p2_main.cpp, write a C++ function that takes as input parameters a list of Person objects stored into a vector and a Date object, and shows on the screen the name and birthdate of all the persons that were born before the given date. The signature of the function is:
void born_before(const vector<Person>& persons, const Date& date)
Download the class declarations Date.h and Person.h and implement the code of the classes using the separate compilation principle, that is, with the definition of each class in a .h file and the implementation of its member functions in a corresponding .cpp file.
In your local workspace, to compile a program in a file named p2_main.cpp, you should use the supplied Makefile and execute the following command in the terminal:
make PROG=p2_main CPP_FILES="Date.cpp Person.cpp p2_main.cpp" HEADERS="Date.h Person.h"
You must submit three files: Date.cpp, Person.cpp and p2_main.cpp.
*/

#include <iostream>
#include <vector>
#include "Date.h"
#include "Person.h"
using namespace std;

void born_before(const vector<Person>& persons, const Date& date){
    Person c_person;
    Date c_birthdate;
    date.show();
    cout << ": ";
    for(unsigned long i = 0; i < persons.size(); i++){
        c_person = persons.at(i);
        c_birthdate = c_person.get_birth_date();
        if(c_birthdate.is_before(date)){
            c_person.show();
            cout << " ";
        }
    }
}

int main(){
    born_before({ {"Ana",{2000,4,5}}, {"Rui",{1999,5,11}}, {"Susana",{1999,5,13}}, {"Pedro",{2010,2,10}} }, {2000,1,1});
    cout << endl;
    born_before({ {"Rui",{2009,4,9}}, {"Susana",{1997,6,19}}, {"Pedro",{2018,3,10}} }, {2019,12,31});
    cout << endl;
    born_before({ {"Ana",{1999,5,12}}, {"Rui",{1960,3,21}}, {"Susana",{1999,7,25}}, {"Pedro",{1999,7,31}} }, {1970,1,1});
    cout << endl;
    born_before({ {"Ana",{2001,7,15}}, {"Susana",{2019,8,12}}, {"Pedro",{2000,5,8}} }, {2001,1,1});
    cout << endl;
    born_before({ {"Pedro",{2000,11,7}} }, {2001,1,1}); 
    return 0;
}