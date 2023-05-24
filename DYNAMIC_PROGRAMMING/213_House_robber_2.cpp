class Solution {
public:
    int dp[105];
    int solve(int n, vector<int> &nums)
    {
        // 1. base case
        if(n == 0)
        {
            return nums[0];
        }
        if(n == 1)
        {
            return max(nums[0], nums[1]);
        }

        // 2. if already solved...
        if(dp[n] != -1)
        {
            return dp[n];
        }

        // 3. calculate from smaller sub states...
        int ans1 = solve(n-1, nums);
        int ans2 = nums[n] + solve(n-2, nums);
        dp[n] = max(ans1, ans2);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        if(nums.size() == 1)
        {
            return nums[0];
        }
        vector<int> temp1(nums.size()-1);
        vector<int> temp2(nums.size()-1);
        for(int i = 0; i < nums.size() - 1; i++)
        {
            temp1[i] = nums[i];
        }
        for(int i = 1; i < nums.size(); i++)
        {
            temp2[i-1] = nums[i];
        }
        memset(dp, -1, sizeof(dp));
        int ans1 = solve(temp1.size() - 1, temp1);
        memset(dp, -1, sizeof(dp));
        int ans2 = solve(temp2.size() - 1, temp2);
        return max(ans1, ans2);
    }
};