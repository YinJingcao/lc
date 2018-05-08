 /**
 * @file 100_Same_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 13:47:39
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL) return q == NULL;
        if (q == NULL) return p == NULL;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right); 
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
