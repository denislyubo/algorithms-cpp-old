
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
      if (root)
      {
        TreeNode *node = root->left;
        root->left = root->right;
        root->right = node;

        invertTree(root->left ? root->left : nullptr);
        invertTree(root->right ? root->right : nullptr);
      }

      return root;
    }
};

int main (int argc, char *argv[])
{

  return 0;
}