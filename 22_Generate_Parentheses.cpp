 /**
 * @file 22_Generate_Parentheses.cpp
 * @author yinjingcao
 * @date 2018/03/16 17:45:34
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s;
        generate(n, 0, 0, s, result);
        return result;
    }

private:
    void generate(int n, int left, int right, string s, vector<string>& result) {
        if (left == n && right == n) {
            result.push_back(s);
            return;
        }
        if (left < n) {
            generate(n, left + 1, right, s + "(", result);
        }
        if (right < left) {
            generate(n, left, right + 1, s + ")", result);
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
