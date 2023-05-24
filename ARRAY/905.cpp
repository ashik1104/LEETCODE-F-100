class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        for(auto val : nums)
        {
            if(val % 2==0)
            {
                even.push_back(val);
            }
            else
            {
                odd.push_back(val);
            }
        }
        for(auto val : odd)
        {
            even.push_back(val);
        }
        return even;
    }
};

//Return a new array is not difficult.
//Here I shared a solution if in-place swap asked.

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       int j = 0;
       for(int i = 0; i < nums.size(); i++)
       {
            if(nums[i] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                j++;
            }
       }
       return nums;
    }
};
