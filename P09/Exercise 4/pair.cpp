/*
Write a C++ class template Pair that provides a way to store two heterogeneous objects as a single unit.
In the definition of the class template, include two data members, let us call them first_ and second_, that can be of different types, and the following member functions a constructor with parameters;
get_first() and get_second() that return the first_ and the second_ data members, respectively;
show() that shows the two elements of the pair, inside brackets and separated by a comma; for example: {1,Porto}, or {A,65}, or {2000,366}, depending on the type of elements of the pair; consider that the elements of the pair are either of a simple type (int, double, ...) or a C++-string.
Consider now that you want to store a set of pairs into a vector<Pair<string,int>>, representing different type of data, for example the name and age of a set of persons, the name and grade of a set of students, or the name and population of a set of cities.
Write two functions, external to class Pair, sort_by_first() and sort_by_second(), that can sort the elements of a vector<Pair<string,int>> in non-descending order, taking into account the values of the first_ or the second_ attribute of the pairs, respectively.
For example, if v is a vector<Pair<string,int>> that represents a set of names and ages of persons, the call sort_by_second(v) should order the elements of v by non-descending age.
Write also the function show(), external to class Pair, that shows on the screen the contents of a vector<Pair<string,int>>. See examples of the output of this function in the public tests.
Hint: the STL algorithm sort can be used to sort the elements of a vector v using the call sort(v.begin(), v.end(), compare_func) where compare_func is a function that, in this case, takes two arguments of type Pair<string,int> and returns true if the first argument is less than the second argument (i.e. it is ordered before).
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    Pair(T1 first, T2 second) : first_(first), second_(second) {}
    T1 get_first() const{ return first_; }
    T2 get_second() const{ return second_; }
    void show() const{ cout << "{" << first_ << "," << second_ << "}";}
private:
    T1 first_;
    T2 second_;
};

template<typename T1, typename T2>
void sort_by_first(vector<Pair<T1, T2>>& v) {
    sort(v.begin(), v.end(), [](const Pair<T1, T2>& a, const Pair<T1, T2>& b) {
        return a.get_first() < b.get_first();
    });
}

template<typename T1, typename T2>
void sort_by_second(vector<Pair<T1, T2>>& v) {
    sort(v.begin(), v.end(), [](const Pair<T1, T2>& a, const Pair<T1, T2>& b) {
        return a.get_second() < b.get_second();
    });
}

template<typename T1, typename T2>
void show(const vector<Pair<T1, T2>>& v) {
    cout << "{";
    for (const auto& pair : v) {
        pair.show();
    }
    cout << "}" << endl;
}

int main(){
    { vector<Pair<string, int>> persons = { {"Maria",17},{"Ana",21},{"Pedro",19} };
  sort_by_first(persons);
  show(persons); cout << '\n'; }
  { vector<Pair<string, int>> persons = { {"Ana",19},{"Rui",16} };
  sort_by_second(persons);
  show(persons); cout << '\n'; }
{ vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
  sort_by_first(teams);
  show(teams); cout << '\n'; }
{ vector<Pair<string, int>> teams = { {"Porto",91},{"Benfica",74},{"Sporting",85} };
  sort_by_second(teams);
  show(teams); cout << '\n'; }
{ vector<Pair<string, int>> calories = { {"orange",37},{"egg",146},{"apple",56},{"yogurt",51} };
  sort_by_second(calories);
  show(calories); cout << '\n'; }
    return 0;
}