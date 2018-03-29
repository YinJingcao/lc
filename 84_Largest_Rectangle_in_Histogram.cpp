/**
 * @file 84_Largest_Rectangle_in_Histogram.cpp
 * @author yinjingcao
 * @date 2018/03/29 19:24:37
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        for (size_t idx = 0; idx < heights.size(); ++idx) {
            int top = 0;
            if (!s.empty()) {
                top = s.top();
            }
            int num = 0;
            int min_height = INT_MAX;
            while (heights[idx] < top) {
                ++num;
                if (min_height > top) {
                    min_height = top;
                }
                int area = max(top, min_height * num);
                if (max_area < area) {
                    max_area = area;
                }
                s.pop();
                if (s.empty()) {
                    top = 0;
                } else {
                    top = s.top();
                }
            }
            for (int n = 0; n <= num; ++n) {
                s.push(heights[idx]);
            }
            if (max_area < heights[idx]) {
                max_area = heights[idx];
            }
        }
        int min_height = INT_MAX;
        int num = 0;
        while (!s.empty()) {
            int top = s.top();
            s.pop();
            ++num;
            if (min_height > top) {
                min_height = top;
            }
            int area = max(top, min_height * num);
            if (max_area < area) {
                max_area = area;
            }
        }
        return max_area;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
