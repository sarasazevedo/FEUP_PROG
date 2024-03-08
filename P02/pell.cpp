/*
Pell numbers 𝑃0,𝑃1,𝑃2,… are given by 𝑃0=0, 𝑃1=1 and 𝑃𝑛=2𝑃𝑛−1+𝑃𝑛−2 for 𝑛≥2.
Write a C++ function unsigned long pell(unsigned long n) to compute Pell numbers.
Note: Use an iterative implementation, not a recursive one. A  "direct" recursive implementation will result in an exponential number of recursive calls and trigger a "Time Limit Exceeded" evaluation error.
*/

#include <iostream>
using namespace std;

unsigned long pell(unsigned long n) {
    unsigned long p0 = 0;
    unsigned long p1 = 1;
    unsigned long result;

    if (n == 0) return 0;
    if (n == 1) return 1;
    
    for (unsigned long i = 2; i <= n; i++) {
        result = 2 * p1 + p0;
        p0 = p1;
        p1 = result;
    }

    return result;
}

int main(){
    cout << pell(5) << '\n';
    cout << pell(50) << '\n';
    return 0;
}