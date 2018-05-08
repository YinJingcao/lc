/**
 * @file 112_Path_Sum.cpp
 * @author yinjingcao
 * @date 2018/05/08 16:38:46
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left == NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
