// MS

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<double, int> mp;
        int i = 0;
        int j = nums.size() - 1;
        while(i < j)
        {
            double avg = (double(nums[i]) + double(nums[j]))/2;
            mp[avg] = 1;
            i++;
            j--;
        }
        return mp.size();
    }
};