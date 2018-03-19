/**
 * @file 26_Remove_Duplicates_from_Sorted_Array.cpp
 * @author yinjingcao
 * @date 2018/03/19 14:52:38
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
        if (nums.empty()) {
            return 0;
        }
        int dup_value = nums[0];
        int len = 1;
        for (size_t idx = 1; idx < nums.size(); ++idx) {
            if (nums[idx] != dup_value) {
                nums[len++] = nums[idx];
            }
            dup_value = nums[idx];
        }
        nums.erase(nums.begin() + len, nums.end());
        return len;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    printf("%d\n", s.removeDuplicates(nums));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
