class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int, int> mp;
        for(auto val : nums)
        {
            mp[val]++;
        }
        int i = 0;
        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            nums[i] = it->first;
            i++;
        }
        return mp.size();
    }
};