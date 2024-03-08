/*
Write a C++ function int max(const int a[], int n) that returns the maximum value of all n > 0 elements stored in array a.
*/

#include <iostream> 
using namespace std;

int max(const int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

int main(){ 
{ const int n = 9;
  const int a[n] = { 10, 20, 30, -2, 50, 3, 1, 50, 49 };
  cout << max(a, n) << '\n'; }
    return 0;
}

