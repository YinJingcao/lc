/**
 * @file 99_Recover_Binary_Search_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 13:26:03
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
    void recoverTree(TreeNode* root) {
        first = NULL;
        second = NULL;
        pre = new TreeNode(INT_MIN);
        helper(root);
        if (first != NULL && second != NULL) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }

private:
    void helper(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        helper(root->left);
        if (first == NULL && pre->val > root->val) {
            first = pre;
        }
        if (first != NULL && pre->val > root->val) {
            second = root;
        }
        pre = root;
        helper(root->right);
    }
    TreeNode* first;
    TreeNode* second;
    TreeNode* pre;

};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
