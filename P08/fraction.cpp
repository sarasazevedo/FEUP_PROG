/*
Create a class Fraction for performing arithmetic operations with fractions according to the specification below. You are free to name the attributes of the class, but the names and signatures of the member functions must be as stated.
Use private int member fields to represent the numerator and the denominator.
Provide two constructors for the class: a default constructor that initialises the numerator with 0 and denominator with 1, and a constructor that takes two int arguments, corresponding to the numerator and denominator values. You may assume that the denominator is always different from 0.
The constructors must ensure that the fraction is stored in normalised form, that is, it must be irreducible and the denominator must always be positive. For example, the fractions 3/15, -3/-4 and 2/-4 must be stored, respectively, as 1/5, 3/4 and -1/2.
Define public numerator() and denominator() accessors for the numerator and denominator fields.
Provide public member functions to perform the basic arithmetic operations with fractions: sum, subtraction, multiplication and division, with the following corresponding signatures:
  Fraction sum(const Fraction& right)
  Fraction sub(const Fraction& right)
  Fraction mul(const Fraction& right)
  Fraction div(const Fraction& right)
The code of the following functions is given in the file fraction_aux.h and must be inserted in the correct place:
Fraction::gcd, to calculate the greatest common divisor of 2 numbers;
Fraction::normalise, to normalise a fraction;
Fraction::write, to write a fraction on the screen.
Note that you need to declare these functions in the Fraction class.
*/

#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>

class Fraction {
    public:
        Fraction();
        Fraction(int numerator, int denominator);
        int numerator() const;
        int denominator() const;
        int gcd(int a, int b);
        void write() const;
        void normalise();
        Fraction sum(const Fraction& right);
        Fraction sub(const Fraction& right);
        Fraction mul(const Fraction& right);
        Fraction div(const Fraction& right);
    private:
        int numerator_;
        int denominator_;
};

#include "fraction_aux.h"

Fraction::Fraction() {
    numerator_ = 0;
    denominator_ = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    numerator_ = numerator;
    denominator_ = denominator;
    Fraction::normalise();
}

int Fraction::numerator() const {
    return numerator_;
}

int Fraction::denominator() const {
    return denominator_;
}

Fraction Fraction::sum(const Fraction& right) {
    int numerator = (numerator_ * right.denominator()) + (right.numerator() * denominator_);
    int denominator = denominator_ * right.denominator();
    return Fraction(numerator, denominator);
}

Fraction Fraction::sub(const Fraction& right) {
    int numerator = (numerator_ * right.denominator()) - (right.numerator() * denominator_);
    int denominator = denominator_ * right.denominator();
    return Fraction(numerator, denominator);
}

Fraction Fraction::mul(const Fraction& right) {
    int numerator = numerator_ * right.numerator();
    int denominator = denominator_ * right.denominator();
    return Fraction(numerator, denominator);
}

Fraction Fraction::div(const Fraction& right) {
    int numerator = numerator_ * right.denominator();
    int denominator = denominator_ * right.numerator();
    return Fraction(numerator, denominator);
}

int main(){
    { Fraction().sum({2, 4}).write(); cout << ' ';
  Fraction(1,1).sum({2, 4}).write(); cout << ' ';
  Fraction(2,4).sum({3, 9}).write(); cout << ' ';
  Fraction(-2,4).sum({1, 2}).write(); cout << ' ';
  Fraction(3,27).sum({-27, 81}).write(); cout << '\n'; }

  { Fraction().sub({2, 4}).write(); cout << ' ';
  Fraction(1,1).sub({2, 4}).write(); cout << ' ';
  Fraction(2,4).sub({3, 9}).write(); cout << ' ';
  Fraction(-2,4).sub({1, 2}).write(); cout << ' ';
  Fraction(3,27).sub({-27, 81}).write(); cout << '\n'; }

  { Fraction().mul({2, 4}).write(); cout << ' ';
  Fraction(1,1).mul({2, 4}).write(); cout << ' ';
  Fraction(2,4).mul({3, 9}).write(); cout << ' ';
  Fraction(-2,4).mul({1, 2}).write(); cout << ' ';
  Fraction(3,27).mul({-27, 81}).write(); cout << '\n'; }

  { Fraction().div({2, 4}).write(); cout << ' ';
  Fraction(1,1).div({2, 4}).write(); cout << ' ';
  Fraction(2,4).div({3, 9}).write(); cout << ' ';
  Fraction(-2,4).div({1, 2}).write(); cout << ' ';
  Fraction(3,27).div({-27, 81}).write(); cout << '\n'; }
    return 0;
}