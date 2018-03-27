/**
 * @file 70_Climbing_Stairs.cpp
 * @author yinjingcao
 * @date 2018/03/27 20:01:04
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (size_t idx = 2; idx < n; ++idx) {
            dp[idx] = dp[idx - 1] + dp[idx - 2];
        }
        return dp[n - 1];
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
