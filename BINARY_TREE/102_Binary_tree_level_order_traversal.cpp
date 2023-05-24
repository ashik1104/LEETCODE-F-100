class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        map<int, vector<int>> mp;

        if (root == NULL)
        {
            vector<vector<int>> ans;
            return ans;
        }
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            pair<TreeNode *, int> parent = q.front();
            q.pop();
            mp[parent.second].push_back(parent.first->val);
            if (parent.first->left)
            {
                q.push({parent.first->left, parent.second + 1});
            }
            if (parent.first->right)
            {
                q.push({parent.first->right, parent.second + 1});
            }
        }
        vector<vector<int>> ans(mp.size());
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            for (int i = 0; i < it->second.size(); i++)
            {
                ans[it->first].push_back(it->second[i]);
            }
        }
        return ans;
    }
};