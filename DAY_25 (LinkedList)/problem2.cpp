// Linked List Insertion At End
// https://www.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=linked-list-insertion

/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
public:
    Node* insertAtEnd(Node* head, int x) {
        Node* temp = head;
        Node* newNode = new Node(x);
        if (head == nullptr){ return newNode; }
        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
};

// TC O(n){n is no. of elements in linkedlist/ no. of nodes} SC O(1) 
// Approach : need to return the new node if the head was empty else move to the last element , create a new node link the last node with this node.  