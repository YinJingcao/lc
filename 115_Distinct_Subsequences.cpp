/**
 * @file 115_Distinct_Subsequences.cpp
 * @author yinjingcao
 * @date 2018/05/09 14:44:53
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    int numDistinct(const string& s, const string& t) {
        return helper(s, t, 0, 0);
    }
private:
    int helper(const string& s, const string& t, int i, int j) {
        if (t.size() <= j) {
            return 1;
        }
        if (s.size() <= i) {
            return 0;
        }
        int sum = 0;
        if (s[i] == t[j]) {
            sum += helper(s, t, i + 1, j + 1);
        }
        sum += helper(s, t, i + 1, j);
        return sum;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
