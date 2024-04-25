#ifndef ERASMUSSTUDENT_H
#define ERASMUSSTUDENT_H
#include "Student.h"

class ErasmusStudent : public Student {
    public:
        ErasmusStudent(int id, const string& name, const string& course, const string& country) : Student(id, name, course), country_(country) {}
        const string& country() const { return country_; }
        string to_string() const override { return Student::to_string() + "/" + country_;}

    private:
        string country_;
    };

#endif 
