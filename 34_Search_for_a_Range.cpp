/**
 * @file 34_Search_for_a_Range.cpp
 * @author yinjingcao
 * @date 2018/03/20 18:40:24
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int> result(2, -1);
        if (nums.empty()) {
            return result;
        }
        int found = search(nums, target, 0, nums.size() - 1);
        if (found == -1) {
            return result;
        }
        int left = found - 1;
        int right = found + 1;
        while (left >= 0 && nums[left] == target) --left;
        while (right < nums.size() && nums[right] == target) ++right;
        result[0] = left + 1;
        result[1] = right - 1;
        return result;
    }
private:
    int search(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if (nums[mid] > target) {
            return search(nums, target, left, mid - 1);
        } else if (nums[mid] < target) {
            return search(nums, target, mid + 1, right);
        } else {
            return mid;
        }
    }
};

int main() {
    vector<int> nums;
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(8);
    Solution s;
    vector<int> result = s.searchRange(nums, 8);
    printf("%d,%d\n", result[0], result[1]);
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
