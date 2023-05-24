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
    vector<vector<int>> answer;
    vector<int> temp;
    void solve(TreeNode * root, int target_sum, int current_sum)
    {
        if(current_sum + root->val == target_sum and root->left == NULL and root->right == NULL)
        {
            answer.push_back(temp);
            temp.pop_back();
            return;
        }
        if(root->left != NULL)
        {
            temp.push_back(root->left->val);
            solve(root->left, target_sum, current_sum + root->val);
        }
        if(root->right != NULL)
        {
            temp.push_back(root->right->val);
            solve(root->right, target_sum, current_sum + root->val);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
        {
            return answer;
        }
        temp.push_back(root->val);
        solve(root, targetSum, 0);
        return answer;
    }
};