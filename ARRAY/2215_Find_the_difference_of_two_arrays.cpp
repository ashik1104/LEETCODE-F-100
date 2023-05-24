class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp1;
        map<int, int> mp2;
        for(auto val : nums1)
        {
            mp1[val] = 1;
        }
        for(auto val : nums2)
        {
            mp2[val] = 1;
        }

        for(int  i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    if(mp1.count(nums1[i]))
                    {
                         mp1.erase(nums1[i]);
                         mp2.erase(nums1[i]);
                    } 
                }
            }
        }

        vector<vector<int>> answer;
        vector<int> temp1;
        vector<int> temp2;
        for(auto it = mp1.begin(); it != mp1.end(); it++)
        {
            temp1.push_back(it->first);
        }
        for(auto it = mp2.begin(); it != mp2.end(); it++)
        {
            temp2.push_back(it->first);
        }
        answer.push_back(temp1);
        answer.push_back(temp2);
        return answer;
    }
};