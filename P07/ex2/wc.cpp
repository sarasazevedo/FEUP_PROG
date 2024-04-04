/*
Write a C++ function wcresult wc(const string& filename) that reads a file and computes statistics that are similar to those computed by the “wc” Linux command line utility: the total number of lines, total number of words, and number of bytes. Any sequence of non-blank characters is considered a word, and wcresult is defined as:
struct wcresult {
  unsigned int lines;
  unsigned int words;
  unsigned int bytes;
};
In your code you should include the header file wc.h (you need to download the file) that contains the declaration of the above wcresult type.
To test your code download the ex2.zip archive containing the text files used in public tests (p2_test[1-5].txt). You may assume that the only blank characters contained in files are the space and newline character.
Hints: You should use an ifstream object to read a file and getline to read entire lines onto string objects. Employing istringstream may also be useful to break a line into words.
*/

#include <iostream>
#include <fstream>
#include "wc.h"
using namespace std;

wcresult wc(const string& filename){
    unsigned int lines = 0, words=0, bytes=0;
    ifstream in(filename);
    for(string line; getline(in, line);){
        lines++;
        bytes += line.length() + 1; //'\n' 
        istringstream iss(line);
        for(string word; iss >> word;){
            words++;
        }
    }
    return {lines, words, bytes};
}

int main(){
    { wcresult r = wc("p2_test1.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }
  
   { wcresult r = wc("p2_test2.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }

  { wcresult r = wc("p2_test3.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }

  { wcresult r = wc("p2_test4.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }

  { wcresult r = wc("p2_test5.txt"); 
  cout << r.lines << ' ' << r.words << ' ' << r.bytes << '\n'; }

  return 0;
}
