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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        if(root == NULL)
        {
            return ans;
        }
        
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            pair<TreeNode*, int> p = q.front();
            q.pop();
            TreeNode * node = p.first;
            int node_val = p.first->val;
            int l = p.second;
            mp[l].push_back(node_val);
            
            if(node->left != NULL)
            {
                q.push({node->left, l+1});
            }
            if(node->right != NULL)
            {
                q.push({node->right, l+1});
            }
        }
        for(auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            vector<int> temp;
            for(auto val : it->second)
            {
                temp.push_back(val);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};