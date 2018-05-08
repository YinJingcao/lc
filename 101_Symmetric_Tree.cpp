 /**
 * @file 101_Symmetric_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 13:54:19
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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return helper(root->left, root->right);
    }
private:
    bool helper(TreeNode* left, TreeNode* right) {
        if (left == NULL) return right == NULL;
        if (right == NULL) return left == NULL;
        return left->val == right->val && helper(left->left, right->right) && helper(left->right, right->left);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
