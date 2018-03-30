/**
 * @file 86_Partition_List.cpp
 * @author yinjingcao
 * @date 2018/03/30 18:04:20
 * @version $Revision$ 
 * @brief 
 *  
 **/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = NULL;
        ListNode* right = NULL;
        ListNode* left_head = NULL;
        ListNode* right_head = NULL;
        ListNode* itr = head;
        while (itr != NULL) {
            if (itr->val < x) {
                if (left_head == NULL) {
                    left_head = itr;
                    left = itr;
                } else {
                    left->next = itr;
                    left = itr;
                }
            } else {
                if (right_head == NULL) {
                    right_head = itr;
                    right = itr;
                } else {
                    right->next = itr;
                    right = itr;
                }
            }
            itr = itr->next;
        }
        if (left != NULL) {
            left->next = right_head;
        } else {
            left_head = right_head;
        }
        if (right != NULL) {
            right->next = NULL;
        }
        return left_head;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
