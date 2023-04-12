using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  static int maxPathSum(TreeNode* root) 
  {
    int val = root->val, val1 = val, val2 = val;

    if (root->left)
      val1 = val + maxPathSum(root->left);


    if (root->right)
      val2 = val + maxPathSum(root->right);

    return val1 > val2 ? val1 : val2;
  }
};

int main(int argc, char *argv[])
{
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(-2);
  //TreeNode *right = new TreeNode(1);
  root->left = left;
  //root->right = right;
  
  int val = Solution::maxPathSum(root);
  return 0;
}