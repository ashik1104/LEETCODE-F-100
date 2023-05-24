class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        mp[0].push_back(root->val);
        vector<int> leaf_node_depth;
        while(!q.empty())
        {
            pair<TreeNode*, int> node = q.front();
            q.pop();
            
            if(node.first->left == NULL and node.first->right == NULL)
            {
                leaf_node_depth.push_back(node.second);
            }
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
        sort(leaf_node_depth.begin(), leaf_node_depth.end());
        return leaf_node_depth[0];
    }
};