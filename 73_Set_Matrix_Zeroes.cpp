/**
 * @file 73_Set_Matrix_Zeroes.cpp
 * @author yinjingcao
 * @date 2018/03/28 19:02:27
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        bool first_row_zero = false;
        bool first_col_zero = false;
        for (size_t idx = 0; idx < matrix.size(); ++idx) {
            for (size_t jdx = 0; jdx < matrix[idx].size(); ++jdx) {
                if (idx != 0 && jdx != 0 && 0 == matrix[idx][jdx]) {
                    matrix[idx][0] = 0;
                    matrix[0][jdx] = 0;
                } else if (0 == matrix[idx][jdx]) {
                    first_row_zero = (idx == 0 ? true : first_row_zero);
                    first_col_zero = (jdx == 0 ? true : first_col_zero);
                }
            }
        }
        for (size_t idx = 1; idx < matrix.size(); ++idx) {
            for (size_t jdx = 1; jdx < matrix[idx].size(); ++jdx) {
                if (matrix[idx][0] == 0 || matrix[0][jdx] == 0) {
                    matrix[idx][jdx] = 0;
                }
            }
        }
        for (size_t idx = 0; idx < 1 && idx < matrix.size(); ++idx) {
            for (size_t jdx = 0; jdx < matrix[idx].size(); ++jdx) {
                if (first_row_zero == true) {
                    matrix[0][jdx] = 0;
                }
            }
        }
        for (size_t idx = 0; idx < matrix.size(); ++idx) {
            for (size_t jdx = 0; jdx < matrix[idx].size() && jdx < 1; ++jdx) {
                if (first_col_zero == true) {
                    matrix[idx][0] = 0;
                }
            }
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
