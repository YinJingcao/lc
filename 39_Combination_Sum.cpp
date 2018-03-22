/**
 * @file 39_Combination_Sum.cpp
 * @author yinjingcao
 * @date 2018/03/22 15:09:51
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combinationSum(result, tmp, candidates, target, 0);
        return result;
    }

private:
    void combinationSum(vector<vector<int> >& result, vector<int> tmp, vector<int>& candidates, int target, int index) {
        if (target == 0) {
            result.push_back(tmp);
            return;
        }
        for (size_t idx = index; idx < candidates.size(); ++idx) {
            if (target < 0) {
                break;
            }
            tmp.push_back(candidates[idx]);
            combinationSum(result, tmp, candidates, target - candidates[idx], idx);
            tmp.erase(tmp.end() - 1);
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
