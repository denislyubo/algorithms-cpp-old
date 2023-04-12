#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  static bool IsHappy(int n) 
  {
    int tempn = n;

    vector<unsigned short int> dig;

    while (true)
    {
       int power = 1;
      int numOfDigits = 1;

      while ((tempn / power) >= 10)
      {
        numOfDigits++;
        power *= 10;
      }



      int intPart = tempn;
      int fracPart = 0;

      while (numOfDigits >= 1)
      {
        fracPart = intPart % power;
        intPart = intPart / power;

        dig.push_back(intPart);

        numOfDigits--;
        power /= 10;

        intPart = fracPart;
      }

      int res = 0;
      for (int i = 0, len = dig.size(); i < len; ++i)
      {
        res += dig[i] * dig[i];
      }
      
      if (res == 1)
        return true;
      else if (res == 4)
        return false;
      else
       tempn = res;

      dig.resize(0);
    }
  }
};

int main (int argc, char *argv[])
{
  cout << Solution::IsHappy(20) << endl;
  return 0;
}