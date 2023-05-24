// MS

class Solution {
public:
    string addStrings(string num1, string num2) {
        string answer = "";
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry = 0;
        while(i >= 0 or j >= 0)
        {
            if(i >= 0 and j >= 0)
            {
                int a = int(num1[i] - '0');
                int b = int(num2[j] - '0');
                int sum = a + b + carry;
                if(sum < 10)
                {
                    answer += char(sum + '0');
                    carry = 0;
                }
                else
                {
                    answer += char((sum % 10) + '0');
                    carry = 1;
                }
                i--;
                j--;
            }
            else if(i >= 0)
            {
                int a = int(num1[i] - '0');
                int b = 0;
                int sum = a + b + carry;
                if(sum < 10)
                {
                    answer += char(sum + '0');
                    carry = 0;
                }
                else
                {
                    answer += (sum % 10) + '0';
                    carry = 1;
                }
                i--;
            }
            else if(j >= 0)
            {
                int a = 0;
                int b = int(num2[j] - '0');
                int sum = a + b + carry;
                if(sum < 10)
                {
                    answer += char(sum + '0');
                    carry = 0;
                }
                else
                {
                    answer += char((sum % 10) + '0');
                    carry = 1;
                }
                j--;
            }
        }

        if(carry == 1)
        {
            answer += char(1 + '0');
        }

        reverse(answer.begin(), answer.end());
        return answer;
    }
};