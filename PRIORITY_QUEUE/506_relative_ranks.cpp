class Solution
{
public:
    int string_to_int(string s)
    {
        stringstream val;
        val << s;
        int x = 0;
        val >> x;
        return x;
    }
    vector<string> findRelativeRanks(vector<int> &score)
    {
        priority_queue<int, vector<int>> pq;
        for (auto val : score)
        {
            pq.push(val);
        }
        map<int, string> mp;
        int i = 1;
        while (!pq.empty())
        {
            int val = pq.top();
            pq.pop();
            mp[val] = to_string(i);
            i++;
        }

        vector<string> answer;
        for (auto val : score)
        {
            answer.push_back(mp[val]);
        }

        for (int j = 0; j < answer.size(); j++)
        {
            if (answer[j] == "1")
            {
                answer[j] = "Gold Medal";
            }
            else if (answer[j] == "2")
            {
                answer[j] = "Silver Medal";
            }
            else if (answer[j] == "3")
            {
                answer[j] = "Bronze Medal";
            }
        }

        return answer;
    }
};