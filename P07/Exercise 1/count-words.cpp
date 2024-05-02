/*
Write a C++ function int count(const string& fname, const string& word) such that count(fname, word) returns the number of occurrences of the word in the file named fname, where word is a string that does not contain blank characters (e.g., spaces, tabs, line breaks). The word count should be case insensitive (e.g. "string" and "STRING" should be considered equivalent).
To test your code download the ex1.zip archive containing 2 text files used in public tests (p1_test_a.txt and p2_test_b.txt).
Hint: you need to use an ifstream object in conjunction with the >> operator (the extraction operator) to read strings from the file ( >> skips over blank characters automatically). You may use toupper or tolower to convert characters to uppercase or lowercase respectively.
*/

#include <iostream>
#include <fstream>
using namespace std;

int count(const string& fname, const string& word){
    ifstream in(fname);
    string word_up = word;
    int count = 0;
    for (char& c : word_up){
        c = toupper(c);
    }
    for(string s; in >> s;){
        for(char& c : s){
            c = toupper(c);
        }
        if(s == word_up){
            count++;
        }
    }
    return count;
}

int main(){
    cout << count("p1_test_a.txt", "THE") << '\n';
    cout << count("p1_test_a.txt", "0") << '\n';
    cout << count("p1_test_a.txt", "code") << '\n';
    cout << count("p1_test_b.txt", "Collider") << '\n';
    cout << count("p1_test_b.txt", "you") << '\n';
    return 0;
}