/**
 * @file 78_Subsets.cpp
 * @author yinjingcao
 * @date 2018/03/29 16:03:27
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> tmp;
        for (size_t idx = 0; idx <= nums.size(); ++idx) {
            helper(nums, result, tmp, 0, idx);
        }
        return result;
    }
private:
    void helper(const vector<int>& nums, vector<vector<int> >& result, vector<int>& tmp, int index, int target) {
        if (target == tmp.size()) {
            result.push_back(tmp);
            return;
        }
        for (size_t idx = index; idx < nums.size(); ++idx) {
            tmp.push_back(nums[idx]);
            helper(nums, result, tmp, idx + 1, target);
            tmp.erase(tmp.end() - 1);
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
