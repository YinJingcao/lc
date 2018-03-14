 /**
 * @file 10_Regular_Expression_Matching.cpp
 * @author yinjingcao
 * @date 2018/03/14 14:23:16
 * @version $Revision$ 
 * @brief 
 *  
 **/

// see https://segmentfault.com/a/1190000007275456

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        return isMatch(s, 0, p, 0);
    }
    bool isMatch(const string& s, size_t i, const string& p, size_t j) {
        if (s.size() <= i) {
            return (p.size() <= j || (p.size() > j + 1 && p[j + 1] == '*' && isMatch(s, i, p, j + 2)));
        }
        if (p.size() > j + 1 && p[j + 1] == '*') {
            if (s[i] == p[j] || p[j] == '.') {
                return isMatch(s, i + 1, p, j) || isMatch(s, i, p, j + 2);
            } else {
                return isMatch(s, i, p, j + 2);
            }
        } else {
            if (s[i] == p[j] || p[j] == '.') {
                return isMatch(s, i + 1, p, j + 1);
            } else {
                return false;
            }
        }
    }
};

int main() {
    Solution s;
    printf("%d\n", s.isMatch("", ""));
    printf("%d\n", s.isMatch("aa", "a"));
    printf("%d\n", s.isMatch("aa", "aa"));
    printf("%d\n", s.isMatch("aaa", "aa"));
    printf("%d\n", s.isMatch("aa", "a*"));
    printf("%d\n", s.isMatch("aa", ".*"));
    printf("%d\n", s.isMatch("ab", ".*"));
    printf("%d\n", s.isMatch("aab", "c*a*b"));
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
