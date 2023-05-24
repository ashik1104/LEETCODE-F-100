// MS

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        // if the size of array is 3
        if(nums.size() == 3)
        {
            return nums[0]*nums[1]*nums[2];
        }

        sort(nums.begin(), nums.end());
        // if all elements are negative
        if(nums.back() < 0)
        {
            return nums.back() * nums[n-2] * nums[n-3];
        }
        // if maximum 2 elements are positive
        if(nums[n-3] <= 0)
        {
            return nums[0] * nums[1] * nums.back();
        }
        
        // for all other cases..
        if((abs(nums[0]) * abs(nums[1])) > (nums[n-2] * nums[n-3]))
        {
            return nums[0] * nums[1] * nums.back();
        }
        else
        {
            return nums[n-1] * nums[n-2] * nums[n-3];
        }
    }
};

// More easier to understand

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int a = nums[0]*nums[1] * nums.back();
        int n = nums.size();
        int b = nums.back() * nums[n-2] * nums[n-3];
        return max(a, b);
    }
};