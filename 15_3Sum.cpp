 /**
 * @file 15_3Sum.cpp
 * @author yinjingcao
 * @date 2018/03/15 14:20:57
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// two sum +  target
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            if(idx > 0 && nums[idx] == nums[idx-1]) {
                continue;
            }
            twoSum(nums, 0 - nums[idx], idx, result);
        }
        return result;
    }

private:
    void twoSum(const vector<int>& nums, int target, size_t start_idx, vector<vector<int> >& result) {
        size_t left = start_idx + 1;
        size_t right = nums.size() - 1;
        while (left < right) {
            if (target == nums[left] + nums[right]) {
                vector<int> tmp;
                tmp.push_back(nums[start_idx]);
                tmp.push_back(nums[left]);
                tmp.push_back(nums[right]);
                result.push_back(tmp);
                do {
                    ++left;
                } while (left < right && nums[left - 1] == nums[left]);
                do {
                    --right;
                } while (left < right && nums[right + 1] == nums[right]);
            } else if (target > nums[left] + nums[right]) {
                ++left;
            } else {
                --right;
            }
        }
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(-4);
    nums.push_back(-2);
    nums.push_back(-2);
    nums.push_back(-2);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(6);
    nums.push_back(6);
    vector<vector<int> > result = s.threeSum(nums);
    for (size_t idx = 0; idx < result.size(); ++idx) {
        for (size_t iidx = 0; iidx < result[idx].size(); ++iidx) {
            printf("%d\t", result[idx][iidx]);
        }
        printf("\n");
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
