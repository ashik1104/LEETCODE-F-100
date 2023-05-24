class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int noo = -1;
        int row = 0;
        for(int i = 0; i < mat.size(); i++)
        {
            int number_of_one = 0;
            for(int j = 0; j < mat[i].size(); j++)
            {
                if(mat[i][j] == 1)
                {
                    number_of_one++;
                }
            }
            if(number_of_one > noo)
            {
                noo = number_of_one;
                row = i;
            }
        }
        vector<int> ans;
        ans.push_back(row);
        ans.push_back(noo);

        return ans;
    }
};