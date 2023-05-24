/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int glob_sum = 0;
    void solve(TreeNode * root)
    {
        if(root->left == NULL and root->right == NULL)
        {
            glob_sum += 0;
            return;
        }
        if(root->left != NULL)
        {
            if(root->left->left == NULL and root->left->right == NULL)
            {
                glob_sum += root->left->val;
            }
        }

        if(root->left != NULL)
        {
            solve(root->left);
        }
        if(root->right != NULL)
        {
            solve(root->right);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        solve(root);
        return glob_sum;
    }
};