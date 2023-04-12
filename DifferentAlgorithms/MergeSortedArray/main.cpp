#include <vector>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

class Solution {
public:
	static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> tempNums1(nums1);
		nums1.resize(n + m);

		int i{}, j{}, k{};

		while (k < n + m) {

			if (i >= m) {
				nums1[k++] = nums2[j++];
			}
			else if (j >= n) {
				nums1[k++] = tempNums1[i++];
			}
			else if (tempNums1[i] < nums2[j]) {
				nums1[k++] = tempNums1[i++];
			}
			else {
				nums1[k++] = nums2[j++];
			}
		}
	}
};

TEST(MergeTest, MergeEmpty) {
	using Vect = vector<int>;
	Vect nums1 = {  }, nums2 = {  };

	Solution::merge(nums1, nums1.size(), nums2, nums2.size());
	EXPECT_EQ(0, nums1.size());
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	using Vect = vector<int>;
	Vect nums1 = { 1,5,7,54,78,87 }, nums2 = { 4,8,19,22,28,67,69,91 };
	
	Solution::merge(nums1, nums1.size(), nums2, nums2.size());

	for (const auto var : nums1) {
		cout << var << " " << endl;
	}

	int a;

	cin >> a;

	return 0;
}