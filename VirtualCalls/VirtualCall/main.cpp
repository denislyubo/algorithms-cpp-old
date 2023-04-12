#include <iostream>

using namespace std;

class Base
{
public:
  virtual void Say()
  {
    std::cout << "Say from base!\n";
  }
};

class Derived : public Base
{
public:
  void Say(const char *str)
  {
    std::cout << str << "\n";
  }
};

int main(int argc, char *argv[])
{
  Base * base = new Derived();
  base->Say();

  Derived * der = new Derived();
  der->Say("abra");

  int a;
  std::cin >> a;
  
  return 0;
}