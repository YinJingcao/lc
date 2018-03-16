 /**
 * @file 18_4Sum.cpp
 * @author yinjingcao
 * @date 2018/03/16 16:26:29
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
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            if (idx > 0 && nums[idx] == nums[idx - 1]) {
                continue;
            }
            threeSum(nums, idx, target - nums[idx], result);
        }
        return result;
    }

private:
    void threeSum(const vector<int>& nums, size_t start_pos, int target, vector<vector<int> >& result) {
        for (size_t idx = start_pos + 1; idx < nums.size(); ++idx) {
            if (idx > start_pos + 1 && nums[idx] == nums[idx - 1]) {
                continue;
            }
            twoSum(nums, start_pos, idx, target - nums[idx], result);
        }
    }
    void twoSum(const vector<int>& nums, size_t start_pos1, size_t start_pos2, int target, vector<vector<int> >& result) {
        size_t left = start_pos2 + 1;
        size_t right = nums.size() - 1;
        while (left < right) {
            if (target == nums[left] + nums[right]) {
                vector<int> tmp;
                tmp.push_back(nums[start_pos1]);
                tmp.push_back(nums[start_pos2]);
                tmp.push_back(nums[left]);
                tmp.push_back(nums[right]);
                result.push_back(tmp);
                do {
                    ++left;
                } while (left < right && nums[left] == nums[left - 1]);
                do {
                    --right;
                } while (left < right && nums[right] == nums[right + 1]);
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
    vector<int> a;
    //a.push_back(1);
    //a.push_back(0);
    //a.push_back(-1);
    //a.push_back(0);
    //a.push_back(-2);
    //a.push_back(2);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    vector<vector<int> > result = s.fourSum(a, 0);
    for (size_t idx = 0; idx < result.size(); ++idx) {
        for (size_t iidx = 0; iidx < result[idx].size(); ++iidx) {
            printf("%d\t", result[idx][iidx]);
        }
        printf("\n");
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
