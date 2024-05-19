/*
Submit a file named highest.cpp containing the C++ code for function student_highest_avg, declared as:
string student_highest_avg(map<string, list<int>> m);
The function takes as input a map where the keys are student names, and the values are the lists of grades of each student, and it should return the name of the student with the highest average grade.
Note that the average grades should be computed as floating point numbers. Moreover, you can assume the following three conditions: (1) all grades are in the range [0..20]
; (2) each student has at least one associated grade, and; (3) exactly one student has the highest average.
*/

#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

string student_highest_avg(map<string, list<int>> m) {
    string student;
    double max_avg = 0.0;

    for (const auto& pair : m) {
        const string& name = pair.first;
        const list<int>& grades = pair.second;
        double sum = 0.0;
        for (int grade : grades) {
            sum += grade;
        }
        double avg = sum / grades.size();
        if (avg > max_avg) {
            max_avg = avg;
            student = name;
        }
    }

    return student;
}

int main(){
    { map<string, list<int>> m1 = {
      {"Jerry", {10, 20, 15}}};
  cout << student_highest_avg(m1) << endl; }

{ map<string, list<int>> m2 = {
      {"Elaine", {15, 18, 14, 16}}, {"Newman", {18, 12, 19}}};
  cout << student_highest_avg(m2) << endl; }

{ map<string, list<int>> m3 = {
      {"Whatley", {10, 10}}, {"Kramer", {11, 12, 14}}, {"Cosmo", { 15, 10, 13}}};
  cout << student_highest_avg(m3) << endl; }

{ map<string, list<int>> m4 = {
      {"Costanza", {0, 11}}, {"Frank", {8, 12}}};
  cout << student_highest_avg(m4) << endl; }

{ map<string, list<int>> m5 = {
      {"Frank", {10, 15}}, {"Costanza", {10, 14}} };
  cout << student_highest_avg(m5) << endl; }
    return 0;
}