class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex + 1);
        answer[0] = 1;
        answer[rowIndex] = 1;
        long long int temp = 1;
        int h = rowIndex;
        int l = 1;
        for(int i = 1; i < rowIndex; i++)
        {
            temp = (temp * h)/l;
            answer[i] = temp;
            h--;
            l++;
        }
        return answer;
    }
};