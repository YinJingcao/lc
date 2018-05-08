 /**
 * @file 103_Binary_Tree_Zigzag_Level_Order_Traversal.cpp
 * @author yinjingcao
 * @date 2018/05/08 14:24:09
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool zig = false;
        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> rev(size, NULL);
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (zig) {
                    rev[size - i - 1] = node;
                } else {
                    rev[i] = node;
                }
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }
            for (int i = 0; i < size; ++i) {
                temp.push_back(rev[i]->val);
            }
            result.push_back(temp);
            zig = !zig;
        }
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
