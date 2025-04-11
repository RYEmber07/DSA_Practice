// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* dummyCurr = dummyHead;

        int carry = 0;
        while (temp1 != nullptr || temp2 != nullptr){
            int sum = carry;
            if (temp1){ sum += temp1->val; }
            if (temp2){ sum += temp2->val; }
            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            dummyCurr->next = newNode;
            dummyCurr = newNode;

            if (temp1){ temp1 = temp1->next; }
            if (temp2){ temp2 = temp2->next; }
        }
        if (carry){
            ListNode* newNode = new ListNode(carry);
            dummyCurr->next = newNode;
        }
        return dummyHead->next;
    }
};

// using dummy node TC O(max(n1,n2)) SC  O(max(n1,n2)) {to store the result} 