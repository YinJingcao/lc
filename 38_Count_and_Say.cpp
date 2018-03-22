/**
 * @file 38_Count_and_Say.cpp
 * @author yinjingcao
 * @date 2018/03/22 14:53:41
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        int count = 1;
        char ch = str[0];
        string result;
        for (size_t idx = 1; idx < str.size(); ++idx) {
            if (ch == str[idx]) {
                ++count;
            } else {
                char buff[256] = {0};
                snprintf(buff, 256, "%d", count);
                result += string(buff);
                result += ch;
                count = 1;
                ch = str[idx];
            }
        }
        char buff[256] = {0};
        snprintf(buff, 256, "%d", count);
        result += string(buff);
        result += ch;
        return result;
    }
};

int main() {
    Solution s;
    for (size_t idx = 0; idx < 10; ++idx) {
        printf("%d: %s\n", idx, s.countAndSay(idx).c_str());
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
