/**
 * @file 69_Sqrt_x.cpp
 * @author yinjingcao
 * @date 2018/03/27 19:24:10
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        uint64_t target = x;
        uint64_t right = x;
        uint64_t left = (target >> 1);
        while (left * left > target) {
            right = left;
            left >>= 1;
        }
        return find(left, right, uint64_t(x));
    }

private:
    int find(uint64_t left, uint64_t right, uint64_t target) {
        if (left >= right) {
            return left;
        }
        uint64_t mid = (left + right) / 2;
        if (mid * mid <= target && (mid + 1) * (mid + 1) > target) {
            return mid;
        } else if ((mid + 1) * (mid + 1) > target) {
            return find(left, mid - 1, target);
        } else {
            return find(mid + 1, right, target);
        }
    }
};

int main() {
    Solution s;
    printf("1 %d\n", s.mySqrt(1));
    printf("2 %d\n", s.mySqrt(2));
    printf("3 %d\n", s.mySqrt(3));
    printf("4 %d\n", s.mySqrt(4));
    printf("30 %d\n", s.mySqrt(30));
    printf("100 %d\n", s.mySqrt(100));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
