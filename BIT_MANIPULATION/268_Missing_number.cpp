// O(n) and o(1) solution from best solution

class Solution {
public:
    // int missingNumber(vector<int>& nums) {
    //     // my approach: using hash table
    //     map<int, int> mp;
    //     for(auto val : nums)
    //     {
    //         mp[val]++;
    //     }
    //     for(int i = 0; i <= nums.size(); i++)
    //     {
    //         if(mp.count(i) == 0)
    //         {
    //             return i;
    //         }
    //     }
    //     return -1;
    // }

    int missingNumber(vector<int>& nums) {
        // from solution
        // existing value 2 bar XOR hoye 0 hoye jacce 
        // mising number 1 bar XOR hocce and oita result e store hocce
        int result = nums.size();
        int i = 0;
        for(auto val : nums)
        {
            result ^= val;
            result ^= i;
            i++;
        }
        return result;
    }
};