// 141. Linked List Cycle
// https://leetcode.com/problems/linked-list-cycle/

// Brute 
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
    bool hasCycle(ListNode* head) {
        unordered_set <ListNode*> st;
        ListNode* temp = head;
        while (temp != nullptr){
            if (st.find(temp) != st.end()){
                return true;
            }
            st.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};
// TC O(n) worst case O(n square) {very rare depends on hash collisons} SC O(n) 


// Optimal using Floyd's Cycle Detection Algorithm or Tortoise and Hare Algo

// The Tortoise and Hare Algorithm is a general two-pointer technique where one pointer moves slower (tortoise) and the other moves faster (hare).
// Floyd's Cycle Detection Algorithm is a special case of this approach that is specifically used to detect cycles in a linked list or directed graph.

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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow){
                return true;
            }
        }
        return false;
    }
};

// TC O(n) SC O(1)
// Approach : if lets say the linked list is linear then the fast pointer always moves away from the slow one , fast pointer moves away 2 nodes and the slow catches by 1 node net resultant is fast pointer oves away 1 node away each time . 
// on the other hand when we enter the cycle now the fast pointer approaches the slow one by 2 and slow runs away by 1 . lets say the original distance between them was d then it becomes d-1 then d-2 and so on becomes 0  and slow and fast pointer eventually meet/collide.