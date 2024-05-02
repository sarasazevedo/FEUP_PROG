/*
Write a C++ function
void count_words(const string& str, vector<pair<string, size_t>>& count)
that receives as parameters a string and a vector, and fills the vector with (𝑤,𝑛)
 pairs, where 𝑤
 is a word appearing in string and 𝑛
 is the the number of occurrences of 𝑤
, ordered alphabetically by word. Consider the words to be case insensitive.
Include the following function, show_vector, to print the contents of the vector in the test cases.
void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}
*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

void show_vector(const vector<pair<string, size_t>>& count) {
  cout << "[ ";
  for (const auto& e : count) {
    cout << e.first << ":" << e.second << ' ';
  }
  cout << "]\n";
}

void count_words(const string& str, vector<pair<string, size_t>>& count){
    map<string, size_t> word_count;
    string word;
    stringstream ss(str);
    while (ss >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        word_count[word]++;
    }
    count.clear();
    for (auto& p : word_count) {
        count.push_back(p);
    }
    sort(count.begin(), count.end());
}

int main(){
    { string s = "If you want to buy  buy  if you don't want to buy  bye bye";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }

{ string s = "You can fool some of the people all of the time and all of the people some of the time  but you cannot fool all of the people all of the time";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }

{ string s = "A tutor who tooted the flute tried to tutor two young tooters to toot   Said the two to the tutor is it tougher to toot or to tutor two young tooters to toot";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }

{ string s = "You do not need to turn on a night light on a clear night like tonight because in a clear night there is always a light light and tonight is a clear night";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }

{ string s = "If one doctor doctors another doctor  Does the doctor who doctors the doctor  Doctor the way the doctor he is doctoring doctor  Or does he doctor the doctor  The way the doctor who doctors doctor";
  vector<pair<string, size_t>> count;
  count_words(s, count);
  show_vector(count); }
    return 0;
}