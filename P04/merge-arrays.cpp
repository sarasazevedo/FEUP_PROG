/*
Write a C++ function void merge_arrays(const int a[], int na, const int b[], int nb, int c[]) that merges 2 arrays, a with na > 0 elements and b, with nb > 0 elements, sorted in ascending order, placing the result in array c. The values in c must also be sorted in ascending order.
To run the provided tests, you need to include a header file named print_array.h (download) that contains an utility function print_array for printing array values.
*/
#include <iostream>
#include "print_array.h"
using namespace std;

void merge_arrays(const int a[], int na, const int b[], int nb, int c[]){
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

}

int main(){
{ const int NA = 15, NB = 15;
  int a[NA] = { 0, 1, 1, 2, 3, 4, 5, 6, 6, 6, 7, 8, 8, 9, 9 };
  int b[NB] = { 0, 0, 1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 7, 8, 9 };
  int c[NA+NB];
  merge_arrays(a, NA, b, NB, c);
  print_array(c, NA+NB); }
    return 0;
}
