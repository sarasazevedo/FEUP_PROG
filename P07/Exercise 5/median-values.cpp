/*
Write a C++ function void calc_medians(const string& input_fname, const string& output_fname) that reads several series of double values, one series per line, stored in input file named input_fname, and outputs to file name output_fname corresponding lines with the median value of the series.
Input files may have comment lines, beginning with the # character, that should be ignored, and each series of values begins with a string identifier followed by the values to consider in the same line separated by one or more space characters.
The output file should have one line per series with the corresponding identifier and median value with one decimal place of precision (you may use fixed and setprecision defined in the iomanip header to guarantee this).
For instance, given the input file with contents:
# a 1.2 1.0 this is a comment line
b 1.2 1.0
# another comment line
c 1.3
d -1.0 2.0 1.0
then the generated output file should have contents:
b 1.1
c 1.3
d 1.0
The median of a sequence of n sorted values v[0], . . . , v[n-1] is:
v[n/2], if n is odd; or
0.5 * (v[ n / 2 - 1] + v[ n / 2]), if n is even.
Note that the values in each series in input files are not guaranteed to be sorted. To handle this detail, you may store read values in a vector v and then sort the values using sort, i.e. call sort(v.begin(), v.end()) before calculating the median value.
To run the provided tests, you need to include a header file named show_file.h (download the file) that contains an utility function show_file for printing file contents. You also need to download the ex5.zip archive containing the text files used in public tests (p5_test[1-5].txt).
*/

#include <iostream>
#include <fstream>
#include "show_file.h"
using namespace std;

void calc_medians(const string& input_fname, const string& output_fname){
    ifstream in(input_fname);
    ofstream out(output_fname);
    for(string line; getline(in, line);){
        if (line.empty() || line[0] == '#'){
            continue;
        } 
        istringstream iss(line);
        string id;
        iss >> id;
        vector<double> values;
        double val;
        while (iss >> val) {
            values.push_back(val);
        }
        sort(values.begin(), values.end());
        double median;
        int n = values.size();
        if (n % 2 == 0) {
            median = 0.5 * (values[n/2 - 1] + values[n/2]);
        } else {
            median = values[n/2];
        }
        out << fixed << setprecision(1) << id << " " << median << "\n";
    }
}

int main(){
    { calc_medians("p5_test1.txt", "p5_test1_out.txt"); 
  show_file("p5_test1_out.txt"); }

    { calc_medians("p5_test2.txt", "p5_test2_out.txt"); 
  show_file("p5_test2_out.txt"); }
    
    { calc_medians("p5_test3.txt", "p5_test3_out.txt"); 
  show_file("p5_test3_out.txt"); }

    { calc_medians("p5_test4.txt", "p5_test4_out.txt"); 
  show_file("p5_test4_out.txt"); }

    { calc_medians("p5_test5.txt", "p5_test5_out.txt"); 
  show_file("p5_test5_out.txt"); }
    return 0;
}