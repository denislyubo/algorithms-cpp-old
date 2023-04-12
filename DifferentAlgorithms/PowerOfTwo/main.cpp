#include <iostream>

class Solution {
public:
  static bool IsPowerOfTwo(int n) 
  {
    if (n == 0)
      return false;

    if (n == 1)
      return true;

    int nDiv2;
    while (true)
    {
      nDiv2 = n >> 1;
      if ((nDiv2 << 1) == n)
        n = nDiv2;
      else
        return false;

      if (n == 1)
        return true;
    }
  }
};

int main(int argc, char *argv[])
{
  std::cout << Solution::IsPowerOfTwo(1);
  return 0;
}