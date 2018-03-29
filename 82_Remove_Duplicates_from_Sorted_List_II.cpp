/**
 * @file 82_Remove_Duplicates_from_Sorted_List_II.cpp
 * @author yinjingcao
 * @date 2018/03/29 18:16:54
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
        if (NULL == head || NULL == head->next) return head;
        ListNode* itr = head;
        ListNode* left_itr = NULL;
        ListNode* new_head = NULL;
        ListNode* last = NULL;
        while (itr != NULL) {
            if (((NULL == left_itr) || (NULL != left_itr && left_itr->val != itr->val)) && 
                    ((NULL == itr->next) || (NULL != itr->next && itr->next->val != itr->val))) {
                if (NULL == new_head) {
                    new_head = itr;
                    last = itr;
                } else {
                    last->next = itr;
                    last = itr;
                }
            }
            left_itr = itr;
            itr = itr->next;
        }
        if (NULL != last) {
            last->next = NULL;
        }
        return new_head;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
