/*
Write a C++ function const char* longest(const char* pa[]) that takes a nullptr-terminated array pa of pointers to C strings and returns the array element (a C string pointer) corresponding to the longest string. In case there is more than one C string with maximum length, the rightmost element should be returned. You may assume pa contains at least one element before nullptr.
Hint: All you need to do is return pa[k] where k is the position pointing to the string of interest. You should not allocate any dynamic memory.
*/

#include <iostream>
using namespace std;

const char* longest(const char* pa[]){
    const char* longest = pa[0];
    int maximo = 0;

     for (int i = 0; pa[i] != nullptr; i++) {
        for (int len = 0; pa[i][len] != '\0'; len++) {
            if (len >= maximo) {
                maximo = len;
                longest = pa[i];
            }
        }
    }
    return longest;
}

int main(){
    { const char* pa[] = { "C++", nullptr };
  cout << "\"" << longest(pa) << "\"\n"; }
    return 0;
}