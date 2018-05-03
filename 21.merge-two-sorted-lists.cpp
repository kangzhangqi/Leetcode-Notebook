/*
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (41.38%)
 * Total Accepted:    343.8K
 * Total Submissions: 830.8K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *temp = new ListNode(-1),*cur = temp;
		while(l1 && l2){
			if(l1->val < l2->val){
				cur->next = l1;
				l1 = l1->next;
			}
			else{
			  cur->next = l2;
			  l2 = l2->next;
			}
			cur = cur->next;
		}
		cur->next = l1 ? l1 : l2;
		return temp->next;
    }
};
