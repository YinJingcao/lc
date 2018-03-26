/**
 * @file 45_Jump_Game_II.cpp
 * @author yinjingcao
 * @date 2018/03/23 18:02:56
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int count = 0;
        int begin = 0;
        int end = nums[0];
        int v_max = 0;
        while (end < nums.size()) {
            ++count;
            int index = begin;
            for (; index <= end; ++index) {
                if (v_max < index + nums[index]) {
                    v_max = index + nums[index];
                }
            }
            begin = index;
            end = v_max;
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    printf("%d\n", s.jump(nums));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
