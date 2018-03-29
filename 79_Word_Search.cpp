 /**
 * @file 79_Word_Search.cpp
 * @author yinjingcao
 * @date 2018/03/29 16:25:12
 * @version $Revision$ 
 * @brief 
 *  
 **/

class Solution {
public:
    bool exist(vector<vector<char> >& board, string& word) {
        if (board.empty()) return word == "";
        if (word.empty()) return true;
        int xlen = board.size();
        int ylen = board[0].size();
        vector<bool> tmp(ylen, false);
        vector<vector<bool> > visit(xlen, tmp);
        for (size_t idx = 0; idx < xlen; ++idx) {
            for (size_t jdx = 0; jdx < ylen; ++jdx) {
                if (helper(board, word, idx, jdx, 0, visit)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool helper(vector<vector<char> >& board, string& word, int x, int y, int len, vector<vector<bool> >& visit) {
        if (len == word.size()) {
            return true;
        }
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || visit[x][y] || board[x][y] != word[len]) {
            return false;
        }
        visit[x][y] = true;
        bool ret = helper(board, word, x + 1, y, len + 1, visit) || 
            helper(board, word, x, y + 1, len + 1, visit) ||
            helper(board, word, x - 1, y, len + 1, visit) ||
            helper(board, word, x, y - 1, len + 1, visit);
        visit[x][y] = false;
        return ret;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
