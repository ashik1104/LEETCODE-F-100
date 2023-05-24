// MS
// time -> O(n^2)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        for(int i = 0; i < nums2.size(); i++)
        {
            bool done = false;
            for(int j = i + 1; j < nums2.size(); j++)
            {
                if(nums2[j] > nums2[i])
                {
                    mp[nums2[i]] = nums2[j];
                    done = true;
                    break;
                }
            }
            if(done == false)
            {
                mp[nums2[i]] = -1;
            }
        }

        vector<int> ans;
        for(auto val : nums1)
        {
            ans.push_back(mp[val]);
        }

        return ans;
    }
};


// BS
// time-> O(nums.size() + nums2.size())

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mp;
        stack<int> s;
        for(auto val : nums2)
        {
            while(!s.empty() and s.top() < val)
            {
                mp[s.top()] = val;
                s.pop();
            }
            s.push(val);
        }
        vector<int> ans;
        for(auto val : nums1)
        {
            ans.push_back(mp.count(val) ? mp[val] : -1);
        }

        return ans;
    }
};