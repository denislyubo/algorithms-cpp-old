#include <iostream>

class Solution 
{
public:
  static int CountDigitOne(int n) 
  {
    int countOfOnes = 0;

    for (int i = 1; i <= n; ++i)
    {
      int numOfDigits = 1;
      int power = 1;

      while ((i / power) >= 10)
      {
        numOfDigits++;
        power *= 10;
      }

      int intPart = i;
      int fracPart = 0;

      while (numOfDigits >= 1)
      {
        fracPart = intPart % power;
        intPart = intPart / power;

        if (intPart == 1)
          countOfOnes++;

        numOfDigits--;
        power /= 10;

        intPart = fracPart;
      }
    }

    return countOfOnes;
  }
};

int main(int argc, char *argv[])
{

  std::cout << Solution::CountDigitOne(824883294) << std::endl;;

  return 0;
}