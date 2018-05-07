 /**
 * @file 97_Interleaving_String.cpp
 * @author yinjingcao
 * @date 2018/05/07 20:07:01
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    bool isInterleave(const string& s1, const string& s2, const string& s3) {
        if (s1.size() + s2.size() != s3.size()) return false;
        return helper(s1, s2, s3, 0, 0, 0);
    }
private:
    bool helper(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
        if (s1.size() == i && s2.size() == j) return s3.size() == k;
        if (s1.size() > i && s1[i] == s3[k] && helper(s1, s2, s3, i + 1, j, k + 1)) return true;
        if (s2.size() > j && s2[j] == s3[k] && helper(s1, s2, s3, i, j + 1, k + 1)) return true;
        return false;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
