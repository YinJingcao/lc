 /**
 * @file 12_Integer_to_Roman.cpp
 * @author yinjingcao
 * @date 2018/03/15 14:00:37
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string v1 = "";
        string v2[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string v3[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string v4[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        for (size_t idx = 0; idx < num / 1000; ++idx) {
            v1 += "M";
        }
        return v1 + v2[num % 1000 / 100] + v3[num % 100 / 10] + v4[num % 10];
    }
};


int main() {
    Solution s;
    printf("%s\n", s.intToRoman(123456).c_str());
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
