 /**
 * @file 1_Two_Sum.cpp
 * @author yinjingcao
 * @date 2018/03/12 14:48:31
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            for (size_t iidx = idx + 1; iidx < nums.size(); ++iidx) {
                if (nums[idx] + nums[iidx] == target) {
                    result.push_back(idx);
                    result.push_back(iidx);
                    return result;
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, size_t> m; 
        vector<int> result;
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            int d = target - nums[idx];
            unordered_map<int, size_t>::iterator it = m.find(d);   
            if (it != m.end()) {
                result.push_back(it->second);
                result.push_back(idx);
                return result;
            }
            m[nums[idx]] = idx;
        }
        return result;
    }
};

// return idx -> not sort
// for 15 :  3_sum
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result;
        size_t left = 0;
        size_t right = nums.size() - 1;
        while (left < right) {
            if (target == nums[left] + nums[right]) {
                result.push_back(nums[left]);
                result.push_back(nums[right]);
                do {
                    ++left;
                } while (left < right && nums[left - 1] == nums[left]);
                do {
                    --right;
                } while (right > left && nums[right] == nums[right + 1]);
            } else if (nums[left] + nums[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};

int main() {
    Solution2 s;
    vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(11);
    a.push_back(15);
    vector<int> b = s.twoSum(a, 9);
    for(size_t idx = 0; idx < b.size(); ++idx) {
        printf("%d\n", b[idx]);
    }
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
