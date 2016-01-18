/*
 * =====================================================================================
 *
 *       Filename:  rm_linked_list_elements.cc
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  07/06/2015 09:46:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include	<iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
        ListNode* removeElements(ListNode* head, int val) {
            if (!head)
                return NULL;

            ListNode* new_head = head;
            ListNode* to_be_deleted = NULL;
            ListNode* curr = head;
            ListNode* prev = head;

            while (curr) {
                if (curr->val == val) {
                    to_be_deleted = curr;

                    if (curr == new_head)
                        new_head = prev = curr->next;
                    else
                        prev->next = curr->next;

                    curr = curr->next;
                    delete to_be_deleted;
                } else {
                    prev = curr;
                    curr = curr->next;
                }
            }

            return new_head;
        }
};

void prt(ListNode* h) {
    ListNode* p = h;

    while (p) {
        std::cout << "val: " << p->val << std::endl;
        p = p->next;
    }
}


/*
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:
 * =====================================================================================
 */
int
main(int argc, char* argv[]) {
    ListNode* head = new ListNode(10);
    head->next = new ListNode(10);
    //head->next->next = new ListNode(6);
    //head->next->next->next = new ListNode(7);
    //head->next->next->next->next = new ListNode(7);
    prt(head);
    Solution s;
    ListNode* n = s.removeElements(head, 10);
    prt(n);
    return 0;
}				/* ----------  end of function main  ---------- */
