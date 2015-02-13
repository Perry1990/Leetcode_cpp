//	Problem	:	Add Two Numbers
//	Author	:	perry1990
//	Date	:	2015/2/12
//	Runtime	:	101 ms
/*
You are given two linked lists representing two non-negative numbers.
The digits are stored in reverse order and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        ListNode *ans;
        ListNode *crnt_node = NULL;
        while(l1 || l2)
        {
            int val_l1 = (l1)?l1->val:0;
            int val_l2 = (l2)?l2->val:0;
            int val_s = val_l1 + val_l2 + carry;
            carry = (val_s >= 10) ? 1 : 0;
            val_s = (val_s >= 10) ? val_s - 10 : val_s;
            ListNode *new_node = new ListNode(val_s);
            if (crnt_node) {
                crnt_node->next = new_node;
                crnt_node = new_node;
            }
            else {
                crnt_node = new_node;
                ans = new_node;
            }
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry)
        {
            ListNode *new_node = new ListNode(carry);
            crnt_node->next = new_node;
        }
        return ans;
    }
};