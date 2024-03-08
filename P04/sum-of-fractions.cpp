/*
[NO GRADE]
Consider a type for integer fractions defined by

struct fraction {
   int num; // Numerator
   int den; // Denominator
}; 

Write a C++ function fraction sum(const fraction fa[], int n) that returns the sum of all n fractions stored in array fa. The returned fraction should be irreducible and its denominator should always be positive; you may assume all fractions stored in fa obey these conditions and that n > 0.
In your code you should include header file fraction.h (you need to download the file) that contains the fraction type, along with support for printing fraction values using cout (used in tests).
Hint: The Euclidean algorithm for computing the greatest common divisor of two numbers can be helpful. It is expressed by the following recurrence:
gcd(𝑎,𝑏)={𝑎gcd(𝑏,𝑎%𝑏), if 𝑏=0, if 𝑏≠0
*/

#include <iostream>
#include "fraction.h"
using namespace std;

int gcd(int a, int b) {
  if(b == 0){
    return a;
  } else{
    return gcd(b, a%b);
  }
}

fraction sum(const fraction fa[], int n) {
    int num = 0;
    int den = 1;

    for(int i = 0; i < n; i++){
        num = num * fa[i].den + fa[i].num * den;
        den = den *fa[i].den;
    }

    int div = gcd(num,den);
    num /= div;
    den /= div;

    if(den < 0){
        num *= -1;
        den *= -1;
    }

    return {num,den};
}

int main() {
  {
    const int n = 1;
    const fraction fa[n] { {1, 2} };
    cout << sum(fa, n) << '\n';
  } 
  {
    const int n = 2;
    const fraction fa[n] { {1, 2}, {-1, 3}};
    cout << sum(fa, n) << '\n';
  } 
  {
    const int n = 3;
    const fraction fa[n] { {1, 2}, {-1, 3}, {-3, 4} };
    cout << sum(fa, n) << '\n';
  } 
  {
    const int n = 4;
    const fraction fa[n] { {-1, 4}, {1, 2}, {-1, 8}, {-1, 8} };
    cout << sum(fa, n) << '\n';
  } 
  return 0; 
}