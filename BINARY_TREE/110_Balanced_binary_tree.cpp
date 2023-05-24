class Solution {
public:
    bool ans = true;
    int depth(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int x = depth(root->left);
        int y = depth(root->right);
        if(abs(x-y)>1)
        {
            ans = false;
        }
        return max(x,y) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int height = depth(root);
        return ans;
    }
};