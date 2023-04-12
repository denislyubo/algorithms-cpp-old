#include <iostream>
#include <numeric>
#include <vector>

class Solution {
public:
  static int CountPrimes(int n) 
  {
    if (n == 0 || n == 1 || n == 2)
      return 0;
    
    std::vector<char> prime(n, true);
    prime[0] = prime[1] = false;

    for (unsigned long int i = 2; i < n; ++i)
    {
      if (prime[i])
        if (i * i < n)
          for (unsigned long int j = i * i; j < n; j += i)
            prime[j] = false;
    }

    unsigned long int sum = 0;
    return std::accumulate(prime.begin(), prime.end(), sum);
  }
};

int main(int argc, char *argv[])
{
  std::cout << Solution::CountPrimes(1);
  return 0;
}