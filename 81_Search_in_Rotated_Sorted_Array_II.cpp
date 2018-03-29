/**
 * @file 81_Search_in_Rotated_Sorted_Array_II.cpp
 * @author yinjingcao
 * @date 2018/03/29 17:17:26
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search(nums, target, 0, int(nums.size()) - 1); 
    }
private:
    bool search(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return false;
        }
        int mid = (left + right) / 2;
        if (target == nums[mid]) {
            return true;
        }
        if (nums[left] < nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                return search(nums, target, left, mid - 1);
            } else {
                return search(nums, target, mid + 1, right);
            }
        } else if (nums[left] == nums[mid]) {
        }
        if (nums[right] > nums[mid]) {
            if (target <= nums[right] && target > nums[mid]) {
                return search(nums, target, mid + 1, right);
            } else {
                return search(nums, target, left, mid - 1);
            }
        }
        return search(nums, target, left, mid - 1) || search(nums, target, mid + 1, right);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
