 /**
 * @file 25_Reverse_Nodes_in_k-Group.cpp
 * @author yinjingcao
 * @date 2018/03/19 14:05:49
 * @version $Revision$ 
 * @brief 
 *  
 **/


#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) {
            return head;
        }
        ListNode* l1 = head;
        ListNode* l2 = NULL;
        if (!check_valid(l1, l2, k)) {
            return head;
        }
        ListNode result(0);
        ListNode* pre = &result;
        while (true) {
            if (!check_valid(l1, l2, k)) {
                break;
            }
            pre->next = l2;
            pre = l1;
            ListNode* tmp = l2->next;
            reverse(l1, l2);
            l1->next = tmp;
            l1 = tmp;
        }
        return result.next;
    }

private:
    void reverse(ListNode* l1, ListNode* l2) {
        ListNode* lhs = l1;
        ListNode* rhs = l1->next;
        while (rhs != l2) {
            ListNode* tmp1 = rhs;
            ListNode* tmp2 = rhs->next;
            rhs->next = lhs;
            rhs = tmp2;
            lhs = tmp1;
        }
        rhs->next = lhs;
    }

    bool check_valid(ListNode* l1, ListNode*& l2, int k) {
        l2 = l1;
        while (l2 != NULL) {
            if (--k <= 0) {
                break;
            }
            l2 = l2->next;
        }
        return l2 != NULL;
    }

};

int main() {
    Solution s;
    ListNode head(-1);
    ListNode* itr = &head;
    for (size_t idx = 1; idx < 6; ++idx) {
        ListNode* node = new ListNode(idx);
        itr->next = node;
        itr = node;
    }
    ListNode* result = s.reverseKGroup(head.next, 3);
    while (result != NULL) {
        printf("%d\t", result->val);
        result = result->next;
    }
    printf("\n");
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
