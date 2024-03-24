/*
A character sequence in some alphabet is called a pangram if it contains every letter in the alphabet. For instance, "The quick brown fox jumps over the lazy dog" is a pangram in English since it contains all letters A to Z.
Write a C++ function bool pangram(const string& s, string& m) such that:
s is a string containing uppercase or lowercase letter characters (‘A’ to ‘Z’, ‘a’ to ‘z’) and also the space character (‘ ‘) — spaces should be ignored and a lowercase character (e.g. ‘a’) should be considered equivalent to the corresponding uppercase letter (e.g., ‘A’);
the function returns true if and only if the given string s is a pangram, that is, it contains all letters A to Z in lowercase or uppercase form; and
on return, m is a lowercase string containing all letters that are missing in s, ordered alphabetically (m will be the empty string if s is a pangram).
Hint: there are 26 letters in the alphabet. Use an internal array of length 26 to keep track of the letters that occur in s.
*/
#include <iostream>
using namespace std;

bool pangram(const string& s, string& m){
    char alfa[26] = {0};
    bool flag = true;

    for(size_t i = 0; i < s.length(); i++){
        if(s[i] != ' '){
            if(s[i] >= 'a' && s[i] <= 'z'){
                alfa[s[i] - 'a'] += 1;
            }
            if(s[i] >= 'A' && s[i] <= 'Z'){
                alfa[s[i] - 'A'] += 1;
            }
        }
    }

    for(int c = 0; c < 26; c++){
        if(alfa[c] == 0){
            m.push_back(c + 'a');
            flag = false;
        }
    }
    return flag;
}

int main(){
    { string s = "The quick brown fox jumps over the lazy dog";
  string m = "";
  bool r = pangram(s, m);
  cout << '\"' << s << "\" " 
       << boolalpha << r << " \"" << m << "\"\n"; }
    return 0;
}