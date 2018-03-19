/**
 * @file 27_Remove_Element.cpp
 * @author yinjingcao
 * @date 2018/03/19 15:03:58
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        int len = 0;
        while (it != nums.end()) {
            if (*it != val) {
                ++len;
                ++it;
            } else {
                it = nums.erase(it);
            }
        }
        return len;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    printf("%d\n", s.removeElement(nums, 1));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
