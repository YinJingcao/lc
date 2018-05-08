/**
 * @file 106_Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal.cpp
 * @author yinjingcao
 * @date 2018/05/08 15:37:57
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;
        cur_pos = postorder.size() - 1;
        return helper(0, inorder.size() - 1, inorder, postorder);
    }
private:
    TreeNode* helper(int start, int end, vector<int>& inorder, vector<int>& postorder) {
        if (start > end || cur_pos < 0) return NULL;
        TreeNode* root = new TreeNode(postorder[cur_pos]);
        int mid = 0;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == postorder[cur_pos]) {
                mid = i;
                break;
            }
        }
        --cur_pos;
        root->right = helper(mid + 1, end, inorder, postorder);
        root->left = helper(start, mid - 1, inorder, postorder);
        return root;
    }

private:
    int cur_pos;
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
