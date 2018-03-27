/**
 * @file 67_Add_Binary.cpp
 * @author yinjingcao
 * @date 2018/03/27 16:36:20
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(const string& a, const string& b) {
        if (a.empty()) return b;
        if (b.empty()) return a;
        string result;
        int idx_a = a.size() - 1;
        int idx_b = b.size() - 1;
        int jw = 0;
        int sum = 0;
        while (idx_a >= 0 && idx_b >= 0) {
            sum = (a[idx_a] + b[idx_b] + jw - '0' - '0') % 2;
            jw = (a[idx_a] + b[idx_b] + jw - '0' - '0') / 2;
            result += '0' + sum;
            --idx_a;
            --idx_b;
        }
        while (idx_a >= 0) {
            sum = (a[idx_a] + jw - '0') % 2;
            jw = (a[idx_a] + jw - '0') / 2;
            result += '0' + sum;
            --idx_a;
        }
        while (idx_b >= 0) {
            sum = (b[idx_b] + jw - '0') % 2;
            jw = (b[idx_b] + jw - '0') / 2;
            result += '0' + sum;
            --idx_b;
        }
        if (jw != 0) {
            result += '0' + jw;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.addBinary("11", "11").c_str());
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
