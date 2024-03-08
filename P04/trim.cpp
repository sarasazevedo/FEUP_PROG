/*
[NO GRADE]
Write a C++ function void trim(char s[]) that takes a C string s and removes all its leading and trailing spaces.
*/

#include <iostream>
using namespace std;

void trim(char s[]) {
  int len = 0;
  int  start = 0;
  int end;

  while(s[len] != '\0'){
    len++;
  }

  while(s[start] == ' '){
    start++;
  }

  if (start == len) {
    s[0] = '\0';
    return;
  }

  end = len-1;
  while( end >= 0 && s[end] == ' '){
    end--;
  }

  int k = 0;
  for(int i=start; i<=end; i++){
    s[k++] = s[i];
  }
  s[k] = '\0';
}

int main() {
  {
    char s[] = " abc! def? ";
    cout << "\"" << s << "\" => ";
    trim(s);
    cout << "\"" << s << "\"\n";
  } 
  return 0;
}
