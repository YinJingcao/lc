/**
 * @file 121_Best_Time_to_Buy_and_SellStock.cpp
 * @author yinjingcao
 * @date 2018/05/14 19:00:27
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
        int max_s = 0;
        for (int i = 0; i < prices.size() - 1; ++i) {
            if (s + prices[i] > 0) {
                s += prices[i];
            } else {
                s = 0;
            }
            if (max_s < s) {
                max_s = s;
            }
        }
        return max_s;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
