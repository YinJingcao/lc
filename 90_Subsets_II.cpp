/**
 * @file 90_Subsets_II.cpp
 * @author yinjingcao
 * @date 2018/04/02 16:32:24
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        gen_random(nums);
        vector<vector<int> > result;
        for (size_t idx = 0; idx <= nums.size(); ++idx) {
            vector<int> tmp;
            helper(nums, 0, idx, tmp, result);
        }
        return result;
    }
private:
    void helper(vector<int>& nums, int index, int target, vector<int>& tmp, vector<vector<int> >& result) {
        if (tmp.size() == target) {
            uint64_t uniq_key = 0;
            for (size_t idx = 0; idx < tmp.size(); ++idx) {
                uniq_key += uint64_t(random_map[tmp[idx]]);
            }
            unordered_set<uint64_t>::iterator it = dedup_set.find(uniq_key);
            if (it == dedup_set.end()) {
                result.push_back(tmp);
                dedup_set.insert(uniq_key);
            }
            return;
        }
        for (size_t idx = index; idx < nums.size(); ++idx) {
            tmp.push_back(nums[idx]);
            helper(nums, idx + 1, target, tmp, result);
            tmp.erase(tmp.end() - 1);
        }
    }
    void gen_random(vector<int>& nums) {
        for (size_t idx = 0; idx < nums.size(); ++idx) {
            unordered_map<int, int>::iterator it = random_map.find(nums[idx]);
            if (it == random_map.end()) {
                random_map[nums[idx]] = rand() % INT_MAX;
            }
        }
    }
    unordered_map<int, int> random_map;
    unordered_set<uint64_t> dedup_set;
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
