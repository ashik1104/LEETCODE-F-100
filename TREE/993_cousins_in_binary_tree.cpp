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
    int parent[110];
    int level[110];
    void helper(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        level[root->val] = 0;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left != NULL)
            {
                q.push(node->left);
                level[node->left->val] = level[node->val] + 1;
                parent[node->left->val] = node->val;
            }
            if(node->right != NULL)
            {
                q.push(node->right);
                level[node->right->val] = level[node->val] + 1;
                parent[node->right->val] = node->val;
            }
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root);
        if(level[x] == level[y] and parent[x] != parent[y])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};