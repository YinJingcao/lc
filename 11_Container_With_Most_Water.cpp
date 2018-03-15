 /**
 * @file 11_Container_With_Most_Water.cpp
 * @author yinjingcao
 * @date 2018/03/14 20:14:07
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) {
            return 0;
        }
        size_t lhs = 0;
        size_t rhs = height.size() - 1;
        int max_area = 0;
        while (lhs < rhs) {
            int area = 0;
            if (height[lhs] < height[rhs]) {
                area = height[lhs] * (rhs - lhs);
                ++lhs;
            } else {
                area = height[rhs] * (rhs - lhs);
                --rhs;
            }
            if (area > max_area) {
                max_area = area;
            }
        }
        return max_area;
    }
};

int main() {
    Solution s;
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    printf("%d\n", s.maxArea(a));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
