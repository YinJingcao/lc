/**
 * @file 122_Best_Time_to_Buy_and_Sell_Stock_II.cpp
 * @author yinjingcao
 * @date 2018/05/14 19:05:28
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            prices[i] = prices[i + 1] - prices[i];
        }
        int s = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (prices[i] > 0) {
                s += prices[i];
            }
        }
        return s;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
