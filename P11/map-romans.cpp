/*
Write a C++ function unsigned roman_to_arab(const string& roman), that, given a valid roman numeral in the standard form (as a string), returns its corresponding decimal value (as an unsigned integer).
Use the following vector to map each individual roman symbol to its decimal value:
vector<pair<char, unsigned>> roman_to_int = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};
Note: a pair<F,S> object is a template struct to represent pairs: it has fields first of type F and second of type S (std::pair).
*/

#include <iostream>
#include <vector>
using namespace std;

unsigned roman_to_arab(const string& roman){
    vector<pair<char, unsigned>> roman_to_int = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    unsigned result = 0;
    unsigned prev_val = 0;
    for (int i = roman.size() - 1; i >= 0; i--) {
        for (auto& p : roman_to_int) {
            if (roman[i] == p.first) {
                if (p.second >= prev_val) {
                    result += p.second;
                } else {
                    result -= p.second;
                }
                prev_val = p.second;
                break;
            }
        }
    }
    return result;
}

int main(){
    { string r = "XV"; cout << roman_to_arab(r) << '\n'; }

    { string r = "LXXXIV"; cout << roman_to_arab(r) << '\n'; }

    { string r = "CMLXIV"; cout << roman_to_arab(r) << '\n'; }

    { string r = "MMMCMXCIX"; cout << roman_to_arab(r) << '\n'; }

    { string r = "MMMDCCCLXXXVIII"; cout << roman_to_arab(r) << '\n'; }

    return 0;
}