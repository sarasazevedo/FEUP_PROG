//Write a program that reads an integer value x and indicates if x is even or odd (i.e., divisible by 2 or not).

#include <iostream>
using namespace std;

int main() {
  int x;         
  cin >> x;      
  if ( x % 2 == 0 ) { 
    cout << x << " is even\n";
  } else {
    cout << x << " is odd\n";
  }
  return 0;
}