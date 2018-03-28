/**
 * @file 74_Search_a_2D_Matrix.cpp
 * @author yinjingcao
 * @date 2018/03/28 19:28:22
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if (matrix.empty()) return false;
        int xlen = matrix.size();
        int ylen = matrix[0].size();
        return find(matrix, xlen, ylen, 0, xlen * ylen - 1, target);
    }
private:
    bool find(vector<vector<int> >& matrix, int xlen, int ylen, int left, int right, int target) {
        if (left > right) {
            return false;
        }
        int mid = (left + right) / 2;
        int mid_x = mid / ylen;
        int mid_y = mid % ylen;
        if (matrix[mid_x][mid_y] < target) {
            return find(matrix, xlen, ylen, mid + 1, right, target);
        } else if (matrix[mid_x][mid_y] > target) {
            return find(matrix, xlen, ylen, left, mid - 1, target);
        } else {
            return true;
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
