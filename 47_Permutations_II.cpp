/**
 * @file 47_Permutations_II.cpp
 * @author yinjingcao
 * @date 2018/03/26 15:17:17
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> tmp;
        permute(nums, tmp, result, 0);
        return result;
    }
private:
    void permute(vector<int>& nums, vector<int>& tmp, vector<vector<int> >& result, int index) {
        if (tmp.size() == nums.size()) {
            string uniq_key;
            for (size_t idx = 0; idx < tmp.size(); ++idx) {
                char buff[32];
                snprintf(buff, 32, "%d", tmp[idx]);
                uniq_key += buff;
            }
            unordered_set<string>::iterator it = dedup.find(uniq_key);
            if (it == dedup.end()) {
                result.push_back(tmp);
                dedup.insert(uniq_key);
            }
            return;
        }
        for (size_t idx = index; idx < nums.size(); ++idx) {
            int tmp1 = nums[idx];
            int tmp2 = nums[index];
            nums[index] = tmp1;
            nums[idx] = tmp2;
            tmp.push_back(nums[index]);
            permute(nums, tmp, result, index + 1);
            nums[index] = tmp2;
            nums[idx] = tmp1;
            tmp.erase(tmp.end() - 1);
        }
    }
    unordered_set<string> dedup;
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(3);
    Solution s;
    vector<vector<int> > result = s.permuteUnique(nums);
    for (size_t idx = 0; idx < result.size(); ++idx) {
        for (size_t iidx = 0; iidx < result[idx].size(); ++iidx) {
            printf("%d\t", result[idx][iidx]);
        }
        printf("\n");
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
