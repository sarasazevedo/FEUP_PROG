/*
A sparse matrix is a matrix where most elements have value 0. For space efficiency, data structures for sparse matrices only encode non-zero values.
Consider the following definition for a smatrix type, defined in smatrix.h (download), where sparse matrices are represented by a vector of type sm_entry:
struct sm_entry {
  size_t row;  // Matrix row
  size_t col;  // Matrix column
  int value;   // Value (non-zero)
};
typedef vector<sm_entry> smatrix;
Write a C++ function void sum(const smatrix& a, const smatrix& b, smatrix& r) such that a call to sum(a, b, r) places in r the result of adding the sparse matrices represented by a and b.
You should consider that entries in a and b are ordered by row first and then by column, and ensure the same type of ordering in r.
The provided tests use an utility function called print for printing sparse matrices, also defined in  smatrix.h.
*/

#include <iostream>
#include <string>
#include <vector>
#include "smatrix.h"
using namespace std;

void sum(const smatrix& a, const smatrix& b, smatrix& r) {
    r.clear(); 
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            r.push_back(a[i]);
            i++;
        } else if (a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            r.push_back(b[j]);
            j++;
        } else {  
            int sum = a[i].value + b[j].value;
            if (sum != 0) {
                r.push_back({a[i].row, a[i].col, sum});
            }
            i++;
            j++;
        }
    }
    while (i < a.size()) {
        r.push_back(a[i]);
        i++;
    }
    while (j < b.size()) {
        r.push_back(b[j]);
        j++;
    }
}

int main(){
    { smatrix r;
  sum({ {0, 0, -1}, {0, 1, 2}, {5, 10, 20}, {10, 5, -20} },
      { {0, 0, 1}, {0, 1, -2}, {10, 5, 20} },
      r);
  print(r); }
    return 0;
}