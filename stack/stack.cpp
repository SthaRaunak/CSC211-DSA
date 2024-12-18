#include "stack.hpp"
#include <iostream>
#include <memory.h>
#include <stdlib.h>

using namespace std;

template <class T> Stack<T>::Stack() {
  tos = -1;
  items = new T[STACKSIZE];
}

template <class T> bool Stack<T>::empty() { return tos == -1; }

template <class T> void Stack<T>::push(T item) {
  if (tos == (STACKSIZE - 1)) {
    cerr << "Stack overflow" << endl;
    return;
  }
  // items[++top] = item;
  *(items + (++tos)) = item; // verbose using pointer arithmetic
}
template <class T> T Stack<T>::pop() {
  T item;
  if (empty()) {
    cerr << "Stack underflow" << endl;
    return -1;
  }
  item = *(items + (tos--));
  cout << "popped element: " << item << endl;
  return item;
}

template <class T> T Stack<T>::peek() {
  T item;
  if (empty()) {
    cerr << "Stack undeflow" << endl;
    return -1;
  }
  item = *(items + tos);
  cout << "peek element: " << item << endl;
  return item;
}

template <class T> void Stack<T>::display() {
  int i;
  cout << "Stack:" << endl;
  for (i = tos; i >= 0; i--) {
    cout << *(items + i) << endl;
  }
}

template <class T> Stack<T>::~Stack() { delete[] items; }

