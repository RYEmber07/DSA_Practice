// Reverse a Doubly Linked List
// https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-doubly-linked-list

// Brute Using Stack

/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        stack<int> stk;
        DLLNode* temp = head;
        while (temp != nullptr){
            stk.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr){
            temp->data = stk.top();
            stk.pop();
            temp = temp->next;
        }
        return head;
    }
};

// TC O(n) SC O(n)
// Approach : keep adding to stack and then again iterate and pop values of stack and modify the values.


// Another Approach using two pointers and swapping the data of the linked list 
/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        DLLNode* temp1 = head;
        DLLNode* temp2 = head;
        int count = 0;
        while (temp2->next != nullptr){
            temp2 = temp2->next;
            count++;
        }
        count = (count + 1) / 2;
        while (count--){
            swap(temp1->data, temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->prev;
        }
        return head;
    }
};
// TC O(n) SC O(1)
// Swap the elements from the two ends
// though Swapping data works but is inefficient if data is large


// Optimal (Reverse the Links in a *Single* Traversal)
// Standard Approach 
// (Only one pass is needed) , (Swaps only pointers, avoiding unnecessary data swaps) , efficient approach

/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        DLLNode* temp = head;
        DLLNode* back = nullptr;
        while (temp != nullptr){
            back = temp->prev;
            temp->prev = temp->next;
            temp->next = back;
            temp = temp->prev;
        }
        return back->prev;
    }
};


// TC O(n) SC O(1)
// Approach : refer article https://takeuforward.org/data-structure/reverse-a-doubly-linked-list/