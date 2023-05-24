class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        int lower = 0;
        for(auto ch : word)
        {
            if(ch >= 'a' and ch <= 'z')
            {
                lower++;
            }
            else
            {
                upper++;
            }
        }

        if(upper == 0 or lower == 0)
        {
            return true;
        }
        else
        {
            if(upper == 1 and word[0] >= 'A' and word[0] <= 'Z')
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};