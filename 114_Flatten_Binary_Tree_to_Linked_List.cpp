/**
 * @file 114_Flatten_Binary_Tree_to_Linked_List.cpp
 * @author yinjingcao
 * @date 2018/05/08 17:01:51
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
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = NULL;
        root->right = left;
        TreeNode* it = root;
        while (it->right != NULL) it = it->right; 
        it->right = right;
        flatten(left);
        flatten(right);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
