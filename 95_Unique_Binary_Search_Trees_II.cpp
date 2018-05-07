 /**
 * @file 95_Unique_Binary_Search_Trees_II.cpp
 * @author yinjingcao
 * @date 2018/05/07 16:48:10
 * @version $Revision$ 
 * @brief 
 *  
 **/


// see https://segmentfault.com/a/1190000007443961

//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            vector<TreeNode*> result;
            return result;
        }
        return helper(n, 1);
    }
private:
    vector<TreeNode*> helper(int n, int s) {
        vector<TreeNode*> result;
        if (n == 0) {
            result.push_back(NULL);
            return result;
        }
        if (n == 1) {
            result.push_back(new TreeNode(s));
            return result;
        }
        for (int i = 0; i < n; ++i) {
            vector<TreeNode*> left = helper(i, s);
            vector<TreeNode*> right = helper(n - i - 1, s + i + 1);
            for (int l = 0; l < left.size(); ++l) {
                for (int r = 0; r < right.size(); ++r) {
                    TreeNode* root = new TreeNode(s + i);
                    root->left = left[l];
                    root->right = right[r];
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
