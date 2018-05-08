/**
 * @file 111_Minimum_Depth_of_Binary_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 16:30:06
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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right != NULL) {
            return minDepth(root->right) + 1;
        }
        if (root->right == NULL && root->left != NULL) {
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left) + 1, minDepth(root->right) + 1);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
