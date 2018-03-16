 /**
 * @file 16_3Sum_Closest.cpp
 * @author yinjingcao
 * @date 2018/03/16 14:25:32
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = INT_MAX;
        sort(nums.begin(), nums.end());
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            if (idx > 0 && nums[idx - 1] == nums[idx]) {
                continue;
            }
            twoSumClosest(nums, idx, target - nums[idx], result);
        }
        return result + target;
    }
private:
    void twoSumClosest(const vector<int>& nums, size_t start_pos, int target, int& result) {
        size_t left = start_pos + 1;
        size_t right = nums.size() - 1;
        while (left < right) {
            int r = nums[left] + nums[right] - target;
            if (r < 0) {
                ++left;
                if (abs(r) < abs(result)) {
                    result = r;
                }
            } else {
                --right;
                if (abs(r) < abs(result)) {
                    result = r;
                }
            }
        }
    }
};

int main () {
    Solution s;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);
    printf("%d\n", s.threeSumClosest(nums, 1));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
