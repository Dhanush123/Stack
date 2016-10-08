//
// Created by chapatel on 10/7/16.
//

#ifndef STACK_H
#define STACK_H

#include <algorithm>
using namespace std;

template <typename V>
class Stack
{
  V* values;
  int cap;
  int siz; // track size
  void capacity(int);

  public:
  Stack(int=5); // tested
  void push(const V&); // tested
  V& peek(); // tested
  void pop() {if (siz > 0) --siz;} // tested
  int size() const {return siz;} //tested
  bool empty() const {return siz==0;} //tested
  void clear() {siz = 0;} //tested
  ~Stack(){delete [] values;}
  Stack<V>& operator=(const Stack<V>&);
};

template <typename V>
Stack<V>::Stack(int cap)
{
  this->cap = cap;
  values = new V[cap];

  for (int index = 0; index < cap; index++){
    values[index] = V();
  }
  siz = 0;
}

template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original) //check if copy or not, better not be tho
  {
    // same as destructor
    delete [] values;

    // same as copy constructor
    cap = original.cap;
    siz = original.siz;
    values = new V[cap]; // not copy, is new
    for (int i = 0; i < cap; i++){ // contents copy original to new
      values[i] = original.values[i];
    }
  }
  return *this; // return self reference
}


template <typename V>
void Stack<V>::push(const V& value)
{
  if (siz == cap) capacity(2 * cap); // double the capacity if full
  values[siz] = value;
  ++siz;
}

template <typename V>
V& Stack<V>::peek()
{
  if (siz < 0){
    return values[0]; // a copy
  }
  else if (siz >= cap){
    capacity(2 * siz);
  }
  return values[siz-1]; // a copy
}

template <typename V>
void Stack<V>::capacity(int newCap)
{
  V* temp = new V[newCap];

  // get the lesser of the new and old capacities
  int limit = min(newCap,cap);

  // copy the contents
  for (int i = 0; i < limit; i++){
    temp[i] = values[i];
  }

  // set added values to their defaults
  for (int i = limit; i < cap; i++){
    temp[i] = V();
  }

  // deallocate original array
  delete [] values;

  // switch newly allocated array into the object
  values = temp;

  // update the capacity
  cap = newCap;
}

#endif
