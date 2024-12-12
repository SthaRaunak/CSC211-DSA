#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct stack {
  int top;
  int items[STACK_SIZE];
};

int empty(struct stack *ps) {
  if (ps->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int pop(struct stack *ps) {
  if (empty(ps)) {
    printf("WARN: Underflow condition (STACK)");
    exit(1);
  } else {
    return ps->items[ps->top--];
  }
}

void push(struct stack *ps, int x) {
  if (ps->top == STACK_SIZE - 1) {
    printf("WARN: Overflow condition(STACK)");
    exit(1);
  }
  ps->items[++(ps->top)] = x;
  return;
}

int stacktop(struct stack *ps) {
  if (empty(ps)) {
    printf("WARN: Underflow condition (STACK)");
    exit(1);
  } else {
    return (ps->items[ps->top]);
  }
}

int main() {
  struct stack s;
  push(&s, 2);
  push(&s, 3);
  int x = pop(&s);
  printf("Popped element : %d", x);
  return 0;
}
