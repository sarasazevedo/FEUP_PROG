/*
Consider the following template class Stack<T> defined in header Stack.h:
template <typename T>
class Stack {
public:
  Stack();
  size_t size() const;
  bool peek(T& elem) const;
  bool pop(T& elem);
  void push(const T& elem);
private:
  std::vector<T> elements;
};
The template is for a stack of elements that uses a vector object to store the stack elements. The stack should have the usual Last-In First-Out (LIFO) discipline: push(v) adds element v to the top of the stack and pop() removes the element on top of the stack, i.e., the one that has been added to the stack most recently through push().
The class should work as follows:
The elements vector should store the elements in order of addition to the stack from most recent to least recent;
Stack() builds an initially empty stack;
size() returns the number of elements stored in the stack;
push(v) adds an element to the (top of the) stack;
Hint: use the push_back() defined for std::vector
pop(v):
if the stack is not empty, removes the element on top of the stack, assigns that element to v, and returns true; or
simply returns false if the stack is empty, leaving v unchanged.
Hint: use the back() and pop_back() defined for std::vector
peek(v):
if the stack is not empty, assigns v with the element on top of the stack without removing the element and returns true; or
simply returns false if the stack is empty, leaving v unchanged.
*/

#include "Stack.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
Stack<T>::Stack() {}

template <typename T>
size_t Stack<T>::size() const {
  return elements.size();
}

template <typename T>
void Stack<T>::push(const T& elem) {
  elements.push_back(elem);
}

template <typename T>
bool Stack<T>::pop(T& elem) {
  if (! elements.empty()) {
    elem = elements.back();
    elements.pop_back();
    return true;
  }
  return false;
}

template <typename T>
bool Stack<T>::peek(T& elem) const {
  if (! elements.empty()) {
    elem = elements.back();
    return true;
  }
  return false;
}

int main(){
    { Stack<int> s;
  const Stack<int>& r = s;
  int v = -1;
  cout << r.size()  << ' ' << boolalpha
       << r.peek(v) << ' ' << v << ' '
       << s.pop(v)  << ' ' << v << ' '
       << s.size() << '\n'; }
{ Stack<int> s;
  int v = -1;
  s.push(123);
  cout << s.size()  << ' ' << boolalpha
       << s.peek(v) << ' ' << v << ' '
       << s.pop(v)  << ' ' << v << ' '
       << s.size() << '\n'; }
{ Stack<string> s; string v;
  s.push("a"); s.push("b"); s.push("c");
  cout << s.size();
  while(s.pop(v)) cout << ' ' << v;
  cout << ' ' << s.size() << '\n'; }
{ Stack<int> s; int v = -1;
  s.push(111); s.push(222); s.push(333);
  cout << s.size();
  while(s.peek(v)) {
    cout << ' ' << v;
    s.pop(v);
    cout << ' ' << v;
    if (v % 2 != 0) s.push(v + 1);
    cout << ' ' << s.size(); }
  cout << '\n'; }
    return 0;
}