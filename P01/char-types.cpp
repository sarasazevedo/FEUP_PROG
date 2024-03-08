// Write a C++ program that reads an integer number n by user input followed by n characters, all separated by spaces, and then prints the number of characters read that are letters, the number of characters read that are digits, and the number of characters read that are not letters or digits. 

#include <iostream>
using namespace std;

int main(){
    int n;
    int digit = 0;
    int letter = 0;
    int other = 0;
    cin >> n; 

    for(int i=0; i<n; i++){
        char x;
        cin >> x;
        if(x >= '0' && x <= '9'){
            digit = digit + 1;
        } else if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') ){
            letter = letter + 1;
        } else {
            other = other + 1;
        }
    }

    cout << letter << " " << digit << " " << other;

    return 0;
}