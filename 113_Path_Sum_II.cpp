/**
 * @file 113_Path_Sum_II.cpp
 * @author yinjingcao
 * @date 2018/05/08 16:46:24
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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> temp;
        helper(root, sum, temp, result);
        return result;
    }
private:
    void helper(TreeNode* root, int sum, vector<int>& temp, vector<vector<int> >& result) {
        if (root == NULL) return;
        if (root->val == sum && root->left == NULL && root->right == NULL) {
            temp.push_back(root->val);
            result.push_back(temp);
            temp.erase(temp.end() - 1);
            return;
        }
        if (root->left != NULL) {
            temp.push_back(root->val);
            helper(root->left, sum - root->val, temp, result);
            temp.erase(temp.end() - 1);
        }
        if (root->right != NULL) {
            temp.push_back(root->val);
            helper(root->right, sum - root->val, temp, result);
            temp.erase(temp.end() - 1);
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
