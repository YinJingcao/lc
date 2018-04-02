 /**
 * @file 89_Gray_Code.cpp
 * @author yinjingcao
 * @date 2018/04/02 15:32:58
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        for (int idx = 0; idx < (1 << n); ++idx) {
            result.push_back((idx >> 1)^idx);
        }
        return result;
    }
};

int main() {
    Solution s;
    s.grayCode(3);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
