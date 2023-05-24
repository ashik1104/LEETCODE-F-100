// Using map

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, int> mp;
        for(auto vec : edges)
        {
            mp[vec[0]]++;
            mp[vec[1]]++;
        }
        int mx_edge = 0;
        int ans_node;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            if(it->second > mx_edge)
            {
                mx_edge = it->second;
                ans_node = it->first;
            }
        }
        return ans_node;
    }
};



// Best of the bests solution

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] or edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};