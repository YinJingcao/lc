 /**
 * @file 105_Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal.cpp
 * @author yinjingcao
 * @date 2018/05/08 15:11:10
 * @version $Revision$ 
 * @brief 
 *  
 **/

// see https://segmentfault.com/a/1190000007533101


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        cur_pos = 0;
        return helper(0, inorder.size() - 1, preorder, inorder);
    }
private:
    TreeNode* helper(int start, int end, vector<int>& preorder, vector<int>& inorder) {
        if (cur_pos >= preorder.size() || start > end) return NULL;
        TreeNode* root = new TreeNode(preorder[cur_pos]);
        int mid = 0;
        for (int i = start; i <= end; ++i) {
            if (inorder[i] == preorder[cur_pos]) {
                mid = i;
                break;
            }
        }
        ++cur_pos;
        root->left = helper(start, mid - 1, preorder, inorder);
        root->right = helper(mid + 1, end, preorder, inorder);
        return root;
    }
private:
    int cur_pos;
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
