class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        map<int, int> mp;
        for(auto value : nums)
        {
            if(value == val)
            {
                continue;
            }
            mp[value]++;
        }
        int i = 0;
        int k = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            for(int j = 0; j < it->second; j++)
            {
                nums[i] = it->first;
                i++;
                k++;
            }
        }
        return k;
    }
};