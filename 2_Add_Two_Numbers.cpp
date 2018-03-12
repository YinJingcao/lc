 /**
 * @file 2_Add_Two_Numbers.cpp
 * @author yinjingcao
 * @date 2018/03/12 20:02:18
 * @version $Revision$ 
 * @brief 
 *  
 **/

#include <iostream>

/**
 * Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = NULL;
        ListNode* itr1 = l1;
        ListNode* itr2 = l2;
        ListNode* itr = result;
        int jw = 0;
        while (itr1 != NULL && itr2 != NULL) {
            int val1 = itr1->val;
            int val2 = itr2->val;
            int val = (jw + val1 + val2) % 10;
            jw = (jw + val1 + val2) / 10;
            ListNode* node = new ListNode(val);
            if (result == NULL) {
                result = node;
                itr = result;
            } else {
                itr->next = node;
                itr = itr->next;
            }
            itr1 = itr1->next;
            itr2 = itr2->next;
        }
        ListNode* e_itr = NULL;
        if (itr1 != NULL) {
            e_itr = itr1;
        } else {
            e_itr = itr2;
        }
        while (e_itr != NULL) {
            int val1 = e_itr->val;
            int val = (jw + val1) % 10;
            jw = (jw + val1) / 10;
            ListNode* node = new ListNode(val);
            if (result == NULL) {
                result = node;
                itr = result;
            } else {
                itr->next = node;
                itr = itr->next;
            }
            e_itr = e_itr->next;
        }
        if (jw != 0) {
            ListNode* node = new ListNode(jw);
            itr->next = node;
        }
        return result;
    }
};

void build_list(ListNode*& l1, ListNode*& l2) {
    l1 = new ListNode(2);
    ListNode* itr = l1;
    ListNode* node = new ListNode(4);
    itr->next = node;
    itr = itr->next;
    node = new ListNode(3);
    itr->next = node;
    l2 = new ListNode(5);
    itr = l2;
    node = new ListNode(6);
    itr->next = node;
    itr = itr->next;
    node = new ListNode(7);
    itr->next = node;
}

int main() {
    Solution s;
    ListNode* l1;
    ListNode* l2;
    build_list(l1, l2);
    ListNode* result = s.addTwoNumbers(l1, l2);
    ListNode* itr = result;
    while (itr != NULL) {
        printf("%d\t", itr->val);
        itr = itr->next;
    }
    printf("\n");
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
