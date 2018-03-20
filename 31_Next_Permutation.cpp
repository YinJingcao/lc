/**
 * @file 31_Next_Permutation.cpp
 * @author yinjingcao
 * @date 2018/03/20 11:19:49
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return; 
        int idx = nums.size() - 1;
        int v = nums[idx];
        for (idx = nums.size() - 2; idx >= 0; --idx) {
            if (nums[idx] < v) {
                break;
            }
            v = nums[idx];
        }
        reverse(nums.begin() + idx + 1, nums.end());
        find_and_replace(idx, nums, idx + 1, nums.size() - 1);
    }
private:
    void find_and_replace(int index, vector<int>& nums, int start_pos, int end_pos) {
        if (index == -1) {
            return;
        }
        if (start_pos >= end_pos) {
            int tmp = nums[index];
            nums[index] = nums[start_pos];
            nums[start_pos] = tmp;
            return;
        }
        int mid = (start_pos + end_pos) / 2;
        printf("mid=%d index=%d\n", nums[mid], nums[index]);
        if (nums[mid] > nums[index] && nums[mid - 1] <= nums[index]) {
            int tmp = nums[index];
            nums[index] = nums[mid];
            nums[mid] = tmp;
            return;
        } else if (nums[mid] <= nums[index]) {
            find_and_replace(index, nums, mid + 1, end_pos);
        } else {
            find_and_replace(index, nums, start_pos, mid - 1);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(1);
    //reverse(nums.begin(), nums.end());
    s.nextPermutation(nums);
    for (size_t idx = 0; idx < nums.size(); ++idx) {
        printf("%d\t", nums[idx]);
    }
    printf("\n");
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
