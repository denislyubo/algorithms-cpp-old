#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	static void swap(vector<int> &nums, int i, int j)
	{
		int temp = nums[i];
		nums[i] = nums[j];
		nums[j] = temp;
	}
	//static void moveZeroes(vector<int>& nums) {
	//	int size = (int)nums.size();
	//	int zeroFirstIndex = size - 1;
	//	int curInd = 0;

	//	for (int i = 0; i < size; ++i)
	//	{
	//		if (nums[i] == 0)
	//		{
	//			curInd = i;
	//			while (curInd < zeroFirstIndex)
	//			{
	//				swap(nums, curInd, curInd + 1);
	//				curInd++;
	//			}

	//			zeroFirstIndex--;
	//		}
	//	}
	//}

	static void moveZeroes(vector<int>& nums) {
		int size = (int)nums.size();
		int currLastZeroPos = size - 1;

		if (size == 1)
			return;
		
		for (int i = size - 2; i >= 0; --i)
		{
			if (nums[i] == 0)
			{
				for (int j = i; j < currLastZeroPos; ++j)
				{
					swap(nums, j, j + 1);
				}

				currLastZeroPos--;
			}
		}
	}
};

int main()
{
	vector<int> nums{ 1, 7, 0, 7, 9, 5, 0, 2, 0, 3 };

	Solution::moveZeroes(nums);

	for (auto elem : nums)
		cout << elem << "\n";

	int a;
	cin >> a;
}