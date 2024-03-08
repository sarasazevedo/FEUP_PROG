/*
[NO GRADE]
Write a C++ function int nrl(const char s[], char low[]) such that:
s is a string containing uppercase or lowercase letter characters (‘A’ to ‘Z’, ‘a’ to ‘z’) and also the space character (‘ ‘) — spaces should be ignored and a lowercase character (e.g. ‘a’) should be considered equivalent to the corresponding uppercase letter (e.g., ‘A’);
the function returns the number of non-repeated letters in s, that is, the number of letters that occur only once in s; and
on return, low is a lowercase string containing all letters that occur only once in s, ordered alphabetically (remember that, as usual, C strings must be null-terminated).
Hint: there are 26 letters in the alphabet. Use an int array of length 26 to keep track of the frequency count of all letters that occur in s.
*/

#include <iostream>
using namespace std;

int nrl(const char s[], char low[]){
   int x = 0, y = 0;
   int count[26] = {0};

   for (int i=0; s[i] != '\0'; i++){
        if(s[i] != ' '){
            if(s[i] >= 'a' && s[i] <= 'z'){
                count[s[i]-'a']++;
            }
            else{
                count[s[i]-'A']++;
            }
        }
   }

   for (int j=0; j<26; j++){
        if(count[j] == 1){
            x++;
            low[y++] = 'a' + j;
        }
   }
   low[y] = '\0';

   return x;
}

int main(){
{ const char s[] = "  F C U P  F E U P  Porto  ";
  char l[27] = { -1 };
  int r = nrl(s, l);
  cout << '\"' << s << "\" "
       << r << " \"" << l << "\"\n"; }
    return 0;
}