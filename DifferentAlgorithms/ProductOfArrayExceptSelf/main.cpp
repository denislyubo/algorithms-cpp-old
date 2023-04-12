#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

class Solution 
{
public:
  static vector<int> productExceptSelf(vector<int>& nums) 
  {
    int len = nums.size();

    if (len < 2)
      return nums;

    vector<int> res1(len, 1);
    vector<int> res2(len, 1);
    vector<int> output(len, 1);

    for (int i = 1; i < len; ++i)
      res1[i] = nums[i - 1] * res1[i - 1];

    for (int i = len - 2; i >= 0; --i)
      res2[i] = nums[i + 1] * res2[i + 1];

    for (int i = 0; i < len; ++i)
      output[i] = res1[i] * res2[i];

    return output;
  }
};

int val = 1;
int func()
{
  return val++;
}

int main (int argc, char *argv[])
{
  int SZ = 4;

  vector<int> array(SZ);

  generate_n(array.begin(), SZ, func);

  vector<int> res = Solution::productExceptSelf(array);

  for (auto it = res.begin(); it != res.end(); it++)
  {
    cout << *it << " ";
  }

  return 0;
}