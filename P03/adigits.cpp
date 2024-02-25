/*
Write a C++ function int adigits(int a, int b, int c) that receives 3 integers, each one with a single decimal digit and returns the highest integer number that can be assembled with the 3 digits given as parameters.
*/

#include <iostream>
using namespace std;

/*
int adigits(int a, int b, int c){
    int max_num; 
    if (a > b && a > c) {
        max_num = a * 100;
        if (b > c) {
            max_num += b * 10 + c;
        } else {
            max_num += c * 10 + b;
        }
    } else if (b > a && b > c) {
        max_num = b * 100;
        if (a > c) {
            max_num += a * 10 + c;
        } else {
            max_num += c * 10 + a;
        }
    } else {
        max_num = c * 100;
        if (a > b) {
            max_num += a * 10 + b;
        } else {
            max_num += b * 10 + a;
        }
    }

    return max_num;
}
*/

int adigits(int a, int b, int c){
    int centenas = max(a, max(b,c));
    int unidades = min(a, min(b,c));
    int dezenas = a + b + c - centenas - unidades;

    return centenas*100 + dezenas*10 + unidades;
}

int main(){
    cout << adigits(4, 2, 5) << '\n';
    cout << adigits(9, 1, 9) << '\n';
    cout << adigits(1, 2, 3) << '\n';
    cout << adigits(1, 0, 0) << '\n';

    return 0;
}

