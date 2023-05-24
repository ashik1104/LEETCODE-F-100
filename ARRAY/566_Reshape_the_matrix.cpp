// MS

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        if ((mat.size() * mat[0].size()) != (r * c))
        {
            return mat;
        }

        vector<int> temp;
        for (auto vec : mat)
        {
            for (auto val : vec)
            {
                temp.push_back(val);
            }
        }

        vector<vector<int>> ans;
        for (int i = 0; i < r; i++)
        {
            vector<int> a;
            for (int j = c * i; j < (i + 1) * c; j++)
            {
                a.push_back(temp[j]);
            }
            ans.push_back(a);
        }

        return ans;
    }
};

// BS

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();
        if(m * n != r * c)
        {
            return mat;
        }

        vector<vector<int>> ans;
        for(int i = 0; i < m*n; i++)
        {
            ans[i/c][i%c] = mat[i/n][i%n];
        }

        return ans;
    }

};