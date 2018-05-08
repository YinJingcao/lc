 /**
 * @file 104_Maximum_Depth_of_Binary_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 14:45:43
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL) {
            return maxDepth(root->right) + 1;
        }
        if (root->right == NULL) {
            return maxDepth(root->left) + 1;
        }
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
