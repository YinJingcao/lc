/**
 * @file 49_Group_Anagrams.cpp
 * @author yinjingcao
 * @date 2018/03/26 16:38:34
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;

class Solution {
public:
    Solution() {
        for (size_t idx = 0; idx <= 26; ++idx) {
            random['a' + idx] = rand() % INT_MAX;
        }
    }
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        for (size_t idx = 0; idx < strs.size(); ++idx) {
            uint64_t md5 = fake_md5(strs[idx]);
            unordered_map<uint64_t, size_t>::iterator it = index.find(md5);
            if (it == index.end()) {
                vector<string> tmp;
                tmp.push_back(strs[idx]);
                result.push_back(tmp);
                index[md5] = result.size() - 1;
            } else {
                result[it->second].push_back(strs[idx]);
            }
        }
        return result;
    }

private:
    uint64_t fake_md5(std::string& str) {
        uint64_t result = 0;
        for (size_t idx = 0; idx < str.size(); ++idx) {
            result += random[str[idx]];
        }
        return result;
    }
    unordered_map<uint64_t, size_t> index;
    unordered_map<char, uint64_t> random;
};

int main() {
    Solution s;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
