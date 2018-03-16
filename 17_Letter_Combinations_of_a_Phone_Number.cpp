 /**
 * @file 17_Letter_Combinations_of_a_Phone_Number.cpp
 * @author yinjingcao
 * @date 2018/03/16 14:54:59
 * @version $Revision$ 
 * @brief 
 *  
 **/

// see https://segmentfault.com/a/1190000012183207

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution() {
        index_['2'] = "abc";
        index_['3'] = "def";
        index_['4'] = "ghi";
        index_['5'] = "jkl";
        index_['6'] = "mno";
        index_['7'] = "qprs";
        index_['8'] = "tuv";
        index_['9'] = "wxyz";
    }
    vector<string> letterCombinations(const string& digits) {
        string tmp;
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        cal(digits, 0, result, tmp);
        return result;
    }

private:
    void cal(const string& digits, int start_idx, vector<string>& result, string& tmp) {
        if (tmp.size() == digits.size()) {
            result.push_back(tmp);
            return;
        }
        for (size_t idx = 0; idx < index_[digits[start_idx]].size(); ++idx) {
            tmp += index_[digits[start_idx]][idx];
            cal(digits, start_idx + 1, result, tmp);
            tmp = tmp.substr(0, tmp.size() - 1);
        }
    }
    std::unordered_map<char, string> index_;
};

int main() {
    Solution s;
    vector<string> result = s.letterCombinations("23");
    for (size_t idx = 0; idx < result.size(); ++idx) {
        printf("%s\n", result[idx].c_str());
    }
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
