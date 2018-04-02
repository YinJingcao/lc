/**
 * @file 92_Reverse_Linked_List_II.cpp
 * @author yinjingcao
 * @date 2018/04/02 17:37:41
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* new_head = NULL;
        ListNode* pre_left = NULL;
        ListNode* left = NULL;
        ListNode* post_right = NULL;
        ListNode* right = NULL;
        ListNode* iter = head;
        while (iter != NULL) {
            if (1 == --m) {
                pre_left = iter;
            } else if (0 == m) {
                left = iter;
            }
            if (-1 == --n) {
                post_right = iter;
                break;
            } else if (0 == n) {
                right = iter;
            }
            iter = iter->next;
        }
        reverseB(left, right);
        if (pre_left != NULL) {
            pre_left->next = right;
            new_head = head;
        } else {
            new_head = right;
        }
        left->next = post_right;
        return new_head;
    }
private:
    void reverseB(ListNode* left, ListNode* right) {
        if (left == right) return;
        ListNode* itr = left->next;
        ListNode* last = left;
        ListNode* end = right->next;
        while (itr != end) {
            ListNode* n = itr->next;
            itr->next = last;
            last = itr;
            itr = n;
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
