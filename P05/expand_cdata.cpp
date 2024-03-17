/*
Consider the following cdata type defined in header cdata.h (you need to download this file):
struct cdata {
   int count;
   int value;
};
A cd value of this type encodes cd.count > 0 repetitions of value cd.value. For instance, cd = {3, 123} expresses value 123 repeated 3 times.
Write a C++ function
int* expand_cdata(const cdata a[], int n)
that returns a dynamically allocated array of type int for the sequence of all values expressed in compressed form by cdata elements in array a of length n.
The resulting array should always be allocated using new. The tests use a print_array function also defined in cdata.h.
*/

#include <iostream>
#include "cdata.h"
using namespace std;

int* expand_cdata(const cdata a[], int n){
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += a[i].count;
    }

    int *result = new int[count];
    int index = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i].count > 0) {
            for (int j = 0; j < a[i].count; j++) {
                result[index++] = a[i].value;
            }
        }
    }

    return result;
}

int main(){
    { const int n = 1;
  const cdata a[] { { 3, 999 } };
  int* r = expand_cdata(a, n);
  print_array(r, 3);
  delete [] r; }
    return 0;
}