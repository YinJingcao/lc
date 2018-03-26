/**
 * @file 50_Pow_x_n.cpp
 * @author yinjingcao
 * @date 2018/03/26 18:44:11
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (0 == n) return 1.0;
        //if (1 == n) return x;
        double result = 1.0;
        uint64_t pos_n = 0;
        if (n < 0) {
            pos_n = uint64_t(0) - n;
        } else {
            pos_n = n;
        }
        uint64_t idx = 1;
        uint64_t re = pos_n;
        double tmp = x;
        while (re >= 1) {
            uint64_t k = (idx << 1);
            if (k > re) {
                re -=  idx;
                result *= tmp;
                tmp = x;
                idx = 1;
            } else {
                tmp *= tmp;
                idx = (idx << 1);
            }
        }
        if (n < 0) {
            result = 1.0 / result;
        }
        return result;
    }
};

int main() {
    Solution s;
    printf("%.6f\n", pow(1.0, -2147483648));
    printf("%.6f\n", s.myPow(1.0, -2147483648));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
