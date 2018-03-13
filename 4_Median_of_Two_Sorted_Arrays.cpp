 /**
 * @file 4_Median_of_Two_Sorted_Arrays.cpp
 * @author yinjingcao
 * @date 2018/03/13 13:10:27
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        size_t idx1 = 0;
        size_t idx2 = 0;
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] < nums2[idx2]) {
                nums.push_back(nums1[idx1++]);
            } else {
                nums.push_back(nums2[idx2++]);
            }
        }
        if (idx1 < nums1.size()) {
            nums.insert(nums.end(), nums1.begin() + idx1, nums1.end());
        } else if (idx2 < nums2.size()) {
            nums.insert(nums.end(), nums2.begin() + idx2, nums2.end());
        }
        if (nums.empty()) {
            return 0.0;
        }
        if (nums.size() % 2 == 0) {
            return (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
        } else {
            return nums[nums.size() / 2];
        }
    }
};

class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    }
};

int main() {
    Solution s;
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(2);
    nums2.push_back(3);
    nums2.push_back(4);
    printf("%f\n", s.findMedianSortedArrays(nums1, nums2));
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
