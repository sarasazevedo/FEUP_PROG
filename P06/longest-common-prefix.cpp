/*
Write a C++ function string longest_prefix(const vector<string>& v) that, given a vector v of strings, returns the longest common prefix to all of the strings.
For example, if v contains "apple", "apply", "ape", and "april", then the longest common prefix is "ap".
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longest_prefix(const vector<string>& v){
    if (v.empty()){
        return "";
    }
    else if (v.size() == 1){
        return v[0];
    }
    
    string common = "";
    long unsigned int letter = 0;
    char first_letter = v[0][0];
    while (true){
        for (size_t i = 0; i < v.size();i++){
            if (letter >= v[i].size() || v[i][letter] != first_letter){
                return common;
            }
        }
        common += first_letter;
        letter++;
        if (letter >= v[0].size()){
            return common;
        }
        first_letter = v[0][letter];
    }
}


int main(){
cout << "\"" << longest_prefix({ "geezer", "geeksforgeeks", "geeks", "geek",  }) << "\"\n";
    return 0;
}