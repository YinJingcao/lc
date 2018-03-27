/**
 * @file 58_Length_of_Last_Word.cpp
 * @author yinjingcao
 * @date 2018/03/27 14:28:48
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) return 0;
        int result = 0;
        for (int idx = s.size() - 1; idx >= 0; --idx) {
            if (s[idx] != ' ') {
                ++result;
            } else if(result != 0) {
                break;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.lengthOfLastWord("a "));
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
