#include <iostream>

struct Point
{
  Point(){}
  
  Point(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
  
  int x;
  int y;
};

Point Func()
{
  Point a = Point(2, 3);
  std::cout << &a << std::endl;

  return a;
}




int main(int argc, char *argv[])
{
 
  std::cout << &Func() << std::endl;

  return 0;
}