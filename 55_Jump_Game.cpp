/**
 * @file 55_Jump_Game.cpp
 * @author yinjingcao
 * @date 2018/03/26 20:11:47
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int end = nums[0];
        int begin = 0;
        int v_max = 0;
        while (end < nums.size() - 1) {
            int index = begin;
            bool flag = false;
            for (; index <= end; ++index) {
                if (v_max < nums[index] + index) {
                    v_max = nums[index] + index;
                    flag = true;
                }
            }
            if (!flag) {
                return false;
            }
            end = v_max;
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(0);
    nums.push_back(0);
    printf("%d\n", s.canJump(nums));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
