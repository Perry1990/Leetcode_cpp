//	Problem	:	Merge k Sorted List
//	Author	:	perry1990
//	Date	:	2015/2/21
//	Runtime	:	54 ms
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
    struct compare {
		bool operator () (ListNode *a, ListNode *b)
		{
			return a->val > b->val;
		}
	};
	
	ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
		for (int i = 0; i < lists.size(); i ++)
			if (lists[i] != NULL)
				q.push(lists[i]);
		if (q.empty()) return NULL;		
		ListNode *ans = q.top(), *crnt = q.top();
		q.pop();
		if (ans->next != NULL)
			q.push(ans->next);
		while (!q.empty())
		{
			crnt->next = q.top();
			q.pop();
			crnt = crnt->next;
			if (crnt->next)
				q.push(crnt->next);
		}
		return ans;
    }
};