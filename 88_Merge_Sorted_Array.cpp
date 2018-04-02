/**
 * @file 88_Merge_Sorted_Array.cpp
 * @author yinjingcao
 * @date 2018/04/02 15:14:23
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        size_t left = 0;
        size_t right = 0;
        while (left < m && right < n) {
            if (nums1[left] > nums2[right]) {
                result.push_back(nums2[right++]);
            } else {
                result.push_back(nums1[left++]);
            }
        }
        result.insert(result.end(), nums1.begin() + left, nums1.begin() + m);
        result.insert(result.end(), nums2.begin() + right, nums2.begin() + n);
        nums1.assign(result.begin(), result.end());
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
