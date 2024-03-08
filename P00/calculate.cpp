//Write a program that reads an integer value x and writes the value of 𝑥 and 𝑥^2−𝑥+1.*/

#include <iostream>
using namespace std;

int main() {
  int x; 
  cin >> x; 
  int y = x*x - x + 1; 
  cout << x << ' ' << y << '\n'; 
  return 0;
}