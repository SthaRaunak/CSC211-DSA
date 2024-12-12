#define STACK_SIZE 100

struct stack
{
  int top;
  double items[STACK_SIZE];
};

int empty(struct stack *ps);

int pop(struct stack *ps);

void push(struct stack *ps, int x);

int stacktop(struct stack *ps);
