/**
 * @file 83_Remove_Duplicates_from_Sorted_List.cpp
 * @author yinjingcao
 * @date 2018/03/29 19:08:28
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (NULL == head) return head;
        int val = head->val;
        ListNode* new_head = head;
        ListNode* itr = head->next;
        ListNode* last = head;
        while (itr != NULL) {
            if (itr->val != val) {
                last->next = itr;
                last = itr;
            }
            val = itr->val;
            itr = itr->next;
        }
        last->next = NULL;
        return new_head;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
