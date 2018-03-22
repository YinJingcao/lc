/**
 * @file 42_Trapping_Rain_Water.cpp
 * @author yinjingcao
 * @date 2018/03/22 16:23:40
 * @version $Revision$ 
 * @brief 
 *  
 **/

// see https://segmentfault.com/a/1190000004369425

class Solution {
public:
    int trap(vector<int>& height) {
        int max_index = 0;
        int water = 0;
        for (int idx = 1; idx < height.size(); ++idx) {
            if (height[max_index] < height[idx]) {
                max_index = idx;
            }
        }
        for (int left = 0, left_max = 0; left < max_index; ++left) {
            if (left_max < height[left]) {
                left_max = height[left];
            } else {
                water += left_max - height[left];
            }
        }
        for (int right = int(height.size()) - 1, right_max = 0; right > max_index; --right) {
            if (right_max < height[right]) {
                right_max = height[right];
            } else {
                water += right_max - height[right];
            }
        }
        return water;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
