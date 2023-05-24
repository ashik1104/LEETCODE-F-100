// my approach --> using map
// time complexity ---> O(n)
// space complexity ---> O(n)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto val : nums)
        {
            mp[val]++;
        }

        int ans;
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second == 1)
            {
                ans = it->first;
                break;
            }
        }
        return ans;
    }
};

// using sorting
// tc --> O(nlogn)
// sc --> O(1)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2)
        {
            if (nums[i] != nums[i - 1])
                return nums[i - 1];
        }
        return nums[nums.size() - 1];
    }
};

// using bitwise XOR
// tc --> O(n)
// sc --> O(1)

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
        {
            ans ^= x;
        }
        return ans;
    }
};