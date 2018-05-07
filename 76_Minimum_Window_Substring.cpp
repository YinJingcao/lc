/**
 * @file 76_Minimum_Window_Substring.cpp
 * @author yinjingcao
 * @date 2018/03/28 19:51:26
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> src_map;
        unordered_map<char, int> dst_map;
        for (size_t idx = 0; idx < t.size(); ++idx) {
            ++src_map[t[idx]];
        }
        int found = 0;
        int left = 0;
        int begin = -1;
        int min_len = s.size();
        for (size_t idx = 0; idx < s.size(); ++idx) {
            char c = s[idx];
            if (++dst_map[c] <= src_map[c]) {
                ++found;
            }
            if (found == t.size()) {
                while (left < idx && dst_map[s[left]] > src_map[s[left]]) {
                    --dst_map[s[left++]];
                }
                if (min_len > idx - left) {
                    min_len = idx - left;
                    begin = left;
                }
                --dst_map[s[left++]];
                --found;
            }
        }
        return begin == -1 ? "" : s.substr(begin, min_len + 1);
    }
};

int main() {
    Solution s;
    printf("%s\n", s.minWindow("a", "a").c_str());
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
