// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/

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
    void deleteNode(ListNode* node) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
    }
};

// TC O(1) SC O(1)
// Approach : We ahve no idea about the previous list so instead of changing the previous next just copy from what our list will continue to the given node and then delete the next node. 
