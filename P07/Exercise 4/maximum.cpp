/*
Write a C++ function void maximum(const string& input_fname, const string& output_fname) that reads double values with variable number of decimal places, stored one per line in input file named input_fname, and outputs to file name output_fname the corresponding values, one per line, rounded to 3 decimal places. In the end, the function outputs the number of values read and the maximum value (see examples in the tests). You may assume that the values are all in the range [-1000,1000].
To run the provided tests, you need to include a header file named show_file.h (download the file) that contains an utility function show_file for printing file contents. You also need to download the ex4.zip archive containing the text files used in public tests (p4_test[1-4].txt).
You may assume that the only blank characters contained in files are the space and newline character and may use fixed and setprecision defined in the iomanip header to write the values rounded to 3 decimal places.
*/

#include <iostream>
#include <fstream>
#include "show_file.h"
using namespace std;

void maximum(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    double numero, maximo = -1000;
    int count = 0;
    while (in >> numero){
        count++;
        maximo = max(maximo, numero);
        out << fixed << setprecision(3) << numero << "\n";
    }
        out<< "count=" << count << "/max=" << fixed << setprecision(3) << maximo << endl;
}

int main(){
    { maximum("p4_test1.txt", "p4_test1_out.txt");
  show_file("p4_test1_out.txt"); }

    { maximum("p4_test2.txt", "p4_test2_out.txt");
  show_file("p4_test2_out.txt"); }
    
    { maximum("p4_test3.txt", "p4_test3_out.txt");
  show_file("p4_test3_out.txt"); }

    { maximum("p4_test4.txt", "p4_test4_out.txt");
  show_file("p4_test4_out.txt"); }
    return 0;
}