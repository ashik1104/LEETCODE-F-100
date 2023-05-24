class Solution {
public:
    int dp[1005];
    int solve(int n, vector<int> & cost)
    {
        // base case
       if(n == 0) // ei jaygata niya pain khaici
       {
           return 0;
       }
       if(n == 1)
       {
           return min(cost[0], cost[1]);
       }

        // if result is already solved, return resutl
        if(dp[n] != -1)
        {
            return dp[n];
        }

        // calculate resutl from smaller substates..
        dp[n] = min(cost[n] + solve(n-1, cost), cost[n-1] + solve(n-2, cost));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return solve(cost.size() - 1, cost);
    }
};