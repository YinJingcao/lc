/**
 * @file 66_Plus_One.cpp
 * @author yinjingcao
 * @date 2018/03/27 16:21:10
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) return digits;
        int idx = int(digits.size()) - 1;
        int result = (digits[idx] + 1) % 10;
        int jw = (digits[idx] + 1) / 10;
        digits[idx] = result;
        --idx;
        for (; idx >= 0; --idx) {
            result = (digits[idx] + jw) % 10; 
            jw = (digits[idx] + jw) / 10; 
            digits[idx] = result;
        }
        if (jw > 0) {
            digits.insert(digits.begin(), jw);
        }
        return digits;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
