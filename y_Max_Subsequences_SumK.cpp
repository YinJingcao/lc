 /**
 * @file y_Max_Subsequences_SumK.cpp
 * @author yinjingcao
 * @date 2018/05/11 14:58:54
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int maxSubLengthSumK(vector<int>& nums, int target) {
    std::map<int, int> index;
    int len = 0;
    int sum = 0;
    for (int idx = 0; idx < nums.size(); ++idx) {
        sum += nums[idx];
        if (sum == target) {
            len = max(idx, len);
        }
        std::map<int, int>::iterator it = index.find(sum - target);
        if (it != index.end()) {
            len = max(idx - it->second, len);
        }
        it = index.find(sum);
        if (it == index.end()) {
            index[sum] = idx;
        }
    }
    return len;
}

int main() {
    vector<int> nums;
    int target = 0;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(-16);
    printf("%d\n", maxSubLengthSumK(nums, target));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
