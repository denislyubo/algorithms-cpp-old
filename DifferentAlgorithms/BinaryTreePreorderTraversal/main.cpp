#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	
};

class Solution 
{
public:
	static vector<int> preorderTraversal(TreeNode* root) 
	{
		vector<int> res;

		if (!root)
			return res;



	}
};

int main()
{
	TreeNode *root = new TreeNode(5);
	TreeNode *left = new TreeNode(4);
	TreeNode *right = new TreeNode(6);
	root->left = left;
	root->right = right;

	vector<int> res = Solution::preorderTraversal(root);

	for (auto str : res)
		cout << str << endl;

	return 0;
}