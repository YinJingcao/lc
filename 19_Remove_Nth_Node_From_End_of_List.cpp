 /**
 * @file 19_Remove_Nth_Node_From_End_of_List.cpp
 * @author yinjingcao
 * @date 2018/03/16 16:49:36
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* itr = head;
        ListNode* itr_del_pre = NULL;
        int idx = 0;
        while (itr != NULL) {
            if (itr_del_pre != NULL) {
                itr_del_pre = itr_del_pre->next;
            }
            if (++idx == n + 1) {
                itr_del_pre = head;
            }
            itr = itr->next;
        }
        if (itr_del_pre != NULL) {
            itr_del_pre->next = itr_del_pre->next->next;
        } else {
            if (head != NULL) {
                return head->next;
            }
        }
        return head;
    }
};

int main() {
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
