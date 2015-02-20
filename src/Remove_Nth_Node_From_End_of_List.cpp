//	Problem	:	Remove Nth Node From End of List
//	Author	:	perry1990
//	Date	:	2015/2/19
//	Runtime	:	9 ms
/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *crntNode = head;
		int total_cnt = 1, crnt_cnt;
		
		while (crntNode->next != NULL)
		{
			crntNode = crntNode->next;
			total_cnt ++;
		}
		int node_cnt = total_cnt - (n - 1);
		if (node_cnt == 1)
		{
			head = head->next;
			return head;
		}
		crnt_cnt = 1;
		crntNode = head;
		for (;crnt_cnt < node_cnt - 1; crnt_cnt ++)
			crntNode = crntNode->next;
		crntNode->next = crntNode->next->next;
		return head;
    }
};