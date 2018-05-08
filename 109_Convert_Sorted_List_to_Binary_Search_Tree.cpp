/**
 * @file 109_Convert_Sorted_List_to_Binary_Search_Tree.cpp
 * @author yinjingcao
 * @date 2018/05/08 16:10:38
 * @version $Revision$ 
 * @brief 
 *  
 **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        return helper(head, NULL);
    }
private:
    TreeNode* helper(ListNode* left, ListNode* right) {
        if (left == right) return NULL;
        ListNode* fast = left;
        ListNode* slow = left;
        while (fast != right && fast->next != right) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* node = new TreeNode(slow->val);
        node->left = helper(left, slow);
        node->right = helper(slow->next, right);
        return node;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
