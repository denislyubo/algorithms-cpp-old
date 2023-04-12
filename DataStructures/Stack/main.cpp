#include <iostream>
#include "Stack/Stack.h"

using namespace DataStructures;

#define N 100

int main(int argc, char *argv[])
{
  Stack<double> stack;
  double a = 1;
  for (int i = 0; i < N; ++i)
  {
    a = i;
    stack.Push_back(a);
  }

  for (int i = 0; i < N; ++i)
    std::cout << stack.Pop() << std::endl;

  return 0;
}