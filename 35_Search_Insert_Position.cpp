/**
 * @file 35_Search_Insert_Position.cpp
 * @author yinjingcao
 * @date 2018/03/20 19:04:54
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        return search(nums, 0, nums.size() - 1, target);
    }
private:
    int search(vector<int>& nums, int left, int right, int target) {
        if (left > right) {
            return left;
        }
        int mid = (left + right) / 2;
        if (target > nums[mid]) {
            return search(nums, mid + 1, right, target);
        } else if (target < nums[mid]) {
            return search(nums, left, mid - 1, target);
        } else {
            return mid;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    printf("%d\n", s.searchInsert(nums, 5));
    printf("%d\n", s.searchInsert(nums, 2));
    printf("%d\n", s.searchInsert(nums, 7));
    printf("%d\n", s.searchInsert(nums, 0));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
