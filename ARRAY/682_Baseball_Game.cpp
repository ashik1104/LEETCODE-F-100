class Solution {
public:
    int convert(string s)
    {
        int sum = 0, c = 1;
        for(int i = s.length()-1; i>=0; i--)
        {
            if(s[i] == '-')
            {
                return -sum;
            }
            
            int digit = s[i] - '0';
            sum += (digit*c);
            c = c*10; 
        }
        return sum;
    }
    
    int calPoints(vector<string>& ops) {
        
        stack<int> st;
        
        for(string s:ops)
        {
            if(s == "+")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }
            else if(s == "D")
            {
                st.push(st.top() * 2);
            }
            else if(s == "C")
            {
                st.pop();
            }
            else
            {
                int val = convert(s);
                st.push(val);
            }
        }
        
        int sum = 0;
        while(!st.empty())
        {
            sum += st.top();
            st.pop();
        }
        
        return sum;
        
    }
    
};