 /**
 * @file 28_Implement_strStr.cpp
 * @author yinjingcao
 * @date 2018/03/19 15:17:18
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        if (haystack == "" && needle == "") {
            return 0;
        }
        for (size_t idx = 0; idx < haystack.size(); ++idx) {
            int len = haystack.size() - idx;
            if (needle.size() > len) {
                return -1;
            }
            if (haystack.substr(idx, needle.size()) == needle) {
                return idx;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.strStr("hello", "ll"));
    printf("%d\n", s.strStr("aaaaa", "bba"));
    return 0; 
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
