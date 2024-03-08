//Write a program that reads an integer n and prints all numbers 𝑑 between 1 and 𝑛−1 such that 𝑑 is a divisor of n (e.g. 1, 2, and 5 if n is 10).

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n; 
    for (int i=1; i<n-1; i++){
        if(n % i == 0){
            cout << i << ' ';
        }
    }
    return 0;
}