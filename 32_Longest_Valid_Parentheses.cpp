/**
 * @file 32_Longest_Valid_Parentheses.cpp
 * @author yinjingcao
 * @date 2018/03/20 15:20:24
 * @version $Revision$ 
 * @brief 
 *  
 **/

// https://segmentfault.com/a/1190000011549629

#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(const string& s) {
        stack<char> st;
        int len = 0;
        int max_len = 0;
        for (size_t idx = 0; idx < s.size(); ++idx) {
            if (s[idx] == '(') {
                st.push(s[idx]);
            } else {
                if (!st.empty()) {
                    char c = st.top();
                    if (c == '(') {
                        st.pop();
                        if (!st.empty()) {
                            len = 0;
                        }
                        len += 2;
                        if (max_len < len) {
                            max_len = len;
                        }
                    }
                }
            }
        }
        return len;
    }
};

class Solution2 {
public:
    int longestValidParentheses(const std::string& s) {
        int left = 0, longest = 0, len = s.size();
        std::vector<int> vec(len);
        for (int i = 0; i < len; ) {
            if (s[i] == '(') {
                vec[left++] = i++;
            } else if (s[i++] == ')' && left > 0) {
                int tmp = i - vec[--left];
                if (tmp > longest)
                    longest = tmp;
                if (i < len && s[i] == '(')
                    vec[left++] = i++ - tmp;
            }
        }
        return longest;
    }
};

int main() {
    Solution2 s;
    printf("%d\n", s.longestValidParentheses(")()())"));
    printf("%d\n", s.longestValidParentheses("(()"));
    printf("%d\n", s.longestValidParentheses("()(()"));
    printf("%d\n", s.longestValidParentheses("()(())"));
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
