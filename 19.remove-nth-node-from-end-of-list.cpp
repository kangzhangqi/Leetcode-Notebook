/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (33.95%)
 * Total Accepted:    247.4K
 * Total Submissions: 728.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		//鲁棒1：链表为空
		if(!head->next) return NULL;
		ListNode *left = head, *right = head;
		for (int i = 0; i < n; ++i) right = right->next;
		//鲁棒2：链表不足n长，移除第一个节点
		if(!right) return head->next;

		while (right->next){
			left = left->next;
			right = right->next;
		}
		left->next = left->next->next;
		return head;
    }
};
