class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        mp[0].push_back(root->val);
        while(!q.empty())
        {
            pair<TreeNode*, int> node = q.front();
            q.pop();
            
            if(node.first->left != NULL)
            {
                q.push({node.first->left, node.second + 1});
                mp[node.second + 1].push_back(node.first->left->val);
            }
            if(node.first->right != NULL)
            {
                q.push({node.first->right, node.second + 1});
                mp[node.second + 1].push_back(node.first->right->val);
            }
        }
        return mp.size();
    }
};