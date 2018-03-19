/**
 * @file 29_Divide_Two_Integers.cpp
 * @author yinjingcao
 * @date 2018/03/19 15:28:17
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <limits.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MAX && divisor == 1) return INT_MAX;
        if (dividend == INT_MAX && divisor == -1) return INT_MIN;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        uint64_t de = dividend < 0 ? uint64_t(0 - int64_t(dividend)) : dividend;
        uint64_t di = divisor < 0 ? uint64_t(0 - int64_t(divisor)) : divisor;
        int res = 0;
        bool flag = (dividend <= 0 && divisor <= 0) || (dividend >= 0 && divisor >= 0);
        while (de >= di) {
            uint64_t v = di;
            uint64_t k = 0;
            while (de >= v) {
                ++k;
                v <<= 1;
            }
            v >>= 1;
            --k;
            res += (1 << k);
            de -= v;
            if (de < di) {
                break;
            }
        }
        if (flag) {
            return res;
        }
        return 0 - res;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.divide(4000, -100));
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
