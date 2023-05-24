class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> v;
        v = s;
        for(int i = 0; i < s.size(); i++)
        {
            s[i] = v[s.size()-1-i];
        }
    }
};