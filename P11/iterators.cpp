/*
Write the C++ code for two template functions to_string and replace, declared as:
template <typename Itr> 
string to_string(Itr start, Itr end)

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b)
such that:
to_string(start, end) takes two iterators start and end associated with the same container and yields a string representation of the form "[ elem_1 elem_2 ... elem_n ]" of all elements of the container between start and end, including start but excluding end; and
replace(start, end, a, b) traverses all elements between start and end, including start but excluding end, replacing values of a by values of b, and returns the number of elements that were replaced.
Hints:
Consider the use of the following iterator operators: ++, != and *.
Use an ostringstream object in to_string() to build the string result.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

template <typename Itr> 
string to_string(Itr start, Itr end){
    ostringstream os;
    os << "[ ";
    for (auto i = start; i != end; i++) {
        os << *i << " ";
    }
    os << "]";
    return os.str();
}

template <typename Itr, typename T> 
int replace(Itr start, Itr end, const T& a, const T& b){
    int count = 0;
    for (auto i = start; i != end; i++) {
        if (*i == a) {
            *i = b;
            count++;
        }
    }
    return count;
}

int main(){
    { vector<int> v;
  cout << ::replace(v.begin(), v.end(), 0, 1) << ' '
       << to_string(v.cbegin(), v.cend()) << '\n'; }

{ vector<int> v { 1, 2, 3, 3, 4 };
  cout << ::replace(v.begin(), v.end(), 3, 0) << ' '
       << to_string(v.cbegin(), v.cend()) << '\n'; }

{ vector<int> v { 5, 1, 2, 3, 4, 5 };
  cout << ::replace(v.begin() + 1, v.end() - 1, 5, 0) << ' '
       << to_string(v.cbegin(), v.cend()) << '\n'; }

{ list<string> l { "C++", "Java", "C++", "Python", "Rust", "C" } ;
  cout << ::replace(l.begin(), l.end(), string("C++"), string("Rust")) << ' '
       << ::replace(l.begin(), l.end(), string("C"), string("Rust")) << ' '
       << to_string(l.cbegin(), l.cend()) << '\n'; }

{ string s = "Hello world";
  cout << ::replace(s.begin(), s.end(), 'l', 'L') << ' '
       << to_string(s.cbegin(), s.cend()) << ' ' 
       << ::replace(s.rbegin(), s.rend(), 'o', 'O') << ' '
       << to_string(s.crbegin(), s.crend()) <<  ' '
       << to_string(s.cbegin(), s.cend()) << '\n'; }
    return 0;
}