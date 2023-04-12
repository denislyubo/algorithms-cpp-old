#include <iostream>

void swap(int &a, int &b)
{
  int temp = a;
  a = b;
  b = temp;
}

// greatest common divisor
int gcd (int a, int b) {
  while (b) {
    a %= b;
    swap (a, b);
  }
  return a;
}
// least common multiplier
int lcm (int a, int b) 
{
  return a / gcd (a, b) * b;
}

int main(int argc, char *argv[])
{
  int a, b;
  
  std::cin >> a;
  std::cin >> b;


  std::cout << gcd(a, b) << std::endl;

  std::cin >> a;
  
  return 0;
}