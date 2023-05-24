class Solution {
public:
    int dp[205][205];
    int solve(int r, int c, vector<vector<int>> &grid)
    {
        // 1. base case
        if(r == 0 and c == 0)
        {
            return grid[r][c];
        }

        // 2. if already solved
        if(dp[r][c] != -1)
        {
            return dp[r][c];
        }

        // 3. calculate from smaller sub states
        int ans1 = -1;
        if(r > 0)
        {
            ans1 = solve(r-1, c, grid) + grid[r][c];
        }
        int ans2 = -1;
        if(c > 0)
        {
            ans2 = solve(r, c-1, grid) + grid[r][c];
        }
        if(ans1 == -1 or ans2 == -1)
        {
            dp[r][c] = ans1 == -1 ? ans2 : ans1;
        }
        else
        {
            dp[r][c] = min(ans1, ans2);
        }
        return dp[r][c];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(r-1, c-1, grid);
    }
};