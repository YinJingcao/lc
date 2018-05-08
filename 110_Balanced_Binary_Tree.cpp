/**
 * @file 110_Balanced_Binary_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 16:19:37
 * @version $Revision$ 
 * @brief 
 *  
 **/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        int left_dep = helper(root->left);
        int right_dep = helper(root->right);
        if ((left_dep - right_dep > 1) || (left_dep - right_dep < -1)) {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int helper(TreeNode* root) {
        if (root == NULL) return 0;
        return max(helper(root->left) + 1, helper(root->right) + 1);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
