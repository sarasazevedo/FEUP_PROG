/*
Write a C++ function void split(const string& s, vector<string>& v) that places in vector v all strings that occur in s separated by one or more spaces.
Hints: The class string member functions find and substr may be useful:
s.find(' ', pos) searches for the space character in s starting from position pos — it returns the position of the first space found, or the constant string::npos if the space character is not found;
s.substr(pos, len) produces the substring of s that starts at position pos and has len characters.
To run the provided tests, you need to include a header file named print_string.h (download) that contains an utility function print for printing string values.
*/

#include <iostream>
#include "print_string.h"
using namespace std;

void split(const string& s, vector<string>& v){
    size_t pos = 0;
    size_t newPos = 0;
    while(pos < s.length()){
        newPos = s.find(' ', pos);
        if(newPos == pos){
            pos++;
            continue;
        }
        if(newPos == string::npos){
            newPos = s.length();
        }
        v.push_back(s.substr(pos, newPos - pos));
        pos = newPos;
    }
}

int main(){
    { string s = "C++ LEIC FCUP FEUP";
  vector<string> v;
  split(s, v);
  print(v); }
    return 0;
}