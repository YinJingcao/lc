 /**
 * @file 20_Valid_Parentheses.cpp
 * @author yinjingcao
 * @date 2018/03/16 17:08:09
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> v;
        for (size_t idx = 0; idx < s.size(); ++idx) {
            char c = s[idx];
            if (c == '(' || c == '[' || c == '{') {
                v.push(c);
            } else {
                if (v.empty()) {
                    return false;
                }
                char pre_c = v.top(); 
                if ((c == ')' && pre_c == '(') || 
                        (c == ']' && pre_c == '[') || 
                        (c == '}' && pre_c == '{')) {
                    v.pop();
                } else {
                    return false;
                }
            }
        }
        return v.empty();
    }
};

int main() {
    Solution s;
    printf("%d\n", s.isValid("()"));
    printf("%d\n", s.isValid("()[]{}"));
    printf("%d\n", s.isValid("([)]"));
    printf("%d\n", s.isValid("(]"));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
