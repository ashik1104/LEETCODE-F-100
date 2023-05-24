class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        bool all_nine = true;
        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] != 9)
            {
                all_nine = false;
                break;
            }
        }
        if(all_nine)
        {
            ans.push_back(1);
            for(int i = 0; i < digits.size(); i++)
            {
                ans.push_back(0);
            }
        }
        else if(digits[digits.size() - 1] == 9)
        {
            int before_last_nine_pos;
            for(int i = digits.size() - 2; i >= 0; i--)
            {
                if(digits[i] != 9)
                {
                    before_last_nine_pos = i;
                    break;
                }
            }
            for(int i = 0; i < digits.size(); i++)
            {
                ans.push_back(digits[i]);
            }
            ans[before_last_nine_pos]++;
            for(int i = before_last_nine_pos + 1; i < digits.size(); i++)
            {
                ans[i] = 0;
            }
        }
        else
        {
            for(int i = 0; i < digits.size(); i++)
            {
                ans.push_back(digits[i]);
            }
            ans[digits.size() - 1]++;
        }
        return ans;
    }
};