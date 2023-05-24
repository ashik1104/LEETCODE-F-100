class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            vector<vector<int>> v;
            return v;
        }
        map<int, vector<int>> mp;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        mp[0].push_back(root->val);
        while (!q.empty())
        {
            pair<TreeNode *, int> node = q.front();
            q.pop();

            if (node.first->left != NULL)
            {
                q.push({node.first->left, node.second + 1});
                mp[node.second + 1].push_back(node.first->left->val);
            }
            if (node.first->right != NULL)
            {
                q.push({node.first->right, node.second + 1});
                mp[node.second + 1].push_back(node.first->right->val);
            }
        }
        vector<vector<int>> v(mp.size());
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            for (int i = 0; i < it->second.size(); i++)
            {
                v[it->first].push_back(it->second[i]);
            }
            if (it->first % 2 == 1)
            {
                reverse(v[it->first].begin(), v[it->first].end());
            }
        }
        return v;
    }
};