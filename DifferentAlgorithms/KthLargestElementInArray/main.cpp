#include <algorithm>
#include <iterator>
#include <vector>
#include <functional>

using namespace std;

template <typename T>
int comp(T *a, T *b)
{
  if (*(int *)a < *(int *)b)
    return -1;
  else if (*(int *)a > *(int *)b)
    return 1;
  else
    return 0;
}

class Solution 
{
public:
  static int findKthLargest(vector<int>& nums, int k) 
  {
    qsort(nums.data(), nums.size(), sizeof(int), comp);

    if (k <= 0 || k > nums.size())
      return - 1;

    if (k == 1)
      return nums[nums.size() - 1];

    int offset = 1, counter = 1;

    for (size_t i = nums.size() - 1; i >= 1 && counter != k; --i)
    {
      if (nums[i - 1] != nums[i])
        counter++;

      offset++;
    }

    return nums[nums.size() - offset];
  }
};
class Rand
{
public:
  Rand(int randMax)
  {
    m_randMax = randMax;
  }
int operator()()
{
  return m_randMax * rand() / RAND_MAX;
}
private:
  int m_randMax;
};


int main (int argc, char *argv[])
{
  const int N = 10;
  vector<int> array;
  generate_n(back_inserter(array), N, Rand(N));

  int k = Solution::findKthLargest(array, 7);
  return 0;
}