class Solution {
public:
    int mySqrt(int x) {
        int ans = -1;
        double eps = 1e-6;
        double lo = 0;
        double hi = 5000000;
        while(hi - lo >= eps)
        {
            double mid = (hi+lo)/2;
            if(mid * mid > x)
            {
                hi = mid;
                ans = mid;
            }
            else
            {
                lo = mid;  
            }
        }
        return ans;
    }
};