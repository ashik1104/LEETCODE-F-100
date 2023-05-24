class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp1;
        map<int, int> mp2;
        for(auto vec : items1)
        {
            mp1[vec[0]] = vec[1];
        }
        for(auto vec : items2)
        {
            mp2[vec[0]] = vec[1];
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

        for(auto it = mp1.begin(); it != mp1.end(); it++)
        {
            if(mp2.count(it->first))
            {
                pq.push({it->first, it->second + mp2[it->first]});
                mp2.erase(it->first);
            }
            else
            {
                pq.push({it->first, it->second});
            }
        }
        for(auto it = mp2.begin(); it != mp2.end(); it++)
        {
            pq.push({it->first, it->second});
        }

        vector<vector<int>> ans;

        while(!pq.empty())
        {
            vector<int> temp;
            pair<int, int> p = pq.top();
            pq.pop();
            temp.push_back(p.first);
            temp.push_back(p.second);
            ans.push_back(temp);
        }
        return ans;
    }
};