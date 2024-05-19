/*
Consider the partial definitions of classes Page and Book in the files Page.h and Book.h and the partial implementation of the classes in the files Page.cpp and Book.cpp given in the archive ex5.zip.
Write the C++ code of the member function void Book::build_index(const set<string>& words) that builds the index of a book.
The words to be indexed are received through parameter words
The index of the book is a map that associates to each word a set containing the numbers of the pages in which the word occurs (see the private data members of class Book)
If there are no occurrences of some words present in the words parameter they must be omitted from the index
Each book is saved in a text file, named book_xx.txt where xx takes the values "01", "02", ..."05", available in the given archive; the string <PAGE> marks the end of each page (see the given examples)
For simplicity, consider that the book does not contain punctuation marks
The examples used for testing are not real books but just collections of words, organised in pages
You must submit only the code for function Book::build_index.
In your local workspace, to compile a program in a file containing the tests, named for instance main.cpp, you should use the supplied Makefile and execute the following command in the Terminal:
make PROG=books CPP_FILES="Page.cpp Book.cpp books.cpp" HEADERS="Page.h Book.h"
*/

#include "Book.h"
#include <set>
#include <string>
using namespace std;

void Book::build_index(const set<string>& words){
    for (string word : words){
        set<size_t> result;
        for (size_t page = 0; page < book_.size(); page++){
            for (size_t i = 0; i < book_[page].get_num_lines(); i++){
                string line = book_[page].get_line(i);
                if (line.find(word) != string::npos)
                {
                    result.insert(page+1);
                    break;
                }
            }
        }
        if (result.size() != 0){
            index_.insert({word, result});
        }
    }
}

int main(){
    { Book b;
  if (!(b.import("book_01.txt"))) cout << "book not found! \n";
  set<string> words = { "C++", "linux", "computer" };
  b.build_index(words);
  b.show_index(); }

{ Book b;
  if (!(b.import("book_02.txt"))) cout << "book not found! \n";
  set<string> words = { "C++", "program", "computer", "windows" };
  b.build_index(words);
  b.show_index(); }
  
{ Book b;
  if (!(b.import("book_03.txt"))) cout << "book not found! \n";
  set<string> words = { "linux", "program", "cpu" };
  b.build_index(words);
  b.show_index(); }
{ Book b;
  if (!(b.import("book_04.txt"))) cout << "book not found! \n";
  set<string> words = { "computer", "program", "file","windows" };
  b.build_index(words);
  b.show_index(); }
{ Book b;
  if (!(b.import("book_05.txt"))) cout << "book not found! \n";
  set<string> words = { "linux", "byte", "cpu" };
  b.build_index(words);
  b.show_index(); }
  return 0;
}