class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {

        // solution - 1: My approach // greedy

        // vector<int> v;
        // for(int i = 0; i < numOnes; i++)
        // {
        //     v.push_back(1);
        // }
        // for(int i = 0; i < numZeros; i++)
        // {
        //     v.push_back(0);
        // }
        // for(int i = 0; i < numNegOnes; i++)
        // {
        //     v.push_back(-1);
        // }

        // int sum = 0;
        // for(int i = 0; i < k; i++)
        // {
        //     sum += v[i];
        // }

        // return sum;


        // Solution 2: best solution // math
        return min(k, numOnes) - max(0, k - numOnes - numZeros);
    }
};