/**
 * @file 80_Remove_Duplicates_from_Sorted_Array_II.cpp
 * @author yinjingcao
 * @date 2018/03/29 17:04:45
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int dup_num = nums[0];
        int count = 1;
        int len = 1;
        for (size_t idx = 1; idx < nums.size(); ++idx) {
            if (nums[idx] != dup_num) {
                nums[len++] = nums[idx];
                count = 1;
            } else if (nums[idx] == dup_num && count < 2) {
                nums[len++] = nums[idx];
                ++count;
            }
            dup_num = nums[idx];
        }
        return len;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    printf("%d\n", s.removeDuplicates(nums));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
