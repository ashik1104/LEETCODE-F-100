class Solution {
public:
    int dp[205][20004];
    bool solve(int n, int target, vector<int> &nums)
    {
        // 1. base case
        if(n == -1)
        {
            if(target == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        // 2. if already solve return result
        if(dp[n][target] != -1)
        {
            return dp[n][target];
        }

        // 3. calculate from smaller sub states..
        bool ans1 = solve(n-1, target, nums);
        if(target < nums[n])
        {
            dp[n][target] = ans1;
            return ans1;
        }
        bool ans2 = solve(n-1, target-nums[n], nums);
        dp[n][target] = ans1 or ans2;
        return dp[n][target];
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int initial_sum = 0;
        int sum = accumulate(nums.begin(), nums.end(), initial_sum);
        if(sum % 2 == 1)
        {
            return false;
        }
        else
        {
            return solve(nums.size() - 1, sum/2, nums);
        }
    }
};