/**
 * @file 40_Combination_Sum_II.cpp
 * @author yinjingcao
 * @date 2018/03/22 15:30:01
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        combinationSum2(result, tmp, candidates, target, 0);
        return result;
    }

private:
    void combinationSum2(vector<vector<int> >& result, vector<int>& tmp, vector<int>& candidates, int target, int index) {
        if (target == 0) {
            string str;
            for (size_t idx = 0; idx < tmp.size(); ++idx) {
                char buff[256];
                snprintf(buff, 256, "%d", tmp[idx]);
                str += buff;
            }
            unordered_set<string>::iterator itr = dedup.find(str);
            if (itr == dedup.end()) {
                result.push_back(tmp);
                dedup.insert(str);
            }
            return;
        }
        for (size_t idx = index; idx < candidates.size(); ++idx) {
            if (target < 0) {
                break;
            }
            if (!tmp.empty() && tmp[tmp.size() - 1] > candidates[idx]) {
                continue;
            }
            tmp.push_back(candidates[idx]);
            combinationSum2(result, tmp, candidates, target - candidates[idx], index + 1);
            tmp.erase(tmp.end() - 1);
        }
    }
    unordered_set<string> dedup;
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
