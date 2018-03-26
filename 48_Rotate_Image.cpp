/**
 * @file 48_Rotate_Image.cpp
 * @author yinjingcao
 * @date 2018/03/26 15:34:15
 * @version $Revision$ 
 * @brief 
 *  
 **/

// see https://segmentfault.com/a/1190000009405899

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        for(int i = 0 ; i < length/2 ; i++){
            for(int j = i ; j<length-i-1 ; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[length-j-1][i];
                matrix[length-j-1][i] = matrix[length-i-1][length-j-1];
                matrix[length-i-1][length-j-1] = matrix[j][length-i-1];
                matrix[j][length-i-1] = temp;
            }
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
