// 203. Remove Linked List Elements
// https://leetcode.com/problems/remove-linked-list-elements/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr != nullptr){
            if (curr->val == val && curr == head){
                ListNode* temp = head;
                head = head->next;
                curr = head;
                delete temp;
            }
            else if (curr->val == val){
                ListNode* temp = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete temp;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

// TC O(n) SC O(1)