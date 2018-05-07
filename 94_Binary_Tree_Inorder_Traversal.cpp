 /**
 * @file 94_Binary_Tree_Inorder_Traversal.cpp
 * @author yinjingcao
 * @date 2018/05/07 16:31:52
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }

private:
    void helper(TreeNode* root, vector<int>& result) {
        if (root != NULL) {
            helper(root->left, result);  
            result.push_back(root->val);
            helper(root->right, result);  
        }
    }

};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
