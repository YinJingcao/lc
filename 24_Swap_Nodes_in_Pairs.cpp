 /**
 * @file 24_Swap_Nodes_in_Pairs.cpp
 * @author yinjingcao
 * @date 2018/03/19 11:32:48
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* l1 = head;
        ListNode* l2 = head->next;
        ListNode* result = new ListNode(0);
        ListNode* pre = result;
        while (l1 != NULL && l2 != NULL) {
            pre->next = l2;
            pre = l1;
            ListNode* tmp = l2->next;
            l2->next = l1;
            l1->next = tmp;
            l1 = tmp;
            if (l1 != NULL) {
                l2 = l1->next;
            }
        }
        return result->next;
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
