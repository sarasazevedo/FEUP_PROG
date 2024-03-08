/*
Consider a type for integer fractions defined by
struct fraction {
   int num; // Numerator
   int den; // Denominator
};

Write two C++ functions for fraction addition and multiplication, i.e. fraction add(fraction a, fraction b) and fraction mul(fraction a, fraction b)

The returned fraction should be irreducible and its denominator should always be positive; you may assume fractions a and b given as arguments obey these conditions.

In your code you should include header file fraction.h (you need to download the file) that contains the declarations of the above functions and the fraction type, along with support from printing fractions using cout (used in tests).

Hint: The Euclidean algorithm for computing the greatest common divisor of two numbers can be helpful. It is expressed by the following recurrence:
gcd(𝑎,𝑏)={𝑎gcd(𝑏,𝑎%𝑏), if 𝑏=0, if 𝑏≠0

*/

#include "fraction.h"
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b==0){
        return a;
    } else{
        return abs(gcd(b,a%b));
    }
}

fraction simplify(fraction result) {
    int div_comum = gcd(result.num, result.den);
    result.num /= div_comum;
    result.den /= div_comum;
    return result;

}

fraction add(fraction a, fraction b){
    fraction result;
    result.num = (a.num * b.den) + (b.num * a.den);
    result.den = a.den * b.den;
    return simplify(result);

}

fraction mul(fraction a, fraction b){
    fraction result;
    result.num = a.num * b.num;
    result.den = a.den * b.den;

    return simplify(result);
}


int main(){
    { fraction a { 0, 1 }, b { 2, 1};
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

{ fraction a { 1, 1 }, b { -1, 2};
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

{ fraction a { -3, 2 }, b { 3, 2 };
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

{ fraction a { -3, 2 }, b { -2, 3 };
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

{ fraction a { -7, 24 }, b { 1, 3 };
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

{ fraction a { -8, 25 }, b { 3, 4 };
  cout << add(a,b) << ' ' << mul(a,b) << '\n'; }

cout << add({7,4536}, mul({-5,21}, add({1,2}, mul({-2,3}, {1,9})))) << '\n';

    return 0;
}