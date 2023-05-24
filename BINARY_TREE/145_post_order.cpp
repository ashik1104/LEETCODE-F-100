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
    // void solve(TreeNode* root)
    // {
    //     if(root == NULL)
    //     {
    //         return;
    //     }
    //     solve(root->left);
    //     solve(root->right);
    //     answer.push_back(root->val);
    // }
    // vector<int> postorderTraversal(TreeNode* root) {
    //     if(root == NULL)
    //     {
    //         return answer;
    //     }
    //     solve(root);
    //     return answer;
    // }


    // iterative solution
    // using two stack

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> answer;
        if(root == NULL)
        {
            return answer;
        }
        stack<TreeNode*> s1;
        stack<int> temp;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode* node = s1.top();
            s1.pop();
            temp.push(node->val);
            if(node->left != NULL)
            {
                s1.push(node->left);
            }
            if(node->right != NULL)
            {
                s1.push(node->right);
            }
        }

        while(!temp.empty())
        {
            answer.push_back(temp.top());
            temp.pop();
        }

        return answer;
    }
};