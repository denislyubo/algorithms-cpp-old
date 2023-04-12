#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  static vector<string> SummaryRanges(vector<int>& nums) 
  {
    vector<string> ranges;
    bool startRange = false;
    int begSymbol = 0, endSymbol = 0;

    for (int i = 0, len = nums.size(); i < len; ++i)
    {
      if (!startRange)
      {
        begSymbol = nums[i];
        startRange = true;
      }
      if (((i + 1) == len) || ((nums[i + 1] - nums[i]) != 1))
      {
        endSymbol = nums[i];
        startRange = false;

        if (begSymbol != endSymbol)
          ranges.push_back(to_string(begSymbol) + "->" + to_string(endSymbol));
        else
          ranges.push_back(to_string(begSymbol));
      }
    }

    return ranges;
  }
};

int main(int argc, char *argv[])
{
  vector<int> nums = { 0, 1, 2, 4, 5, 7 , 9, 10, 11};

  vector<string> ranges = Solution::SummaryRanges(nums);

  for (int i = 0, len = ranges.size(); i < len; ++i)
  {
    cout << ranges[i] << endl;
  }
  return 0;
}