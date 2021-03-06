 /**
 * @file 21_Merge_Two_Sorted_Lists.cpp
 * @author yinjingcao
 * @date 2018/03/16 17:25:40
 * @version $Revision$ 
 * @brief 
 *  
 **/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* lhs = l1;
        ListNode* rhs = l2;
        ListNode* result = new ListNode(0);
        result->next = lhs;
        ListNode* itr = result;
        while (lhs != NULL && rhs != NULL) {
            if (lhs->val < rhs->val) {
                itr = lhs;
                lhs = lhs->next;
            } else {
                itr->next = rhs;
                rhs = rhs->next;
                itr = itr->next;
                itr->next = lhs;
            }
        }
        if (lhs != NULL) {
            itr->next = lhs;
        } else {
            itr->next = rhs;
        }
        return result->next;
    }
};

// wrong
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* lhs = l1;
        ListNode* rhs = l2;
        while (lhs != NULL && rhs != NULL) {
            if (lhs->val < rhs->val) {
                ListNode* tmp = lhs;
                lhs = lhs->next;
                tmp->next = rhs;
            } else {
                ListNode* tmp = rhs;
                rhs = rhs->next;
                tmp->next = lhs;
            }
        }
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        if (l1->val < l2->val) {
            return l1;
        } else {
            return l2;
        }
    }
};

/* vim: set ts=4 sw=4 sts=4 tw=100 */
