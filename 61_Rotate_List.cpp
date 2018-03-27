/**
 * @file 61_Rotate_List.cpp
 * @author yinjingcao
 * @date 2018/03/27 15:51:40
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode* itr = head;
        int idx = 0;
        while (itr != NULL) {
            ++idx;
            itr = itr->next;
        }
        k %= idx;
        idx = 0;
        itr = head;
        ListNode* pre = NULL;
        ListNode* tail = NULL;
        ListNode* new_head = NULL;
        while (itr != NULL) {
            if (++idx == k + 1) {
                pre = head;
                new_head = pre->next;
            } else if (pre != NULL) {
                pre = pre->next;
                new_head = pre->next;
            }
            tail = itr;
            itr = itr->next;
        }
        if (new_head == NULL) {
            new_head = head;
        }
        if (new_head != head) {
            tail->next = head;
            pre->next = NULL;
        }
        return new_head;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
