class Solution {
public:
    bool check_palindrome(vector<char> s)
    {
        int i = 0;
        int j = s.size() - 1;
        while(i <= j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        vector<char> temp;
        for(auto ch : s)
        {
            if(ch >= 'A' and ch <= 'Z')
            {
                temp.push_back(tolower(ch));
            }
            else if(ch >= 'a' and ch <= 'z')
            {
                temp.push_back(ch);
            }
            else if(ch >= '0' and ch <= '9')
            {
                temp.push_back(ch);
            }
        }
        if(temp.size() == 0)
        {
            return true;
        }
        bool chk = check_palindrome(temp);
        return chk ? true : false;
    }
};