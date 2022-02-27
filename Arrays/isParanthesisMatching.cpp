#include <iostream>
#include <cstring>
#define SIZE 20
using namespace std;
int pop(char *stack, int &top)
{
  if (top == 0)
  {
    return -1;
  }
  top = top - 1;
  stack[top] = '\0';
  return 0;
}
int push(char *stack, int &top, char c, int n)
{
  if (top == n)
  {
    return -1;
  }
  stack[top] = c;
  top = top + 1;
  return 0;
}
void isParanthesisMatching(char *expression)
{
  char stack[SIZE] = "";
  int top = 0, result;
  for (int i = 0; i < expression[i] != '\0'; i++)
  {
    char x = expression[i];
    if (x == '(')
    {
      result = push(stack, top, x, SIZE);
    }
    else if (x == ')')
    {
      result = pop(stack, top);
    }
    if (result == -1)
    {
      cout << "NOT A BALANCED EXPRESSION\n";
      return;
    }
  }
  if (strlen(stack) == 0)
  {
    cout << "BALANCED EXPRESSION\n";
    return;
  }
  cout << "NOT A BALANCED EXPRESSION\n";
}
int main()
{
  char expression[SIZE];
  cin >> expression;
  isParanthesisMatching(expression);
}