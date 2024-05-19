/*
Write a C++ function void replace(const map<char, char>& r, string& s), that replaces all characters in s according to the character replacement dictated by r, i.e., a character c in s should be replaced by r[c] if c is a key in r.
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

void replace(const map<char, char>& m, string& s){
    for(char& c:s){
        map<char, char>::const_iterator it = m.find(c); //or auto 
        if(it != m.end()){
            c = it->second;
        }
    }

}

int main(){
    { string s = "C / C++ @ LEIC";
  replace({ {'C', 'z'}, {'+', '-'}, {'L', 'X'}}, s);
  cout << s << '\n'; }
  { string s = "C / C++ @ LEIC";
  replace({ }, s);
  cout << s << '\n'; }
{ string s = "A B C D E F";
  replace({ {' ', '_'}}, s);
  cout << s << '\n'; }
{ string s = "A B C D E F";
  replace({ {'_', ' '}, {'A', '?'}, {'?', '!'}, {'F', '!'}}, s);
  cout << s << '\n'; }
  return 0;
}