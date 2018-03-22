/**
 * @file 43_Multiply_Strings.cpp
 * @author yinjingcao
 * @date 2018/03/22 16:39:37
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(const string& num1, const string& num2) {
        if (num1.empty() || num2.empty()) return "";
        string result;
        for (int idx = num1.size() - 1; idx >= 0; --idx) {
            string tmp;
            for (int iidx = 0; iidx < num1[idx] - '0'; ++iidx) {
                tmp = add(tmp, num2);
            }
            for (int iidx = idx; iidx < num1.size() - 1; ++iidx) {
                tmp = tmp + "0";
            }
            result = add(result, tmp);
        }
        if (result.empty()) return "0";
        if (result[0] == '0') return "0";
        return result;
    }

private:
    string add(const string& num1, const string& num2) {
        string result;
        int iter1 = int(num1.size()) - 1;
        int iter2 = int(num2.size()) - 1;
        int jw = 0;
        while (iter1 >= 0 && iter2 >= 0) {
            int res = (num1[iter1] + num2[iter2] + jw - '0' - '0') % 10;
            jw = (num1[iter1] + num2[iter2] + jw - '0' - '0') / 10;
            result = ltos(res) + result;
            --iter2;
            --iter1;
        }
        while (iter1 >= 0) {
            int res = (num1[iter1] + jw - '0') % 10;
            jw = (num1[iter1] + jw - '0')/ 10;
            result = ltos(res) + result;
            --iter1;
        }
        while (iter2 >= 0) {
            int res = (num2[iter2] + jw - '0') % 10;
            jw = (num2[iter2] + jw - '0') / 10;
            result = ltos(res) + result;
            --iter2;
        }
        if (jw > 0) {
            result = ltos(jw) + result;
        }
        return result;
    }
    string ltos(int res) {
        char buff[120] = {0};
        snprintf(buff, 120, "%d", res);
        return buff;
    }
    int atoi(string& s) {
        int result;
        sscanf(s.c_str(), "%d", &result);
        return result;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.multiply("11", "123").c_str());
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
