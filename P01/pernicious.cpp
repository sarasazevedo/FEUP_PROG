/*In number theory, a pernicious number is a positive integer that has a prime number of 1s in their binary representation. We are interested in numbers that are both prime and pernicious. 
For instance 7=1112 is both prime and pernicious, 6=1102 is pernicious but not prime, and 23=101112 is prime but not pernicious.
Write a C++ program that prints the value of all numbers between a and b that are both pernicious and prime, where a and b are positive integers supplied as input.*/
#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i=2;i*i <= num;i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int bitCounter(int n) {
    int count = 0;
    while (n!=0) {
        n &= (n-1);
        count++;
    }
    return count;
}

bool isPernicious(int n) {
    return isPrime(bitCounter(n));
}

int main(){
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (isPrime(i) && isPernicious(i)) {
            std::cout << i << " ";
        }
    }
    return 0;
}