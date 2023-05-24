class Solution {
public:
    int countSegments(string s) {
        // if(s.length() == 0)
        // {
        //     return 0;
        // }
        // bool space_active = false;
        // string str = "";
        // for(int i = 0; i < s.length(); i++)
        // {
        //     if(s[i] != ' ')
        //     {
        //         str += s[i];
        //         space_active = false;
        //     }
        //     else if(s[i] == ' ' and space_active == false)
        //     {
        //         str += ' ';
        //         space_active = true;
        //     }
        // }

        // int segments = 0;
        // bool all_space = true;
        // for(auto ch : str)
        // {
        //     if(ch == ' ')
        //     {
        //         segments++;
        //     }
        //     else
        //     {
        //         all_space = false;
        //     }
        // }
        // if(all_space == true)
        // {
        //     return 0;
        // }
        
        // if(str[0] == ' ' and str.back() == ' ')
        // {
        //     return --segments;
        // }
        // else if(str.back() == ' ' or str[0] == ' ')
        // {
        //     return segments;
        // }
        // else
        // {
        //     return ++segments;
        // }


        s.push_back(' '); // This is the turning point of this code...
        int ans = 0;
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == ' ' and s[i-1] != ' ')
            {
                ans++;
            }
        }
        return ans;
    }
};