#include <iostream>
#include "SingleLinkedList/SingleLinkedList.h"
#include "Stack/Stack.h"

#define N 3

using namespace DataStructures;

template <typename T>
bool InvertSSList(SingleLinkedList<T> &list)
{
  SingleLinkedList<T> tempList = list;

  list.clear();

  for (int i = 0, len = tempList.Length(); i < len; i++)
    list.push_back(tempList.pop());

  return false;
}

int main(int argc, char* argv[])
{
  DataStructures::SingleLinkedList<double> list;

  for (int i = 0; i < N; ++i)
    list.push_back(double(i));

  InvertSSList<double>(list);

  return 0;
}