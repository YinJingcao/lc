/**
 * @file 60_Permutation_Sequence.cpp
 * @author yinjingcao
 * @date 2018/03/27 14:42:11
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    Solution() {
        index[0] = 1;
        index[1] = 1;
        index[2] = 2;
        index[3] = 6;
        index[4] = 24;
        index[5] = 120;
        index[6] = 720;
        index[7] = 5040;
        index[8] = 40320;
        index[9] = 362880;
    }

    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        string result;
        vector<int> a;
        for (size_t idx = 1; idx <= n; ++idx) {
            a.push_back(idx);
        }
        --k;
        for (size_t idx = 1; idx <= n; ++idx) {
            int first = k / index[n - idx];
            k %= index[n - idx];
            result += (a[first] + '0');
            a.erase(a.begin() + first);
        }
        return result;
    }

private:
    unordered_map<int, int> index;
};

int main() {
    Solution s;
    printf("%s\n", s.getPermutation(3, 6).c_str());
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
