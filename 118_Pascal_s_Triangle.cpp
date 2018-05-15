 /**
 * @file 118_Pascal_s_Triangle.cpp
 * @author yinjingcao
 * @date 2018/05/14 15:30:28
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows <= 0) return result;
        {
            vector<int> tmp(1, 1);
            result.push_back(tmp);
        }
        for (int i = 1; i < numRows; ++i) {
            vector<int> tmp(1, 1);
            for (int j = 1; j < i; ++j) {
                tmp.push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            tmp.push_back(1);
            result.push_back(tmp);
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
