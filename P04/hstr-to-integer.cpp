/*
Write a C++ function unsigned long hstr_to_integer(const char hstr[]) that converts a C string formed by the characters that correspond to hexadecimal digits (‘0’ to ‘9’, ‘a’ to ‘f’, or ‘A’ to ‘F’) to the corresponding integer decimal value. Remember that, as usual, C strings are null-terminated.
*/

#include <iostream>
using namespace std; 

unsigned long hstr_to_integer(const char hstr[]){
    unsigned long result = 0;
    for (int i = 0; hstr[i] != '\0'; i++) {
        char c = hstr[i];
        unsigned long value;
        if (c >= '0' && c <= '9')
        {
            value = c - '0';
        }
        else if (c >= 'a' && c <= 'f')
        {
            value = c - 'a' + 10;
        }
       else if (c >= 'A' && c <= 'F')
        {
            value = c -'A' + 10;
        }
        else{
            return 0;
        }
        result = result * 16 + value;
    }
    return result;
}

int main(){
    cout << hstr_to_integer("A");
    return 0;
}