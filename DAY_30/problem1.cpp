// 148. Sort List
// https://leetcode.com/problems/sort-list/

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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp = dummy;
        while (temp1 != nullptr && temp2 != nullptr){
            if (temp1->val <= temp2->val){
                temp->next = temp1;
                temp = temp1;
                temp1 = temp1->next;
            }
            else{
                temp->next = temp2;
                temp = temp2;
                temp2 = temp2->next;
            }
        }
        if (temp1){ temp->next = temp1; }
        else if (temp2){ temp->next = temp2; }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = nullptr;
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);
        return mergeTwoLists(leftHead, rightHead);
    }
};

// TC O(nlogn) SC O(logn){recursive stack space}