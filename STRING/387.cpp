// MS

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, vector<int>> counts;
        for(int i = 0; i < s.length(); i++)
        {
            counts[s[i]].push_back(i);
        }
        bool nr_exist = false;

        int idx = s.size();
        for(auto p : counts)
        {
            if(p.second.size() == 1)
            {
                idx = min(idx, p.second[0]);
                nr_exist = true;
            }
        }
        if(!nr_exist)
        {
            return -1;
        }
        return idx;
    }
};