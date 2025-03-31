// 876. Middle of the Linked List
// https://leetcode.com/problems/middle-of-the-linked-list/description/

// Brute 
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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr){
            count++;
            temp = temp->next;
        }
        int pos = (count / 2) + 1;
        temp = head;
        while (--pos){
            temp = temp->next;
        }
        return temp;
    }
};
// TC O(n+n/2) SC O(1)
// Approach : By counting the total number of elements . then finding the pos of middle element 


// Optimal Using Tortoise and Hare Algo 

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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// TC O(n/2) SC O(1)
// approach : we assume 2 pointers one that traverse two times faster than slower one. when the iteration gets over which depends on the condition of the fast pointer reaching the last element in odd elements condn and reaching null in even elements condn stop the iteration and slow would have reached the middle.
