/**
 * @file 68_Text_Justification.cpp
 * @author yinjingcao
 * @date 2018/03/27 16:55:04
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        init_maxWidth_blank(maxWidth);
        if (words.empty()) return words;
        vector<string> result;
        vector<string> tmp;
        int cur_size = 0;
        for (size_t idx = 0; idx < words.size(); ++idx) {
            int interval_size = (tmp.size() <= 0 ? 0 : tmp.size());
            if (cur_size + interval_size + words[idx].size() <= maxWidth) {
                cur_size += words[idx].size();
                tmp.push_back(words[idx]);
            } else {
                redesign(tmp, maxWidth - cur_size, result);
                tmp.clear();
                tmp.push_back(words[idx]);
                cur_size = words[idx].size();
            }
        }
        last_line(tmp, maxWidth - cur_size, result);
        return result;
    }
private:
    void last_line(vector<string>& tmp, int blank_size, vector<string>& result) {
        int b_used = 0;
        string res;
        for (size_t idx = 0; idx < tmp.size(); ++idx) {
            if (blank_size > 0) {
                res += tmp[idx] + index[1];
            } else {
                res += tmp[idx];
            }
            ++b_used;
        }
        res += index[blank_size - b_used];
        result.push_back(res);
    }
    void redesign(vector<string>& tmp, int blank_size, vector<string>& result) {
        int step = 1;
        int re = 0;
        if (tmp.size() == 1) {
            step =  blank_size / tmp.size();
        } else {
            step = blank_size / (tmp.size() - 1);
            re = blank_size % (tmp.size() - 1);
        }
        string res;
        for (size_t idx = 0; idx < tmp.size(); ++idx) {
            res += tmp[idx];
            int bq = 0;
            if (re > 0) {
                --re;
                bq = 1;
            }
            if (blank_size > 0) {
                res += index[step + bq];
            }
            blank_size -= (step + bq);
        }
        result.push_back(res);
    }

    void init_maxWidth_blank(int maxWidth) {
        string str;
        for (int idx = 0; idx <= maxWidth; ++idx) {
            index[idx] = str;
            str += " ";
        }
    }
    unordered_map<int, string> index;
};

int main() {
    vector<string> words;
    words.push_back("a");
    //words.push_back("must");
    //words.push_back("be");
    //words.push_back("shall");
    //words.push_back("be.");
    //words.push_back("text");
    //words.push_back("justification.");
    Solution s;
    vector<string> result = s.fullJustify(words, 1);
    for (size_t idx = 0; idx < result.size(); ++idx) {
        printf("%s\n", result[idx].c_str());
    }
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
