/*
A Mersenne number is a number of the form 𝑀𝑛=2𝑛−1 for some positive integer 𝑛≥0.
Write a C++ function unsigned long next_mersenne(unsigned long n) that returns the lowest Mersenne number greater or equal to n.
You cannot use the pow or other cmath functions.
*/

#include <iostream>
using namespace std;

unsigned long next_mersenne(unsigned long n) {
    unsigned long result = 1;
    while (result <= n){
        result <<= 1;
    }
    return result -1 ;
}
int main() {
    cout << next_mersenne(4294967296UL) << '\n';
    cout << next_mersenne(128) << '\n';
    return 0;
}