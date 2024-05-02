/*
Write a C++ function void normalise(const string& input_fname, const string& output_fname) that normalises the contents of input file named input_fname and writes them onto an output file named output_fname. The input file contents should be converted to the output file as follows:
Lines that contain only space characters should not be written to the output file;
Leading and trailing spaces in a line should be erased;
All characters should be uppercased.
To run the provided tests, you need to include a header file named print.h (download the file) that contains an utility function print for printing file contents. You also need to download the ex3.zip archive containing the text files used in public tests (p3_test[1-5].txt). You may assume that the only blank characters contained in files are the space and newline character.
Hints: You should use an ofstream object to write the output file. You may use toupper to convert characters to uppercase.
*/

#include <iostream>
#include <fstream>
#include <string>
#include "print.h"
using namespace std;

void normalise(const string& input_fname, const string& output_fname) {
    ifstream in(input_fname);
    ofstream out(output_fname);
    string line;
    while (getline(in, line)) {
        line.erase(0, line.find_first_not_of(" "));
        line.erase(line.find_last_not_of(" ") + 1);
        if(line.length() > 0){
            for (char& c : line) {
                c = toupper(c);
            }
            out << line << "\n";
        }
    }
}

int main(){
    { normalise("p3_test1.txt", "p3_test1_out.txt"); 
  print("p3_test1_out.txt"); }

    { normalise("p3_test2.txt", "p3_test2_out.txt"); 
  print("p3_test2_out.txt"); }

    { normalise("p3_test3.txt", "p3_test3_out.txt"); 
    print("p3_test3_out.txt"); }

    { normalise("p3_test4.txt", "p3_test4_out.txt"); 
  print("p3_test4_out.txt"); }

   { normalise("p3_test5.txt", "p3_test5_out.txt"); 
  print("p3_test5_out.txt"); }
  
    return 0;
}

