/**
 * @file 41_First_Missing_Positive.cpp
 * @author yinjingcao
 * @date 2018/03/22 15:54:01
 * @version $Revision$ 
 * @brief 
 *  
 **/

// see https://segmentfault.com/a/1190000011755575

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (size_t idx = 0; idx < nums.size();) {
            int tmp = nums[idx] - 1;
            if (tmp < 0 || tmp >= nums.size() || tmp == idx || nums[tmp] == tmp + 1) {
                ++idx;
            } else {
                nums[idx] = nums[tmp];
                nums[tmp] = tmp + 1;
            }
        }
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            if (nums[idx] != idx + 1) {
                return idx + 1;
            }
        }
        return nums.size() + 1;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
