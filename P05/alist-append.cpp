/*
Consider the code given in alist.h (you need to download the file), supporting the definition of “array lists” (lists represented using an array) containing elements of type int. Type alist defines member fields size of type int, expressing the number of elements in an array list, and elements, a pointer to a dynamically allocated array of elements of type int containing the elements and length equal to size.
struct alist {
  int size;       // Number of elements.
  int* elements;  // List elements.
};
The following functions, implemented in alist.h, are defined in association to alist:
alist* build(int n, int v[]): create a new array list with n > 0 elements with initial values given in array v.
alist* empty(): create a new array list that is initially empty, i.e., has no elements — for an empty list al, al->size is set to 0 and al->elements is set to nullptr.
destroy(alist* al): releases the memory allocated to al; and
print(alist* al): prints the elements in al.
Define a new function void append(alist* a, const alist* b) such that a call to append(a, b) appends all the elements in list b to list a. Note that, except when a or b represent the empty list, the internal array used by a must be replaced by a new array with size a->size + b->size. Moreover, b can't be changed.
*/

#include <iostream>
#include "alist.h"
using namespace std;

void append(alist* a, const alist* b){
    if (b->size == 0)
        return;

    int len = a->size + b->size;
    int *res = new int[len];
    int count = 0;

    for (int i = 0; i < a->size; i++) {
        res[count++] = a->elements[i];
    }

    for (int i = 0; i < b->size; i++) {
        res[count++] = b->elements[i];
    }

    delete[] a->elements;
    a->elements = res;
    a->size = len;
}

int main(){
    { const int nA = 2;
  int eA[nA] = { 1, 2 }; 
  alist* a = build(nA, eA);
  const alist* b = empty();
  append(a, b);
  print(a);
  destroy(a); 
  destroy(b); }
    return 0;
}