 /**
 * @file 9_Palindrome_Number.cpp
 * @author yinjingcao
 * @date 2018/03/14 14:15:40
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        return x == reverse(x);
    }
    int reverse(int x) {
        int64_t result = 0;
        char buff[256];
        snprintf(buff, 256, "%d", x);
        string s(buff);
        std::reverse(s.begin(), s.end());
        sscanf(s.c_str(), "%ld", &result);
        if (result > INT_MAX) {
            return 0;
        }
        return result;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.isPalindrome(123));
    printf("%d\n", s.isPalindrome(121));
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
