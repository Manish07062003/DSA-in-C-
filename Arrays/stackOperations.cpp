#include <iostream>
#include <cstring>
#define SIZE 20
using namespace std;
void pop(int *stack, int &top)
{
  if (top == 0)
  {
    cout << "Cannot pop, Stack is empty\n";
    return;
  }
  top--;
  cout << stack[top] << " is poped from the stack\n";
  stack[top] = '\0';
}
void push(int *stack, int &top, int c, int n)
{
  if (top == n)
  {
    cout << "Stack is full\n";
    return;
  }
  stack[top] = c;
  cout << c << " is pushed to the stack\n";
  top++;
}
void display(int *stack, int top)
{
  for (int i = 0; i < top; i++)
  {
    if (i == top - 1)
    {
      cout << stack[i] << endl;
    }
    else
    {
      cout << stack[i] << " ";
    }
  }
}
int main()
{
  int stack[SIZE];
  int top = 0;
  int choice;
  cout << "1)Push\n2)Pop\n3)Print Stack\n4)Exit\n\n";
  cout << "Enter your choice: \n";
  cin >> choice;
  if (choice == 2)
  {
    cout << "Cannot pop since there are no element in the stack";
    return 0;
  }
  while (choice != 4)
  {
    switch (choice)
    {
    case 1:
      int c;
      cout << "ENTER THE NUMBER TO BE PUSHED:\n";
      cin >> c;
      push(stack, top, c, SIZE);
      break;
    case 2:
      pop(stack, top);
      break;
    case 3:
      display(stack, top);
      break;

    default:
      cout << "INVALID CHOICE\n";
      break;
    }
    cout << "ENTER YOUR CHOICE\n";
    cin >> choice;
  }
}