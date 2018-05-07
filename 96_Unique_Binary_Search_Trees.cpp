 /**
 * @file 96_Unique_Binary_Search_Trees.cpp
 * @author yinjingcao
 * @date 2018/05/07 17:21:04
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n + 1, 0);
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                a[i] += (a[j] * a[i - j - 1]);
            }
        }
        return a[n];
    }
};

int main() {
    Solution s;
    for (size_t idx = 0; idx < 10; ++idx) {
        printf("%d\t%d\n", idx, s.numTrees(idx));
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
