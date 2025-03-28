// Doubly linked list Insertion at given position
// https://www.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=insert-a-node-in-doubly-linked-list

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
public:
    // Function to insert a new node at given position in doubly linked list.
    Node* addNode(Node* head, int pos, int data) {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr){
            if (count == pos){
                break;
            }
            temp = temp->next;
            count++;
        }
        Node* newNode = new Node(data);
        if (temp->next == nullptr){
            newNode->prev = temp;
            temp->next = newNode;
            return head;
        }
        newNode->prev = temp;
        newNode->next = temp->next;

        temp->next->prev = newNode;
        temp->next = newNode;

        return head;
    }
};

// TC O(n) SC O(1)
// Approach : first find the element in the linked list that corresponds to the given element , then make a new node if the index was of the last of the linkedlist consider seperately and insert element at tail , otherwise simply insert the element considering the before and after node to it.