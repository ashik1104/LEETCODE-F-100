class Solution {
public:
    string convertToTitle(int columnNumber) {
        string answer = "";
        int n = columnNumber;
        while(n > 0)
        {
            n--;
            int r = n % 26;
            answer += (r + 'A');
            n = n/26;
        }
        reverse(answer.begin(), answer.end());
        return answer;
    }
};