 /**
 * @file 107_Binary_Tree_Level_Order_Traversal_II.cpp
 * @author yinjingcao
 * @date 2018/05/08 15:51:37
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > result;
        if (root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for (int i = 0; i < size; ++i) {
                TreeNode* n = q.front();
                q.pop();
                temp.push_back(n->val);
                if (n->left != NULL) {
                    q.push(n->left);
                }
                if (n->right != NULL) {
                    q.push(n->right);
                }
            }
            result.push_back(temp);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
