class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> mp;
        for(auto ch : s)
        {
            mp[ch]++;
        }

        vector<int> odd;
        int even_sum = 0;

        for(auto p : mp)
        {
            if(p.second % 2 == 0)
            {
                even_sum += p.second;
            }
            else
            {
                odd.push_back(p.second);
            }
        }

        int odd_sum = 0;
        for(auto val : odd)
        {
            odd_sum += val;
        }

        return odd_sum > 0 ? even_sum + (odd_sum - odd.size()) + 1 : even_sum;
    }
};


// idea： 
// count the frequency of each char, the chars appears even times can all be kept, however, the chars appears odd times must remove one char, then the rest instances of that char can be collected for composition. Finally, the middle char can be from OddGroup
// Example: "abccccdd",
// step 1: count freq of char before clearning:
// a:1
// b:1
// c:4
// d:2

// step 2: perform clearning and prepare for palindrom composition:
// a:0
// b:0
// c:4
// d:2
// answer = s.size() - 1 - 1
// Step 3: make correction, if necessary (i.e., when at least one char shows odd times)
// if OddGroup > 0: answer +=1