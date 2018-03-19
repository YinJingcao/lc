/**
 * @file 23_Merge_k_Sorted_Lists.cpp
 * @author yinjingcao
 * @date 2018/03/16 18:06:43
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* itr = NULL;
        for (size_t idx = 0; idx < lists.size(); ++idx) {
            itr = mergeTwoLists(itr, lists[idx]);
        }
        return itr;
    }

private:
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

/* vim: set ts=4 sw=4 sts=4 tw=100 */
