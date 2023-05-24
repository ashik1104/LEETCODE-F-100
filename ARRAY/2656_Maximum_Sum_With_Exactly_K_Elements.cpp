class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < k; i++)
        {
            ans += (mx+i);
        }
        return ans;
    }
};