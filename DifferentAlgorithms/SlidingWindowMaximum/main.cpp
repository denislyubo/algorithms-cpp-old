#include <vector>
#include <map>

using namespace std;
class Solution 
{
public:
  static vector<int> MaxSlidingWindow(vector<int>& nums, int k) 
  {
    vector<int> res;
    multimap<int, int> map;

    for (int i = 0; i < k; ++i)
      map[nums[k]] = i;

    
};

int main(int argc, char *argv[])
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  Solution::MaxSlidingWindow(nums, k);
  return 0;
}
