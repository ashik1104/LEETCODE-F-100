// MS

class Solution
{
public:
    // Graph problem solving by hash table
    int findJudge(int n, vector<vector<int>> &trust)
    {
        map<int, int> believe;
        map<int, int> incomming_edge;
        for (auto vec : trust)
        {
            believe[vec[0]] = 1;
            incomming_edge[vec[1]]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (believe.count(i) == 0 and incomming_edge[i] == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// AS

class Solution
{
public:
    // Graph problem solving by hash table
    int findJudge(int n, vector<vector<int>> &trust)
    {
        int findJudge(int N, vector<vector<int>> &trust)
        {
            vector<int> count(N + 1, 0);
            for (auto &t : trust)
                count[t[0]]--, count[t[1]]++;
            for (int i = 1; i <= N; ++i)
            {
                if (count[i] == N - 1)
                    return i;
            }
            return -1;
        }
    }
};