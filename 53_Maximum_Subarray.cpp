/**
 * @file 53_Maximum_Subarray.cpp
 * @author yinjingcao
 * @date 2018/03/26 19:58:52
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int sum = 0;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            if (sum < 0) {
                sum = nums[idx];
            } else {
                sum += nums[idx];
            }
            if (result < sum) {
                result = sum;
            }
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
