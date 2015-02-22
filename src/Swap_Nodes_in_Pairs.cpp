//	Problem	:	Swap Nodes in Pairs
//	Author	:	perry1990
//	Date	:	2015/2/21
//	Runtime	:	6 ms
/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *preNode, *crntNode, *preHead;
		preNode = new ListNode(0);
		preNode->next = head;
		preHead = preNode;
		crntNode = head;
		
		while(crntNode && crntNode->next)
		{
			preNode->next = crntNode->next;
			crntNode->next = crntNode->next->next;
			preNode->next->next = crntNode;
			preNode = crntNode;
			crntNode = crntNode->next;
		}
		return preHead->next;
    }
};