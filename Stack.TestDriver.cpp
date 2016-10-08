// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <iostream>
using namespace std;

#include<cassert>

#include "Stack.h"
#include "Stack.h"

int main(){
  cout << "Programmer: Dhanush Patel\n";
  cout << "Programmer's ID: 1553428\n";
  cout << "File: " << __FILE__ << endl;
  cout << endl;

  Stack<int> a;
  cout << "Using int values:" << endl;
  cout << "Testing Stack constructor and Stack size()\n";
  for (int i = 0; i < a.size(); i++){
    assert(a.peek() == 0);
    a.pop();
  }

  cout << "\nTesting Stack push(), peek(), and pop()\n";
  a.push(456);
  a.push(123);
  cout << "EXPECTED: 123 for 2nd add\n";
  int addT = a.peek();
  a.pop();
  cout << "ACTUAL: " << addT << endl;
  assert(123 == addT);
  cout << "EXPECTED: 546 for 1st add\n";
  int addO = a.peek();
  a.pop();
  cout << "ACTUAL: " << addO << endl;

  cout << "Testing Stack empty()\n";
  cout << "EXPECTED: true (1) \n";
  cout << "ACTUAL: " << a.empty() << endl;

  a.push(111);
  a.push(222);
  cout << "Testing Stack clear()\n";
  a.clear();
  cout << "EXPECTED size = 0\n";
  cout << "ACTUAL: " << a.size() << endl;

  cout << "\nConst object test" << endl;
  const Stack<int> c;
  assert(c.size() == 0);
  assert(c.empty());

  a.push(1000);
  a.push(2000);
  cout << "\nObject copy test\n";
  Stack<int> d(a); // making a copy
  assert(a.size() == d.size());
  for (int i = 0; i < a.size(); i++){
    assert(a.peek() == d.peek());
    a.pop();
    d.pop();
  }

  a.push(3000);
  a.push(4000);
  // object assignment test
  cout << "\nObject assignment test\n";
  Stack<int> e;
  e = a;
  assert(a.size() == e.size());
  for (int i = 0; i < 10; i++) {
    assert(a.size() == e.size());
    a.pop();
    e.pop();
  }
}