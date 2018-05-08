/**
 * @file 102_Binary_Tree_Level_Order_Traversal.cpp
 * @author yinjingcao
 * @date 2018/05/08 14:03:37
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
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            if (!temp.empty()) {
                result.push_back(temp);
            }
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
