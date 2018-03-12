 /**
 * @file 3_Longest_Substring_Without_Repeating_Characters.cpp
 * @author yinjingcao
 * @date 2018/03/12 20:32:57
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
    int lengthOfLongestSubstring(const string& s) {
        unordered_map<char, size_t> id_map;
        unordered_map<char, size_t>::iterator itr;
        int longest_size = 0;
        int start_pos = 0;
        int idx = 0;
        while (idx < s.size()) {
            char c = s[idx];
            itr = id_map.find(c);
            if (itr != id_map.end()) {
                if (start_pos < (itr->second + 1)) {
                    start_pos = (itr->second + 1);
                }
            }
            id_map[c] = idx;
            if (longest_size < (idx - start_pos + 1)) {
                longest_size = idx - start_pos + 1;
            }
            ++idx;
        }
        return longest_size;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.lengthOfLongestSubstring("abba"));
    printf("%d\n", s.lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", s.lengthOfLongestSubstring("bbbbb"));
    printf("%d\n", s.lengthOfLongestSubstring("pwwkew"));
    printf("%d\n", s.lengthOfLongestSubstring("pwke"));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
