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
    // recursive solution
    // vector<int> answer;
    // void solve(TreeNode * root)
    // {
    //     if(root == NULL)
    //     {
    //         return;
    //     }
    //     answer.push_back(root->val);
    //     solve(root->left);
    //     solve(root->right);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     if(root == NULL)
    //     {
    //         return answer;
    //     }
    //     solve(root);
    //     return answer;
    // }

    // iterative solution
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> solution;
        if(root == NULL)
        {
            return solution;
        }
        
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode * head = s.top();
            s.pop();
            solution.push_back(head->val);

            if(head->right != NULL)
            {
                s.push(head->right);
            }
            if(head->left != NULL)
            {
                s.push(head->left);
            }
        }
        return solution;
    }
};