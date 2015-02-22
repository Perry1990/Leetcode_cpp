//	Problem	:	Reverse Nodes in k-Group
//	Author	:	perry1990
//	Date	:	2015/2/21
//	Runtime	:	31 ms
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *preHead, *crntNode, *preNode;
		preNode = new ListNode(0);
		preNode->next = head;
		preHead = preNode;
		
		int gpDetected = 1;
		while (gpDetected)
		{
			crntNode = preNode;
			for (int i = 0; i < k; i ++)
			{
				if (crntNode->next)
					crntNode = crntNode->next;
				else {
					gpDetected = 0;
					break;
				}
			}
			if (!gpDetected)
				break;
			crntNode = preNode;
			ListNode **l;
			l = new ListNode *[k];
			for (int i = 0; i < k; i ++)
			{
				crntNode = crntNode->next;
				l[i] = crntNode;
			}
			l[0]->next = l[k - 1]->next;
			for (int i = 1; i < k; i ++)
				l[i]->next = l[i - 1];
			preNode->next = l[k - 1];
			preNode = l[0];
		}
		return preHead->next;
    }
};