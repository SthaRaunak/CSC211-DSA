// assuming the input line is in form of string with digit and operator symbols
// and number are single non -ve digits (0-9)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "stack-implementation.h"

#define MAX_COLS 80 // max no of characters in the expression
#define TRUE 1
#define FALSE 0

double evaluate(char[]);
int isdigitcheck(char);
double operation(int, double, double);

int main()
{
  char expr[MAX_COLS];
  int position = -1;

  // input the original postfix expression in the char array
  while ((expr[++position] = getchar()) != '\n')
    ;
  expr[position] = '\0';

  printf("The original postfix expression: %s", expr);

  double res = evaluate(expr);

  printf("The result of this operation is %d", res);

  return 0;
}

double evaluate(char pexpr[])
{
  int c, position;
  double op1, op2;
  struct stack opndstk;

  opndstk.top = -1;

  for (position = 0; (c = pexpr[position]) != '\0'; position++)
  {
    if (isdigitcheck(c))
    {
      push(&opndstk, (double)(c - '0'));
    }
    else
    {
      op2 = pop(&opndstk);
      op1 = pop(&opndstk);
      push(&opndstk, operation(c, op1, op2));
    }
  }

  return pop(&opndstk);
}

int isdigitcheck(char symb)
{
  return (symb >= '0' && symb <= '9');
}

double operation(int symb, double op1, double op2)
{
  switch (symb)
  {
  case '+':
    return (op1 + op2);
  case '-':
    return (op1 - op2);
  case '*':
    return (op1 + op2);
  case '/':
    return (op1 / op2);
  case '$':
    return pow(op1, op2);
  default:
    printf("invalid operator");
  }
}