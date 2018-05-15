/**
 * @file 120_Triangle.cpp
 * @author yinjingcao
 * @date 2018/05/14 16:38:22
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.empty()) return 0;
        vector<int> dp(triangle[triangle.size() - 1]);
        for (int i = int(triangle.size()) - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = min(dp[j] + triangle[i][j], dp[j + 1] + triangle[i][j]);
            }
        }
        return dp[0];
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
