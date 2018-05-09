/*
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (31.86%)
 * Total Accepted:    126.3K
 * Total Submissions: 395.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		//step 1 : check k node exist
		ListNode *temp = head;
		for (int i = 0; i < k-1; ++i){
			if (!temp) return head;
			temp = temp->next;
		}
		if(!temp) return head;
		//step 2 : swap k node
		ListNode *cur = head->next;
		head->next = reverseKGroup(temp->next,k);
		for(int j = 1; j < k; ++j){
			temp = cur->next;
			cur->next = head;
			head = cur;
			cur = temp;
		}
		return head;
    }
};
