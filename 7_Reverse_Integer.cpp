 /**
 * @file 7_Reverse_Integer.cpp
 * @author yinjingcao
 * @date 2018/03/14 13:45:58
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <limits.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        char buff[256] = {0};
        if (x < 0) {
            snprintf(buff, 256, "%d", 0 - x);
        } else {
            snprintf(buff, 256, "%d", x);
        }
        return x < 0 ? (0 - reverse(buff)) : reverse(buff);
    }
    int reverse(char* p) {
        uint64_t result = 0;
        string s(p);
        std::reverse(s.begin(), s.end());
        sscanf(s.c_str(), "%lu", &result);
        if (result > INT_MAX) {
            return 0;
        }
        return result;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.reverse(2137483647));
    printf("%d\n", s.reverse(-2137483648));
    printf("%d\n", s.reverse(2137483312));
    printf("%d\n", s.reverse(-2137483312));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
