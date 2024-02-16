//Write a C++ program that, given an integer by user input, computes its reverse (the number with the digits by the reverse order) and prints it.
#include <iostream>
using namespace std;

int main(){
    int n;
    int digit;
    int reversed=0;
    cin >> n;

    while(n != 0){
        digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    cout << reversed;

    return 0;
}