class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // my approach: using hash table
        // O(n), O(n)
        map<int, int> mp;
        for(auto val : nums)
        {
            mp[val]++;
        }
        for(int i = 0; i <= nums.size(); i++)
        {
            if(mp.count(i) == 0)
            {
                return i;
            }
        }
        return -1;
    }
};