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
	static int maxDepth(TreeNode* root) 
	{
		int leftDepth = 0, rightDepth = 0;
		
		if (root == nullptr)
			return 0;

		TreeNode* left = root->left;
		TreeNode* right = root->right;

		if (left != nullptr)
			leftDepth = maxDepth(left);
		else
			leftDepth = 0;


		if (right != nullptr)
			rightDepth = maxDepth(right);
		else
			rightDepth = 0;

		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;

	}
};

int main()
{
	TreeNode node(5);

	Solution::maxDepth(&node);
}