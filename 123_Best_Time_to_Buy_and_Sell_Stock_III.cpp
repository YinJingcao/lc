 /**
 * @file 123_Best_Time_to_Buy_and_Sell_Stock_III.cpp
 * @author yinjingcao
 * @date 2018/05/14 19:11:43
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            prices[i] = prices[i + 1] - prices[i];
        }
        vector<int> left(prices.size() - 1, 0);
        vector<int> right(prices.size() - 1, 0);
        int s = 0;
        int max_s = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (s + prices[i] > 0) {
                s += prices[i];
            } else {
                s = 0;
            }
            if (i != 0) {
                left[i] = left[i - 1];
            }
            if (max_s < s) {
                max_s = s;
                left[i] = max_s;
            }
        }
        s = 0;
        max_s = 0;
        for (int i = int(prices.size()) - 2; i >= 1; --i) {
            if (s + prices[i] > 0) {
                s += prices[i];
            } else {
                s = 0;
            }
            right[i - 1] = right[i]; 
            if (max_s < s) {
                max_s = s;
                right[i - 1] = max_s;
            }
        }
        max_s = 0;
        for (int i = 0; i < left.size(); ++i) {
            max_s = max(max_s, left[i] + right[i]);
        }
        return max_s;
    }
};

int main() {
    vector<int> prices;
    prices.push_back(3);
    prices.push_back(3);
    prices.push_back(5);
    prices.push_back(0);
    prices.push_back(0);
    prices.push_back(3);
    prices.push_back(1);
    prices.push_back(4);
    Solution s;
    printf("%d\n", s.maxProfit(prices));
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
