class Solution
{
    // negative indexing has controlled here....

public:
    int dp[25][50000];
    int solve(int n, int target, vector<int> &nums)
    {
        // 1. base case
        if (n == -1)
        {
            if (target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }

        // 2. if already solved return resutlj
        if (target < 0)
        {
            if (dp[n][25000 + abs(target)] != -1)
            {
                return dp[n][25000 + abs(target)];
            }
        }
        else
        {
            if (dp[n][target] != -1)
            {
                return dp[n][target];
            }
        }

        // 3. calculate result from smaller sub states....
        int ans1 = solve(n - 1, target + nums[n], nums);
        int ans2 = solve(n - 1, target - nums[n], nums);
        if (target < 0)
        {
            dp[n][25000 + abs(target)] = ans1 + ans2;
        }
        else
        {
            dp[n][target] = ans1 + ans2;
        }
        return ans1 + ans2;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof(dp));
        return solve(nums.size() - 1, target, nums);
    }
};