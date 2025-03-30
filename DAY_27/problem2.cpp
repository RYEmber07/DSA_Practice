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

// Optimal (Reverse the Links in a Single Traversal)


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