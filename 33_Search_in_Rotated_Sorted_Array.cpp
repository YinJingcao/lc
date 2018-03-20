/**
 * @file 33_Search_in_Rotated_Sorted_Array.cpp
 * @author yinjingcao
 * @date 2018/03/20 16:51:45
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return search(nums, 0, nums.size() - 1, target);
    }
private:
    int search(vector<int>& nums, int start_pos, int end_pos, int target) {
        if (start_pos > end_pos) {
            return -1;
        }
        int mid = (start_pos + end_pos) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[start_pos] <= nums[mid]) {
            if (target >= nums[start_pos] && target < nums[mid]) {
                return search(nums, start_pos, mid - 1, target);
            } else {
                return search(nums, mid + 1, end_pos, target);
            }
        }
        if (nums[end_pos] >= nums[mid]) {
            if (target <= nums[end_pos] && target > nums[mid]) {
                return search(nums, mid + 1, end_pos, target);
            } else {
                return search(nums, start_pos, mid - 1, target);
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    printf("%d\n", s.search(nums, 3));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
