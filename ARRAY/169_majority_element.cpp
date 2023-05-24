// My approach using map
// tc --> O(n)
// sc --> O(n)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> mp;
        for (auto val : nums)
        {
            mp[val]++;
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            if (it->second > (nums.size() / 2))
            {
                return it->first;
            }
        }
        return 0;
    }
};

// O(n) and O(1) solution

class Solution
{
public
    int majorityElement(vector<int> &nums)
    {
        int major = num[0], count = 1;
        for (int i = 1; i < num.length; i++)
        {
            if (count == 0)
            {
                count++;
                major = num[i];
            }
            else if (major == num[i])
            {
                count++;
            }
            else
                count--;
        }
        return major;
    }
}