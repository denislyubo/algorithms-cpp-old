#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	static vector<string> binaryTreePaths(TreeNode* root) 
	{
		vector<string> resStringArray;
		string curString;

		AddElementToPath(root, curString, resStringArray);

		return resStringArray;
	}

	static void AddElementToPath(TreeNode* node, string curString, vector<string> &resStringArray)
	{
		if (node == nullptr)
			return ;

		if (curString.empty())
			curString += std::to_string(node->val);
		else
			curString += "->" + std::to_string(node->val);

		if (node->left)
			AddElementToPath(node->left, curString, resStringArray);

		if (node->right)
			AddElementToPath(node->right, curString, resStringArray);

		if (node->left == nullptr && node->right == nullptr)
			resStringArray.push_back(curString);
	}
};

int main(int argc, char *argv[])
{
	TreeNode *root = new TreeNode(5);
	TreeNode *left = new TreeNode(4);
	TreeNode *right = new TreeNode(6);
	root->left = left;
	root->right = right;
	
	vector<string> res = Solution::binaryTreePaths(root);

	for (auto str : res)
		cout << str.data() << endl;
	return 0;
}