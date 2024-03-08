/*
Write a C++ function int* merge_arrays(const int a[], int na, const int b[], int nb) that returns a dynamically allocated array that merges the elements of two arrays, a with na > 0 elements and b, with nb > 0 elements, both sorted in ascending order. The result array must also be sorted in ascending order.
To run the provided tests, you need to include a header file named print_array.h (download) that contains an utility function print_array for printing array values.
Hint: You should allocate the array for the result using new. The code should be otherwise the same as exercise 4.2.
*/

#include <iostream>
#include "print_array.h"
using namespace std;

int* merge_arrays(const int a[], int na, const int b[], int nb){
    int *c = new int[na + nb];
    int i = 0, j = 0, k = 0;

   while (i < na && j < nb) {
    if (a[i] < b[j]) {
        c[k] = a[i];
        i++;
    } else {
        c[k] = b[j];
        j++;
    }
    k++;
  }

while (i < na) {
    c[k] = a[i];
    i++;
    k++;
  }

while (j < nb) {
    c[k] = b[j];
    j++;
    k++;
  }

    return c;
}


int main(){
    { const int NA = 4, NB = 6;
  int a[NA] = { 1, 2, 4, 7};
  int b[NB] = { 0, 3, 5, 6, 8, 9};
  int* c = merge_arrays(a, NA, b, NB);
  print_array(c, NA+NB);
  delete [] c; }
    return 0;
}