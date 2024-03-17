/*
The median of a sequence of n sorted values v[0], . . . , v[n-1] is:
v[n/2], if n is odd; or
(v[ n / 2 - 1] + v[ n / 2]) / 2, if n is even.

Write a C++ function int median(const int a[], int n) that returns the median value of n values contained in an arbitrary array a. Note that a is not guaranteed to be sorted and must not be changed by the function.
To implement the function, the following steps are suggested:
Create a temporary array tmp of size n allocated using new.
Copy the values of a onto tmp.
Sort the temporary array using the std::sort library function declared in the <algorithm> system header using a call of the form: sort(tmp, tmp + n);
Compute the median value as explained above.
Before returning, don't forget to release the memory associated with tmp using delete (since the array is no longer necessary).
*/

#include <iostream>
#include <algorithm>
using namespace std;

int median(const int a[], int n){
    int *tmp = new int[n];
    int result;

    for (int i = 0; i < n; i++) {
        tmp[i] = a[i];
    }

    sort(tmp, tmp + n);

    if (n % 2 == 0) {
        result = (tmp[n / 2 - 1] + tmp[n / 2]) / 2;
    } else {
        result = tmp[n / 2];
    }

    delete[] tmp;
    return result;

}

int main(){
    { const int n = 5; 
  int a[n] { 10, -10, 0, 12, 11 };
  cout << median(a, n) << '\n'; }
    return 0;
}