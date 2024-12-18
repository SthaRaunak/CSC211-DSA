#ifndef STACK_HPP
#define STACK_HPP

#define STACKSIZE 100

template <class T> class Stack {
private:
  int tos;
  T *items;

public:
  Stack();
  bool empty();
  void push(T item);
  T pop();
  T peek();
  void display();
  ~Stack();
};

#endif
