#include <vector>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
	static int removeElement(vector<int>& nums, int val) {
		int p = 0;
		int q = nums.size() - 1;
		while (p <= q)
		{
			if (nums[p] != val)
				p++;
			else if (nums[q] == val)
				q--;
			else
			{
				int tmp = nums[p];
				nums[p++] = nums[q];
				nums[q--] = tmp;
			}
		}

		return p;


	}
};

TEST(LinkedListTest, ListEmpty) {

}

TEST(LinkedListTest, ListOneEl) {

}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();


	int a;
	cin >> a;

	return 0;
}