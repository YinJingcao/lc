 /**
 * @file 8_String_to_Integer.cpp
 * @author yinjingcao
 * @date 2018/03/14 14:01:56
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <limits.h>
using namespace std;

class Solution {
public:
    int myAtoi(const string& str) {
        int64_t result = 0;
        sscanf(str.c_str(), "%ld", &result);
        if (result > INT_MAX) {
            result = INT_MAX;
        } else if (result < INT_MIN) {
            result = INT_MIN;
        }
        return int(result);
    }
};

int main() {
    Solution s;
    printf("%d\n", s.myAtoi("+"));
    //printf("%d\n", s.myAtoi("1234546"));
    //printf("%d\n", s.myAtoi("2147483647"));
    //printf("%d\n", s.myAtoi("-2147483648"));
    //printf("%d\n", s.myAtoi("2147483648"));
    //printf("%d\n", s.myAtoi("-2147483649"));
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
