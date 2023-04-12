#include "stdint.h"
#include <iostream>

class Solution {
public:
  static uint32_t ReverseBits(uint32_t n) 
  {
    uint32_t numOfBits = sizeof(n) * 8;
    uint32_t reverce = 0;

    for (uint32_t i = 0; i < numOfBits; ++i)
      if (n & (1 << i))
        reverce |= 1 << (numOfBits - 1 - i); 
    
    return reverce;
  }
};

int main (int argc, char *argv[])
{
  int a = 0;

  a = 1 << 0;
  
  std::cout << Solution::ReverseBits(2);

  return 0;
}