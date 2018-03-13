 /**
 * @file 5_Longest_Palindromic_Substring.cpp
 * @author yinjingcao
 * @date 2018/03/13 13:41:36
 * @version $Revision$ 
 * @brief 
 *  
 **/

// see https://segmentfault.com/a/1190000002991199

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// wrong
class Solution {
public:
    string longestPalindrome(const string& s) {
        unordered_map<char, size_t> id_map;
        unordered_map<char, size_t>::iterator itr;
        int longest_size = 0;
        int start_pos = 0;
        int idx = 0;
        string longest_str = "";
        while (idx < s.size()) {
            char c = s[idx];
            itr = id_map.find(c);
            if (itr != id_map.end()) {
                start_pos = itr->second;
                int psize = idx - start_pos + 1;
                string pstr = s.substr(start_pos, psize); 
                if (judge(pstr)) {
                    if (longest_size < psize) {
                        longest_size = psize;
                        longest_str = pstr;
                    }
                } else {
                    ++start_pos;
                }
            } else {
                id_map[c] = idx;
            }
            ++idx;
        }
        if (!s.empty() && longest_str.empty()) {
            return s.substr(0, 1);
        }
        return longest_str;
    }
    bool judge(const string& str) {
        size_t lhs = 0;
        size_t rhs = str.size() - 1;
        while (lhs < rhs) {
            if (str[lhs++] != str[rhs--]) {
                return false;
            }
        }
        return true;
    }
};

// 暴力
class Solution2 {
public:
    string longestPalindrome(const string& s) {
        int max_length = 0;
        string max_str = "";
        for (size_t idx = 0; idx < s.size(); ++idx) {
            for (size_t iidx = idx; iidx < s.size(); ++iidx) {
                string str = s.substr(idx, iidx - idx + 1);
                if (judge(str)) {
                    if (max_length < (iidx - idx + 1)) {
                        max_str = str;
                        max_length = iidx - idx + 1;
                    }
                }
            }
        }
        return max_str;
    }
    bool judge(const string& s) {
        size_t lhs = 0;
        size_t rhs = s.size() - 1;
        while (lhs < rhs) {
            if (s[lhs++] != s[rhs--]) {
                return false;
            }
        }
        return true;
    }
};

// 动态规划
class Solution3 {
public:
    string longestPalindrome(const string& s) {
        int max_length = 0;
        int max_start = 0;
        bool** dp = (bool**) malloc(sizeof(bool*) * s.size());
        for (size_t idx = 0; idx < s.size(); ++idx) {
            dp[idx] = (bool*) malloc(sizeof(bool) * s.size());
        }
        for (size_t i = 0; i < s.size(); ++i) {
            for (size_t j = 0; j < s.size() - i; ++j) {
                if (i == 0 || i == 1) {
                    dp[j][j+i] = (s[j] == s[j+i]);
                } else if(s[j] == s[j+i]) {
                    dp[j][j+i] = dp[j+1][j+i-1];
                } else {
                    dp[j][j+i] = false;
                }
                if (dp[j][j+i] && i > max_length) {
                    max_length = i;
                    max_start = j;
                }
            }
        }
        return s.substr(max_start, max_length + 1);
    }
};

int main() {
    Solution3 s;
    printf("%s\n", s.longestPalindrome("cbbd").c_str());
    printf("%s\n", s.longestPalindrome("babad").c_str());
    printf("%s\n", s.longestPalindrome("a").c_str());
    printf("%s\n", s.longestPalindrome("ccc").c_str());
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
