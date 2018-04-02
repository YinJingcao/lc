/**
 * @file 91_Decode_Ways.cpp
 * @author yinjingcao
 * @date 2018/04/02 16:54:24
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(const string& s) {
        if (s.empty() || s[0] == '0') return 0;
        vector<int> dp(s.size(), 1);
        for (size_t idx = 1; idx < s.size(); ++idx) {
            if (s[idx] == '0') {
                if (s[idx - 1] == '0' || s[idx - 1] >= '3') {
                    return 0;
                } else {
                    if (idx > 1 && dp[idx - 1] != dp[idx - 2]) {
                        dp[idx] = dp[idx - 1] - 1;
                    } else {
                        dp[idx] = dp[idx - 1];
                    }
                }
            } else if (s[idx - 1] == '0') {
                dp[idx] = dp[idx - 1];
            } else if (s[idx - 1] == '1') {
                dp[idx] = dp[idx - 1] + 1;
            } else if (s[idx - 1] == '2' && s[idx] < '7') {
                dp[idx] = dp[idx - 1] + 1;
            } else {
                dp[idx] = dp[idx - 1];
            }
        }
        return dp[s.size() - 1];
    }
};

int main() {
    Solution s;
    printf("%d\n", s.numDecodings("1"));
    printf("%d\n", s.numDecodings("2"));
    printf("%d\n", s.numDecodings("12"));
    printf("%d\n", s.numDecodings("123"));
    printf("%d\n", s.numDecodings("00"));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
