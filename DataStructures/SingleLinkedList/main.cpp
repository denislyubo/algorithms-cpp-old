#include <iostream>
#include <stdlib.h>

#include <SingleLinkedList/SingleLinkedList.h>

#define N 100

using namespace DataStructures;

int main(int argc, char *argv[])
{
  {
    DataStructures::SingleLinkedList<double> list;

    for (int i = 0; i < N; ++i)
    {
      list.push_back(double(N - i - 1));
    }
      
    list.Invert();

    //double b = 5;
    //SingleLinkedList<double>::iterator it = list.Find(list.begin(), list.end(), b);

    for (int i = 0; i < N; ++i)
      std::cout << list.pop() << std::endl;

  }

  int a;
  std::cin >> a;

  return 0;
}