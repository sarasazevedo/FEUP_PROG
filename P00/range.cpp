//Write a program that reads two integers a and b and prints all numbers between 𝑎 and 𝑏 (closed interval).

#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    cout << i << ' ';
  }
  return 0;
}