/**
 * @file 77_Combinations.cpp
 * @author yinjingcao
 * @date 2018/03/29 15:43:53
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> tmp;
        helper(n, k, 1, tmp, result);
        return result;
    }
private:
    void helper(int n, int k, int index, vector<int>& tmp, vector<vector<int> >& result) {
        if (tmp.size() == k) {
            result.push_back(tmp);
            return;
        }
        for (size_t idx = index; idx <= n; ++idx) {
            tmp.push_back(idx);
            helper(n, k, idx + 1, tmp, result);
            tmp.erase(tmp.end() - 1);
        }
    }
};

int main() {
    Solution s;
    vector<vector<int> > result = s.combine(4, 2);
    for (size_t idx = 0; idx < result.size(); ++idx) {
        for (size_t iidx = 0; iidx < result[idx].size(); ++iidx) {
            printf("%d\t", result[idx][iidx]);
        }
        printf("\n");
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
