 /**
 * @file 14_Longest_Common_Prefix.cpp
 * @author yinjingcao
 * @date 2018/03/15 14:11:09
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        string result = strs[0];
        for (size_t idx = 1; idx < strs.size(); ++idx) {
            longestCommonPrefix(strs[idx], result);
            if (result == "") {
                break;
            }
        }
        return result;
    }
private:
    void longestCommonPrefix(const string& src, string& dst) {
        size_t idx1 = 0;
        size_t idx2 = 0;
        while (idx1 < src.size() && idx2 < dst.size()) {
            if (src[idx1] != dst[idx2]) {
                break;
            }
            ++idx1;
            ++idx2;
        }
        dst = dst.substr(0, idx2);
    }
};

int main() {
    Solution s;
    vector<string> strs;
    strs.push_back("123");
    strs.push_back("123");
    strs.push_back("12xx");
    printf("%s\n", s.longestCommonPrefix(strs).c_str());
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
