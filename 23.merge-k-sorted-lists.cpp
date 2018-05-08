/*
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (28.31%)
 * Total Accepted:    222.4K
 * Total Submissions: 785K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//方法1：两两折半查找
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		int size = lists.size();
		if (size == 0 ) return NULL;
		while(size > 1){
			int next_size = (size + 1) / 2;
			for (int i = 0; i < size / 2; ++i){
				lists[i] = mergeLists(lists[i], lists[i + next_size]);
			}
			size = next_size;
		}
		return lists[0];
    }

	//merge two list
	ListNode* mergeLists(ListNode *l1, ListNode *l2){
		ListNode *head = new ListNode(0);
		ListNode *cur = head;

		while (l1 && l2){
			if (l1 -> val < l2 -> val){
				cur -> next = new ListNode(l1 -> val);
				l1 = l1 -> next;
			}
			else{
				cur -> next = new ListNode(l2 -> val);
				l2 = l2 -> next;
			}
			cur = cur -> next;
		}
		cur  -> next = l1 ? l1 : l2;
		return head->next;
	}
};
