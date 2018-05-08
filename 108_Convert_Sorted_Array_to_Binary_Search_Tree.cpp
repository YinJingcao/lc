/**
 * @file 108_Convert_Sorted_Array_to_Binary_Search_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 15:58:36
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, int(nums.size()) - 1, nums);
    }
private:
    TreeNode* helper(int start, int end, vector<int>& nums) {
        if (start > end) {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode* n = new TreeNode(nums[mid]);
        n->left = helper(start, mid - 1, nums);
        n->right = helper(mid + 1, end, nums);
        return n;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
