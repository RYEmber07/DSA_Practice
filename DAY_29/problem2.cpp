// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/description/

// Brute Force using Stack

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
    bool isPalindrome(ListNode* head) {
        stack<int> stk;
        ListNode* temp = head;
        while (temp != nullptr){
            stk.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr){
            if (temp->val != stk.top()){
                return false;
            }
            stk.pop();
            temp = temp->next;
        }
        return true;
    }
};

// TC O(n) SC O(n)
// Appraoch : Store in stack and in other loop compare the values.


// Optimal using tortoise and hare algo

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverseList(slow);
        ListNode* p1 = head;
        ListNode* p2 = slow;
        while (p2 != nullptr){
            if (p2->val != p1->val){
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        slow = reverseList(slow);
        return true;
    }
private:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* temp = head;
        while (temp != nullptr){
            ListNode* nextElement = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextElement;
        }
        return prev;
    }
};

// TC O(n){n/2+n/2+n/2+n/2} SC O(1)
// Approach : reach the middle using slow and fast pointers then reverse the last part then make two pointers one at start other at slow now compare values till slow reaches end then reverse the linked list back.
