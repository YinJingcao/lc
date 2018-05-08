 /**
 * @file 98_Validate_Binary_Search_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 10:57:18
 * @version $Revision$ 
 * @brief 
 *  
 **/


//Definition for a binary tree node.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> a;
        helper(root, a);
        for (int idx = 1; idx < a.size(); ++idx) {
            if (a[idx] <= a[idx - 1]) {
                return false;
            }
        }
        return true;
    }
private:
    void helper(TreeNode* root, vector<int>& a) {
        if (root != NULL) {
            helper(root->left, a);
            a.push_back(root->val);
            helper(root->right, a);
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
