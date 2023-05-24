class Solution {
public:
    int dp[1001][1020];
    int solve(int n, int cur_age_limit, vector<pair<int, int>> &score_age)
    {
        // 1. base case
        if(n < 0)
        {
            return 0;
        }

        // 2. if already solved return result
        if(dp[n][cur_age_limit] != -1)
        {
            return dp[n][cur_age_limit];
        }

        // 3. calculate from smaller sub states...
        if(score_age[n].second <= cur_age_limit)
        {
            int nt = solve(n-1, cur_age_limit, score_age);
            int t = score_age[n].first + solve(n-1, score_age[n].second, score_age);
            dp[n][cur_age_limit] = max(nt, t);
        }
        else
        {
            dp[n][cur_age_limit] = solve(n-1, cur_age_limit, score_age);
        }
        return dp[n][cur_age_limit];
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        memset(dp, -1, sizeof(dp));
        vector<pair<int,  int>> score_age;
        for(int i = 0; i < scores.size(); i++)
        {
            score_age.push_back({scores[i], ages[i]});
        }
        sort(score_age.begin(), score_age.end());
        return solve(scores.size() - 1, 1010, score_age);
    }
};