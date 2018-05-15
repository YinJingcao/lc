/**
 * @file 116_Populating_Next_Right_Pointers_in_Each_Node.cpp
 * @author yinjingcao
 * @date 2018/05/14 14:53:56
 * @version $Revision$ 
 * @brief 
 *  
 **/


//Definition for binary tree with next pointer.
struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (NULL == root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            TreeLinkNode* t = NULL;
            for (int i = 0; i < size; ++i) {
                TreeLinkNode* n = q.front();
                q.pop();
                if (t != NULL) {
                    t->next = n;
                }
                t = n;
                if (NULL != n->left) {
                    q.push(n->left);
                }
                if (NULL != n->right) {
                    q.push(n->right);
                }
            }
            t->next = NULL;
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
