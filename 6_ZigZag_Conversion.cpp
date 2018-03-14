 /**
 * @file 6_ZigZag_Conversion.cpp
 * @author yinjingcao
 * @date 2018/03/13 19:59:02
 * @version $Revision$ 
 * @brief 
 *  
 **/

// see https://segmentfault.com/a/1190000004156886

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(const string& s, int numRows) {
        int size = s.size();
        if (numRows <= 1 || numRows >= size) {
            return s;
        }
        vector<string> rowString(numRows);
        int rowNum = 1;
        int flag = 1;
        for (int i = 0; i < size; ++i) {
            rowString[rowNum-1] += s[i];
            if (rowNum == numRows){
                flag = -1;
            }
            if (rowNum == 1) {
                flag = 1;
            }
            rowNum += flag;
        }
        
        string result;
        for (int i = 0; i < numRows; ++i) {
            result += rowString[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.convert("PAYPALISHIRING", 3).c_str());
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
