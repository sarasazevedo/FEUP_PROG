/*
Write a C++ function char* duplicate(const char s[]) that returns a pointer to a dynamically allocated C string with the same contents as s. The result string should be allocated using new.
*/

#include <iostream>
using namespace std;

char* duplicate(const char s[]){
    if (!s) {
        char *result = new char[1];
        result[0] = '\0';
        return result;
    }

    int len = 0;
    for(int i=0; s[i] != '\0'; i++){
        len++;
    }

    char *result = new char[len + 1];
    for (int i = 0; i < len; i++) {
        result[i] = s[i];
    }
    result[len] = '\0';

    return result;
}

int main(){
    { char* s = duplicate("0123 456 789 @ abc");
  cout << "\"" << s << "\"\n";
  delete [] s; }
    return 0;
}