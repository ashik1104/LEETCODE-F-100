class Solution {
public:
    int ans = 0;
    int convert(string s)
    {
        int dec = 0;
        int p = 1;
        for(int i = s.length()-1; i>=0; i--)
        {
            dec += (s[i]-'0') * p;
            p = p*2;
        }
        return dec;
    }
    void solution(TreeNode * root, string s)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            int val = convert(s+to_string(root->val));
            ans = ans + val;
            return;
        }
        
        solution(root->left, s+to_string(root->val));
        solution(root->right, s+to_string(root->val));
        
    }
    int sumRootToLeaf(TreeNode* root) {
        
        solution(root, "");
        return ans;
        
    }
};