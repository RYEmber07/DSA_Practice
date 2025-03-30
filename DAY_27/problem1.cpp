// Delete in a Doubly Linked List
// https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=delete-node-in-doubly-linked-list

/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        if (x == 1){
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
            return head;
        }
        int count = 1;
        Node* temp = head;
        while (temp->next != nullptr){
            if (count == x){
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return head;
            }
            temp = temp->next;
            count++;
        }
        temp->prev->next = nullptr;
        delete temp;
        return head;
    }
};

// TC O(n) SC O(1)
// check if node is head or some element or tail 
// constraints :
// 2 <= size of the linked list <= 1e6
// 1 <= x <= size of the linked list
// 1 <= node->data <= 1e4