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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 1. base case
        if(p == NULL and q != NULL)
        {
            return false;
        }
        if(p != NULL and q == NULL)
        {
            return false;
        }
        if(p == NULL and q == NULL)
        {
            return true;
        }
        if(p->val != q->val)
        {
            return false;
        }

        // 2. calculate from smaller substates..
        bool a = isSameTree(p->left, q->left);
        if(a == false)
        {
            return false;
        }
        bool b = isSameTree(p->right, q->right);
        if(b == false)
        {
            return false;
        }
        return true;
    }
};