struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	static bool isSameTree(TreeNode* p, TreeNode* q) 
	{
		bool resOfCheckL = false, resOfCheckR = false;

		if (p != nullptr && q != nullptr)
		{
			if (p->val != q->val)
				return 0;
		}
		else if (p == nullptr && q == nullptr)
		{
			return 1;
		}
		else
			return 0;
		
		resOfCheckL = isSameTree(p->left, q->left);
		resOfCheckR = isSameTree(p->right, q->right);

		return resOfCheckL && resOfCheckR;
	}
};

int main()
{


}