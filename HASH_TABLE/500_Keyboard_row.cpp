class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        map<char, int> mp;

        string r11 = "qwertyuiop";
        string r12 = "QWERTYYUIOP";
        string r21 = "asdfghjkl";
        string r22 = "ASDFGHJKL";
        string r31 = "zxcvbnm";
        string r32 = "ZXCVBNM";

        for(auto ch : r11)
        {
            mp[ch] = 1;
        }
        for(auto ch : r12)
        {
            mp[ch] = 1;
        }

        for(auto ch : r21)
        {
            mp[ch] = 2;
        }
        for(auto ch : r22)
        {
            mp[ch] = 2;
        }

        for(auto ch : r31)
        {
            mp[ch] = 3;
        }
        for(auto ch : r32)
        {
            mp[ch] = 3;
        }

        vector<string> answer;
        
        for(auto word : words)
        {
            int level = mp[word[0]];
            bool same = true;
            for(auto ch : word)
            {
                if(mp[ch] != level)
                {
                    same = false;
                    break;
                }
            }
            if(same)
            {
                answer.push_back(word);
            }
        }

        return answer;
    }
};